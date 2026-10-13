# EDU MK II pin map (shared, not code)

Used by S03–S18 (Uno jumpers) and S20+ (Tiva stack). Scenario-specific wire **types and ends** stay in that ID’s `wiring.md`.

The pack does **not** plug onto the Uno, Pi, or Vilros cobbler.

## Power

GND + 3.3 V + 5 V from **one** host (Uno **or** Tiva). Never tie Uno 3.3 V and Pi cobbler 3.3 V together.

Uno GPIO is 5 V. Analog *inputs* from 3.3 V sensors are OK. Do not drive 5 V into SPI, I2C, or the LCD. RGB/buzzer from Uno: series 330 Ω–1 kΩ.

## Analog / buttons (Uno jumpers)

| Pack | Function | Typical Uno | Scenarios |
| --- | --- | --- | --- |
| J3.22 | GND | GND | S03+ |
| J3.21 | 5 V | 5 V | S03+ |
| J1.1 | 3.3 V | 3.3 V | S03+ |
| J1.2 | Joy X | A0 | S03, S11, S28 |
| J3.26 | Joy Y | A1 | S03, S11, S28 |
| J1.5 | Joy SEL | D2 | S03 |
| J3.23–25 | Accel X/Y/Z | A2–A4 | S13 |
| J1.6 | Mic | A5 | S16 |
| J4.33 / J4.32 | S1 / S2 | D3 / D4 | S12 |
| J4.40 | Buzzer | D5 via R | S15 |
| J4.39–37 | RGB | D9–D11 via R | S14 |
| J2.19 | Servo | — | S18 |

Joystick wire **ends**: [S03 wiring](../s03/wiring.md).
