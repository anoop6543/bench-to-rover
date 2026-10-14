# S09 setup / infra — Transistor as switch

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S08](../s08/setup.md) · **S09** · [Next S10](../s10/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s09_transistor/)

- **Level:** 1
- **Hardware:** Uno, breadboard, TO-92 NPN, LED, ~330 Ω, ~10 kΩ
- **Code:** [`code/s09_transistor/s09_transistor.ino`](../../../code/s09_transistor/s09_transistor.ino)
- **Wiring:** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Wire as in [wiring.md](wiring.md) (**USB unplugged**).
2. Plug USB (COM4).

```powershell
.\scripts\upload-uno.ps1 -Port COM4 -Sketch (Join-Path $PWD "code\s09_transistor")
```

3. LED blinks ~1 Hz, switched by the transistor from **D8**.

## What you are learning

D8 only feeds a tiny base current through 10 kΩ. Most LED current flows **5V → 330 Ω → LED → collector → emitter → GND**. Same idea later for higher loads (with a proper transistor/MOSFET rating).

## Safety

Unplug USB while rearranging. Series LED resistor required. Base resistor required.

## Done when

[tests.md](tests.md) T1–T4 pass. (Passed 2026-10-13 — see bench notes there.)
