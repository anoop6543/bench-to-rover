# Scenarios: baby → amazing

Use only what is in [hardware-inventory.md](hardware-inventory.md). We will implement these **one at a time**. Check the box when a scenario works on the bench.

**Tracking:** [scenarios/TRACKING.md](scenarios/TRACKING.md) — each ID has `setup.md`, `wiring.md` (boards/jumpers, not code), `tests.md`, and [`code/<slug>/`](../code/INDEX.md). Prev/next links on every page.

**Safety (every level):** 3.3 V TI pack vs 5 V Uno — no stacking pack on Uno/Pi/cobbler. LiPo only with a charger and a 3.7 V-safe board. Multimeter before first power on a new circuit. Pi 3 has 1 GB RAM — stay Lite, skip desktop stacks.

**Legend:** `[x]` already done in this repo · `[ ]` next · *optional* if the Feather / Perma-Proto / DOFBOT arm turns up.

---

## Level 0 — Already done (Uno + USB only)

| # | Scenario | What it teaches | Hardware |
| --- | --- | --- | --- |
| S00 | Blink onboard **L** LED | Compile/upload from Cursor (`arduino-cli`) | Uno |
| S01 | 15 named LED codes + dashboard | Serial commands, Flask | Uno, PC |
| S02 | USB self-test (Vcc, die temp, SRAM, EEPROM) | Chip internals, no wires | Uno, PC |
| S03 | Joystick sketch + wiring map (**done 2026-10-12**) | Analog + click, Dupont gender | Uno, EDU MK II, 6× M-M jumpers |

Level 0 complete. S04–S08 done 2026-10-12. Next: **S09** or Level 2 pack.

---

## Level 1 — Baby (one board, few parts)

Arduino + breadboard + LEDs / buttons / resistors / meter. No Pi, no rover.

| # | Scenario | Goal |
| --- | --- | --- |
| S04 | Meter the bench (**done 2026-10-12**) | Measure Uno 5 V and 3.3 V; confirm a resistor; never guess LiPo. |
| S05 | External LED blink (**done 2026-10-12**) | One LED + ~330 Ω from D13 (or D8) to GND. Same as S00 but you wired it. |
| S06 | Two-LED heartbeat (**done 2026-10-12**) | Red/yellow alternate (+ funny pattern). |
| S07 | Button toggles LED (**done 2026-10-12**) | Tactile + pull-up (or INPUT_PULLUP). |
| S08 | LED brightness PWM (**done 2026-10-12**) | `analogWrite` on D9; dashboard slider. |
| S09 | Transistor as switch | TO-92 drives an LED from a GPIO (current primer). |
| S10 | Serial Morse | Type SOS on the PC, LED blinks Morse. |

---

## Level 2 — EDU MK II on the Uno (jumpers)

Six to ~12 Duponts. Dashboard on this PC. Full-size breadboard optional.

| # | Scenario | Goal |
| --- | --- | --- |
| S11 | Joystick as a mouse pad | Build on S03; richer pad UI / cursor feel. |
| S12 | Buttons S1 / S2 | Two more wires; dashboard flags. |
| S13 | Tilt (accel X/Y/Z) | Analog bars; “level” bubble. |
| S14 | RGB mood light | Series resistors; color picker (5 V caution). |
| S15 | Buzzer beeps | `tone()`; map joystick Y to pitch. |
| S16 | Mic VU meter | Analog mic → bar on the page (noisy is OK). |
| S17 | Game: keep the ball on the pad | Joystick steers; S1 reset; buzzer on miss. |
| S18 | Servo header on the pack | One rover motor as a *test servo* on J8 (5 V), 90° sweep — wheels **off** the table. |

---

## Level 3 — Tiva LaunchPad (native 3.3 V)

The pack **plugs onto** the EK-TM4C123GXL. Energia or CCS. No Uno 5 V risk.

| # | Scenario | Goal |
| --- | --- | --- |
| S19 | LaunchPad blink / USB enumerate | Proof the Tiva is alive (micro-USB). |
| S20 | Stack EDU MK II, Energia joystick | Official pairing; LCD shows X/Y. |
| S21 | LCD splash + buttons | Text/shapes on the 128×128 TFT. |
| S22 | OPT3001 lux (I2C) | Cover the light sensor; numbers on LCD. |
| S23 | Pack as a handheld instrument | LCD: lux + tilt + joystick cursor. |
| S24 | Tiva talks serial to the PC dashboard | Same Flask idea as the Uno, 3.3 V native. |

---

## Level 4 — Rover body (motors, no Pi yet)

Orange chassis, two micro-servo-bodied motors, AA box. Drive from **Uno PWM** first (3-pin leads). Keep the Motor HAT for Level 6 if the motors behave as DC (2-wire) after you meter them.

| # | Scenario | Goal |
| --- | --- | --- |
| S25 | Identify motor wires with the meter | Servo-style 3-pin vs two-wire DC — decides HAT vs `Servo.h`. |
| S26 | One motor, wheels off the desk | Slow spin, then stop. |
| S27 | Both motors: forward / back / spin | Serial commands: `F B L R S`. |
| S28 | Joystick tank drive | EDU MK II stick → rover. **The first “it moves” moment.** |
| S29 | Button turbo / reverse | S1/S2 on the pack. |
| S30 | Bumper-less “watchdog” | If no joystick packet for 0.3 s, motors stop (USB yank safety). |
| S31 | AA-box power for motors, USB for Uno | Split supplies, common GND. |

---

## Level 5 — Raspberry Pi 3 as the brain

Lite 32-bit, SSH, cobbler. 1 GB RAM.

| # | Scenario | Goal |
| --- | --- | --- |
| S32 | First boot + SSH | [first-boot.md](first-boot.md); cobbler unplugged until GPIO. |
| S33 | Pi vitals page | CPU temp, RAM, disk on the LAN. |
| S34 | Uno on a Pi USB port | Move COM4 sketch to `/dev/ttyACM0`; same dashboard. |
| S35 | Cobbler + LED/button | Vilros labels; blink from Python. |
| S36 | Phone / laptop drives the rover over Wi-Fi | Pi hosts the page; Uno still owns PWM/ADC. |
| S37 | Log joystick + tilt to a CSV on the Pi | Tiny “black box” for the rover. |

---

## Level 6 — Best / amazing (full kit)

These are the capstones. Each needs Level 4–5 solid.

| # | Scenario | Goal |
| --- | --- | --- |
| S38 | **Wi-Fi RC rover** | Phone browser: stick + camera-less HUD. Pi + Uno + pack + chassis + AA. |
| S39 | **Assistive rover** | Tilt the BoosterPack (accel) to drive; LCD shows heading; buzzer on reverse. |
| S40 | **Pi Motor HAT rover** | Only if S25 says true DC motors: HAT M1/M2, 5–12 V on the HAT power terminal (not from Pi 5 V). |
| S41 | **Instrument cluster** | Pack LCD = speed/mode; RGB = battery-ish (AA voltage via divider later); dashboard on Pi. |
| S42 | **Follow the light** | OPT3001 (Tiva or Pi I2C) steers toward a flashlight. |
| S43 | **Line of stations** | Button S1 = dock / stop; joystick override. |
| S44 | **Telemetry recorder** | Pi logs time, joy, accel, commands; replay on the dashboard. |
| S45 | **Perma-Proto permanent joystick harness** *optional* | Solder the six Uno wires so it survives rover vibration. |
| S46 | **Feather HUZZAH Wi-Fi stick** *optional* | If you find kit 3032: rover remote without the Pi. |
| S47 | **DOFBOT arm on the rover** *optional* | Only if the Yahboom arm exists; Uno/Pi sequential servos. Do not force this. |

---

## Suggested order (first 10 we will actually run)

1. ~~**S03** — joystick live on the dashboard~~ **done 2026-10-12**  
2. ~~**S04** — meter 5 V / 3.3 V / a resistor~~ **done 2026-10-12** (~10 kΩ found)  
3. ~~**S05** — one external LED~~ **done 2026-10-12**  
4. ~~**S06** — two-LED heartbeat~~ **done 2026-10-12**  
5. ~~**S07** — button + LED~~ **done 2026-10-12**  
6. ~~**S08** — PWM LED brightness~~ **done 2026-10-12**  
7. ~~**S09–S12** — transistor, Morse, mouse pad, S1/S2~~ **done 2026-10-13**  
8. **S13** — tilt accel ← **next**  
9. **S14** — RGB · **S15** — buzzer  
10. **S19–S20** / rover / Pi later  

When you say “next,” start **S13**.
