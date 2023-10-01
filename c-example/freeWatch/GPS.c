#include "GPS.h"



static PIO pio;
static uint sm;
static int8_t pio_irq;
static queue_t fifo;
static uint offset;
static uint32_t counter;
static bool work_done;


uint8_t *data;
char *temp_buff; 
uint16_t temp_buff_index;
typedef enum
{
    LOOKING_FOR_START = 0x01,
    LOOKING_FOR_END = 0x02,
    HANDLING_CMD = 0x04,
} GPS_handling_state;

GPS_handling_state state;


static void pio_irq_func(void) {
    while(!pio_sm_is_rx_fifo_empty(pio, sm)) {
        char c = uart_rx_program_getc(pio, sm);
        if (!queue_try_add(&fifo, &c)) {
            printf("fifo full\n\r");
        }
    }
}

static bool init_pio(const pio_program_t *program, PIO *pio_hw, uint *sm, uint *offset) {
    // Find a free pio
    *pio_hw = pio1;
    if (!pio_can_add_program(*pio_hw, program)) {
        *pio_hw = pio0;
        if (!pio_can_add_program(*pio_hw, program)) {
            *offset = -1;
            return false;
        }
    }
    *offset = pio_add_program(*pio_hw, program);
    // Find a state machine
    *sm = (int8_t)pio_claim_unused_sm(*pio_hw, false);
    if (*sm < 0) {
        return false;
    }
    return true;
}







/**
 * parses only whole NMEA messages
 * 
 * @param line data from nmea stream to be parsed
 * @param len length of data in line param
 */
static void GPS_parse_message(char *line, uint16_t len)
{
    switch (minmea_sentence_id(line, false))
    {
        case MINMEA_SENTENCE_RMC:
        {
            struct minmea_sentence_rmc frame;
            if (minmea_parse_rmc(&frame, line))
            {
                float lat = minmea_tocoord(&frame.latitude);
                float lon = minmea_tocoord(&frame.longitude);

                if (frame.valid)
                {
                    printf("lat %f, lon %f\n", lat, lon);
                           
                    // TODO pass information to center block
                }
            }
            else
            {

            }
        }
        break;

        case MINMEA_SENTENCE_GGA:
        {
            struct minmea_sentence_gga frame;
            //printf("line is %s\n", line);
            if (minmea_parse_gga(&frame, line))
            {
                struct minmea_time t = frame.time;
                printf("time is %d:%d:%d in UTC\n\r", t.hours, t.minutes, t.seconds);
                //INFORMATION_set(AIR_SAT_CNT, frame.satellites_tracked);
                // ESP_LOGI(tag, "GGA sats in use: %d", frame.satellites_tracked);
            }
            else
            {
                //ESP_LOGE(tag, "$xxGGA sentence is not parsed\n");
            }
        }
        break;

        case MINMEA_INVALID:
        {
            //ESP_LOGE(tag, "$xxxxx sentence is not valid\n");
        }
        break;

        default:
        {
            // ESP_LOGI(tag, "$xxxxx sentence is not parsed\n");
        }
        break;
    }
}




void GPS_init()
{
    queue_init(&fifo, 1, FIFO_SIZE);
    if (!init_pio(&uart_rx_program, &pio, &sm, &offset)) 
    {
        panic("failed to setup pio");
    }
    uart_rx_program_init(pio, sm, offset, PIO_RX_PIN, SERIAL_BAUD);
    
    // Find a free irq
    static_assert(PIO0_IRQ_1 == PIO0_IRQ_0 + 1 && PIO1_IRQ_1 == PIO1_IRQ_0 + 1, "");
    pio_irq = (pio == pio0) ? PIO0_IRQ_0 : PIO1_IRQ_0;
    if (irq_get_exclusive_handler(pio_irq)) {
        pio_irq++;
        if (irq_get_exclusive_handler(pio_irq)) {
            panic("All IRQs are in use");
        }
    }

    // Enable interrupt
    irq_add_shared_handler(pio_irq, pio_irq_func, PICO_SHARED_IRQ_HANDLER_DEFAULT_ORDER_PRIORITY); // Add a shared IRQ handler
    irq_set_enabled(pio_irq, true); // Enable the IRQ
    const uint irq_index = pio_irq - ((pio == pio0) ? PIO0_IRQ_0 : PIO1_IRQ_0); // Get index of the IRQ
    pio_set_irqn_source_enabled(pio, irq_index, pis_sm0_rx_fifo_not_empty + sm, true); // Set pio to tell us when the FIFO is NOT empty
    
    data = (uint8_t *)malloc(1024);
    temp_buff = (char *)malloc(MINMEA_MAX_SENTENCE_LENGTH);
    temp_buff_index = 0;

    state = LOOKING_FOR_START;

   
}


void GPS_handle_parse()
{
    int write_index = 0;
    while(!queue_is_empty(&fifo)) {
        char c;
        if (!queue_try_remove(&fifo, &c)) {
            //panic("fifo empty");
            break;
        }
        //putchar(c); // Display character in the console
        data[write_index] = c;
        write_index++;        
    }
    
    uint16_t len = write_index;
     
    for (uint16_t i = 0; i < len; i++)
    {
        uint8_t curr_byte = data[i];
        if (state == LOOKING_FOR_START && curr_byte == '$')
        {
            state = LOOKING_FOR_END;
        }

        if (state == LOOKING_FOR_END && curr_byte == '\n')
        {
            state = HANDLING_CMD;
        }
        else
        {
            if (temp_buff_index + 1 < MINMEA_MAX_SENTENCE_LENGTH)
            {
                temp_buff[temp_buff_index] = (char)curr_byte;
                temp_buff_index++;
            }
        }

        if (state == HANDLING_CMD)
        {
            temp_buff[temp_buff_index] = 0;
            //printf("message is %s\n", temp_buff);
            GPS_parse_message(temp_buff, temp_buff_index);
            temp_buff_index = 0;
            state = LOOKING_FOR_START;
        }
    }    
}







