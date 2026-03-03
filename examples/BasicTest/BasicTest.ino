#include <SoftI2C_VPORT.h>

// ATtiny1604 / 404 / 202
// PA1 = 1
// PA2 = 2

SoftI2C_VPORT i2c(1, 2);   // SDA=PA1, SCL=PA2

void setup() {
    i2c.begin();
}

void loop() {
    i2c.start();
    i2c.write(0x50);  // テスト送信
    i2c.stop();
    delay(1000);
}
