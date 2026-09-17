#ifndef GPIO_H
#define GPIO_H

#include "stm32f446xx.h"
#include <stdint.h>


typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1
} GPIO_PinState_t;


typedef enum
{
    GPIO_MODE_INPUT  = 0,
    GPIO_MODE_OUTPUT = 1
} GPIO_Mode_t;


typedef enum
{
    GPIO_OUTPUT_PUSH_PULL  = 0,
    GPIO_OUTPUT_OPEN_DRAIN = 1
} GPIO_OutputType_t;


typedef enum
{
    GPIO_SPEED_LOW       = 0,
    GPIO_SPEED_MEDIUM    = 1,
    GPIO_SPEED_HIGH      = 2,
    GPIO_SPEED_VERY_HIGH = 3
} GPIO_Speed_t;


typedef enum
{
    GPIO_NO_PULL  = 0,
    GPIO_PULL_UP  = 1,
    GPIO_PULL_DOWN = 2
} GPIO_Pull_t;


typedef struct
{
    GPIO_TypeDef *port;
    uint8_t pin;

    GPIO_Mode_t mode;
    GPIO_OutputType_t output_type;
    GPIO_Speed_t speed;
    GPIO_Pull_t pull;

} GPIO_Config_t;


/* GPIO initialization */

void GPIO_Init(GPIO_Config_t *config);


/* Output */

void GPIO_SetPin(GPIO_TypeDef *port, uint8_t pin);
void GPIO_ResetPin(GPIO_TypeDef *port, uint8_t pin);
void GPIO_WritePin(GPIO_TypeDef *port,
                   uint8_t pin,
                   GPIO_PinState_t state);

void GPIO_TogglePin(GPIO_TypeDef *port, uint8_t pin);


/* Input */

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef *port,
                              uint8_t pin);


/* Button */

uint8_t GPIO_ButtonPressed(GPIO_TypeDef *port,
                           uint8_t pin);

#endif
