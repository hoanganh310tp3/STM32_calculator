#include "gpio.h"
#include "rcc.h"
#include "systick.h"

void GPIO_Init(GPIO_Config_t *config)
{
    uint8_t pin = config->pin;

    /*
     * Enable GPIO peripheral clock
     */
    RCC_EnableGPIOClock(config->port);


    /*
     * MODER
     *
     * Each GPIO pin uses 2 bits.
     *
     * pin 0 -> bits [1:0]
     * pin 1 -> bits [3:2]
     * pin 2 -> bits [5:4]
     */

    config->port->MODER &= ~(3U << (pin * 2U));

    config->port->MODER |=
        ((uint32_t)config->mode << (pin * 2U));


    /*
     * OTYPER
     *
     * Each pin uses 1 bit.
     */

    config->port->OTYPER &= ~(1U << pin);

    config->port->OTYPER |=
        ((uint32_t)config->output_type << pin);


    /*
     * OSPEEDR
     *
     * Each pin uses 2 bits.
     */

    config->port->OSPEEDR &= ~(3U << (pin * 2U));

    config->port->OSPEEDR |=
        ((uint32_t)config->speed << (pin * 2U));


    /*
     * PUPDR
     *
     * Each pin uses 2 bits.
     */

    config->port->PUPDR &= ~(3U << (pin * 2U));

    config->port->PUPDR |=
        ((uint32_t)config->pull << (pin * 2U));
}

void GPIO_SetPin(GPIO_TypeDef *port, uint8_t pin)
{
    port->BSRR = (1U << pin);
}

void GPIO_ResetPin(GPIO_TypeDef *port, uint8_t pin)
{
    port->BSRR = (1U << (pin + 16U));
}

void GPIO_WritePin(GPIO_TypeDef *port,
                   uint8_t pin,
                   GPIO_PinState_t state)
{
    if (state == GPIO_PIN_SET)
    {
        GPIO_SetPin(port, pin);
    }
    else
    {
        GPIO_ResetPin(port, pin);
    }
}

void GPIO_TogglePin(GPIO_TypeDef *port, uint8_t pin)
{
    if (port->ODR & (1U << pin))
    {
        GPIO_ResetPin(port, pin);
    }
    else
    {
        GPIO_SetPin(port, pin);
    }
}

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef *port,
                              uint8_t pin)
{
    if (port->IDR & (1U << pin))
    {
        return GPIO_PIN_SET;
    }

    return GPIO_PIN_RESET;
}

uint8_t GPIO_ButtonPressed(GPIO_TypeDef *port,
                           uint8_t pin)
{
    static GPIO_PinState_t previous_state =
        GPIO_PIN_SET;

    GPIO_PinState_t current_state =
        GPIO_ReadPin(port, pin);


    if ((previous_state == GPIO_PIN_SET) &&
        (current_state == GPIO_PIN_RESET))
    {
        SysTick_DelayMs(20);

        if (GPIO_ReadPin(port, pin) ==
            GPIO_PIN_RESET)
        {
            previous_state = GPIO_PIN_RESET;

            return 1;
        }
    }


    previous_state = current_state;

    return 0;
}
