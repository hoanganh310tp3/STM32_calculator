#include "main.h"
#include "gpio.h"
#include "tim2.h"

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & (1U << 0))
    {
        TIM2_ClearUpdateFlag();

        GPIO_TogglePin(GPIOA, 5);
    }
}

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

    // Assume TIM2 clock 16 MHz
    TIM2_Init1Hz(16000000U);

    TIM2_EnableUpdateInterrupt();

    TIM2_Start();

    while (1)
    {
        // CPU do not need to poll timer
    }
}