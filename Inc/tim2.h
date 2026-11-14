#ifndef TIM2_H
#define TIM2_H

#include <stdint.h>

void TIM2_Init1Hz(uint32_t timer_clock_hz);
void TIM2_Start(void);
void TIM2_Stop(void);

void TIM2_EnableUpdateInterrupt(void);
void TIM2_ClearUpdateFlag(void);

#endif