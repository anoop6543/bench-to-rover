# Hardware manuals (photos)

Paper quick-start cards photographed for offline reference. Prefer these over guesswork when wiring.

| File | Document | Useful for |
| --- | --- | --- |
| [`20261012_215151.jpg`](20261012_215151.jpg) | EK-TM4C123GXL BoosterPack connector pinout (color map) | LaunchPad J1–J4 functions, GND/3.3V/5V |
| [`20261012_215159.jpg`](20261012_215159.jpg) | Tiva C Series TM4C123G LaunchPad Evaluation Kit card (front/inside) | Kit overview, BoosterPack ecosystem |
| [`20261012_215233.jpg`](20261012_215233.jpg) | Educational BoosterPack MKII card (overview / Energia) | Features list, Energia / CCS pointers |
| [`20261012_215250.jpg`](20261012_215250.jpg) | Educational BoosterPack MKII card (board photo + stack note) | **Pack top = female header blocks** (visible in photo) |
| [`20261012_215301.jpg`](20261012_215301.jpg) | EDU MK II “closer look” + full pinout diagram | Joystick / LCD / sensors → J1–J4 pin numbers |

## Header gender (from these cards + your boards)

| Surface | Gender | Source |
| --- | --- | --- |
| EDU MK II **top** (LCD face) | **Female** sockets (most pins; some nets use M-F — see S03 wire 6) | Manual photo `215250` / `215301` |
| EDU MK II **bottom** | **Female** sockets | Seats on LaunchPad male pins |
| Tiva LaunchPad **BoosterPack** headers | **Male** pins on this kit | Board photo `Hardware Images/20261012_194232.jpg` |
| Arduino Uno | **Female** holes | Board |

**S03** jumpers pack → Uno (not stacked on LaunchPad). See [scenarios/s03/wiring.md](../scenarios/s03/wiring.md).
