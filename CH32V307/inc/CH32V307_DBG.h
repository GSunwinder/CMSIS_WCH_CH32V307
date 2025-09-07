//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_DBG.h
// Version     : V1.0
// Date        : 05-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Debug support Header File.
//==============================================================================

#ifndef __CH32V307_DBG_H
#define __CH32V307_DBG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

// Debug MCU
typedef struct
{
    __IO uint32_t DBGMCU_CR;
} DBGMCU_TypeDef;

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for DBGMCU_CR register  ===================
#define DBGMCU_TIM10_STOP       ((uint32_t)0x00800000) // Timer10 debug stop
#define DBGMCU_TIM9_STOP        ((uint32_t)0x00400000) // Timer9 debug stop
#define DBGMCU_CAN2_STOP        ((uint32_t)0x00200000) // CAN2 debug stop
#define DBGMCU_CAN1_STOP        ((uint32_t)0x00100000) // CAN1 debug stop
#define DBGMCU_TIM8_STOP        ((uint32_t)0x00080000) // Timer8 debug stop
#define DBGMCU_TIM7_STOP        ((uint32_t)0x00040000) // Timer7 debug stop
#define DBGMCU_TIM6_STOP        ((uint32_t)0x00020000) // Timer6 debug stop
#define DBGMCU_TIM5_STOP        ((uint32_t)0x00010000) // Timer5 debug stop
#define DBGMCU_TIM4_STOP        ((uint32_t)0x00008000) // Timer4 debug stop
#define DBGMCU_TIM3_STOP        ((uint32_t)0x00004000) // Timer3 debug stop
#define DBGMCU_TIM2_STOP        ((uint32_t)0x00002000) // Timer2 debug stop
#define DBGMCU_TIM1_STOP        ((uint32_t)0x00001000) // Timer1 debug stop
#define DBGMCU_I2C1_STOP        ((uint32_t)0x00000200) // WWDG debug stop
#define DBGMCU_I2C2_TIMEOUT     ((uint32_t)0x00000200) // WWDG debug stop
#define DBGMCU_WWDG_TIMEOUT     ((uint32_t)0x00000200) // WWDG debug stop
#define DBGMCU_IWDG_STOP        ((uint32_t)0x00000100) // IWDG debug stop
#define DBGMCU_STANDBY          ((uint32_t)0x00000004) // Debug standby mode
#define DBGMCU_STOP             ((uint32_t)0x00000002) // Debug stop mode
#define DBGMCU_SLEEP            ((uint32_t)0x00000001) // Debug sleep mode

#ifdef __cplusplus
}
#endif

#endif /* __CH32V307_DBG_H */
