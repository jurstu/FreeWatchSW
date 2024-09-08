#include <Arduino.h>
#include "pin_config.h"
#include "LVGL_Setup.h"

void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");
    LVGL_Setup();
    ui_init();
}

void loop()
{
    static int counter = 0;
    counter++;
    lv_timer_handler(); /* let the GUI do its work */
    LVGL_check_touch();
}