# S12 test cases — Pack buttons S1/S2

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S11](../s11/setup.md) · **S12** · [Next S13](../s13/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s12_pack_buttons/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S12-T1 | S03 wires + S1→D3, S2→D4 + USB | No smoke | [x] |
| S12-T2 | Upload `code/s12_pack_buttons` + `/buttons` | COM4 OK; connected | [x] |
| S12-T3 | Press **S1** | `btn[0]=1`; counts[0]++; Uno **L** on while held | [x] |
| S12-T4 | Press **S2** | `btn[1]=1`; counts[1]++; L stays off (unless S1 also held) | [x] |

Date: **2026-10-13**  Result: **pass** (T1–T4)

## Bench notes

- Cleared prior D3 jumper; S1=J4.33→D3, S2=J4.32→D4. S03 joystick wires kept.
- UI: http://127.0.0.1:5000/buttons
