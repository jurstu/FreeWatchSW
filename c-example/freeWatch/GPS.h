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


#define SERIAL_BAUD 9600
#define PIO_RX_PIN 18
#define FIFO_SIZE 256

void GPS_init();

void GPS_handle_parse();

#endif
