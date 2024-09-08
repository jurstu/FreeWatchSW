#include "LVGL_Setup.h"



uint32_t my_tick();
void Arduino_IIC_Touch_Interrupt(void);
static void event_handler(lv_event_t * e);
void disp_flush(lv_display_t * display, const lv_area_t * area, uint8_t * px_map);
void my_input_read(lv_indev_t * indev, lv_indev_data_t*data);




Arduino_DataBus *bus = new Arduino_ESP32QSPI(LCD_CS, LCD_SCLK, LCD_SDIO0, LCD_SDIO1, LCD_SDIO2, LCD_SDIO3);
Arduino_GFX *gfx = new Arduino_SH8601(bus, LCD_RST, 0, false, LCD_WIDTH, LCD_HEIGHT);
std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);
std::unique_ptr<Arduino_IIC> FT3168(new Arduino_FT3x68(IIC_Bus, FT3168_DEVICE_ADDRESS, DRIVEBUS_DEFAULT_VALUE, TP_INT, Arduino_IIC_Touch_Interrupt));


static int touch_pressed = 0;
static int touch_x = 0;
static int touch_y = 0;
lv_obj_t *label;


void LVGL_Setup()
{
    pinMode(LCD_EN, OUTPUT);
    digitalWrite(LCD_EN, HIGH);

    while (FT3168->begin() == false)
    {
        Serial.println("FT3168 initialization fail");
        delay(2000);
    }
    Serial.println("FT3168 initialization successfully");

    gfx->begin(80000000); // 80MHz clock
    gfx->Display_Brightness(100);

    lv_init();

    lv_tick_set_cb(my_tick);

    lv_display_t * display = lv_display_create(gfx->width(), gfx->height());
    lv_display_set_flush_cb(display, disp_flush);



    const uint32_t size = (LCD_HEIGHT) * (LCD_WIDTH) * BYTE_PER_PIXEL;    
    uint16_t *buf_3_1 = (uint16_t*) aligned_alloc(2, size);
    uint16_t *buf_3_2 = (uint16_t*) aligned_alloc(2, size);
    lv_display_set_buffers(display, buf_3_1, buf_3_2, size, LV_DISPLAY_RENDER_MODE_FULL);

    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, my_input_read);
    //label = lv_label_create(lv_scr_act());
    //lv_label_set_text(label, "Hello Arduino! (V" GFX_STR(LVGL_VERSION_MAJOR) "." GFX_STR(LVGL_VERSION_MINOR) "." GFX_STR(LVGL_VERSION_PATCH) ")");
    //lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}


void LVGL_check_touch()
{
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




void Arduino_IIC_Touch_Interrupt(void)
{
    FT3168->IIC_Interrupt_Flag = true;
}







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


void my_input_read(lv_indev_t * indev, lv_indev_data_t*data)
{
    if(touch_pressed) {
        data->point.x = touch_x;
        data->point.y = touch_y;
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
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
