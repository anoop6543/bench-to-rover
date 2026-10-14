# S11 wiring — Joystick as mouse pad

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S10](../s10/setup.md) · **S11** · [Next S12](../s12/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s11_joy_pad/)

**Same 6 jumpers as S03.** Full pin table: [s03/wiring.md](../s03/wiring.md).

| Color | Pack | Uno |
| --- | --- | --- |
| Black | J3.22 GND | GND |
| Red | J3.21 5V | 5V |
| Orange | J1.1 3.3V | 3.3V |
| Yellow | J1.2 X | A0 |
| Green (M-F) | J3.26 Y | A1 |
| Blue | J1.5 SEL | D2 |

You can leave the S09 transistor LED on the breadboard — it is unused by this sketch (D8 idle). Pack LCD stays blank (SPI not wired).

## Do not

- Stack pack on Uno / LaunchPad / cobbler for this scenario.  
- Use VIN instead of 5V.
