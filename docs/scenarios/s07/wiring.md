# S07 wiring — Button toggles LED

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S06](../s06/setup.md) · **S07** · [Next S08](../s08/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s07_button_led/)

**Unplug Uno USB** before adding the button.

## Keep from S06

Leave **one** LED chain: **D8 — 330 Ω — LED — GND**.  
You can leave the D9 LED plugged in unused, or remove it — either is fine.

## Add: tactile button (INPUT_PULLUP — no extra resistor)

Debug page: http://127.0.0.1:5000/button — idle `btn=0 raw=1`; press should show `btn=1 raw=0`.

### Which two of the four legs?

```
  Top view of 6 mm tactile:

    A ●─────● B
      │  ○  │
    C ●─────● D
```

Internally **A is tied to B**, and **C is tied to D**. Press connects left↔right.

Use a **diagonal**: **A → D7**, **D → GND** (or B→D7 and C→GND).  
If you pick A and B (same side), pressing does **nothing** — that matches `raw` stuck at 1.

### Meter check (USB unplugged, button alone)

1. Ω mode between A and D: open until pressed → then ~0 Ω. Those two go to D7 and GND.
2. If A–D never closes, try B–C.

### Breadboard tip

Straddle the **center trench** so left legs are in one half and right legs in the other (not all four in one 5-hole row).

```
  Uno D7 ──(M-M)── breadboard row with leg A (or B)
  Uno GND ──────── breadboard row with leg D (or C)  ← diagonal partner
```

| Net | Wire | End A | End B |
| --- | --- | --- | --- |
| LED (existing) | as S05 | Uno **D8** | LED via 330 Ω to GND |
| Button sense | M-M | Uno **D7** | Diagonal leg 1 |
| Button ground | M-M or rail | Diagonal leg 2 | Uno **GND** |

## Do not

- Wire button from **5V** to a pin.
- Put all four legs in one breadboard row (shorts the switch closed or open permanently).
