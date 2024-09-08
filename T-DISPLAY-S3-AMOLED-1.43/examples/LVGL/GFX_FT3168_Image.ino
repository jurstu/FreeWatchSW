/*
 * @Description: GFX屏幕显示+触摸切换图片
 * @version: V1.0.0
 * @Author: LILYGO_L
 * @Date: 2023-09-06 10:58:19
 * @LastEditors: LILYGO_L
 * @LastEditTime: 2024-05-29 10:44:34
 * @License: GPL 3.0
 */
#include <Arduino.h>
#include "pin_config.h"
#include "LVGL_Setup.h"












void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");
    LVGL_Setup();
    ui_init();


    /*
    lv_obj_t * btn1 = lv_button_create(lv_screen_active());
    //lv_obj_reset_style_list(obj, LV_OBJ_PART_MAIN);

    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);
    lv_obj_set_height(btn1, 140);
    lv_obj_set_width(btn1, 80);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 100);



    lv_obj_t * label2;
    label2 = lv_label_create(btn1);
    lv_label_set_text(label2, "Button");
    lv_obj_center(label2);
    */

    

}

void loop()
{
    static int counter = 0;
    counter++;

    lv_timer_handler(); /* let the GUI do its work */
    LVGL_check_touch();
    //delay(100);    
    // Serial.printf("System running time: %d\n\n", (uint32_t)millis() / 1000);

    char buff[50];



}
