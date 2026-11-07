#include "nvic.h"

void NVIC_EnableIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    NVIC->ISER[register_index] = (1U << bit_position);
}

void NVIC_DisableIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    NVIC->ICER[register_index] = (1U << bit_position);
}

void NVIC_SetPendingIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    NVIC->ISPR[register_index] = (1U << bit_position);
}

void NVIC_ClearPendingIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    NVIC->ICPR[register_index] = (1U << bit_position);
}

uint8_t NVIC_GetPendingIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    return (NVIC->ISPR[register_index] >> bit_position) & 1U;
}

uint8_t NVIC_GetActiveIRQ(uint8_t IRQn)
{
    uint8_t register_index = IRQn / 32U;
    uint8_t bit_position = IRQn % 32U;

    return (NVIC->IABR[register_index] >> bit_position) & 1U;
}

void NVIC_SetPriority(uint8_t IRQn, uint8_t priority)
{
    if (priority > 15U)
    {
        return;
    }

    NVIC->IPR[IRQn] = (uint8_t)(priority << 4U);
}