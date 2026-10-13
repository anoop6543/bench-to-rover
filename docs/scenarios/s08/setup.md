# S08 setup / infra — LED brightness PWM

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S07](../s07/setup.md) · **S08** · [Next S09](../s09/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s08_pwm_led/)

- **Level:** 1
- **Hardware:** Uno, LED + 330 Ω on **D9** (PWM)
- **Code:** [`code/s08_pwm_led/s08_pwm_led.ino`](../../../code/s08_pwm_led/s08_pwm_led.ino)
- **Wiring:** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)
- **UI:** http://127.0.0.1:5000/pwm

## Bring-up

1. Unplug USB → move LED jumper **D8 → D9** ([wiring.md](wiring.md)).
2. Plug USB (COM4).
3. Upload + start dashboard (we’ll do this when you say wiring is done):

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s08_pwm_led")
cd pi\dashboard
$env:SERIAL_PORT="COM4"
.\.venv\Scripts\python app.py
```

4. Open `/pwm`, drag the slider — LED dims/brightens.

## Safety

Series resistor still required. Unplug USB while moving the jumper.

## Done when

[tests.md](tests.md) T1–T3 pass.

## Result

**Passed 2026-10-12** — `/pwm` slider drives D9. Fun add-on: joystick X→PWM if S03 A0 still wired. Next: [S09](../s09/setup.md).
