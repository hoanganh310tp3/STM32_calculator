#ifndef EXTI_H
#define EXTI_H

#include "stm32f446xx.h"
#include <stdint.h>

void EXTI_Init(void);
void EXTI0_IRQHandler(void);

#endif
