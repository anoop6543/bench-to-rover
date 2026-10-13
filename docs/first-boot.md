# Raspberry Pi 3 Model B v1.2 — first boot

Board: 1GB RAM. Use **Raspberry Pi OS Lite (32-bit)** on the 32GB SanDisk card. Skip the 64-bit desktop image.

## Flash (Windows)

1. Install [Raspberry Pi Imager](https://www.raspberrypi.com/software/).
2. Choose device **Raspberry Pi 3**, OS **Raspberry Pi OS Lite (32-bit)**, storage = the SanDisk card.
3. Open OS customisation:
   - hostname: `raspi3`
   - username / password (remember these)
   - wireless LAN if you are not using Ethernet
   - enable SSH (password authentication is fine on a home LAN)
4. Write the image, eject the card, insert it in the Pi.

## Before you power the Pi

Unplug the **Vilros GPIO cobbler ribbon** from the Pi 40-pin header. An empty mini breadboard can short 3.3V / 5V / GND. Plug the ribbon back only when you need GPIO (Phase 3).

Use a 5V micro-USB supply around 2.5A if you can. Weak phone chargers often reboot under USB load.

## First login

From PowerShell on this PC:

```powershell
ssh YOURUSER@raspi3.local
```

If `.local` does not resolve, check the router DHCP list for `raspi3` and SSH to that IP.

Then:

```bash
sudo apt update && sudo apt upgrade -y
sudo timedatectl set-timezone America/Los_Angeles
```

## Next

Keep the Arduino on the laptop **COM4** until the JSON sketch is uploaded. After that you can move the Uno USB cable to a Pi USB port (`/dev/ttyACM0`) and run the dashboard — see the repo README.
