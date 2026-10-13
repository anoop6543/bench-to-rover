# S03 setup / infra — Joystick sketch + wiring

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S02](../s02/setup.md) · **S03** · [Next S04](../s04/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s03_joystick/)

- **Level:** 0
- **Hardware:** Uno R3, BOOSTXL-EDUMKII, 6× **male-to-male** Dupont (see wiring + [`docs/manuals/`](../../manuals/README.md)), USB COM4
- **Code:** [`code/s03_joystick/s03_joystick.ino`](../../../code/s03_joystick/s03_joystick.ino)
- **Wiring (wire types and both ends):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)
- **Dashboard:** http://127.0.0.1:5000 (shared [`pi/dashboard`](../../../pi/dashboard/))

## Bring-up

1. Plug Uno USB into the PC.

```powershell
.\scripts\upload-uno.ps1 -Sketch (Join-Path $PWD "code\s03_joystick")
cd pi\dashboard
$env:SERIAL_PORT="COM4"
.\.venv\Scripts\python app.py
```

2. Fit the **six male-to-male** jumpers exactly as in [wiring.md](wiring.md): each **male** pin into pack **top female**, other **male** into Uno **female**. No cobbler, no stacking on LaunchPad/Uno/Pi.

3. JSON is `{"joy":[x,y,sel], "nx","ny","mag","dir","mode","latched","clicks","cx","cy"}` at ~25 Hz.

## Sub-routines (same 6 wires — no rewiring)

Use the mode buttons on http://127.0.0.1:5000 or serial lines `MODE:0`…`MODE:3` / `CAL`.

| Mode | Uno **L** | What to try |
| --- | --- | --- |
| 0 | On while stick clicked | Baseline (S03-T5) |
| 1 | Blink faster when stick farther from center | Push out; blink speeds up; return to center → L off |
| 2 | Follows **latched** bit | Click once → L stays on; click again → off; `clicks` increments |
| 3 | On only outside deadzone | Nudge past the grey circle → L on |
| CAL | — | Stick idle, press **CAL center**; `cx,cy` update; deadzone recenters |

Pack LCD stays blank (SPI not on these six jumpers).

## Safety

3.3 V pack vs 5 V Uno. Analog *into* the Uno is OK. Do not drive Uno 5 V into LCD/I2C. Do not stack pack on LaunchPad while Uno jumpers are powered.

## Done when

[tests.md](tests.md) T1–T5 pass; try T7–T10 for sub-routines.

## Result

**Passed 2026-10-12** — core T1–T5 + sub-routines T7–T10 on COM4 / dashboard `:5000`. See [tests.md](tests.md). Next: [S04](../s04/setup.md).
