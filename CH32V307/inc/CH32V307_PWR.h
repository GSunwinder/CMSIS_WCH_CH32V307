//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V003_PWR.h
// Version     : V1.0
// Date        : 22-03-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V003 Power Control Header File.
//==============================================================================

#ifndef __CH32V003_PWR_H
#define __CH32V003_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V003.h"

typedef struct
{
    __IO uint32_t CTLR;
    __I  uint32_t CSR;
} PWR_TypeDef;

#define PWR         ((PWR_TypeDef *)PWR_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for PWR_CTLR register  ====================
#define PWR_CTLR_RAMLV      ((uint32_t)0x00100000) // RAM low voltage mode enable
#define PWR_CTLR_R30KVBAT   ((uint32_t)0x00080000) // 30K RAM VBAT power enable
#define PWR_CTLR_R2KVBAT    ((uint32_t)0x00040000) // 2K RAM VBAT power enable
#define PWR_CTLR_R30KSTY    ((uint32_t)0x00020000) // 30K RAM power in Standby
#define PWR_CTLR_R2KSTY     ((uint32_t)0x00010000) // 2K RAM power in Standby
#define PWR_CTLR_DBP        ((uint32_t)0x00001000) // Backup domain write enable

#define PWR_CTLR_PLS        ((uint32_t)0x000000E0) // PLS[2:0] bits (PVD Level Selection)
#define PWR_CTLR_PLS_270    ((uint32_t)0x00000000) // 2.37V rising edge / falling edge 2.29V
#define PWR_CTLR_PLS_290    ((uint32_t)0x00000020) // 2.55V rising edge / falling edge 2.46V
#define PWR_CTLR_PLS_315    ((uint32_t)0x00000040) // 2.63V rising edge / falling edge 2.55V
#define PWR_CTLR_PLS_330    ((uint32_t)0x00000060) // 2.76V rising edge / falling edge 2.67V
#define PWR_CTLR_PLS_350    ((uint32_t)0x00000080) // 2.87V rising edge / falling edge 2.78V
#define PWR_CTLR_PLS_370    ((uint32_t)0x000000A0) // 3.03V rising edge / falling edge 2.93V
#define PWR_CTLR_PLS_390    ((uint32_t)0x000000C0) // 3.18V rising edge / falling edge 3.06V
#define PWR_CTLR_PLS_420    ((uint32_t)0x000000E0) // 3.29V rising edge / falling edge 3.19V

#define PWR_CTLR_PVDE       ((uint32_t)0x00000010) // Power Voltage Detector Enable
#define PWR_CTLR_CSBF       ((uint32_t)0x00000008) // Clear standby flag
#define PWR_CTLR_CWUF       ((uint32_t)0x00000004) // Clear wakeup flag
#define PWR_CTLR_PDDS       ((uint32_t)0x00000002) // Power Down Deepsleep
#define PWR_CTLR_LPDS       ((uint32_t)0x00000001) // Voltage regulator mode selection

//===================  Bit definition for PWR_CSR register  ====================
#define PWR_CSR_EWUP        ((uint32_t)0x00000100) // WKUP pin enable
#define PWR_CSR_PVDO        ((uint32_t)0x00000004) // PVD Output
#define PWR_CSR_SBF         ((uint32_t)0x00000002) // Standby flag
#define PWR_CSR_WUF         ((uint32_t)0x00000001) // Wake-up flag

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_PWR_H
