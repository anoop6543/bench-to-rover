# S02 setup / infra — USB self-test vitals

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S01](../s01/setup.md) · **S02** · [Next S03](../s03/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s02_selftest/)

- **Level:** 0
- **Hardware:** Uno USB
- **Code:** [`code/s02_selftest/`](../../../code/s02_selftest/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Upload `code/s02_selftest`. Dashboard `/vitals`.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
