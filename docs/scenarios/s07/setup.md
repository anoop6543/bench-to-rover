# S07 setup / infra — Button toggles LED

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S06](../s06/setup.md) · **S07** · [Next S08](../s08/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s07_button_led/)

- **Level:** 1
- **Hardware:** Uno, breadboard, LED + 330 Ω (from S05), 1× tactile button, M-M Duponts
- **Code:** [`code/s07_button_led/s07_button_led.ino`](../../../code/s07_button_led/s07_button_led.ino)
- **Wiring:** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Wire as in [wiring.md](wiring.md) (**USB unplugged**).
2. Plug USB (COM4).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s07_button_led")
```

3. Each **press** toggles the D8 LED on/off (debounced). Holding does not spam toggles.

## Safety

Unplug USB while rearranging. Button goes to **GND**, not 5V, with `INPUT_PULLUP`.

## Done when

[tests.md](tests.md) T1–T3 pass.

## Result

**Passed 2026-10-12** — D7 button (diagonal legs) toggles D8 LED; dashboard `/button`. Next: [S08](../s08/setup.md) (PWM brightness).
