#include "GPS.h"



static PIO pio;
static uint sm;
static int8_t pio_irq;
static queue_t fifo;
static uint offset;
static uint32_t counter;
static bool work_done;


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
   
}


void GPS_handle_parse()
{
    while(!queue_is_empty(&fifo)) {
        char c;
        if (!queue_try_remove(&fifo, &c)) {
            //panic("fifo empty");
            break;
        }
        putchar(c); // Display character in the console
    }
}