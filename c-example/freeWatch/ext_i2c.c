#include "ext_i2c.h"


void EXT_I2C_init()
{
    i2c_init(EXT_I2C_PORT, 100 * 1000);
    gpio_set_function(EXT_I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(EXT_I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(EXT_I2C_SCL);
    gpio_pull_up(EXT_I2C_SDA);
}


void EXT_I2C_write(uint8_t addr, uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    i2c_write_blocking(EXT_I2C_PORT, addr, data, 2, false);
}


uint8_t EXT_I2C_read(uint8_t addr, uint8_t reg)
{
    uint8_t buf;
    i2c_write_blocking(EXT_I2C_PORT, addr, &reg, 1, true);
    i2c_read_blocking(EXT_I2C_PORT, addr, &buf, 1, false);
    DEV_Delay_ms(1);
    return buf;
}

void EXT_I2C_read_multi(uint8_t addr, uint8_t reg0, uint8_t num, uint8_t *out)
{
    i2c_write_blocking(EXT_I2C_PORT, addr, &reg0, 1, true);
    i2c_read_blocking(EXT_I2C_PORT, addr, out, num, false);
}

void EXT_I2C_write_multi(uint8_t addr, uint8_t num, uint8_t *in)
{
    i2c_write_blocking(EXT_I2C_PORT, addr, in, num, false);
}