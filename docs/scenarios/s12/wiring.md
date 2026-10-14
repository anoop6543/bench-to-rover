# S12 wiring — Pack buttons S1/S2

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S11](../s11/setup.md) · **S12** · [Next S13](../s13/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s12_pack_buttons/)

**Keep the S03 six joystick jumpers.** Add two more (male-to-male into pack **top** female → Uno female).

| Color (suggest) | Pack top | Button | Uno | Notes |
| --- | --- | --- | --- | --- |
| Purple | **J4.33** | **S1** | **D3** | Active LOW |
| White | **J4.32** | **S2** | **D4** | Active LOW |

J4 is the header column with pins **31–40** (same end of the pack as J3’s 21–30). Count: 31…**32=S2**, **33=S1**…40. Do not land on J3.

Leave D2 for joystick select. Clear anything else that was on D3/D4.

Shared map: [_shared/edumkii-pinout.md](../_shared/edumkii-pinout.md). Joystick ends: [s03/wiring.md](../s03/wiring.md).

## Do not

- Stack pack on Uno / LaunchPad / cobbler.  
- Swap S1/S2 pins without updating the sketch (S1=D3, S2=D4).
