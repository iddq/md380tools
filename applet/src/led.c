#include "led.h"

//extern void md380_sleep(__IO uint32_t ms);

void __attribute__((optimize("O0"))) led_process_replacement() {
    static int led_status = 1;
    
    while (1) {
        if (led_status) {
            LED_GREEN_ON
            LED_RED_OFF
        } else {
            LED_RED_ON
            LED_GREEN_OFF
        }

        led_status ^= 1;

        //md380_sleep(333); // Why the audio doesn't work without sleep?

//ROM:080A1086 64 20                       MOVS            R0, #0x64
//ROM:080A1088 92 F7 14 FF                 BL              sub_8033EB4
//ROM:080A108C E0 E7                       B               loc_80A1050

        ((void (*)(uint32_t))0x08033EB4+1)(333); // calling the sleep in different way. Why does the compiler place blx into the code?.

//ROM:080A1084 1A 60                       STR             R2, [R3]
//ROM:080A1086 04 4B                       LDR             R3, =sub_8033EB4
//ROM:080A1088 64 20                       MOVS            R0, #0x64
//ROM:080A108A 98 47                       BLX             R3 ; sub_8033EB4
//ROM:080A108C E0 E7                       B               loc_80A1050
    }
}
