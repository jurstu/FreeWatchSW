#ifndef __gps
#define __gps

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "pico/util/queue.h"
#include "hardware/pio.h"
#include "hardware/uart.h"
#include "uart_rx.pio.h"
#include "minmea.h"
#include "information.h"
#include "math.h"


#define SERIAL_BAUD 9600
#define PIO_RX_PIN 18
#define FIFO_SIZE 256

void GPS_init();
void GPS_handle_parse();

float GPS_CALC_ctt(float lat1, float lon1, float lat2, float lon2);
float GPS_CALC_dtt(float lat1, float lon1, float lat2, float lon2);

#endif
