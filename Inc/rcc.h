#ifndef RCC_H
#define RCC_H

#include "stm32f446xx.h"

void RCC_EnableGPIOClock(GPIO_TypeDef *port);
void RCC_EnableTIM2Clock(void);

#endif
