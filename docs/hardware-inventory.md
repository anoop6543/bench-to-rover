# Hardware inventory

Photos: [`docs/Hardware Images/`](Hardware%20Images/).  
Original Adafruit invoice scan was removed from the repo (contained personal shipping details). Line items below are kept for kit tracking only.

## 1. Adafruit order (line list, no PII)

**Vendor:** Adafruit  
**Invoice #:** 1863912  
**Ordered:** 2018-09-25  
**Source note:** transcribed from paper invoice; photo not stored in git

| Qty | Product | Adafruit P/N | Price | Seen in photos? |
| --- | --- | --- | ---: | --- |
| 1 | Microsoft Azure IoT Starter Kit w/ Adafruit Feather HUZZAH | 3032 | $46.95 | Not clearly photographed |
| 1 | Adafruit Perma-Proto Half-sized Breadboard PCB — Single | 1609 | $4.50 (FREE) | Not clearly photographed |
| 1 | Lithium Ion Polymer Battery — 3.7 V 500 mAh | 1578 | $7.95 | Yes (`PKCELL LP503035`) |
| 1 | Brass M2.5 Standoffs for Pi HATs — Black Plated — Pack of 2 | 1110 | $0.75 | Yes (black nylon/brass mix in bags) |
| 1 | Adafruit DC & Stepper Motor HAT for Raspberry Pi — Mini Kit | 2248 | $22.50 | Yes (blue HAT, M1–M4) |
| 1 | Mini Robot Rover Chassis Kit — 2WD with DC Motors | 2940 | $24.95 | Yes (assembled chassis) |

**Invoice “includes” under kit 2940**

| Qty | Included part | Adafruit P/N | Seen in photos? |
| --- | --- | --- | --- |
| 2 | Wheel for Micro Continuous Rotation FS90R Servo | 2744 | Yes (black 5-spoke + rubber tires). Bag labeled P2744 also held loose **LEDs** — contents mixed. |
| 1 | Top Metal Plate for a Mini Robot Rover Chassis | 2944 | Yes (orange slotted plate) |
| 1 | Anodized Aluminum Metal Chassis for a Mini Robot Rover | 2943 | Yes (orange chassis, caster mounted) |
| 1 | Supporting Swivel Caster Wheel — 1.3″ Diameter | 2942 | Yes (on chassis) |
| 2 | DC Motor in Micro Servo Body | 2941 | Yes (blue bodies on chassis, 3-pin leads). Screws bag labeled P2941. |

Invoice total of photographed lines: **$46.95 + $7.95 + $0.75 + $22.50 + $24.95 = $103.10** (Perma-Proto was free).

## 2. Everything in the photos (whether or not it is on that invoice)

### Compute and MCU

| Item | Photo | Notes |
| --- | --- | --- |
| Raspberry Pi 3 Model B **v1.2** | `184559`, `194243`, `224002` | Heatsinks, black case (lid off), 40-pin GPIO, CSI/DSI. 32 GB SanDisk (from earlier). |
| Arduino Uno R3 | (in use on COM4; not in this folder) | USB serial already proven |
| TI Tiva C Series LaunchPad **EK-TM4C123GXL** | `194232` | TM4C123GH6PM, BoosterPack headers, USB |
| BOOSTXL-EDUMKII Educational BoosterPack MK II | `194249`, `224002` | Joystick, 128×128 LCD, S1/S2, RGB, buzzer CEM-1203, accel, servo header J8, silkscreen JOY-X / JOY-Y / JOY-SEL |
| Adafruit DC & Stepper Motor HAT | `194232` | Pi HAT; terminals M1–M4, 5–12 V power |
| Vilros 40-pin GPIO cobbler + IDC ribbon | `224524`, `195117` | Mini breadboard; **Pi GPIO only**, not TI pinout |

### Breadboards, wire, headers

| Item | Photo | Notes |
| --- | --- | --- |
| Full-size solderless breadboard (~63 rows) | `195117`, `224002` | Use this if you want a middle island |
| Mini breadboard (cobbler seated) | `224524`, `195117` | Leave for Pi |
| Male-to-female Dupont (bag) | `184609` | Female onto pack/LaunchPad **males** where present, male into Uno |
| Male-to-male Dupont (bag + loose) | `184617`, `193150` | **S03 preferred:** pack **top** female → Uno female |
| 2×20 female header strip | `194325`, `194338` | Extra |
| Small 1×3 / 2×2 / 2×3 housings | `194302` | Servo / jumper housings |
| Gold 40-pin male header strips | `184625` | Two pieces in a bag |

### Rover / mechanical

| Item | Photo |
| --- | --- |
| Orange 2WD chassis with caster + two blue micro motors/servos | `194228` |
| Orange slotted top plate | `194232`, `194235` |
| Two black 5-spoke wheels | `194235` |
| Two rubber tires | `194319` |
| 4× AA battery box (empty) | `194238` |
| Chassis screws / nuts | `184703`, `195041`, `195052` |
| M2.5 standoffs + nuts | `194307` |

### Power and cables

| Item | Photo | Notes |
| --- | --- | --- |
| USB-A to USB-micro-B | `194353` | Pi, Tiva, some Adafruit boards |
| Wall-wart PSU | `194342` | On Tiva / BoosterPack paperwork |
| 3.7 V 500 mAh LiPo (PKCELL LP503035) | `194325`, `194338` | Adafruit 1578. Charge correctly; do not put raw on 5 V rails |
| 4× AA holder | `194238` | Rover power |

### Discrete parts and tools

| Item | Photo | Notes |
| --- | --- | --- |
| 5 mm LEDs, red and yellow | `184636` | In a bag labeled P2744 (wheels) |
| Through-hole resistors (two bags) | `194530`, `194542` | **S04 ~10 kΩ**; **S05 found ~330 Ω** (use for LEDs). Label bags when you can. |
| 2× 6 mm tactile buttons | `184655` |
| TO-92 transistor | `195033` | Typical 2N2222 / similar |
| Compact digital multimeter | `194359` | MEASURE IT / Etekcity-style |

### Paper / manuals

Full card photos (readable pinouts): [`docs/manuals/`](manuals/README.md).

| Item | Photo |
| --- | --- |
| Adafruit invoice 1863912 | *(redacted — not in repo)* |
| Tiva LaunchPad kit card + BoosterPack pinout | `manuals/215159`, `manuals/215151` |
| EDU MK II kit card + closer-look pinout | `manuals/215233`, `manuals/215250`, `manuals/215301` |
| “Meet the Tiva / Educational BoosterPack” cards (table shot) | `Hardware Images/194342` |
| Yahboom **DOFBOT-Pro** robot-arm manual (arm not in photos) | `Hardware Images/194325` |

## 3. Master checklist

| Have it | Source |
| --- | --- |
| Pi 3 B v1.2, case, cobbler, ribbon, mini + full breadboard | Photos |
| Arduino Uno R3 | Earlier session (COM4) |
| Tiva C LaunchPad + EDU MK II | Photos + TI cards |
| Motor HAT 2248 | Invoice + photo |
| Rover 2940 (chassis, plate, caster, 2 motors, 2 wheels, tires) | Invoice + photos |
| LiPo 1578 | Invoice + photo |
| M2.5 standoffs 1110 | Invoice + photo |
| Dupont M-M and M-F, extra headers | Photos |
| LEDs, resistors, buttons, transistor, meter, USB cable, PSU, AA box | Photos |
| Azure IoT / Feather HUZZAH 3032 | Invoice only — find the box if you still have it |
| Perma-Proto 1609 | Invoice only — not in photos |
| Yahboom DOFBOT-Pro | Manual only |

## 4. How the pieces fit (projects)

1. **Joystick today** — EDU MK II ↔ Uno with **male-to-male** Duponts (pack top females → Uno females). Vilros cobbler not used. See [scenarios/s03/wiring.md](scenarios/s03/wiring.md). Manuals: [manuals/](manuals/README.md).
2. **TI-native** — stack EDU MK II on the **Tiva LaunchPad** (pack **bottom female** onto LaunchPad **male** pins; 3.3 V).
3. **Pi later** — Lite OS, cobbler on the mini breadboard, Motor HAT if you drive DC motors from the Pi.
4. **Rover** — chassis motors are **micro-servo-bodied** (3-pin). Easier from Uno/Tiva PWM than from the Motor HAT’s M1–M4 DC channels. HAT + Pi is for true DC/stepper loads.
5. **LiPo / AA** — rover: AA box; LiPo only with a charger and a board that accepts 3.7 V.

## Photo index

| File | What it shows |
| --- | --- |
| `20261010_224002.jpg` | Overview: Pi, cobbler, full breadboard, EDU MK II, case bits |
| `20261010_224524.jpg` | Vilros cobbler close-up |
| `20261012_184559.jpg` | Pi 3 B v1.2 in case |
| `20261012_184609.jpg` | M-F Dupont bag |
| `20261012_184617.jpg` | M-M Dupont bag |
| `20261012_184625.jpg` | Male header strips |
| `20261012_184636.jpg` | LEDs (P2744 bag) |
| `20261012_184655.jpg` | Tactile buttons |
| `20261012_184703.jpg` | Small screws |
| `20261012_193150.jpg` | Loose M-M jumpers |
| `20261012_194228.jpg` | Rover chassis + motors + caster |
| `20261012_194232.jpg` | Tiva LaunchPad, Motor HAT, top plate |
| `20261012_194235.jpg` | Two wheels |
| `20261012_194238.jpg` | 4× AA box |
| `20261012_194243.jpg` | Pi + case lid |
| `20261012_194249.jpg` | EDU MK II close-up |
| `20261012_194302.jpg` | Small female housings |
| `20261012_194307.jpg` | Standoffs |
| `20261012_194319.jpg` | Rubber tires |
| `20261012_194325.jpg` | LiPo + header + DOFBOT manual |
| `20261012_194338.jpg` | LiPo + 2×20 header |
| `20261012_194342.jpg` | PSU + TI quick-start cards |
| `20261012_194353.jpg` | USB-A / micro-B cable |
| `20261012_194359.jpg` | Multimeter |
| `20261012_194530.jpg` | Resistors (with breadboard/rover in background) |
| `20261012_194542.jpg` | Resistors close-up |
| `20261012_195033.jpg` | TO-92 transistor |
| `20261012_195041.jpg` | Two screws |
| `20261012_195052.jpg` | Screws, bag P2941 |
| `20261012_195117.jpg` | Full-size breadboard + cobbler + ribbon |
