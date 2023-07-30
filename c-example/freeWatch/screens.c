#include "screens.h"



void SCREENS_paint_rainbows(uint16_t* pixel_data)
{
    int a = 0;
    for (int8_t r = 117; r >= 90; r-=5)
    {
        for (uint16_t i = 0; i < 360; i++)
        {
            if(i % 8 == 0)
            {
                uint8_t x = 120 + r*cos((i+a*2)*M_PI/180);
                uint8_t y = 122 + r*sin((i+a*2)*M_PI/180);
                uint16_t col = COLORS_get_565_rgb_from_hsv(i*255/360, 255, 255);

                //Paint_SetPixel(x, y, col);
                Paint_DrawPoint(x, y, col, DOT_PIXEL_3X3, DOT_FILL_AROUND);
                LCD_1IN28_Display(pixel_data);
                DEV_Delay_ms(10);
            }

        }
        a+=2;
    }
}