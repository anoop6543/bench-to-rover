# S32 setup / infra — Pi 3 first boot + SSH

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S31](../s31/setup.md) · **S32** · [Next S33](../s33/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s32_pi_boot/)

- **Level:** 5
- **Hardware:** Pi, 32GB, PSU
- **Code:** [`code/s32_pi_boot/`](../../../code/s32_pi_boot/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Follow [../../first-boot.md](../../first-boot.md). Unplug cobbler for first boot.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
