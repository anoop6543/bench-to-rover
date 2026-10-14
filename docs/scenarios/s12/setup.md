# S12 setup / infra — Pack buttons S1/S2

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S11](../s11/setup.md) · **S12** · [Next S13](../s13/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s12_pack_buttons/)

- **Level:** 2
- **Hardware:** S03 jumpers + J4.33→D3 (S1), J4.32→D4 (S2)
- **Code:** [`code/s12_pack_buttons/s12_pack_buttons.ino`](../../../code/s12_pack_buttons/s12_pack_buttons.ino)
- **Wiring:** [wiring.md](wiring.md)
- **UI:** http://127.0.0.1:5000/buttons
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Wire the two new jumpers ([wiring.md](wiring.md)). USB unplugged while seating if you prefer.
2. Free COM4 (stop dashboard / serial monitor).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s12_pack_buttons")
```

3. Start dashboard (`pi\dashboard\.venv\Scripts\python app.py`).
4. Open http://127.0.0.1:5000/buttons — press S1 / S2 on the pack.

## What you are learning

Pack buttons are active-LOW digital inputs with the Uno’s internal pull-ups. Same pattern later for rover face buttons / UI flags.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno / Pi / cobbler.

## Done when

[tests.md](tests.md) T1–T4 pass. (Passed 2026-10-13 — see bench notes there.)
