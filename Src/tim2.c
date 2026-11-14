#include "tim2.h"
#include "stm32f446xx.h"
#include "rcc.h"

#define TIM2_COUNTER_FREQ 10000U

void TIM2_Init1Hz(uint32_t timer_clock_hz)
{
    RCC_EnableTIM2Clock();

    // Stop timer before config
    TIM2->CR1 &= ~(1U << 0);

    // Set counter to 0
    TIM2->CNT = 0U;

    // Counter clock = 10 kHz
    TIM2->PSC = (timer_clock_hz / TIM2_COUNTER_FREQ) - 1U;

    // Count 10000 tick to update event 1 Hz
    TIM2->ARR = 9999U;

    // Load value PSC/ARR
    TIM2->EGR = (1U << 0);

    // Delete UIF due to recent update generation
    TIM2->SR &= ~(1U << 0);
}

void TIM2_Start(void)
{
    TIM2->CR1 |= (1U << 0);
}

void TIM2_Stop(void)
{
    TIM2->CR1 &= ~(1U << 0);
}

void TIM2_WaitUpdate(void)
{
    while ((TIM2->SR & (1U << 0)) == 0U)
    {
    }

    // Clear update flag
    TIM2->SR &= ~(1U << 0);
}