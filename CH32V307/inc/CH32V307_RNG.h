//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_RNG.h
// Version     : V1.0
// Date        : 11-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Random Number Generator register Header File.
//==============================================================================

#ifndef __CH32V307_RNG_H
#define __CH32V307_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t SR;
    __I  uint32_t DR;
} RNG_TypeDef;

#define RNG     ((RNG_TypeDef *)RNG_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//====================  Bit definition for RNG_CR register  ====================
#define RNG_CR_IE       ((uint32_t)0x00000008) // Interrupt enable
#define RNG_CR_RNGEN    ((uint32_t)0x00000004) // Enable random number generator

//====================  Bit definition for RNG_SR register  ====================
#define RNG_SR_SEIS     ((uint32_t)0x00000001) // Seed error interrupt status
#define RNG_SR_CEIS     ((uint32_t)0x00000001) // Clock error interrupt status
#define RNG_SR_SECS     ((uint32_t)0x00000001) // Seed error current status
#define RNG_SR_CECS     ((uint32_t)0x00000001) // Clock error current status
#define RNG_SR_DRDY     ((uint32_t)0x00000001) // Data ready

//====================  Bit definition for RNG_DR register  ====================
#define RNG_DR          ((uint32_t)0xFFFFFFFF) // 32-bit random number

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_RNG_H
