# S05 setup / infra — External LED blink

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S04](../s04/setup.md) · **S05** · [Next S06](../s06/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s05_led_ext/)

- **Level:** 1
- **Hardware:** Uno, breadboard, 1× LED, **330 Ω**, 2× M-M Dupont
- **Code:** [`code/s05_led_ext/s05_led_ext.ino`](../../../code/s05_led_ext/s05_led_ext.ino)
- **Wiring:** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Wire as in [wiring.md](wiring.md) (**USB unplugged** while building).
2. Plug USB (COM4).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s05_led_ext")
```

3. External LED blinks ~1 Hz. Onboard **L** stays off (sketch uses **D8**, not D13).

## Safety

Series resistor required. Unplug USB while rearranging. No LiPo. Joystick pack optional leftover from S03.

## Done when

[tests.md](tests.md) T1–T3 pass.

## Result

**Passed 2026-10-12** — external LED on D8 + 330 Ω blinks on COM4. Next: [S06](../s06/setup.md) (two-LED heartbeat) or [S07](../s07/setup.md) (button).
