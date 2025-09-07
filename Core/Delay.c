//========================================================  (C) COPYRIGHT  =====
// File Name   : Delay.c
// Version     : V1.0
// Date        : 15-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : Delay function source file
//==============================================================================

#include "stdint.h"
#include "Delay.h"

uint32_t systick_us;

void Delay_Init(uint32_t sysclk)
{
    SysTick->CTLR = STK_STCLK | STK_STE;
    if ((SysTick->CTLR & STK_STCLK) != STK_STCLK)
        systick_us = sysclk / 8000000;
    else
        systick_us = sysclk / 1000000;
}

#if 0
void Delay_us(uint32_t delay)
{
    uint64_t start, stop;

    start = (uint64_t)SysTick->CNTL;
    start |= SysTick->CNTH << 32;
    stop = start + ((delay-1) * systick_us);
    while ((SysTick->CNTH << 32 + SysTick->CNTL) < stop);
}
#else
// delay >= 3 uS
void Delay_us(uint32_t delay)
{
    uint64_t start, stop;

    start = (uint64_t)SysTick->CNTL;
    start |= SysTick->CNTH << 32;
    SysTick->SR = 0;
    stop = start + ((delay - 1) * systick_us);
    SysTick->CMPLR = (uint32_t)(stop & 0x00000000FFFFFFFF);
    SysTick->CMPHR = (uint32_t)(stop >> 32);
    while ((SysTick->SR & STK_CNTIF) != STK_CNTIF);
}
#endif
