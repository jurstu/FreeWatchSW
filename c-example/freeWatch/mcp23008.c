#include "mcp23008.h"


void MCP23008_init()
{
    uint8_t reg_map[] = {0xFF, 0x00, 0x00, 0x00, 0x00, 
                         0x00, 0x00, 0x00, 0x00, 0x00};
    for(uint8_t i = 0; i < 0x0A; i++)
    {
        EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_IODIR + i, reg_map[i]);
    }                
    
   
}

void MCP23008_set_pin_dir(uint8_t dirs_in)
{
    EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_IODIR, dirs_in);
}

void MCP23008_set_pullups(uint8_t pullups)
{
    EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_GPPU, pullups);
}

void MCP23008_set_pin_state(uint8_t states)
{
    EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_GPIO, states);
}

void MCP23008_read_gpio(uint8_t *state)
{
    *state = EXT_I2C_read(MCP23008_I2C_ADDR, MCP23008_REG_GPIO);
}

