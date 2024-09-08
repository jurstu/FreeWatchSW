#include "rtc.h"



void RTC_init()
{
    // do nothing? 
}

void RTC_get_time(uint8_t *h, uint8_t *m, uint8_t *s)
{
    uint8_t data[3];
    EXT_I2C_read_multi(DS3231_I2C_ADDR, DS3231_SECONDS_REG_ADDR, 3, data);

    if(data[2] & 0x40)
    {
        //12h system
        uint8_t plus_12 = (uint8_t)12 * ((data[5] & 0x20)>>5);
        *h = ((data[2]&0x10)>>4) * 10 + (data[2]&0x0F) + plus_12;
    }
    else
    {
        //24h system
        *h = ((data[2]&0x30)>>4)*10 + (data[2]&0x0F);
    }
    *m = ((data[1] & 0xF0)>>4)*10 + ((data[1] & 0x0F))*1;
    *s = ((data[0] & 0xF0)>>4)*10 + ((data[0] & 0x0F))*1;
}
void RTC_get_date(uint8_t *y, uint8_t *m, uint8_t *d)
{

}

//h in 24h system
void RTC_set_time(uint8_t h, uint8_t m, uint8_t s)
{
    s = s%60;
    m = m%60;
    h = h%24;

    uint8_t s_reg = ((s/10)&0x07)<<4 | ((s%10)&0x0F);

    uint8_t m_reg = ((m/10)&0x07)<<4 | ((m%10)&0x0F);

    uint8_t h_reg = 0x00 | (((h/10)&0x03)<<4 | ((h%10)&0x0F));



    uint8_t reg_write_seq[4] = {DS3231_SECONDS_REG_ADDR, s_reg, m_reg, h_reg};

    EXT_I2C_write_multi(DS3231_I2C_ADDR, 4, reg_write_seq);


}


void RTC_set_date(uint8_t y, uint8_t m, uint8_t d)
{

}

void RTC_set_12or24(uint8_t isIt24)
{

}


