# S05 test cases — External LED blink

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S04](../s04/setup.md) · **S05** · [Next S06](../s06/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s05_led_ext/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S05-T1 | USB after wiring D8–330Ω–LED–GND | No heat, no smoke | [x] |
| S05-T2 | Upload `code/s05_led_ext` | COM4 OK (~924 bytes) | [x] |
| S05-T3 | Watch breadboard LED | Blinks ~once per second | [x] |
| S05-T4 | Reverse LED legs (USB off), power, fix | Dim/off when reversed; OK after correct polarity | [ ] skipped |

Date: **2026-10-12**  Result: **pass**  Notes: 330 Ω series; D8 external LED.
