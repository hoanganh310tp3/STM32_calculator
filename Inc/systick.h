#ifndef SYSTICK_H
#define SYSTICK_H

#include "stm32f446xx.h"
#include <stdint.h>

void SysTick_Init(uint32_t clock_hz);
void SysTick_DelayMs(uint32_t ms);

#endif
