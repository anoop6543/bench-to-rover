#!/usr/bin/env python3
"""Live dashboard for the Uno JSON bridge (COM4 on Windows, /dev/ttyACM0 on Pi)."""

from __future__ import annotations

import json
import os
import platform
import threading
import time
from pathlib import Path

from flask import Flask, jsonify, render_template, request
from serial import Serial, SerialException
from serial.tools import list_ports

BAUD = int(os.environ.get("SERIAL_BAUD", "115200"))
HOST = os.environ.get("DASHBOARD_HOST", "0.0.0.0")
PORT = int(os.environ.get("DASHBOARD_PORT", "5000"))

_state_lock = threading.Lock()
_serial_lock = threading.Lock()
_latest: dict = {}
_connected = False
_last_error = ""
_serial: Serial | None = None


def default_serial_port() -> str:
    explicit = os.environ.get("SERIAL_PORT")
    if explicit:
        return explicit
    if platform.system() == "Windows":
        return "COM4"
    for candidate in ("/dev/ttyACM0", "/dev/ttyUSB0"):
        if Path(candidate).exists():
            return candidate
    return "/dev/ttyACM0"


def read_pi_stats() -> dict:
    stats = {
        "cpu_c": None,
        "load1": None,
        "mem_total_mb": None,
        "mem_avail_mb": None,
        "uptime_s": None,
        "hostname": platform.node(),
    }
    temp_path = Path("/sys/class/thermal/thermal_zone0/temp")
    if temp_path.exists():
        try:
            stats["cpu_c"] = round(int(temp_path.read_text().strip()) / 1000.0, 1)
        except (OSError, ValueError):
            pass
    try:
        load1, _, _ = os.getloadavg()
        stats["load1"] = round(load1, 2)
    except (OSError, AttributeError):
        pass
    meminfo = Path("/proc/meminfo")
    if meminfo.exists():
        fields = {}
        for line in meminfo.read_text().splitlines():
            parts = line.split()
            if len(parts) >= 2:
                fields[parts[0].rstrip(":")] = int(parts[1])
        if "MemTotal" in fields:
            stats["mem_total_mb"] = round(fields["MemTotal"] / 1024, 1)
        if "MemAvailable" in fields:
            stats["mem_avail_mb"] = round(fields["MemAvailable"] / 1024, 1)
    uptime = Path("/proc/uptime")
    if uptime.exists():
        try:
            stats["uptime_s"] = int(float(uptime.read_text().split()[0]))
        except (OSError, ValueError, IndexError):
            pass
    return stats


def send_line(line: str) -> bool:
    global _last_error
    with _serial_lock:
        if _serial is None or not _serial.is_open:
            _last_error = "Arduino serial is not open"
            return False
        try:
            _serial.write((line.strip() + "\n").encode("ascii"))
            _serial.flush()
            return True
        except SerialException as exc:
            _last_error = str(exc)
            return False


def serial_loop(port_name: str) -> None:
    global _serial, _connected, _latest, _last_error
    backoff = 1.0
    while True:
        try:
            ser = Serial(port_name, BAUD, timeout=1)
            with _serial_lock:
                _serial = ser
            with _state_lock:
                _connected = True
                _last_error = ""
            backoff = 1.0
            while True:
                with _serial_lock:
                    raw = ser.readline()
                if not raw:
                    continue
                try:
                    text = raw.decode("ascii", errors="ignore").strip()
                    if not text.startswith("{"):
                        continue
                    payload = json.loads(text)
                except (json.JSONDecodeError, ValueError):
                    continue
                with _state_lock:
                    _latest = payload
                    _connected = True
        except SerialException as exc:
            with _state_lock:
                _connected = False
                _last_error = str(exc)
            with _serial_lock:
                if _serial is not None:
                    try:
                        _serial.close()
                    except SerialException:
                        pass
                    _serial = None
            time.sleep(backoff)
            backoff = min(backoff * 2, 8.0)


app = Flask(__name__)
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.get("/")
def index():
    return render_template("joystick.html")


@app.get("/vitals")
def vitals():
    return render_template("vitals.html")


@app.get("/patterns")
def patterns():
    return render_template("patterns.html")


@app.get("/button")
def button():
    return render_template("button.html")


@app.get("/pwm")
def pwm():
    return render_template("pwm.html")


@app.get("/pad")
def pad():
    return render_template("pad.html")


@app.get("/buttons")
def buttons():
    return render_template("buttons.html")


@app.get("/tilt")
def tilt():
    return render_template("tilt.html")


@app.get("/bench")
def bench():
    return render_template("index.html")


@app.get("/api/state")
def api_state():
    with _state_lock:
        sample = dict(_latest)
        connected = _connected
        error = _last_error
    return jsonify(
        {
            "arduino": sample,
            "connected": connected,
            "error": error,
            "serial_port": default_serial_port(),
            "pi": read_pi_stats(),
            "ports": [p.device for p in list_ports.comports()],
        }
    )


@app.post("/api/rgb")
def api_rgb():
    body = request.get_json(silent=True) or {}
    r = max(0, min(255, int(body.get("r", 0))))
    g = max(0, min(255, int(body.get("g", 0))))
    b = max(0, min(255, int(body.get("b", 0))))
    ok = send_line(f"RGB:{r},{g},{b}")
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/led")
def api_led():
    body = request.get_json(silent=True) or {}
    on = 1 if body.get("on") else 0
    ok = send_line(f"LED:{on}")
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/pwm")
def api_pwm():
    body = request.get_json(silent=True) or {}
    value = max(0, min(255, int(body.get("value", 0))))
    ok = send_line(f"PWM:{value}")
    return jsonify({"ok": ok, "value": value}), 200 if ok else 503


@app.post("/api/eeprom")
def api_eeprom():
    body = request.get_json(silent=True) or {}
    msg = str(body.get("msg", ""))[:48]
    ok = send_line("MSG:" + msg)
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/pattern")
def api_pattern():
    body = request.get_json(silent=True) or {}
    if "id" in body:
        pid = int(body["id"])
        pid = max(0, min(14, pid))
        ok = send_line(f"P:{pid}")
    else:
        name = str(body.get("name", "off")).strip()
        ok = send_line(f"P:{name}")
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/beep")
def api_beep():
    body = request.get_json(silent=True) or {}
    freq = max(50, min(4000, int(body.get("freq", 880))))
    ms = max(10, min(1000, int(body.get("ms", 150))))
    ok = send_line(f"BEEP:{freq},{ms}")
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/joy_mode")
def api_joy_mode():
    body = request.get_json(silent=True) or {}
    mode = max(0, min(3, int(body.get("mode", 0))))
    ok = send_line(f"MODE:{mode}")
    return jsonify({"ok": ok, "mode": mode}), 200 if ok else 503


@app.post("/api/joy_cal")
def api_joy_cal():
    ok = send_line("CAL")
    return jsonify({"ok": ok}), 200 if ok else 503


@app.post("/api/joy_home")
def api_joy_home():
    ok = send_line("HOME")
    return jsonify({"ok": ok}), 200 if ok else 503


def main() -> None:
    port_name = default_serial_port()
    thread = threading.Thread(target=serial_loop, args=(port_name,), daemon=True)
    thread.start()
    app.run(host=HOST, port=PORT, debug=False, threaded=True)


if __name__ == "__main__":
    main()
