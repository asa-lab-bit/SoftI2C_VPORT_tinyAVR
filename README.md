# SoftI2C_VPORT_tinyAVR
![License](https://img.shields.io/badge/license-MIT-green)
![Version](https://img.shields.io/badge/version-v1.0.0-blue)
![Platform](https://img.shields.io/badge/platform-tinyAVR-orange)

Lightweight Software I2C library using VPORT for tinyAVR 0/1-series devices.

Designed for small Flash/RAM microcontrollers such as:

- ATtiny1604
- ATtiny404
- ATtiny202

---

## Overview

This library provides a simple software I2C implementation using VPORT
for fast GPIO control on tinyAVR 0/1-series MCUs.

It is designed to be:

- Small
- Fast
- Easy to understand
- Suitable for low-resource devices

---

## Supported Devices

Confirmed working on:

- ATtiny1604
- ATtiny404
- ATtiny202

Other tinyAVR 0/1-series devices may also work.

---

## Pin Configuration

Currently supports **PA port pins**.

Example:

- SDA → PA1 (pin number 1)
- SCL → PA2 (pin number 2)

Constructor example:

```cpp
SoftI2C_VPORT i2c(1, 2);   // SDA=PA1, SCL=PA2
Important: I2C Addressing

I2C devices use 7-bit addresses.

When transmitting the address, you must shift it left by 1 bit.
The least significant bit (LSB) becomes the Read/Write control bit.

Example:

If the device 7-bit address is:

0x28

Write mode transmission becomes:

0x28 << 1 = 0x50

Usage:

uint8_t address = 0x28;
i2c.write(address << 1);   // Write operation

This library does NOT automatically shift the address.
The user must provide the correct 8-bit value.

Basic Example
#include <SoftI2C_VPORT.h>

SoftI2C_VPORT i2c(1, 2);   // SDA=PA1, SCL=PA2

void setup() {
    i2c.begin();
}

void loop() {

    uint8_t address = 0x28;   // 7-bit device address

    i2c.start();
    i2c.write(address << 1);  // Write
    i2c.stop();

    delay(1000);
}
Installation

Click Code → Download ZIP

Open Arduino IDE

Sketch → Include Library → Add .ZIP Library

Select downloaded ZIP file

License

MIT License

