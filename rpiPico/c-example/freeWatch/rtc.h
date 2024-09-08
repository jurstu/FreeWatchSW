#ifndef __rtc
#define __rtc

#include "ext_i2c.h"


#define DS3231_SECONDS_REG_ADDR 0x00


#define DS3231_I2C_ADDR    0x68




void RTC_init();
void RTC_get_time(uint8_t *h, uint8_t *m, uint8_t *s);
void RTC_get_date(uint8_t *y, uint8_t *m, uint8_t *d);

void RTC_set_time(uint8_t h, uint8_t m, uint8_t s);
void RTC_set_date(uint8_t y, uint8_t m, uint8_t d);

void RTC_set_12or24(uint8_t isIt24);

#endif
