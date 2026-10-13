# S04 wiring — Meter the bench

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S03](../s03/setup.md) · **S04** · [Next S05](../s05/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s04_meter/)

**No Dupont jumpers.** Probes only. Joystick pack may stay wired from S03 or be unplugged — either is fine.

## Meter leads

| Lead | Jack on meter | Color (typical) |
| --- | --- | --- |
| COM (reference) | **COM** | Black |
| Positive | **VΩmA** (not the 10 A jack) | Red |

## Probe points on Uno (USB on the LEFT)

Power strip along the **bottom** edge:

```
  …  VIN   GND   GND   5V   3.3V   RESET  …
                 ▲           ▲      ▲
              black here   red    red
              (common)    for 5V  for 3.3V
```

| Measurement | Black (COM) | Red (VΩmA) | Dial |
| --- | --- | --- | --- |
| Uno 5 V | Any **GND** | **5V** | DC volts (V⎓), range ≥ 20 V |
| Uno 3.3 V | Any **GND** | **3.3V** | Same DC volts |
| Resistor | One resistor lead | Other lead | Resistance (Ω) — **Uno unpowered or resistor off-board** |

Do **not** put red on **VIN** while USB is plugged in (that is not the rail you are checking). Do **not** short 5V to GND with the probe tips.

## Boards involved

| Board | Role |
| --- | --- |
| Arduino Uno R3 | USB-powered source of 5 V and 3.3 V |
| Multimeter | Measure only |
| One through-hole resistor from the bag | Confirm Ω (photo guess was 330 / 1k; **bench: one part read ~10 kΩ**) |
| LiPo | **Do not probe** in this scenario |

Same-board vs cross-board: both probe tips land on the **Uno** for voltage; for ohms, both tips on the **resistor only** (not bridging to the Uno unless the part is isolated).
