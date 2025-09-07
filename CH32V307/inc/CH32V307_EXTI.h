//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_EXTI.h
// Version     : V1.0
// Date        : 22-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 External Interrupt/Event Controller Header File.
//==============================================================================

#ifndef __CH32V307_EXTI_H
#define __CH32V307_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t INTENR;
    __IO uint32_t EVENR;
    __IO uint32_t RTENR;
    __IO uint32_t FTENR;
    __IO uint32_t SWIEVR;
    __O  uint32_t INTFR;
} EXTI_TypeDef;

#define EXTI    ((EXTI_TypeDef *)EXTI_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for EXTI_INTENR register  =================
#define EXTI_INTENR(EventNumber)    ((uint32_t)(0x1 << EventNumber))

//==================  Bit definition for EXTI_EVENR register  ==================
#define EXTI_EVENR(EventNumber)     ((uint32_t)(0x1 << EventNumber))

//==================  Bit definition for EXTI_RTENR register  ==================
#define EXTI_RTENR(EventNumber)     ((uint32_t)(0x1 << EventNumber))

//==================  Bit definition for EXTI_FTENR register  ==================
#define EXTI_FTENR(EventNumber)     ((uint32_t)(0x1 << EventNumber))

//==================  Bit definition for EXTI_SWIEVR register  =================
#define EXTI_SWIEVR(EventNumber)    ((uint32_t)(0x1 << EventNumber))

//==================  Bit definition for EXTI_INTFR register  ==================
#define EXTI_INTF(EventNumber)      ((uint32_t)(0x1 << EventNumber))

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_EXTI_H
