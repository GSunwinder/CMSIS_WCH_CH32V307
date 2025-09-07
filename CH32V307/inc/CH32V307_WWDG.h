//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_WWDG.h
// Version     : V1.0
// Date        : 01-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Window Watchdog Header File.
//==============================================================================

#ifndef __CH32V307_WWDG_H
#define __CH32V307_WWDG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint16_t CTLR;
         uint16_t :16;
    __IO uint16_t CFGR;
         uint16_t :16;
    __IO uint16_t STATR;
         uint16_t :16;
} WWDG_TypeDef;

#define WWDG        ((WWDG_TypeDef *)WWDG_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for WWDG_CTLR register  ===================
#define WWDG_CTLR_WDGA          ((uint16_t)0x0080) // Activation bit
#define WWDG_CTLR_T             ((uint16_t)0x007F) // Self-decrement counter

//==================  Bit definition for WWDG_CFGR register  ===================
#define WWDG_CFGR_EWI           ((uint16_t)0x0200) // Early Wakeup Interrupt

#define WWDG_CFGR_WDGTB         ((uint16_t)0x0180) // Clock division selection
#define WWDG_CFGR_WDGTB_Div1    ((uint16_t)0x0000) // Not divided, HCLK/4096
#define WWDG_CFGR_WDGTB_Div2    ((uint16_t)0x0080) // Divded by 2, HCLK/4096/2
#define WWDG_CFGR_WDGTB_Div4    ((uint16_t)0x0100) // Divded by 4, HCLK/4096/4
#define WWDG_CFGR_WDGTB_Div8    ((uint16_t)0x0180) // Divded by 8, HCLK/4096/8

#define WWDG_CFGR_W             ((uint16_t)0x007F) // Window value

//==================  Bit definition for WWDG_STATR register  ===================
#define WWDG_STATR_EWIF         ((uint16_t)0x0001) // Early Wakeup Interrupt Flag

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_WWDG_H
