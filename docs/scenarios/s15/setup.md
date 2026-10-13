# S15 setup / infra — Buzzer beeps

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S14](../s14/setup.md) · **S15** · [Next S16](../s16/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s15_buzzer/)

- **Level:** 2
- **Hardware:** Pack J4.40
- **Code:** [`code/s15_buzzer/`](../../../code/s15_buzzer/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
