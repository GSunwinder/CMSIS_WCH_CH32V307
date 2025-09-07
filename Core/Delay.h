//========================================================  (C) COPYRIGHT  =====
// File Name   : Delay.c
// Version     : V1.0
// Date        : 15-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : Delay function header file
//==============================================================================

#ifndef __DELAY_H__
#define __DELAY_H__

#include "RISC-V_QingKe_V4F.h"

void Delay_Init(uint32_t sysclk);
void Delay_us(uint32_t delay);

#endif /* __DELAY_H__ */
