#include <Arduino.h>
//#include "I2C_center.h"
#include "RTC.h"
#include "BATT.h"
#include "pin_config.h"
#include "LVGL_Setup.h"


void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");
    delay(2000);
    Serial.println("Ciallo");
    delay(2000);
    Serial.println("Ciallo");
    delay(2000);

    RTC_init();
    BATT_init();
    TOUCH_init();
    LVGL_Setup();
}

void loop()
{
    LVGL_tick(); // handles whole LVGL drawing/touch
    
}