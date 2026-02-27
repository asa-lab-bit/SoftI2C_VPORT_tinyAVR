# SoftI2C_VPORT_tinyAVR

Lightweight Software I2C library using VPORT for tinyAVR 0/1-series.

Tested on:
- ATtiny1604
- ATtiny404
- ATtiny202

This library allows software I2C communication using PA port pins.

---

## Features

- Uses VPORT for fast GPIO control
- Works on tinyAVR 0/1 series
- Simple and lightweight
- Suitable for small memory devices

---

## Supported MCUs

- ATtiny1604
- ATtiny404
- ATtiny202

(Other tinyAVR 0/1 series devices may also work)

---

## Pin Usage

This library currently supports **PA port pins only**.

Example:
- SDA → PA1
- SCL → PA2

---

## Installation

1. Download ZIP from GitHub
2. Arduino IDE → Sketch → Include Library → Add .ZIP Library
3. Select the downloaded ZIP file

---

## Example

Basic test example is included:
