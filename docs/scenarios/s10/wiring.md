# S10 wiring — Serial Morse

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S09](../s09/setup.md) · **S10** · [Next S11](../s11/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s10_morse/)

**Keep the S09 transistor LED circuit.** No new jumpers. Sketch drives **D8** (NPN base) and mirrors onboard **L**.

If you tore S09 down, rebuild from [s09/wiring.md](../s09/wiring.md), or for a minimal test use only onboard **L** (still upload this sketch — L blinks Morse either way).

| Net | From S09 | Role in S10 |
| --- | --- | --- |
| Base drive | D8 → 10 kΩ → B | Morse keying |
| LED path | 5V → 330 Ω → LED → C; E → GND | Visible Morse |
| USB | Uno ↔ PC | Serial text in |

## Do not

- Rewire for S10 unless the S09 LED path is broken.  
- Change baud — sketch expects **115200**.
