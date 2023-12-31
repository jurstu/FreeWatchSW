﻿#include "LCD_Test.h" //Examples

#include "LCD_Test.h"
#include "LCD_1in28.h"
#include "QMI8658.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "CST816S.h"
#include "math.h"

#include "ext_i2c.h"
#include "mcp23008.h"
#include "screens.h"
#include "buttons.h"
#include "rtc.h"
#include "GPS.h"

// 104 94 84, 6AEA - szary dronowy ? 

void DEV_init()
{
    if (DEV_Module_Init() != 0)
    {
        return;
    }
    printf("LCD_1in28_test Demo\r\n");
    LCD_1IN28_Init(HORIZONTAL);
    // 5 6 5
    LCD_1IN28_Clear(0x0000);
    // LCD_1IN28_Clear(0xFFFF);
    DEV_SET_PWM(100);
}

void SUBDEV_init()
{
    EXT_I2C_init();
    MCP23008_init();
    MCP23008_set_pullups(0x07);    
    MCP23008_set_dir(0x07);
    MCP23008_set_state(~0x07);

    RTC_init();

    GPS_init();
}

int main(void)
{
    DEV_init();
    SUBDEV_init();

    uint32_t Imagesize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    uint16_t *BlackImage;
    if ((BlackImage = (uint16_t *)malloc(Imagesize)) == NULL)
    {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }
    // /*1.Create a new image cache named IMAGE_RGB and fill it with white*/
    Paint_NewImage((uint8_t *)BlackImage, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(COLORS_get_565_from_888(0,0,0));


    uint8_t r=0, g=0, bc=0;

    

    uint8_t screen = 0;
    uint8_t screen_num = 3;
    while(1)
    {
        
        //printf("%02d:%02d:%02d\n\r", h, m, s);

        button_event b = BUTTONS_get_events();
        if(b&LEFT)
        {
            screen = (screen+1)%screen_num;
        }
        if(b&CENTER)
        {

        }
        if(b&RIGHT)
        {
            screen = (screen-1 + screen_num)%screen_num;
        }

        if (screen == 0)
        {
            SCREENS_draw_watch();
        }

        if (screen == 1)
        {
            SCREENS_debug();
        }

        if (screen == 2)
        {
            SCREENS_draw_Paulina_is_super();
        }

        LCD_1IN28_Display(BlackImage);

        GPS_handle_parse();
        
        
        //printf("%d %d %d, %04X\n\r", r, g, bc, COLORS_get_565_from_888(r,g,bc));
        //Paint_Clear(COLORS_get_565_from_888(r,g,bc));
        //LCD_1IN28_Display(BlackImage);
    }

/*

    MCP23008_set_pullups(0xFF);    
    MCP23008_pin_dir(MCP23008_PIN_0, MCP23008_INPUT);
    MCP23008_pin_dir(MCP23008_PIN_3, MCP23008_OUTPUT);
    MCP23008_pin_dir(MCP23008_PIN_5, MCP23008_OUTPUT);
    MCP23008_pin_dir(MCP23008_PIN_6, MCP23008_OUTPUT);
    MCP23008_pin_dir(MCP23008_PIN_7, MCP23008_OUTPUT);

    
    uint8_t state;
    uint8_t in = 0;

*/



    int a = 0;
    while(1)
    {
        for (int8_t r = 117; r >= 0; r-=5)
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
                    LCD_1IN28_Display(BlackImage);
                }

            }
            a+=2;    
        }
        
    }





/*



    while(1)
    {
        state = MCP23008_read_pin(0);
        printf("state: %d\n\r", state);
        DEV_Delay_ms(1);
        if(state)
        {
            MCP23008_set_state(0x00);
            LCD_1IN28_Clear(0xFFFF);
        }
        else
        {
            MCP23008_set_state(0xF8);
            LCD_1IN28_Clear(0x0000);
        }

        DEV_Delay_ms(10);
        if(in++ > 200)
        {
            //break;
        }
    }

*/


    
    Paint_DrawString_EN(0, 128, "Jurstu Watch", &Font20, 0x000f, 0xfff0);
    Paint_DrawString_EN(50, 161, "WaveShare", &Font16, RED, WHITE);

    LCD_1IN28_Display(BlackImage);

    // LCD_1in28_test();

    int32_t dec = 2;
    while (1)
    {

        for (uint32_t i = 0; i < 240/dec; i++)
        {
            Paint_Clear(0xF81F);
            Paint_DrawString_EN(40, i*dec, "Jurstu Watch", &Font20, 0x000f, 0xF81F);
            //Paint_DrawString_EN(50, 161, "WaveShare", &Font16, RED, WHITE);

            LCD_1IN28_Display(BlackImage);
        }
        //   printf("asdf\r\n");
        //DEV_Delay_ms(100);
    }

    return 0;
}
