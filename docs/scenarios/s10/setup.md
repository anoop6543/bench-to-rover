# S10 setup / infra — Serial Morse

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S09](../s09/setup.md) · **S10** · [Next S11](../s11/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s10_morse/)

- **Level:** 1
- **Hardware:** Uno + S09 breadboard LED (NPN on D8); USB serial
- **Code:** [`code/s10_morse/s10_morse.ino`](../../../code/s10_morse/s10_morse.ino)
- **Wiring:** [wiring.md](wiring.md) — leave S09 as-is
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Leave S09 wired. Plug USB (COM4).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s10_morse")
```

2. Open Serial Monitor **115200**, newline ending (NL or both).
3. Type `SOS` + Enter. Breadboard LED and onboard L blink `... --- ...`.

## What you are learning

PC sends characters over USB; firmware turns them into timed dots/dashes on GPIO. Same D8→transistor path as S09, now keyed by Morse timing instead of a fixed blink.

## Safety

Unplug USB only if you rearrange wires. No new high-current path.

## Done when

[tests.md](tests.md) T1–T4 pass. (Passed 2026-10-13 — see bench notes there.)
