#ifndef SOFTI2C_VPORT_H
#define SOFTI2C_VPORT_H

#include <Arduino.h>

class SoftI2C_VPORT {
public:
    SoftI2C_VPORT(uint8_t sdaPin, uint8_t sclPin);

    void begin(void);

    void start(void);
    void stop(void);

    uint8_t write(uint8_t data);
    uint8_t read(uint8_t ack);

private:
    uint8_t _sda;
    uint8_t _scl;

    void sda_high(void);
    void sda_low(void);
    void scl_high(void);
    void scl_low(void);
    void i2c_delay(void);
};

#endif