#ifndef __buttons
#define __buttons

#include "mcp23008.h"
#include <stdint.h>

typedef enum 
{ 
    LEFT = 0x01, 
    CENTER = 0x02,
    RIGHT = 0x04,
} button_event;

button_event BUTTONS_get_events();


#endif