# S13 setup / infra — Tilt accelerometer

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S12](../s12/setup.md) · **S13** · [Next S14](../s14/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s13_tilt/)

- **Level:** 2
- **Hardware:** EDU MK II accel → Uno A2/A3/A4 (+ S03 power)
- **Code:** [`code/s13_tilt/s13_tilt.ino`](../../../code/s13_tilt/s13_tilt.ino)
- **Wiring:** [wiring.md](wiring.md)
- **UI:** http://127.0.0.1:5000/tilt
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Add J3.23→A2, J3.24→A3, J3.25→A4 ([wiring.md](wiring.md)).
2. Free COM4, then:

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s13_tilt")
```

3. Dashboard: `pi\dashboard\.venv\Scripts\python app.py`
4. Open http://127.0.0.1:5000/tilt — pack **flat** → **CAL**; tip the pack and watch bars + bubble.

## What you are learning

Analog accelerometer → ADC → tilt UI. Same sensor later for assistive rover drive (S39).

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno / Pi / cobbler.

## Done when

[tests.md](tests.md) T1–T4 pass.
