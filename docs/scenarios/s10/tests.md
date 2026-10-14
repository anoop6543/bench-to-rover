# S10 test cases — Serial Morse

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S09](../s09/setup.md) · **S10** · [Next S11](../s11/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s10_morse/)

| ID | Step | Expected | Pass |
| --- | --- | --- | --- |
| S10-T1 | USB with S09 circuit still up | No heat / smoke | [x] |
| S10-T2 | Upload `code/s10_morse` | COM4 OK; Serial says `S10 Morse…` | [x] |
| S10-T3 | Type `SOS` + Enter (115200) | LED/L blink dit-dit-dit / dah-dah-dah / dit-dit-dit; `TX:` + `done` | [x] |
| S10-T4 | Type `HI THERE` + Enter | Word gap longer between HI and THERE; unknown chars skipped | [x] |

Date: **2026-10-13**  Result: **pass** (T1–T4)

## Bench notes

- Kept S09 NPN LED on D8; no rewire. Sketch mirrors onboard L.
- Upload via `upload-uno.ps1`; Serial Monitor 115200 + Enter to send.
- Agent-launched `arduino-cli monitor` exits quickly — use a normal Cursor/IDE terminal for typing.
