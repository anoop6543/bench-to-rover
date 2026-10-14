# S09 wiring — Transistor as switch

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S08](../s08/setup.md) · **S09** · [Next S10](../s10/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s09_transistor/)

**Unplug Uno USB** before building. You can leave S05–S08 parts on the board if they don’t fight these nets; simplest is a clear breadboard area for this circuit.

## Goal

GPIO turns an **NPN** transistor on/off; the transistor switches the LED (GPIO does not carry the LED current — current primer for later motors).

## Parts

| Part | Notes |
| --- | --- |
| TO-92 transistor (photo `195033`) | Treat as **NPN** (2N2222 / PN2222-style) |
| 1× LED | Long leg = anode (+) |
| 1× **~330 Ω** | LED series |
| 1× **~10 kΩ** | Base resistor (limits GPIO → base current) |
| Breadboard + M-M Duponts | |

## TO-92 pinout (flat face toward you)

Pin order is **not universal**. Wire by role: **B** = D8 via 10 kΩ, **C** = LED(−), **E** = GND. Middle pin is usually base.

**Common A — E-B-C** (many 2N3904 / some PN2222):

```
        flat face
     ┌───────────┐
     │           │
     └─┬───┬───┬─┘
       │   │   │
       E   B   C
```

**Common B — C-B-E** (BC547-style / many bag “2N2222” clones):

```
        flat face
     ┌───────────┐
     │           │
     └─┬───┬───┬─┘
       │   │   │
       C   B   E
```

**This kit (photo `195033`, bench 2026-10-13):** user read flat-face order as **C-E-B** (left→right). If that is what is printed on your part/bag, use that — do not force E-B-C. Confirm with the diode test if unsure: B→E and B→C each show ~0.6 V drop one way.

If the LED never switches, try the other common order **with USB unplugged** between tries.

## Circuit (NPN low-side switch)

```
  Uno 5V ── 330 Ω ── LED(+) ── LED(−) ── Collector (C)
                                              │
                                         NPN transistor
                                              │
  Uno D8 ── 10 kΩ ── Base (B)                 │
                                              │
  Uno GND ──────────────────────────── Emitter (E)
```

| Net | Wire | End A | End B | Boards |
| --- | --- | --- | --- | --- |
| LED power | M-M | Uno **5V** | 330 Ω → LED anode | cross → breadboard |
| LED return | breadboard | LED cathode | Transistor **C** | same board |
| Base drive | M-M | Uno **D8** | 10 kΩ → transistor **B** | cross → breadboard |
| Emitter ground | M-M | Transistor **E** | Uno **GND** | cross |

## Do not

- Connect collector/emitter backwards without a resistor on the LED.  
- Drive the LED from D8 *and* through the transistor at once (pick this circuit only).  
- Use the transistor with no base resistor.
- Put LED(−) / collector on the **same breadboard row** as emitter or GND (bypasses the switch — LED stays on with D8 unplugged).

## Bench gotcha (2026-10-13)

Onboard **L** is D13; it still blinks if you pull the D8 base jumper. Only the **breadboard** LED should go dark. Solid-on breadboard LED with D8 open usually means collector jumper in the wrong hole (return to GND). Reseat LED(−) → **C** only.
