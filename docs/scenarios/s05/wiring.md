# S05 wiring — External LED blink

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S04](../s04/setup.md) · **S05** · [Next S06](../s06/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s05_led_ext/)

**Unplug Uno USB** before placing parts. Joystick jumpers from S03 may stay; they do not use D8.

## Parts

| Part | Notes |
| --- | --- |
| 1× LED (red or yellow from bag) | **Long leg = anode (+)**, short = cathode (−) / flat side |
| 1× **330 Ω** resistor (just metered) | Series current limit |
| Full-size breadboard | Preferred |
| 2× male-to-male Dupont | Uno → breadboard |

## Circuit (one path)

```
  Uno D8 ──(M-M)── breadboard ── 330 Ω ── LED anode(+) ── LED cathode(−) ──(M-M)── Uno GND
```

Same board vs cross-board: **cross-board** Uno ↔ breadboard; resistor+LED sit on the breadboard (same board as each other).

## Step-by-step

1. Unplug USB.
2. On breadboard: put LED and 330 Ω in series (resistor may be on either side of the LED).
3. M-M: Uno **D8** → breadboard node toward **anode / resistor** chain start.
4. M-M: breadboard node at **cathode** → Uno **GND** (power strip).
5. Check polarity once more: short LED leg toward GND.
6. Plug USB back in when ready to upload.

## Do not

- Wire LED straight from 5V to GND with no resistor.
- Use the **10 kΩ** resistor here (LED will be very dim / look “broken”).
- Put LED legs into the Uno female headers without a resistor (easy to short / reverse).
