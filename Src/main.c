#include "main.h"
#include "gpio.h"
#include "tim2.h"

int main(void)
{
    GPIO_Config_t led = {
        .port = GPIOA,
        .pin = 5,
        .mode = GPIO_MODE_OUTPUT,
        .output_type = GPIO_OUTPUT_PUSH_PULL,
        .speed = GPIO_SPEED_LOW,
        .pull = GPIO_NO_PULL
    };

    GPIO_Init(&led);

    // Assume TIM2 clock = 90 MHz
    TIM2_Init1Hz(90000000U);

    TIM2_Start();

    while (1)
    {
        TIM2_WaitUpdate();

        GPIO_TogglePin(GPIOA, 5);
    }
}