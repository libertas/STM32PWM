#include "stm32f10x_flash.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_tim.h"
#include "misc.h"

void RCC_Config(void);
void USART_Config(uint32_t baudRate);
void LED_Config(void);
void Timer2_Config(void);
void GPIO_Config(void);
