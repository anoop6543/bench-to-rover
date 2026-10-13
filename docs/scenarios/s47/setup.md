# S47 setup / infra — DOFBOT arm on rover

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S46](../s46/setup.md) · **S47** · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s47_dofbot/)

- **Level:** 6
- **Hardware:** Yahboom arm if found
- **Code:** [`code/s47_dofbot/`](../../../code/s47_dofbot/)
- **Wiring (not code):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

Skip unless DOFBOT arm hardware exists.

## Safety

3.3 V pack vs 5 V Uno. No stacking EDU MK II on Uno, Pi, or Vilros cobbler. LiPo only with a charger. Rover wheels off the desk until commanded.

## Done when

All pass cases in [tests.md](tests.md) are checked on the bench.
