# S03 test cases — Joystick sketch + wiring

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S02](../s02/setup.md) · **S03** · [Next S04](../s04/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s03_joystick/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S03-T1 | USB + upload `code/s03_joystick` | COM enumerates; sketch uploads | [x] |
| S03-T2 | http://127.0.0.1:5000 | “Arduino on COMx”; `joy` array | [x] |
| S03-T3 | Centered, not clicked | Dot mid-ish (not stuck 0/1023); L off; sel=0 | [x] |
| S03-T4 | Move stick | Dot tracks X and Y | [x] |
| S03-T5 | Click stick | sel=1, red dot, Uno **L** on | [x] |
| S03-T6 | Pull the yellow (X) male pin off J1.2 | X freezes; no smoke; Y still works | [ ] skipped |
| S03-T7 | Mode 1, push stick hard | **L** blinks faster; `mag` rises; `dir` N/E/S/W… | [x] |
| S03-T8 | Mode 2, click twice | `latched` 0→1→0; **L** follows; `clicks` +2 | [x] |
| S03-T9 | Mode 3, idle then nudge | Idle **L** off; outside deadzone **L** on | [x] |
| S03-T10 | Stick idle → **CAL center** | `cx,cy` near current x,y; grey circle recenters | [x] |

**Pass:** T1–T5 (core). T7–T10 = same-wiring sub-routines.

Date: **2026-10-12**  Result: **pass**  Notes: COM4; idle center ~342,338 after CAL; pack LCD blank (expected — no SPI wires); pack not stacked on LaunchPad for this run.
