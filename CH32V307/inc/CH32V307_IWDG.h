//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_IWDG.h
// Version     : V1.0
// Date        : 01-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Independent Watchdog Header File.
//==============================================================================

#ifndef __CH32V307_IWDG_H
#define __CH32V307_IWDG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __O  uint16_t CTLR;
         uint16_t :16;
    __IO uint16_t PSCR;
         uint16_t :16;
    __IO uint16_t RLDR;
         uint16_t :16;
    __I  uint16_t STATR;
         uint16_t :16;
} IWDG_TypeDef;

#define IWDG        ((IWDG_TypeDef *)IWDG_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for IWDG_CTLR register  ===================
#define IWDG_KEY        ((uint16_t)0xFFFF) // Key value (write only, read 0000h)
#define IWDG_KEY_LOAD   ((uint16_t)0xAAAA) // Loading of the RLDR reg
#define IWDG_KEY_MODIF  ((uint16_t)0x5555) // Allow modif. PSCR and RLDR reg's
#define IWDG_KEY_START  ((uint16_t)0xCCCC) // Start the watchdog (if enable)

//==================  Bit definition for IWDG_PSCR register  ===================
#define IWDG_PR         ((uint16_t)0x0007) // PR[2:0] (Prescaler divider)
#define IWDG_PR_Div4    ((uint16_t)0x0000)
#define IWDG_PR_Div8    ((uint16_t)0x0001)
#define IWDG_PR_Div16   ((uint16_t)0x0002)
#define IWDG_PR_Div32   ((uint16_t)0x0003)
#define IWDG_PR_Div64   ((uint16_t)0x0004)
#define IWDG_PR_Div128  ((uint16_t)0x0005)
#define IWDG_PR_Div256  ((uint16_t)0x0006)
#define IWDG_PR_Div256_ ((uint16_t)0x0007)

//==================  Bit definition for IWDG_RLDR register  ===================
#define IWDG_RL         ((uint16_t)0x0FFF) // Watchdog counter reload value

//==================  Bit definition for IWDG_STATR register  ==================
#define IWDG_RVU        ((uint16_t)0x0002) // Watchdog counter reload value update
#define IWDG_PVU        ((uint16_t)0x0001) // Watchdog prescaler value update

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_IWDG_H
