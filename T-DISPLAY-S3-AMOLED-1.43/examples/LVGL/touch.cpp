#include "touch.h"

void TOUCH_FT3168_interrupt(void);


std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);
std::unique_ptr<Arduino_IIC> FT3168(new Arduino_FT3x68(IIC_Bus, FT3168_DEVICE_ADDRESS, DRIVEBUS_DEFAULT_VALUE, TP_INT, TOUCH_FT3168_interrupt));
static int touch_pressed = 0;
static int touch_x = 0;
static int touch_y = 0;


void TOUCH_init()
{
    while (FT3168->begin() == false)
    {
        Serial.println("FT3168 initialization fail");
        delay(2000);
    }
    Serial.println("FT3168 initialization successfully");

}

void TOUCH_get_status(int *x, int *y, int *pressed)
{
    *x = touch_x;
    *y = touch_y;
    *pressed = touch_pressed;
}


void TOUCH_check_touch()
{
    if (FT3168->IIC_Interrupt_Flag == true)
    {
        FT3168->IIC_Interrupt_Flag = false;
        touch_x = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_X);
        touch_y = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_COORDINATE_Y);
        uint8_t fingers_number = FT3168->IIC_Read_Device_Value(FT3168->Arduino_IIC_Touch::Value_Information::TOUCH_FINGER_NUMBER);
        touch_pressed = fingers_number > 0;
    }
}

void TOUCH_FT3168_interrupt(void)
{
    FT3168->IIC_Interrupt_Flag = true;
}


