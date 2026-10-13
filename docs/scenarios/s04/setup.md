# S04 setup / infra — Meter the bench

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S03](../s03/setup.md) · **S04** · [Next S05](../s05/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s04_meter/)

- **Level:** 1
- **Hardware:** Multimeter, Uno R3 (USB), one through-hole resistor from the bags
- **Code:** none (probes only) — [`code/s04_meter/`](../../../code/s04_meter/)
- **Wiring (probe map):** [wiring.md](wiring.md)
- **Tests:** [tests.md](tests.md)

## Bring-up

1. Leave Uno USB connected (powers 5 V / 3.3 V).
2. Meter **DC V**: black → GND, red → **5V**, then red → **3.3V**. See [wiring.md](wiring.md).
3. Meter **Ω**: both probes on a **loose bag resistor** (not an onboard Uno part).
4. Do not probe the LiPo.

## Safety

Do not short 5V to GND with probe tips. Do not use the meter’s 10 A jack for these checks. LiPo stays in the bag for S04.

## Done when

[tests.md](tests.md) T1–T5 pass.

## Result

**Passed 2026-10-12** — 5 V and 3.3 V OK; bag resistor **~10 kΩ**. Next: [S05](../s05/setup.md) (external LED + series resistor — find ~220–470 Ω first).
