#ifndef __BATT
#define __BATT

#include "Arduino.h"
#include "pin_config.h"
#include "util.h"

#define BATT_MIN_MV 3200
#define BATT_MAX_MV 4200


void BATT_init();
uint16_t BATT_get_perc();


#endif