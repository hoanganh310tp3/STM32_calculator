#include "rcc.h"

void RCC_EnableGPIOClock(GPIO_TypeDef *port)
{
    if (port == GPIOA)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    }
    else if (port == GPIOB)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    }
    else if (port == GPIOC)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    }
    else if (port == GPIOD)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    }
    else if (port == GPIOE)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    }
    else if (port == GPIOF)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
    }
    else if (port == GPIOG)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
    }
    else if (port == GPIOH)
    {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    }
}
