# S06 test cases — Two-LED heartbeat

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S05](../s05/setup.md) · **S06** · [Next S07](../s07/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s06_two_led/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S06-T1 | USB after D8 + D9 LED chains | No heat / smoke | [x] |
| S06-T2 | Upload `code/s06_two_led` | COM4 OK | [x] |
| S06-T3 | Watch both LEDs | Alternate, then lub-dub / disco / both-on loop | [x] |

Date: **2026-10-12**  Result: **pass**  Notes: Funny pattern kept (alternate → lub-dub → speed ramp → high-five).
