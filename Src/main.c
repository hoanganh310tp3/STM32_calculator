#include "main.h"
#include "gpio.h"
#include "systick.h"


int main(void)
{
    /*
     * LED
     *
     * Nucleo-F446RE:
     * LD2 -> PA5
     */
    GPIO_Config_t led =
    {
        .port = GPIOA,
        .pin = 5,
        .mode = GPIO_MODE_OUTPUT,
        .output_type = GPIO_OUTPUT_PUSH_PULL,
        .speed = GPIO_SPEED_LOW,
        .pull = GPIO_NO_PULL
    };

    /*
     * External button
     *
     * PA0 --- button --- GND
     *
     * Internal pull-up
     */
    GPIO_Config_t button =
    {
        .port = GPIOA,
        .pin = 0,
        .mode = GPIO_MODE_INPUT,
        .output_type = GPIO_OUTPUT_PUSH_PULL,
        .speed = GPIO_SPEED_LOW,
        .pull = GPIO_PULL_UP
    };

    /*
     * Initialize GPIOs
     */
    GPIO_Init(&led);
    GPIO_Init(&button);

    /*
     * Initialize SysTick.
     *
     * Assuming CPU clock = 180 MHz.
     */

    SysTick_Init(180000000U);

    /*
     * Main loop
     */

    while (1)
    {
        if (GPIO_ButtonPressed(GPIOA, 0))
        {
            GPIO_TogglePin(GPIOA, 5);
        }
    }
}
