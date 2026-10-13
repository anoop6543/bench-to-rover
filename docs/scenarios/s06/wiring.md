# S06 wiring — Two-LED heartbeat

[All scenarios](../../scenarios.md) · [Tracking](../TRACKING.md) · [Code index](../../../code/INDEX.md) · [Prev S05](../s05/setup.md) · **S06** · [Next S07](../s07/setup.md) · [Setup](setup.md) · [Wiring](wiring.md) · [Tests](tests.md) · [Code](../../../code/s06_two_led/)

**Unplug Uno USB** before adding the second LED. Keep the S05 LED on D8.

## Parts

| Part | Notes |
| --- | --- |
| LED A (already on breadboard) | **D8** — 330 Ω — LED — GND (from S05) |
| LED B (new: other color if you have it) | **D9** — 330 Ω — LED — GND |
| 1× more **330 Ω** (or another ~220–470 Ω) | Own series resistor per LED |
| 1× more M-M Dupont | Uno **D9** → breadboard |

Both cathodes can share the same Uno **GND** rail on the breadboard.

## Circuit

```
  Uno D8 ── 330Ω ── LED A(+) ── LED A(−) ──┐
                                            ├── Uno GND
  Uno D9 ── 330Ω ── LED B(+) ── LED B(−) ──┘
```

Cross-board: Uno ↔ breadboard. Same-board: both LEDs + resistors on the breadboard.

## Steps

1. Unplug USB.
2. Leave D8 chain as-is.
3. Add second LED + 330 Ω in series on the breadboard.
4. M-M: Uno **D9** → that chain’s anode/resistor start.
5. Cathode of LED B → same GND rail as LED A.
6. Plug USB when ready to upload.
