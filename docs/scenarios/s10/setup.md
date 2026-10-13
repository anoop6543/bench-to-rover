# S10 setup / infra — Serial Morse

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S09](../s09/setup.md) · **S10** · [Next S11](../s11/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s10_morse/)

- **Level:** 1
- **Hardware:** Uno USB
- **Code:** [`code/s10_morse/`](../../../code/s10_morse/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
