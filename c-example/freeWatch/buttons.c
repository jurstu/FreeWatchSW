#include "buttons.h"

static uint8_t last_left = 0;
static uint8_t last_center = 0;
static uint8_t last_right = 0;


button_event BUTTONS_get_events()
{
    uint8_t in = 0;
    MCP23008_read_gpio(&in);
    uint8_t left = (in&0x01)>>0;
    uint8_t center = (in&0x02)>>1;
    uint8_t right = (in&0x04)>>2;

    button_event out = 0;
    out |= (!((left) || (!last_left)))*LEFT; 
    out |= (!((center) || (!last_center)))*CENTER;
    out |= (!((right) || (!last_right)))*RIGHT;

    last_right = right;
    last_center = center;
    last_left = left;

    return out;    
}