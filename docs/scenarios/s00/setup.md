# S00 setup / infra — Blink onboard L LED

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · **S00** · [Next S01](../s01/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s00_blink/)

- **Level:** 0
- **Hardware:** Uno USB
- **Code:** [`code/s00_blink/`](../../../code/s00_blink/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Upload with `scripts/upload-uno.ps1 -Sketch code/s00_blink`. USB only. Watch LED **L**.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
