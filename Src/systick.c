#include "systick.h"


static void SysTick_Delay1ms(void)
{
    while ((SysTick->CTRL & (1U << 16)) == 0U)
    {
    }
}


void SysTick_Init(uint32_t clock_hz)
{
    /*
     * 1 ms period
     *
     * number of clock cycles:
     *
     * clock_hz / 1000
     */

    SysTick->LOAD =
        (clock_hz / 1000U) - 1U;


    /*
     * Clear current counter.
     */

    SysTick->VAL = 0U;


    /*
     * CTRL:
     *
     * bit 0 = ENABLE
     * bit 2 = CLKSOURCE
     */

    SysTick->CTRL =
          (1U << 0)
        | (1U << 2);
}


void SysTick_DelayMs(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        SysTick_Delay1ms();
    }
}
