
---

## Basic Usage

```cpp
#include <SoftI2C_VPORT.h>

SoftI2C_VPORT i2c(PIN_PA1, PIN_PA2);

void setup() {
    i2c.begin();
}

void loop() {
    i2c.start();
    i2c.write(0x50);
    i2c.stop();
    delay(1000);
}