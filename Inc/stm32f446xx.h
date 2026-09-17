#ifndef STM32F446XX_H
#define STM32F446XX_H

#include <stdint.h>

/* ============================================================
 * RCC
 * ============================================================ */

#define RCC_BASE    0x40023800UL

typedef struct
{
    volatile uint32_t CR;          // 0x00
    volatile uint32_t PLLCFGR;     // 0x04
    volatile uint32_t CFGR;        // 0x08
    volatile uint32_t CIR;         // 0x0C
    volatile uint32_t AHB1RSTR;    // 0x10
    volatile uint32_t AHB2RSTR;    // 0x14
    volatile uint32_t AHB3RSTR;    // 0x18
    uint32_t RESERVED0;            // 0x1C
    volatile uint32_t APB1RSTR;    // 0x20
    volatile uint32_t APB2RSTR;    // 0x24
    uint32_t RESERVED1[2];         // 0x28, 0x2C
    volatile uint32_t AHB1ENR;     // 0x30
    volatile uint32_t AHB2ENR;     // 0x34
    volatile uint32_t AHB3ENR;     // 0x38
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *)RCC_BASE)


/* ============================================================
 * GPIO
 * ============================================================ */

typedef struct
{
    volatile uint32_t MODER;       // 0x00
    volatile uint32_t OTYPER;      // 0x04
    volatile uint32_t OSPEEDR;     // 0x08
    volatile uint32_t PUPDR;       // 0x0C
    volatile uint32_t IDR;         // 0x10
    volatile uint32_t ODR;         // 0x14
    volatile uint32_t BSRR;        // 0x18
    volatile uint32_t LCKR;        // 0x1C
    volatile uint32_t AFR[2];      // 0x20, 0x24
} GPIO_TypeDef;


/* GPIO base addresses */

#define GPIOA_BASE  0x40020000UL
#define GPIOB_BASE  0x40020400UL
#define GPIOC_BASE  0x40020800UL
#define GPIOD_BASE  0x40020C00UL
#define GPIOE_BASE  0x40021000UL
#define GPIOF_BASE  0x40021400UL
#define GPIOG_BASE  0x40021800UL
#define GPIOH_BASE  0x40021C00UL

#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)


/* ============================================================
 * RCC AHB1ENR bits
 * ============================================================ */

#define RCC_AHB1ENR_GPIOAEN    (1U << 0)
#define RCC_AHB1ENR_GPIOBEN    (1U << 1)
#define RCC_AHB1ENR_GPIOCEN    (1U << 2)
#define RCC_AHB1ENR_GPIODEN    (1U << 3)
#define RCC_AHB1ENR_GPIOEEN    (1U << 4)
#define RCC_AHB1ENR_GPIOFEN    (1U << 5)
#define RCC_AHB1ENR_GPIOGEN    (1U << 6)
#define RCC_AHB1ENR_GPIOHEN    (1U << 7)


/* ============================================================
 * SysTick
 * ============================================================ */

#define SYSTICK_BASE    0xE000E010UL

typedef struct
{
    volatile uint32_t CTRL;       // 0x00
    volatile uint32_t LOAD;       // 0x04
    volatile uint32_t VAL;        // 0x08
    volatile uint32_t CALIB;      // 0x0C
} SysTick_TypeDef;

#define SysTick ((SysTick_TypeDef *)SYSTICK_BASE)

#endif
