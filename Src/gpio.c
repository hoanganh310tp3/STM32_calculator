#include "gpio.h"
#include "rcc.h"


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
