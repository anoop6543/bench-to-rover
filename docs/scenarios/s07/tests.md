# S07 test cases — Button toggles LED

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S06](../s06/setup.md) · **S07** · [Next S08](../s08/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s07_button_led/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S07-T1 | USB after D8 LED + D7 button to GND | No heat / smoke | [x] |
| S07-T2 | Upload `code/s07_button_led` | COM4 OK | [x] |
| S07-T3 | Press button several times | LED toggles; `/button` shows btn 0↔1 | [x] |
| S07-T4 | Hold button 2 s | LED does **not** flicker rapidly | [x] |

Date: **2026-10-12**  Result: **pass**  Notes: 4-pin tactile needed diagonal legs; debug via http://127.0.0.1:5000/button (`btn`/`raw`/`led`).
