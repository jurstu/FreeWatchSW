#include "LVGL_Setup.h"

uint32_t LVGL_get_tick();

void LVGL_display_flush(lv_display_t * display, const lv_area_t * area, uint8_t * px_map);
void LVGL_input_read(lv_indev_t * indev, lv_indev_data_t*data);



/// # TODO maybe let's move this to display.cpp ?
Arduino_DataBus *bus = new Arduino_ESP32QSPI(LCD_CS, LCD_SCLK, LCD_SDIO0, LCD_SDIO1, LCD_SDIO2, LCD_SDIO3);
Arduino_GFX *gfx = new Arduino_SH8601(bus, LCD_RST, 0, false, LCD_WIDTH, LCD_HEIGHT);


lv_obj_t *label;


void LVGL_Setup()
{
    pinMode(LCD_EN, OUTPUT);
    digitalWrite(LCD_EN, HIGH);

    gfx->begin(80000000); // 80MHz clock
    gfx->Display_Brightness(100);

    lv_init();

    // LVGL timer init
    lv_tick_set_cb(LVGL_get_tick);

    // LVGL display init
    lv_display_t * display = lv_display_create(gfx->width(), gfx->height());
    lv_display_set_flush_cb(display, LVGL_display_flush);

    // LVGL framebuffer init
    const uint32_t size = (LCD_HEIGHT) * (LCD_WIDTH) * BYTE_PER_PIXEL;    
    uint16_t *buf_3_1 = (uint16_t*) aligned_alloc(2, size);
    uint16_t *buf_3_2 = (uint16_t*) aligned_alloc(2, size);
    lv_display_set_buffers(display, buf_3_1, buf_3_2, size, LV_DISPLAY_RENDER_MODE_FULL);

    // LVGL touch control
    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, LVGL_input_read);

    ui_init();
}

void LVGL_tick()
{
    TOUCH_check_touch();
    lv_timer_handler(); /* let the GUI do its work */
}

void LVGL_input_read(lv_indev_t * indev, lv_indev_data_t*data)
{
    int x, y, p;
    TOUCH_get_status(&x, &y, &p);
    if(p) {
        data->point.x = x;
        data->point.y = y;
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void LVGL_display_flush(lv_display_t * display, const lv_area_t * area, uint8_t * px_map)
{
    uint16_t * buf16 = (uint16_t *)px_map;
    int32_t w, h;
    w = area->x2 - area->x1 + 1;
    h = area->y2 - area->y1 + 1;
    gfx->draw16bitRGBBitmap(area->x1, area->y1, buf16, w, h);
    //gfx->drawCircle(466/2, 466/2, 100, 0x0000);
    
    lv_display_flush_ready(display);
}


uint32_t LVGL_get_tick()
{
    return millis();
}
