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
#include "Arduino_GFX_Library.h"
#include "Arduino_DriveBus_Library.h"
#include "pin_config.h"
#include "src/ui/ui.h"
//#include "Material_16Bit_466x466px.h"

//#define LV_CONF_INCLUDE_SIMPLE 1
//#include "lvgl.h"
#include <lvgl.h>

static uint8_t Image_Flag = 0;
#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */


Arduino_DataBus *bus = new Arduino_ESP32QSPI(LCD_CS, LCD_SCLK, LCD_SDIO0, LCD_SDIO1, LCD_SDIO2, LCD_SDIO3);
Arduino_GFX *gfx = new Arduino_SH8601(bus, LCD_RST, 0, false, LCD_WIDTH, LCD_HEIGHT);
static int touch_pressed = 0;
static int touch_x = 0;
static int touch_y = 0;

lv_obj_t *label;


static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        Serial.println("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        Serial.println("Toggled");
    }
}


std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

void Arduino_IIC_Touch_Interrupt(void);

std::unique_ptr<Arduino_IIC> FT3168(new Arduino_FT3x68(IIC_Bus, FT3168_DEVICE_ADDRESS, DRIVEBUS_DEFAULT_VALUE, TP_INT, Arduino_IIC_Touch_Interrupt));

void Arduino_IIC_Touch_Interrupt(void)
{
    FT3168->IIC_Interrupt_Flag = true;
}


void my_input_read(lv_indev_t * indev, lv_indev_data_t*data)
{
  if(touch_pressed) {
    data->point.x = touch_x;
    data->point.y = touch_y;
    data->state = LV_INDEV_STATE_PRESSED;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
  //lv_obj_align(label, LV_ALIGN_CENTER, touch_x-LCD_WIDTH/2, touch_y-LCD_HEIGHT/2);
}


void disp_flush(lv_display_t * display, const lv_area_t * area, uint8_t * px_map)
{

    //Serial.print("data at ");
    //Serial.print(area->x1);
    //Serial.print(", ");
    //Serial.print(area->y1);
    //Serial.println("");

    uint16_t * buf16 = (uint16_t *)px_map;
    int32_t w, h;
    w = area->x2 - area->x1 + 1;
    h = area->y2 - area->y1 + 1;
    gfx->draw16bitRGBBitmap(area->x1, area->y1, buf16, w, h);
    //gfx->drawCircle(466/2, 466/2, 100, 0x0000);
    
    lv_display_flush_ready(display);
}


uint32_t my_tick()
{
    return millis();
}




void setup()
{
    Serial.begin(115200);
    Serial.println("Ciallo");

    pinMode(LCD_EN, OUTPUT);
    digitalWrite(LCD_EN, HIGH);

    while (FT3168->begin() == false)
    {
        Serial.println("FT3168 initialization fail");
        delay(2000);
    }
    Serial.println("FT3168 initialization successfully");

    gfx->begin(80000000);
    //gfx->fillScreen(PURPLE);
    gfx->Display_Brightness(100);


    lv_init();

    lv_tick_set_cb(my_tick);

    lv_display_t * display = lv_display_create(gfx->width(), gfx->height());
    lv_display_set_flush_cb(display, disp_flush);


    /*
    LV_ATTRIBUTE_MEM_ALIGN
    uint8_t *buf_3_1 = (uint8_t*)malloc(LCD_WIDTH * LCD_HEIGHT * BYTE_PER_PIXEL);

    LV_ATTRIBUTE_MEM_ALIGN
    uint8_t *buf_3_2 = (uint8_t*)malloc(LCD_WIDTH * LCD_HEIGHT * BYTE_PER_PIXEL);

    lv_display_set_buffers(display, buf_3_1, buf_3_2, sizeof(buf_3_1), LV_DISPLAY_RENDER_MODE_DIRECT);
    */

    //LV_ATTRIBUTE_MEM_ALIGN
    //static uint8_t buf_1_1[LCD_HEIGHT * 50 * 2]; //BYTE_PER_PIXEL];            /*A buffer for 10 rows*/
    
    //uint8_t buf_1_1[size]; //BYTE_PER_PIXEL];            /*A buffer for 10 rows*/
    //LV_ATTRIBUTE_MEM_ALIGN
    //uint8_t *buf_1_1 = (uint8_t*) aligned_alloc(2, size);
    
    //lv_display_set_buffers(display, buf_1_1, NULL, size, LV_DISPLAY_RENDER_MODE_FULL);


    //uint8_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
    const uint32_t size = (LCD_HEIGHT) * (LCD_WIDTH) * BYTE_PER_PIXEL;
    
    uint16_t *buf_3_1 = (uint16_t*) aligned_alloc(2, size);
    uint16_t *buf_3_2 = (uint16_t*) aligned_alloc(2, size);
    //uint8_t *buf_3_1 = (uint8_t*)malloc(size);

    //uint8_t *buf_3_2 = (uint8_t*) aligned_alloc(2, size);

    lv_display_set_buffers(display, buf_3_1, buf_3_2, size, LV_DISPLAY_RENDER_MODE_FULL);


    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_input_read);
    
    
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello Arduino! (V" GFX_STR(LVGL_VERSION_MAJOR) "." GFX_STR(LVGL_VERSION_MINOR) "." GFX_STR(LVGL_VERSION_PATCH) ")");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);


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

    ui_init();

}

void loop()
{
    static int counter = 0;
    counter++;

    lv_timer_handler(); /* let the GUI do its work */
    //delay(100);    
    // Serial.printf("System running time: %d\n\n", (uint32_t)millis() / 1000);

    char buff[50];

    sprintf(buff, "%d", counter);
    lv_label_set_text(label, buff);
    

    if (FT3168->IIC_Interrupt_Flag == true)
    {
        FT3168->IIC_Interrupt_Flag = false;

        
        touch_x = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_X);
        touch_y = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_Y);
        
        uint8_t fingers_number = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_FINGER_NUMBER);

        
        Serial.println(touch_x);
        touch_pressed = fingers_number > 0;
    }
}
