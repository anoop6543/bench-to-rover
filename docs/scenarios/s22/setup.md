# S22 setup / infra — OPT3001 lux

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S21](../s21/setup.md) · **S22** · [Next S23](../s23/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s22_lux/)

- **Level:** 3
- **Hardware:** S20
- **Code:** [`code/s22_lux/`](../../../code/s22_lux/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
