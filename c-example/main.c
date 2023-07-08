#include "LCD_Test.h" //Examples

#include "LCD_Test.h"
#include "LCD_1in28.h"
#include "QMI8658.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "CST816S.h"
void DEV_init()
{
    if (DEV_Module_Init() != 0)
    {
        return -1;
    }
    printf("LCD_1in28_test Demo\r\n");
    LCD_1IN28_Init(HORIZONTAL);
    // 5 6 5
    LCD_1IN28_Clear(0xF81F);
    // LCD_1IN28_Clear(0xFFFF);

    DEV_SET_PWM(100);
}

void SUBDEV_init()
{
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
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(WHITE);
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
