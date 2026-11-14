#include "tim2.h"
#include "stm32f446xx.h"
#include "rcc.h"
#include "nvic.h"

void TIM2_Init1Hz(uint32_t timer_clock_hz)
{
    RCC_EnableTIM2Clock();

    TIM2->CR1 &= ~(1U << 0);

    TIM2->CNT = 0U;

    TIM2->PSC = (timer_clock_hz / 10000U) - 1U;

    TIM2->ARR = 9999U;

    TIM2->EGR = (1U << 0);

    TIM2->SR &= ~(1U << 0);
}

void TIM2_EnableUpdateInterrupt(void)
{
    // Clear pending old flag on timer
    TIM2->SR &= ~(1U << 0);

    // Enable Update Interrupt
    TIM2->DIER |= (1U << 0);

    // Config NVIC
    NVIC_SetPriority(TIM2_IRQn, 2);
    NVIC_ClearPendingIRQ(TIM2_IRQn);
    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_ClearUpdateFlag(void)
{
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