#include <SoftI2C_VPORT.h>

// ATtiny1604 / 404 / 202
// SDA = PA1 (1)
// SCL = PA2 (2)

SoftI2C_VPORT i2c(1, 2);   // SDA=PA1, SCL=PA2

void setup() {
    i2c.begin();
}

void loop() {

    uint8_t address = 0x28;   // 7-bit I2C device address (example)

    i2c.start();

    // I2C uses 7-bit addressing.
    // When transmitting, shift left by 1 bit.
    // LSB becomes R/W bit.
    i2c.write(address << 1);   // Write operation

    i2c.stop();

    delay(1000);
}
