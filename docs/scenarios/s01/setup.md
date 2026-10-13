# S01 setup / infra — 15 LED patterns + dashboard

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S00](../s00/setup.md) · **S01** · [Next S02](../s02/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s01_patterns/)

- **Level:** 0
- **Hardware:** Uno USB
- **Code:** [`code/s01_patterns/`](../../../code/s01_patterns/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Upload `code/s01_patterns`. Dashboard `/patterns`. Commands `P:0`–`P:14`.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
