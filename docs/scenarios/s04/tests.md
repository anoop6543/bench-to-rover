# S04 test cases — Meter the bench

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S03](../s03/setup.md) · **S04** · [Next S05](../s05/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s04_meter/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S04-T1 | USB powers Uno; meter on DC volts | No smoke / shorts | [x] |
| S04-T2 | Black GND, red **5V** | ~4.8–5.2 V | [x] |
| S04-T3 | Black GND, red **3.3V** | ~3.2–3.4 V | [x] |
| S04-T4 | Ω mode on one bag resistor (loose) | Stable reading; not open/short | [x] |
| S04-T5 | Do **not** probe LiPo | Skipped on purpose | [x] |

Date: **2026-10-12**  Result: **pass**  Notes: One bag resistor measured **~10 kΩ** (not the photo-guess 330/1k). Still need ~220–470 Ω from the other bag before S05 LED.
