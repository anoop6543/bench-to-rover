# S43 setup / infra — Dock / station stop

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S42](../s42/setup.md) · **S43** · [Next S44](../s44/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s43_dock/)

- **Level:** 6
- **Hardware:** S28+S12
- **Code:** [`code/s43_dock/`](../../../code/s43_dock/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
