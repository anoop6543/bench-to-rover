# S08 wiring — LED brightness PWM

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S07](../s07/setup.md) · **S08** · [Next S09](../s09/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s08_pwm_led/)

**Unplug USB** for the one change below.

## Why move the pin

Uno PWM (`analogWrite`) works on **3, 5, 6, 9, 10, 11** only. **D8 is not PWM** — keep the same LED + 330 Ω, move the jumper to **D9**.

## Circuit (same as S05, pin D9)

```
  Uno D9 ──(M-M)── 330 Ω ── LED(+) ── LED(−) ── Uno GND
```

| Change | Action |
| --- | --- |
| LED anode side jumper | Pull out of **D8**, plug into **D9** |
| Resistor + LED + GND | Leave as-is |
| Button on D7 | Optional — unused |
| Joystick X (fun) | Keep S03 **A0** + **3.3V** + **GND** if you want stick→brightness |

Dashboard: http://127.0.0.1:5000/pwm — slider **and** joystick X when wired.
