# S11 test cases — Joystick as mouse pad

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S10](../s10/setup.md) · **S11** · [Next S12](../s12/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s11_joy_pad/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S11-T1 | S03 six wires + USB | No smoke | [x] |
| S11-T2 | Upload `code/s11_joy_pad` + dashboard | COM4 OK; `/pad` shows connected | [x] |
| S11-T3 | Hold stick one direction | Cursor **walks** across pad (not stuck to stick angle); trail follows | [x] |
| S11-T4 | Release stick; click stick | Cursor stops; ripple + `clicks`++; Uno **L** on while held | [x] |
| S11-T5 | HOME / CAL buttons | Cursor snaps mid; idle center after CAL | [x] |

Date: **2026-10-13**  Result: **pass** (T1–T5)

## Bench notes

- Reused S03 jumpers; S09 transistor circuit unplugged (unused by S11).
- Dashboard via `pi/dashboard/.venv`; page **http://127.0.0.1:5000/pad** (not `/`).
