# S09 test cases — Transistor as switch

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S08](../s08/setup.md) · **S09** · [Next S10](../s10/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s09_transistor/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S09-T1 | USB after NPN + LED circuit | No heat / smoke on transistor or resistors | [x] |
| S09-T2 | Upload `code/s09_transistor` | COM4 OK | [x] |
| S09-T3 | Watch breadboard LED | Blinks ~1 Hz via transistor (in sync with onboard L) | [x] |
| S09-T4 | Unplug base jumper from D8 (USB on OK) | Breadboard LED stays **off** | [x] |

Date: **2026-10-13**  Result: **pass** (T1–T4)

## Bench notes (what we did)

- Circuit: Uno **D8** → 10 kΩ → **B**; **5V** → 330 Ω → LED(+) → LED(−) → **C**; **E** → GND. Sketch syncs D8 + onboard **L** (D13). Pin order on this TO-92 may be **C-E-B** (flat face, user read) rather than the doc’s first-guess E-B-C — wire by C/B/E role, not by assuming a brand.
- First bring-up: breadboard LED stayed **solid on**; onboard L blinked. Removing D8 did **not** turn breadboard LED off → bypass (LED return not only through C).
- Clarification: onboard L blinking with D8 unplugged is **normal** (L is D13). Only the breadboard LED should follow D8.
- Fix: reseated the **collector** jumper so LED(−) lands on **C** only (not sharing E/GND row). After that, LED off with D8 open; with D8 connected, breadboard LED flashes with L.
- Diagnostic to remember: if LED stays on with D8 removed, pull the transistor entirely — if LED still on, cathode is tied to GND somehow.
