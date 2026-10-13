# S08 test cases — LED brightness PWM

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S07](../s07/setup.md) · **S08** · [Next S09](../s09/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s08_pwm_led/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S08-T1 | LED on **D9** + 330 Ω + GND | No heat | [x] |
| S08-T2 | Upload `code/s08_pwm_led` | COM4 OK | [x] |
| S08-T3 | `/pwm` slider 0 → 255 | LED off → bright; `pwm` in JSON follows | [x] |
| S08-T4 *fun* | Joystick X (A0) still wired; move stick | LED brightness tracks stick; slider follows | [x] |

Date: **2026-10-12**  Result: **pass** (T1–T4)  Notes: D9 LED; `/pwm` slider + joystick X→PWM.
