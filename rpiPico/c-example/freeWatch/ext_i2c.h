#ifndef __ext_i2c_h
#define __ext_i2c_h

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"



#include "DEV_Config.h"

#define EXT_I2C_PORT (i2c0)
#define EXT_I2C_SDA     (16)
#define EXT_I2C_SCL     (17)



void EXT_I2C_init();
uint8_t EXT_I2C_read(uint8_t addr, uint8_t reg);
void EXT_I2C_write(uint8_t addr, uint8_t reg, uint8_t Value);
void EXT_I2C_read_multi(uint8_t addr, uint8_t reg0, uint8_t num, uint8_t *out);
void EXT_I2C_write_multi(uint8_t addr, uint8_t num, uint8_t *in);






#endif
