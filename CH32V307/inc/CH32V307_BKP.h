//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_BKP.h
// Version     : V1.0
// Date        : 08-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Backup register Header File.
//==============================================================================

#ifndef __CH32V307_BKP_H
#define __CH32V307_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint16_t DATAR;
         uint16_t :16;
} BKPD_TypeDef;

typedef struct
{
         uint16_t :16;
         uint16_t :16;
         BKPD_TypeDef BANK1[10];
         uint16_t :16;
    __IO uint16_t OCTLR;
         uint16_t :16;
    __IO uint16_t TPCTLR;
         uint16_t :16;
    __IO uint16_t TPCSR;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         BKPD_TypeDef BANK2[32];
} BKP_TypeDef;

#define BKP     ((BKP_TypeDef *)BKP_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for BKP_OCTLR register  ===================
#define BKP_ASOS        ((uint16_t)0x0200) // TAMPER pin alarm/second selection
#define BKP_ASOE        ((uint16_t)0x0100) // TAMPER pin output enable
#define BKP_CCO         ((uint16_t)0x0080) // Calibration clock output selection
#define BKP_CAL         ((uint16_t)0x007F) // Calibration value register

//==================  Bit definition for BKP_TPCTLR register  ===================
#define BKP_TPAL        ((uint16_t)0x0002) // TAMPER pin active level
#define BKP_TPE         ((uint16_t)0x0001) // TAMPER pin function enable

//==================  Bit definition for BKP_TPCSR register  ===================
#define BKP_TIF         ((uint16_t)0x0020) // TAMPER interrupt flag
#define BKP_TEF         ((uint16_t)0x0010) // TAMPER event flag
#define BKP_TPIE        ((uint16_t)0x0004) // TAMPER interrupt enable
#define BKP_CTI         ((uint16_t)0x0002) // Clear TAMPER detection interrupt
#define BKP_CTE         ((uint16_t)0x0001) // Clear TAMPER detection event

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_BKP_H
