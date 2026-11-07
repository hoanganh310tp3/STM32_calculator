#ifndef NVIC_H
#define NVIC_H

#include "stm32f446xx.h"
#include <stdint.h>

void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);

void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);

uint8_t NVIC_GetPendingIRQ(IRQn_Type IRQn);
uint8_t NVIC_GetActiveIRQ(IRQn_Type IRQn);

void NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority);

#endif