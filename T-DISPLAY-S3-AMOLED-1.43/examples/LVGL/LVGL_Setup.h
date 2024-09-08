#ifndef __LVGL_SETUP
#define __LVGL_SETUP

#include <lvgl.h>
#include <Arduino.h>
#include "Arduino_GFX_Library.h"
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"
#include "src/ui/ui.h"


#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */

void LVGL_Setup();
void LVGL_check_touch();





#endif