#include "BATT.h"

void BATT_init()
{
    pinMode(BATTERY_VOLTAGE_ADC_DATA, INPUT_PULLDOWN);
    analogReadResolution(12);
    analogSetPinAttenuation(BATTERY_VOLTAGE_ADC_DATA, ADC_ATTENDB_MAX);
    adcAttachPin(BATTERY_VOLTAGE_ADC_DATA);
}

uint16_t BATT_get_perc()
{
    uint32_t out = analogReadMilliVolts(BATTERY_VOLTAGE_ADC_DATA) * 2;
    out = UTIL_limit(out, 0, 100);

    return out;
}