# Bench→Rover

**One kit. One ladder of projects.** Start with an Arduino blink on the desk and climb to a Wi‑Fi rover driven from a phone — using only the parts already in the box.

Repo slug (for GitHub): `bench-to-rover`  
Local folder may still be named `RasPiProj`; rename the remote when you push.

---

## What this is

A **scenario-driven lab**: each ID (S00…S47) has wiring docs, tests, and firmware. You finish one on the bench, check it off, then take the next. No shopping list creep — inventory is fixed in [docs/hardware-inventory.md](docs/hardware-inventory.md).

**Endgame:** joystick (or tilt / phone) steers a small 2WD rover; Raspberry Pi hosts the page; Uno owns motors and ADC; TI Educational BoosterPack MK II is the handheld “cockpit.”

**Today:** Windows laptop + Uno on COM4; Flask dashboard on this PC. Pi and rover come later by design.

---

## Board roles (do not mix these up)

| Board | Job | Notes |
| --- | --- | --- |
| **Arduino Uno R3** | Real-time I/O: ADC, PWM, motors, beep | 5 V logic. Upload with `arduino-cli` — no Arduino IDE required |
| **BOOSTXL-EDUMKII** | Joystick, LCD, buttons, RGB, buzzer, sensors | **Never stack on Uno / Pi / cobbler.** Jumpers to Uno, *or* stack on Tiva |
| **EK-TM4C123GXL (Tiva)** | Native 3.3 V host for the pack | Official BoosterPack mating; Energia/CCS later (Level 3) |
| **Raspberry Pi 3 B v1.2** | Network brain, dashboard, Wi-Fi RC | No ADC — Uno stays the analog front-end. Lite OS only (1 GB RAM) |
| **Vilros cobbler** | Pi GPIO ↔ mini breadboard | Pi pinout only — wrong for the EDU pack |
| **Adafruit Motor HAT + rover** | DC / later drive experiments | Chassis motors are micro-servo-bodied; early tests use Uno PWM on pack J8 |

---

## Progress (2026-10-12)

| Level | Focus | Status |
| --- | --- | --- |
| **0** | Uno USB + joystick wiring (S00–S03) | **Done** |
| **1** | Breadboard baby steps (S04–S08) | **Done** through PWM + joy→brightness |
| **Level 2** | S11–S12 done | Next: S13 tilt accel |
| **2** | More EDU pack jumpers (S11–S18) | Upcoming |
| **3** | Tiva + stacked pack + LCD (S19–S24) | Later |
| **4–6** | Rover motors → Pi → Wi-Fi RC (S25–S47) | Endgame |

Live checklist: [docs/scenarios/TRACKING.md](docs/scenarios/TRACKING.md) · full catalog: [docs/scenarios.md](docs/scenarios.md) · sketches: [code/INDEX.md](code/INDEX.md)

**Resume:** [S13 tilt](docs/scenarios/s13/setup.md) (accel X/Y/Z on pack).

---

## How a scenario works

Every ID has four pieces:

| File | Purpose |
| --- | --- |
| `docs/scenarios/sNN/setup.md` | Goal, bring-up commands, pass criteria |
| `docs/scenarios/sNN/wiring.md` | Boards, wire gender, both ends, same vs cross-board |
| `docs/scenarios/sNN/tests.md` | Checkbox bench tests |
| `code/sNN_slug/` | Firmware (or “no sketch” for meter-only) |

Wire from **wiring.md**, not from memory. Gender mistakes (M-M vs M-F) are documented for the EDU pack / Uno headers.

---

## Hardware kit (summary)

Photographed and invoiced parts — full tables in [docs/hardware-inventory.md](docs/hardware-inventory.md). Manual card photos: [docs/manuals/](docs/manuals/README.md).

- Pi 3 B v1.2, case, cobbler, ribbon, mini + full breadboard  
- Uno R3 (COM4 on this PC)  
- Tiva LaunchPad + EDU MK II (joystick / LCD / sensors)  
- Motor HAT, orange 2WD rover chassis, AA box, LiPo (charge correctly — do not freestyle)  
- Dupont M-M and M-F, LEDs, resistors (**~330 Ω** and **~10 kΩ** confirmed on bench), tactile buttons, TO-92, meter  

---

## Dev machine (Windows + Uno)

### Tools

```powershell
winget install ArduinoSA.CLI
arduino-cli core install arduino:avr
```

### Upload any scenario sketch

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s08_pwm_led")
```

Close the Flask dashboard first if you get **Access is denied** on COM4 — only one process can own the serial port.

### Dashboard (this PC)

```powershell
cd pi\dashboard
python -m venv .venv
.\.venv\Scripts\pip install -r requirements.txt
$env:SERIAL_PORT="COM4"
.\.venv\Scripts\python app.py
```

| URL | Use |
| --- | --- |
| http://127.0.0.1:5000/ | Joystick map (S03) |
| http://127.0.0.1:5000/pad | Mouse-pad cursor (S11) |
| http://127.0.0.1:5000/buttons | Pack S1/S2 (S12) |
| http://127.0.0.1:5000/tilt | Accel level bubble (S13) |
| http://127.0.0.1:5000/button | Button debug (S07) |
| http://127.0.0.1:5000/pwm | PWM slider + joy→dim (S08) |
| http://127.0.0.1:5000/vitals | Self-test UI (S02) |
| http://127.0.0.1:5000/patterns | LED pattern UI (S01) |
| http://127.0.0.1:5000/api/state | Raw JSON from the Uno |

Serial is **115200** JSON lines the Flask app parses into `/api/state`.

### Serial monitor without the IDE

```powershell
& "C:\Program Files\Arduino CLI\arduino-cli.exe" monitor -p COM4 -c baudrate=115200
```

---

## Safety (non-negotiable)

- **3.3 V pack vs 5 V Uno** — jumper only the nets you mean; never stack the pack on the Uno, Pi, or cobbler.  
- **LiPo** — only with a proper charger / board that expects 3.7 V; never probe as a casual S04-style meter drill.  
- **Series resistor** on every discrete LED (~220–470 Ω).  
- **Rover wheels off the desk** until a scenario says to drive.  
- **Pi 3** — Lite 32-bit; skip heavy desktop stacks ([docs/first-boot.md](docs/first-boot.md)).

---

## Roadmap in one glance

```
Level 0–1   Uno + breadboard + joystick jumpers     ← you are here (S08 done)
Level 2     More EDU MK II signals on the Uno
Level 3     Pack on Tiva (LCD, I2C sensors, 3.3 V native)
Level 4     Rover motors on the bench
Level 5     Pi boots; Uno moves to Pi USB; LAN page
Level 6     Wi-Fi RC, tilt drive, cluster, optional arm
```

Suggested early order after S08: S09 or S10 → S12/S13 → S19–S20 → S25–S28 → S32 + S36 + S38. Details in [docs/scenarios.md](docs/scenarios.md).

---

## Repo layout

```
README.md                 ← you are here
code/INDEX.md             all scenario firmware folders
code/s03_joystick/        … through s08_pwm_led/, then stubs
docs/scenarios/           setup + wiring + tests per ID
docs/scenarios/TRACKING.md  done / in_progress / next
docs/hardware-inventory.md  photos + order line items (no PII)
docs/manuals/             TI quick-start card photos
pi/dashboard/             shared Flask UI (PC now, Pi later)
scripts/upload-uno.ps1    compile + flash Uno
arduino/                  older sketches (patterns, selftest, bridge)
```

---

## Raspberry Pi (later)

Flash Lite, hostname `raspi3`, SSH on — see [docs/first-boot.md](docs/first-boot.md).  
Then move Uno USB to the Pi (`/dev/ttyACM0`), run the same dashboard with `SERIAL_PORT=/dev/ttyACM0`, browse `http://raspi3.local:5000`. Optional systemd unit: `pi/dashboard/dashboard.service`.

---

## Git

Initialized locally; push when ready (prefer renaming the GitHub repo to **`bench-to-rover`**):

```powershell
gh repo create bench-to-rover --private --source=. --remote=origin --push
```

---

## License / intent

Personal learning lab — wire carefully, document what worked, one scenario at a time.
