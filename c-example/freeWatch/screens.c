#include "screens.h"


void SCREENS_debug()
{
    
}


void SCREENS_draw_watch()
{

    absolute_time_t t = get_absolute_time();
    

    uint8_t hour = (t/100000)%12;
    uint8_t minute = (t/100000 + 10)%60;
    uint8_t second = (t/100000)%60;

    uint8_t centerX = LCD_1IN28.WIDTH/2;
    uint8_t centerY = LCD_1IN28.HEIGHT/2;
    uint8_t R = LCD_1IN28.WIDTH/2;

    Paint_Clear(COLORS_get_565_from_888(0, 0, 0));

    Paint_DrawCircle(centerX, centerY, R-5, 0xFFFF, 2, 0);

    uint8_t sEndX = centerX + sinf(((float)second/60)*2*M_PI) * (R-9);
    uint8_t sEndY = centerY - cosf(((float)second/60)*2*M_PI) * (R-9);
    Paint_DrawLine(centerX, centerY, sEndX, sEndY, COLORS_get_565_from_888(255, 0, 0), 2, LINE_STYLE_SOLID);

    uint8_t mEndX = centerX + sinf(((float)minute/60)*2*M_PI) * (R*0.8 - 9);
    uint8_t mEndY = centerY - cosf(((float)minute/60)*2*M_PI) * (R*0.8 - 9);
    Paint_DrawLine(centerX, centerY, mEndX, mEndY, COLORS_get_565_from_888(255, 255, 0), 2, LINE_STYLE_SOLID);

    uint8_t hEndX = centerX + sinf(((float)hour/12)*2*M_PI) * (R*0.5 - 9);
    uint8_t hEndY = centerY - cosf(((float)hour/12)*2*M_PI) * (R*0.5 - 9);
    Paint_DrawLine(centerX, centerY, hEndX, hEndY, COLORS_get_565_from_888(0, 255, 0), 2, LINE_STYLE_SOLID);



}

void SCREENS_paint_rainbows(uint16_t *pixel_data)
{
    int a = 0;
    for (int8_t r = 117; r >= 90; r -= 5)
    {
        for (uint16_t i = 0; i < 360; i++)
        {
            if (i % 8 == 0)
            {
                uint8_t x = 120 + r * cos((i + a * 2) * M_PI / 180);
                uint8_t y = 122 + r * sin((i + a * 2) * M_PI / 180);
                uint16_t col = COLORS_get_565_rgb_from_hsv(i * 255 / 360, 255, 255);

                // Paint_SetPixel(x, y, col);
                Paint_DrawPoint(x, y, col, DOT_PIXEL_3X3, DOT_FILL_AROUND);
                LCD_1IN28_Display(pixel_data);
                DEV_Delay_ms(10);
            }
        }
        a += 2;
    }
}