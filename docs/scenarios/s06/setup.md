# S06 setup / infra — Two-LED heartbeat

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S05](../s05/setup.md) · **S06** · [Next S07](../s07/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s06_two_led/)

- **Level:** 1
- **Hardware:** Uno, breadboard, 2× LED, 2× ~330 Ω, M-M Duponts
- **Code:** [`code/s06_two_led/s06_two_led.ino`](../../../code/s06_two_led/s06_two_led.ino)
- **Wiring:** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Wire as in [wiring.md](wiring.md) (**USB unplugged**).
2. Plug USB (COM4).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s06_two_led")
```

3. LEDs run the funny loop: alternate → lub-dub → disco ramp → both-on “high five”.

## Safety

One series resistor **per** LED. Unplug USB while rearranging.

## Done when

[tests.md](tests.md) T1–T3 pass.

## Result

**Passed 2026-10-12** — D8/D9 two-LED heartbeat (+ funny pattern). Next: [S07](../s07/setup.md) (button toggles LED).
