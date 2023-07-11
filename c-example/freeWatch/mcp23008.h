#ifndef __mcp23008
#define __mcp23008

#include "ext_i2c.h"


void MCP23008_init();
void MCP23008_set_pin_dir(uint8_t pin, uint8_t dir);
void MCP23008_set_pin_state(uint8_t pin, uint8_t state);
void MCP23008_read_gpio(uint8_t *state);

#endif
