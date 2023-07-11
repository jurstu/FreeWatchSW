#ifndef __mcp23008
#define __mcp23008

#include "ext_i2c.h"


#define MCP23008_REG_IODIR   0x00
#define MCP23008_REG_IPOL    0x01
#define MCP23008_REG_GPINTEN 0x02
#define MCP23008_REG_DEFVAL  0x03
#define MCP23008_REG_INTCON  0x04
#define MCP23008_REG_IOCON   0x05
#define MCP23008_REG_GPPU    0x06
#define MCP23008_REG_INTF    0x07
#define MCP23008_REG_INTCAP  0x08
#define MCP23008_REG_GPIO    0x09
#define MCP23008_REG_OLAT    0x0A

#define MCP23008_I2C_ADDR    0x20


void MCP23008_init();
void MCP23008_set_pin_dir(uint8_t dirs_in);
void MCP23008_set_pin_state(uint8_t states);
void MCP23008_read_gpio(uint8_t *state);
void MCP23008_set_pullups(uint8_t pullups);

#endif
