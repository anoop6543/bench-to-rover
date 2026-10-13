"""Generate per-scenario docs + code folders. From repo root:

python scripts/generate_scenario_docs.py
"""

from __future__ import annotations

import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DOCS = ROOT / "docs" / "scenarios"
CODE = ROOT / "code"

# sid, level, title, status, slug, hardware
SCENARIOS = [
    ("S00", 0, "Blink onboard L LED", "done", "s00_blink", "Uno USB"),
    ("S01", 0, "15 LED patterns + dashboard", "done", "s01_patterns", "Uno USB"),
    ("S02", 0, "USB self-test vitals", "done", "s02_selftest", "Uno USB"),
    ("S03", 0, "Joystick sketch + wiring", "in_progress", "s03_joystick", "Uno, EDU MK II, Dupont"),
    ("S04", 1, "Meter the bench", "not_started", "s04_meter", "Meter, Uno"),
    ("S05", 1, "External LED blink", "not_started", "s05_led_ext", "Uno, LED, 330R"),
    ("S06", 1, "Two-LED heartbeat", "not_started", "s06_two_led", "Uno, 2 LEDs"),
    ("S07", 1, "Button toggles LED", "not_started", "s07_button_led", "Uno, button, LED"),
    ("S08", 1, "LED brightness PWM", "not_started", "s08_pwm_led", "Uno, LED on PWM pin"),
    ("S09", 1, "Transistor as switch", "not_started", "s09_transistor", "Uno, TO-92, LED"),
    ("S10", 1, "Serial Morse", "not_started", "s10_morse", "Uno USB"),
    ("S11", 2, "Joystick as mouse pad", "not_started", "s11_joy_pad", "S03 working"),
    ("S12", 2, "Pack buttons S1/S2", "not_started", "s12_pack_buttons", "S03 + J4.32/33"),
    ("S13", 2, "Tilt accelerometer", "not_started", "s13_tilt", "S03 + J3.23-25"),
    ("S14", 2, "RGB mood light", "not_started", "s14_rgb", "Pack RGB + series R"),
    ("S15", 2, "Buzzer beeps", "not_started", "s15_buzzer", "Pack J4.40"),
    ("S16", 2, "Mic VU meter", "not_started", "s16_mic", "Pack J1.6"),
    ("S17", 2, "Keep-the-ball game", "not_started", "s17_ball_game", "S11+S12+S15"),
    ("S18", 2, "Pack servo header J8", "not_started", "s18_pack_servo", "One rover motor"),
    ("S19", 3, "Tiva LaunchPad blink", "not_started", "s19_tiva_blink", "EK-TM4C123GXL"),
    ("S20", 3, "Stack EDU MK II Energia joystick", "not_started", "s20_tiva_joy", "Tiva + packed stack"),
    ("S21", 3, "LCD splash + buttons", "not_started", "s21_lcd", "S20"),
    ("S22", 3, "OPT3001 lux", "not_started", "s22_lux", "S20"),
    ("S23", 3, "Handheld instrument", "not_started", "s23_handheld", "S20-S22"),
    ("S24", 3, "Tiva serial dashboard", "not_started", "s24_tiva_dash", "S20, PC"),
    ("S25", 4, "Identify rover motor wiring", "not_started", "s25_motor_id", "Rover motors, meter"),
    ("S26", 4, "One motor spin (desk)", "not_started", "s26_one_motor", "S25"),
    ("S27", 4, "Both motors F/B/L/R/S", "not_started", "s27_both_motors", "S26"),
    ("S28", 4, "Joystick tank drive", "not_started", "s28_tank", "Pack + rover + Uno"),
    ("S29", 4, "Button turbo / reverse", "not_started", "s29_turbo", "S12+S28"),
    ("S30", 4, "Motor watchdog timeout", "not_started", "s30_watchdog", "S28"),
    ("S31", 4, "Split AA motors / USB logic", "not_started", "s31_split_psu", "AA box"),
    ("S32", 5, "Pi 3 first boot + SSH", "not_started", "s32_pi_boot", "Pi, 32GB, PSU"),
    ("S33", 5, "Pi vitals page", "not_started", "s33_pi_vitals", "S32"),
    ("S34", 5, "Uno on Pi USB", "not_started", "s34_uno_on_pi", "S32, Uno"),
    ("S35", 5, "Cobbler LED/button", "not_started", "s35_cobbler_gpio", "Vilros cobbler"),
    ("S36", 5, "LAN page drives rover", "not_started", "s36_lan_rover", "S34+S28"),
    ("S37", 5, "CSV black box log", "not_started", "s37_csv_log", "S34"),
    ("S38", 6, "Wi-Fi RC rover", "not_started", "s38_wifi_rc", "Pi+Uno+pack+chassis"),
    ("S39", 6, "Tilt-to-drive assistive rover", "not_started", "s39_tilt_drive", "S13+S28"),
    ("S40", 6, "Pi Motor HAT rover", "not_started", "s40_hat_rover", "HAT if S25 is DC"),
    ("S41", 6, "Instrument cluster", "not_started", "s41_cluster", "Pack LCD + Pi"),
    ("S42", 6, "Follow the light", "not_started", "s42_follow_light", "S22+S28"),
    ("S43", 6, "Dock / station stop", "not_started", "s43_dock", "S28+S12"),
    ("S44", 6, "Telemetry recorder + replay", "not_started", "s44_replay", "Pi"),
    ("S45", 6, "Perma-Proto joystick harness", "not_started", "s45_perma_proto", "P/N 1609 if found"),
    ("S46", 6, "Feather HUZZAH Wi-Fi remote", "not_started", "s46_huzzah", "Kit 3032 if found"),
    ("S47", 6, "DOFBOT arm on rover", "not_started", "s47_dofbot", "Yahboom arm if found"),
]

LEGACY_INO = {
    "S00": ROOT / "arduino" / "blink" / "blink.ino",
    "S01": ROOT / "arduino" / "patterns" / "patterns.ino",
    "S02": ROOT / "arduino" / "selftest" / "selftest.ino",
    "S03": ROOT / "arduino" / "joystick" / "joystick.ino",
}

SKIP_DOC_OVERWRITE = {"S03"}  # hand-written setup/tests/wiring

SETUP_EXTRA = {
    "S00": "Upload with `scripts/upload-uno.ps1 -Sketch code/s00_blink`. USB only. Watch LED **L**.",
    "S01": "Upload `code/s01_patterns`. Dashboard `/patterns`. Commands `P:0`–`P:14`.",
    "S02": "Upload `code/s02_selftest`. Dashboard `/vitals`.",
    "S04": "USB-powered Uno. Meter 5V–GND and 3.3V–GND. Ohm a resistor. Do not short the LiPo.",
    "S32": "Follow [../../first-boot.md](../../first-boot.md). Unplug cobbler for first boot.",
    "S40": "Gate: S25 must show 2-wire DC. Never power HAT motors from the Pi 5V pin.",
    "S45": "Skip unless Perma-Proto 1609 is found.",
    "S46": "Skip unless Feather HUZZAH kit 3032 is found.",
    "S47": "Skip unless DOFBOT arm hardware exists.",
}


def nav(i: int) -> str:
    sid, _, title, _, slug, _ = SCENARIOS[i]
    prev = SCENARIOS[i - 1] if i > 0 else None
    nxt = SCENARIOS[i + 1] if i + 1 < len(SCENARIOS) else None
    bits = [
        "[All scenarios](../../scenarios.md)",
        "[Tracking](../TRACKING.md)",
        "[Code index](../../../code/INDEX.md)",
    ]
    if prev:
        bits.append(f"[Prev {prev[0]}](../{prev[0].lower()}/setup.md)")
    bits.append(f"**{sid}**")
    if nxt:
        bits.append(f"[Next {nxt[0]}](../{nxt[0].lower()}/setup.md)")
    bits.append("[Setup](setup.md)")
    bits.append("[Wiring](wiring.md)")
    bits.append("[Tests](tests.md)")
    bits.append(f"[Code](../../../code/{slug}/)")
    return " · ".join(bits)


def setup_body(i: int) -> str:
    sid, level, title, _, slug, hw = SCENARIOS[i]
    extra = SETUP_EXTRA.get(
        sid,
        "Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.",
    )
    return f"""# {sid} setup / infra — {title}

{nav(i)}

- **Level:** {level}
- **Hardware:** {hw}
- **Code:** [`code/{slug}/`](../../../code/{slug}/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

{extra}

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
"""


def wiring_stub(i: int) -> str:
    sid, _, title, _, _, _ = SCENARIOS[i]
    return f"""# {sid} wiring — {title}

{nav(i)}

Boards and jumpers for this scenario live **here**, not in the code folder.

If this ID is USB-only, there are **no Dupont wires**. If it needs jumpers, list for each net:

- **Wire type** (male-to-male vs male-to-female)
- **End A** (which housing / pin)
- **End B** (which housing / pin)

Shared EDU MK II pin map: [_shared/edumkii-pinout.md](../_shared/edumkii-pinout.md).
"""


def tests_body(i: int) -> str:
    sid, _, title, _, _, _ = SCENARIOS[i]
    return f"""# {sid} test cases — {title}

{nav(i)}

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| {sid}-T1 | Power / connect as in setup.md | No smoke, no brown-out | [ ] |
| {sid}-T2 | Firmware or OS from setup.md is running | Enumerates (COM / SSH / Energia) | [ ] |
| {sid}-T3 | Happy path | Goal in scenarios.md happens on hardware | [ ] |
| {sid}-T4 | Fault path | Unplug / wrong pin / stop fails safe | [ ] |

Date: ________  Result: pass / fail  Notes: ________
"""


def tracking_md() -> str:
    lines = [
        "# Scenario tracking",
        "",
        "Jump: [catalog](../scenarios.md) · [code index](../../code/INDEX.md)",
        "",
        "Each ID: `setup.md` (infra) · `wiring.md` (boards/jumpers) · `tests.md` · `code/<slug>/`",
        "",
        "| ID | Lv | Title | Status | Docs | Code |",
        "| --- | --- | --- | --- | --- | --- |",
    ]
    for sid, level, title, status, slug, _ in SCENARIOS:
        folder = sid.lower()
        lines.append(
            f"| {sid} | {level} | {title} | `{status}` | "
            f"[setup]({folder}/setup.md) · [wiring]({folder}/wiring.md) · [tests]({folder}/tests.md) | "
            f"[{slug}](../../code/{slug}/) |"
        )
    lines += [
        "",
        "## Active",
        "",
        "**S03** — [setup](s03/setup.md) · [wiring](s03/wiring.md) · [code](../../code/s03_joystick/) · [tests](s03/tests.md)",
        "",
    ]
    return "\n".join(lines) + "\n"


def code_index() -> str:
    lines = [
        "# Code by scenario",
        "",
        "One folder per ID. Upload Uno sketches with:",
        "",
        "```powershell",
        ".\\scripts\\upload-uno.ps1 -Sketch (Join-Path $PWD \"code\\s03_joystick\")",
        "```",
        "",
        "Shared dashboard (S01–S03, later Pi): [`pi/dashboard`](../pi/dashboard).",
        "",
        "| ID | Folder | Firmware | Docs |",
        "| --- | --- | --- | --- |",
    ]
    for i, (sid, _lv, title, _st, slug, _) in enumerate(SCENARIOS):
        ino = CODE / slug / f"{slug}.ino"
        fw = f"`{slug}.ino`" if ino.exists() or sid in LEGACY_INO else "placeholder README"
        lines.append(
            f"| {sid} | [{slug}]({slug}/) | {fw} | "
            f"[setup](../docs/scenarios/{sid.lower()}/setup.md) |"
        )
    lines.append("")
    return "\n".join(lines) + "\n"


def ino_banner(i: int) -> str:
    sid, _, title, _, slug, _ = SCENARIOS[i]
    prev = SCENARIOS[i - 1][0] if i else None
    nxt = SCENARIOS[i + 1][0] if i + 1 < len(SCENARIOS) else None
    return (
        f"/* {sid} {title}\n"
        f" * Docs: docs/scenarios/{sid.lower()}/setup.md\n"
        f" * Wiring: docs/scenarios/{sid.lower()}/wiring.md\n"
        f" * Tests: docs/scenarios/{sid.lower()}/tests.md\n"
        f" * Nav: {prev or '—'} <- {sid} -> {nxt or '—'}\n"
        f" * Upload: scripts/upload-uno.ps1 -Sketch code/{slug}\n"
        f" */\n\n"
    )


def write_code_folder(i: int) -> None:
    sid, _, title, _, slug, _ = SCENARIOS[i]
    dest = CODE / slug
    dest.mkdir(parents=True, exist_ok=True)
    readme = dest / "README.md"
    readme.write_text(
        f"# {sid} code — {title}\n\n"
        f"{nav(i)}\n\n"
        f"- Docs: [setup](../../docs/scenarios/{sid.lower()}/setup.md), "
        f"[wiring](../../docs/scenarios/{sid.lower()}/wiring.md), "
        f"[tests](../../docs/scenarios/{sid.lower()}/tests.md)\n"
        f"- Index: [code/INDEX.md](../INDEX.md)\n",
        encoding="utf-8",
    )
    src = LEGACY_INO.get(sid)
    ino_path = dest / f"{slug}.ino"
    if src and src.exists():
        body = src.read_text(encoding="utf-8")
        if not body.startswith(f"/* {sid}"):
            body = ino_banner(i) + body
        ino_path.write_text(body, encoding="utf-8")
    elif not ino_path.exists():
        (dest / "PLACEHOLDER.md").write_text(
            f"Firmware for {sid} is added when this scenario is implemented.\n",
            encoding="utf-8",
        )


def main() -> None:
    DOCS.mkdir(parents=True, exist_ok=True)
    (DOCS / "TRACKING.md").write_text(tracking_md(), encoding="utf-8")
    for i, (sid, *_rest) in enumerate(SCENARIOS):
        folder = DOCS / sid.lower()
        folder.mkdir(exist_ok=True)
        if sid not in SKIP_DOC_OVERWRITE:
            (folder / "setup.md").write_text(setup_body(i), encoding="utf-8")
            (folder / "tests.md").write_text(tests_body(i), encoding="utf-8")
            (folder / "wiring.md").write_text(wiring_stub(i), encoding="utf-8")
        write_code_folder(i)
    (CODE / "INDEX.md").write_text(code_index(), encoding="utf-8")
    print(f"Docs {DOCS} · code {CODE} · {len(SCENARIOS)} scenarios")


if __name__ == "__main__":
    main()
