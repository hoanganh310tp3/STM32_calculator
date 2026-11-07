#include "exti.h"
#include "nvic.h"

void EXTI_Init(void)
{
    // Enable clock cho SYSCFG
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // EXTI0 source = GPIOA
    SYSCFG->EXTICR[0] &= ~(0xFU << 0);

    // Falling edge
    EXTI->FTSR |= (1U << 0);

    // Not using rising edge
    EXTI->RTSR &= ~(1U << 0);

    // Clear pending old flag
    EXTI->PR = (1U << 0);

    // Enable EXTI line 0
    EXTI->IMR |= (1U << 0);

    // Configure NVIC
    NVIC_EnableIRQ(6);
    NVIC_SetPriority(6, 2);
}

volatile uint8_t button_event = 0;

void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & (1U << 0))
    {
        EXTI->PR = (1U << 0);

        button_event = 1;
    }
}