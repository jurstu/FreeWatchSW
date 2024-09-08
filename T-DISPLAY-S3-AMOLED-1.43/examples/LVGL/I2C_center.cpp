
#include "I2C_center.h"





//std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus = std::make_shared<Arduino_HWIIC>(IIC_SDA, IIC_SCL, &Wire);

extern std::shared_ptr<Arduino_IIC_DriveBus> IIC_Bus;
void I2C_init()
{

}


std::shared_ptr<Arduino_IIC_DriveBus> I2C_get_bus()
{
    return IIC_Bus;
}




