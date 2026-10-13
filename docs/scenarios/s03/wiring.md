# S03 wiring — Joystick (boards and jumpers)

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S02](../s02/setup.md) · **S03** · [Next S04](../s04/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s03_joystick/)

This file is **hardware only**. Sketch: [`code/s03_joystick/`](../../../code/s03_joystick/). Full pack map: [_shared/edumkii-pinout.md](../_shared/edumkii-pinout.md). Manual photos: [`docs/manuals/`](../../manuals/README.md).

## Connector gender (from manuals + your boards)

| Surface | Gender | What fits | Evidence |
| --- | --- | --- | --- |
| EDU MK II **top** (LCD / joystick face) | **Female** sockets | **Male** pin pushes in | Manual [`215250`](../../manuals/20261012_215250.jpg), [`215301`](../../manuals/20261012_215301.jpg) |
| EDU MK II **bottom** | **Female** sockets | Seats onto LaunchPad **male** pins | Your stacking observation |
| Tiva LaunchPad (this kit) | **Male** pins | Pack bottom female slides on | Photo `Hardware Images/20261012_194232.jpg` |
| Arduino Uno R3 | **Female** holes | **Male** pin pushes in | Board |

S03 does **not** stack pack on LaunchPad. Jumpers go **pack top → Uno**.

Both ends of each preferred wire land in a **female** hole → need **male-to-male**.

## Which jumper bag to use

| Jumper type | End A (pack top) | End B (Uno) | Use? |
| --- | --- | --- | --- |
| **Male-to-male** (pin both ends) — bag `184617` / loose `193150` | **Male pin** into pack **top female** | **Male pin** into Uno **female** | **Preferred** |
| **Male-to-female** | **Female** onto a pack pin that is male on your build (e.g. wire 6 / J3.26) | **Male** into Uno | As needed |
| Female-to-female | Will not enter pack top or Uno | — | Do not use |
| Vilros cobbler / Pi ribbon | Wrong pinout | — | Do not use |

Do **not** stack the pack onto the Uno, Pi, or cobbler.

## Six nets — type, color, both ends

Every wire below is **cross-board**: End A = EDU MK II **top**, End B = Uno (never both ends on the same board). Do power first. USB may stay on the laptop.

Pin numbers match the EDU MK II card [`215301`](../../manuals/20261012_215301.jpg): JOY horiz J1.2, sel J1.5, vert J3.26; GND J3.22; 5V J3.21; 3.3V J1.1.

### 1. Ground — black — male-to-male — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Into this |
| --- | --- | --- | --- |
| A | **EDU MK II** (not Uno) | **Male pin** | Pack **top** **J3.22 GND** (2nd pin in the 5 V column: 21=5V, **22=GND**) |
| B | **Uno** (not pack) | **Other male pin** | Uno **GND** on the **power** strip (bottom, USB on the left: VIN, **GND**, GND, 5V, 3.3V…) |

### 2. 5 V — red — male-to-male — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Into this |
| --- | --- | --- | --- |
| A | **EDU MK II** | Male pin | Pack **top** **J3.21 5V** |
| B | **Uno** | Male pin | Uno **5V** (power strip, next to GND). **Not VIN.** |

### 3. 3.3 V — orange — male-to-male — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Into this |
| --- | --- | --- | --- |
| A | **EDU MK II** | Male pin | Pack **top** **J1.1 3.3V** (often marked 3V3) |
| B | **Uno** | Male pin | Uno **3.3V** (power strip, labeled `3.3V`) |

If 3.3V and 5V are at opposite ends of the header, you counted the column backwards.

### 4. Joystick X — yellow — male-to-male — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Into this |
| --- | --- | --- | --- |
| A | **EDU MK II** | Male pin | Pack **top** **J1.2** JOYSTICK_HORIZ (next to 3.3V) |
| B | **Uno** | Male pin | Uno **A0** (analog strip, bottom-right, first analog hole) |

### 5. Joystick select — blue — male-to-male — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Into this |
| --- | --- | --- | --- |
| A | **EDU MK II** | Male pin | Pack **top** **J1.5** JOYSTICK_SEL (count 1=3.3V, 2=X, 3, 4, **5=SEL**) |
| B | **Uno** | Male pin | Uno **D2** on the **digital** top row. USB on the left: D2 is **third from the right** (`0`, `1`, **`2`**). Not A2. |

Click = pack pin pulled LOW.

### 6. Joystick Y — green — male-to-female — **cross-board** (pack ↔ Uno)

| End | Board | Plug this | Onto / into this |
| --- | --- | --- | --- |
| A | **EDU MK II** | **Female socket** | Pack **J3.26** JOYSTICK_VERT (same column as 5V/GND: 21…**26**). Do not land on 25 (accel Z). |
| B | **Uno** | **Male pin** | Uno **A1** (analog, next to A0) |

## Physical map (LCD facing you)

Wires go to the **center 40-pin header**, not into the plastic stick. Each arrow is one **cross-board** jumper (1–5 M-M; **6 green = M-F**, female on pack). No wire stays on one board only.

```
  EDU MK II (End A)                         Uno R3 female (End B; USB on LEFT)

  J1                     J3
  1  3.3V  <--orange-->  21 5V  <--red-->   5V   (power, not VIN)
  2  X     <--yellow-->  22 GND <--black--> GND
  5  SEL   <--blue  -->  26 Y   <--green--> A1   (green: female on pack)
                         ...
                                            A0  <-- yellow from J1.2
  (stick is the knob)                       D2  <-- blue from J1.5
                                            (D2 = 3rd digital hole from the RIGHT)
```

Leave every other pack pin empty.

## Optional breadboard

Pack **bottom is female** (that face sits on the LaunchPad’s male pins). It does **not** plug into a breadboard. Keep the pack LCD-up and jumper from the top/side pins you are using to the Uno. Leave the Vilros mini board alone.
