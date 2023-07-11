#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"

#define EXT_I2C_PORT (i2c0)
#define EXT_I2C_SDA     (16)
#define EXT_I2C_SCL     (17)



void EXT_I2C_init();










#endif
