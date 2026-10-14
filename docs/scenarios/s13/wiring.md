# S13 wiring — Tilt accelerometer

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S12](../s12/setup.md) · **S13** · [Next S14](../s14/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s13_tilt/)

**Keep S03 power (GND / 5V / 3.3V).** Joystick and S12 buttons can stay. Add three accel jumpers (male-to-male into pack top → Uno).

| Suggest color | Pack top | Signal | Uno |
| --- | --- | --- | --- |
| Brown | **J3.23** | Accel **X** | **A2** |
| Grey | **J3.24** | Accel **Y** | **A3** |
| White (spare) | **J3.25** | Accel **Z** | **A4** |

J3 column (same as 5V/GND/joy Y): **21=5V, 22=GND, 23=X, 24=Y, 25=Z, 26=joy Y**. Do not pull the green joy-Y wire off **26**.

Accel is **3.3 V** analog. Leave Uno **AREF** alone (still 5 V) — readings land ~0–675; **CAL** with the pack flat.

Shared map: [_shared/edumkii-pinout.md](../_shared/edumkii-pinout.md).

## Do not

- Land on J3.26 (joystick Y).  
- Enable EXTERNAL AREF without jumpering AREF→3.3V (not needed for S13).
