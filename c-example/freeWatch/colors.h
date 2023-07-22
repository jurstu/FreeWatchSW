#ifndef __colors
#define __colors

#include "stdint.h"



uint16_t COLORS_get_565_from_888 (uint8_t r, uint8_t g, uint8_t b);
uint16_t COLORS_get_565_rgb_from_hsv(uint8_t h, uint8_t s, uint8_t v);





#endif