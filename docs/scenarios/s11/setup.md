# S11 setup / infra — Joystick as mouse pad

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S10](../s10/setup.md) · **S11** · [Next S12](../s12/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s11_joy_pad/)

- **Level:** 2
- **Hardware:** EDU MK II joystick ↔ Uno (S03 six wires)
- **Code:** [`code/s11_joy_pad/s11_joy_pad.ino`](../../../code/s11_joy_pad/s11_joy_pad.ino)
- **Wiring:** [wiring.md](wiring.md) → details in [s03/wiring.md](../s03/wiring.md)
- **UI:** http://127.0.0.1:5000/pad
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Restore the S03 six jumpers if you pulled them for breadboard work.
2. Stop anything holding COM4 (old dashboard / serial monitor).
3. Upload:

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s11_joy_pad")
```

4. Start dashboard:

```powershell
python pi\dashboard\app.py
```

5. Open http://127.0.0.1:5000/pad — hold stick to walk the cursor; click stick for a ripple + Uno **L**.

## What you are learning

Stick position is **velocity**, not absolute pad position (more like a mouse). Firmware integrates deflection into `cursor:[x,y]`; the page draws a trail and click ripples.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno / Pi / cobbler.

## Done when

[tests.md](tests.md) T1–T5 pass. (Passed 2026-10-13 — see bench notes there.)
