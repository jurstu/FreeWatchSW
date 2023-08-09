#ifndef __screens
#define __screens

#include "colors.h"
#include "stdint.h"
#include "GUI_Paint.h"
#include <math.h>
#include "DEV_Config.h"
#include "LCD_1in28.h"
#include "time.h"
#include <pico/types.h>

void SCREENS_debug();
void SCREENS_paint_rainbows(uint16_t* pixel_data);
void SCREENS_draw_watch();

#endif