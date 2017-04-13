#include "led.h"

extern void sleep(__IO uint32_t ms);

void led_process_replacement() {
    static int led_status = 1;
    
    while (1) {
        if (led_status) {
            LED_GREEN_ON
            LED_RED_OFF
        } else {
            LED_RED_ON
            LED_GREEN_OFF
        }
        sleep(100);
        led_status ^= 1;
    }
}
