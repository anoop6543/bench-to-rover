# S30 setup / infra — Motor watchdog timeout

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S29](../s29/setup.md) · **S30** · [Next S31](../s31/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s30_watchdog/)

- **Level:** 4
- **Hardware:** S28
- **Code:** [`code/s30_watchdog/`](../../../code/s30_watchdog/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow safety in [scenarios.md](../../scenarios.md). Implement when this ID is active.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
