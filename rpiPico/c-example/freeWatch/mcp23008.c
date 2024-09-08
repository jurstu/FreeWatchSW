#include "mcp23008.h"

static uint8_t MCP23008_last_pin_dirs = 0x00;
static uint8_t MCP23008_last_pin_states = 0x00;
static uint8_t MCP23008_last_pin_pullups = 0x00;

void MCP23008_init()
{
    uint8_t reg_map[] = {0xFF, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00};
    for (uint8_t i = 0; i < 0x0A; i++)
    {
        EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_IODIR + i, reg_map[i]);
    }
}

// pin <0,7>
void MCP23008_pin_dir(uint8_t pin, uint8_t direction)
{
    uint8_t out = MCP23008_last_pin_dirs;
    if (direction == 0)
    {
        out &= ~(1 << (pin));
    }
    else
    {
        out |= (1 << (pin));
    }
    MCP23008_set_dir(out);
}
void MCP23008_set_dir(uint8_t dirs_in)
{
    if(dirs_in != MCP23008_last_pin_dirs)
    {
        MCP23008_last_pin_dirs = dirs_in;
        EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_IODIR, dirs_in);
    }
}

void MCP23008_pin_pullup(uint8_t pin, uint8_t pullup)
{
    uint8_t out = MCP23008_last_pin_pullups;
    if (pullup == 0)
    {
        out &= ~(1 << (pin));
    }
    else
    {
        out |= (1 << (pin));
    }
    MCP23008_set_pullups(out);
}
void MCP23008_set_pullups(uint8_t pullups)
{
    if(pullups != MCP23008_last_pin_pullups)
    {
        MCP23008_last_pin_pullups = pullups;
        EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_GPPU, pullups);
    }
}

void MCP23008_pin_state(uint8_t pin, uint8_t state)
{
    uint8_t out = MCP23008_last_pin_states;
    if (state == 0)
    {
        out &= ~(1 << (pin));
    }
    else
    {
        out |= (1 << (pin));
    }
    MCP23008_set_state(out);
}
void MCP23008_set_state(uint8_t states)
{
    if(states != MCP23008_last_pin_states)
    {
        MCP23008_last_pin_states = states;
        EXT_I2C_write(MCP23008_I2C_ADDR, MCP23008_REG_GPIO, states);
    }
}

uint8_t MCP23008_read_pin(uint8_t pin)
{
    uint8_t state = 0;
    MCP23008_read_gpio(&state);
    state = (state & (1 << pin)) != 0;
    return state;
}
void MCP23008_read_gpio(uint8_t *state)
{
    *state = EXT_I2C_read(MCP23008_I2C_ADDR, MCP23008_REG_GPIO);
}
