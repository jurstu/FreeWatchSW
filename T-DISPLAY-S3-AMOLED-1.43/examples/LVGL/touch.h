#ifndef __touch
#define __touch

#include "Arduino.h"
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"
#include "I2C_center.h"


void TOUCH_init();
void TOUCH_check_touch();
void TOUCH_get_status(int *x, int *y, int *pressed);

#endif