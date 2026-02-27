#include "SoftI2C_VPORT.h"

SoftI2C_VPORT::SoftI2C_VPORT(uint8_t sdaPin, uint8_t sclPin)
{
    _sda = sdaPin;
    _scl = sclPin;
}

void SoftI2C_VPORT::begin(void)
{
    VPORTA.OUT |= (1 << _sda) | (1 << _scl);
    VPORTA.DIR &= ~((1 << _sda) | (1 << _scl));
}

void SoftI2C_VPORT::i2c_delay(void)
{
    delayMicroseconds(4);   // 約100kHz
}

void SoftI2C_VPORT::sda_high(void)
{
    VPORTA.DIR &= ~(1 << _sda);
}

void SoftI2C_VPORT::sda_low(void)
{
    VPORTA.OUT &= ~(1 << _sda);
    VPORTA.DIR |= (1 << _sda);
}

void SoftI2C_VPORT::scl_high(void)
{
    VPORTA.DIR &= ~(1 << _scl);
}

void SoftI2C_VPORT::scl_low(void)
{
    VPORTA.OUT &= ~(1 << _scl);
    VPORTA.DIR |= (1 << _scl);
}

void SoftI2C_VPORT::start(void)
{
    sda_high(); scl_high(); i2c_delay();
    sda_low();  i2c_delay();
    scl_low();
}

void SoftI2C_VPORT::stop(void)
{
    sda_low();  scl_high(); i2c_delay();
    sda_high(); i2c_delay();
}

uint8_t SoftI2C_VPORT::write(uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (data & 0x80) sda_high();
        else             sda_low();

        scl_high(); i2c_delay();
        scl_low();  i2c_delay();
        data <<= 1;
    }

    // ACK受信
    sda_high();
    scl_high(); i2c_delay();

    uint8_t ack = !(VPORTA.IN & (1 << _sda));

    scl_low();
    return ack;
}

uint8_t SoftI2C_VPORT::read(uint8_t ack)
{
    uint8_t data = 0;
    sda_high();

    for (uint8_t i = 0; i < 8; i++)
    {
        data <<= 1;
        scl_high(); i2c_delay();

        if (VPORTA.IN & (1 << _sda))
            data |= 1;

        scl_low(); i2c_delay();
    }

    // ACK/NACK送信
    if (ack) sda_low();
    else     sda_high();

    scl_high(); i2c_delay();
    scl_low();
    sda_high();

    return data;
}