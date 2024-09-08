
#include "I2C_center.h"





//std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

void I2C_init()
{

}


void I2C_get_bus(std::shared_ptr<Arduino_IIC_DriveBus> &dest)
{
    dest = IIC_Bus;
}




