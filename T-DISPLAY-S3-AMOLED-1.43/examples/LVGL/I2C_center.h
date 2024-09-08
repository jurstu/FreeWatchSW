#ifndef __i2c_center
#define __i2c_center

#include "Arduino.h"
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"

void I2C_init();
void I2C_get_bus(std::shared_ptr<Arduino_IIC_DriveBus> &dest);

#endif