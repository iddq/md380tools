#include "stm32f4xx_gpio.h"

#define LED_GREEN_ON  GPIO_SetBits(GPIOE, GPIO_Pin_0);
#define LED_GREEN_OFF GPIO_ResetBits(GPIOE, GPIO_Pin_0);
#define LED_RED_ON    GPIO_SetBits(GPIOE, GPIO_Pin_1);
#define LED_RED_OFF   GPIO_ResetBits(GPIOE, GPIO_Pin_1);
