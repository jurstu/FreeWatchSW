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


#define MCP23008_PIN_0 0x01
#define MCP23008_PIN_1 0x02
#define MCP23008_PIN_2 0x04
#define MCP23008_PIN_3 0x08
#define MCP23008_PIN_4 0x10
#define MCP23008_PIN_5 0x20
#define MCP23008_PIN_6 0x40
#define MCP23008_PIN_7 0x80


#define MCP23008_OUTPUT 0x00
#define MCP23008_INPUT 0x01




void MCP23008_init();
void MCP23008_set_dir(uint8_t dirs_in);
void MCP23008_set_state(uint8_t states);
void MCP23008_read_gpio(uint8_t *state);
void MCP23008_set_pullups(uint8_t pullups);

void MCP23008_pin_dir(uint8_t pin, uint8_t direction);
void MCP23008_pin_pullup(uint8_t pin, uint8_t pullup);
void MCP23008_pin_state(uint8_t pin, uint8_t state);
uint8_t MCP23008_read_pin(uint8_t pin);

#endif
