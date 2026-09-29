#include "exti.h"

#define NVIC_ISER0 (*(volatile uint32_t *)0xE000E100UL)

void EXTI_Init(void)
{
    /*
     * Select GPIOA as source for EXTI0.
     *
     * EXTICR[0] bits [3:0]
     *
     * 0000 = GPIOA
     */

    SYSCFG->EXTICR[0] &= ~(0xFU << 0);


    /*
     * Enable EXTI0 interrupt.
     */

    EXTI->IMR |= (1U << 0);


    /*
     * Enable falling-edge trigger.
     */

    EXTI->FTSR |= (1U << 0);


    /*
     * Enable EXTI0 IRQ in NVIC.
     *
     * EXTI0_IRQn = 6
     */

    NVIC_ISER0 |= (1U << 6);
}

void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & (1U << 0))
    {
        /* Clear pending flag */
        EXTI->PR = (1U << 0);

        /* Button event */
        GPIO_TogglePin(GPIOA, 5);
    }
}
