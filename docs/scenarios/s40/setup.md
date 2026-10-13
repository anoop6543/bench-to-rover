# S40 setup / infra — Pi Motor HAT rover

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S39](../s39/setup.md) · **S40** · [Next S41](../s41/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s40_hat_rover/)

- **Level:** 6
- **Hardware:** HAT if S25 is DC
- **Code:** [`code/s40_hat_rover/`](../../../code/s40_hat_rover/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Gate: S25 must show 2-wire DC. Never power HAT motors from the Pi 5V pin.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
