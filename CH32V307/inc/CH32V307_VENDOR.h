//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_VENDOR.h
// Version     : V1.0
// Date        : 04-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Vendor information Header File.
//==============================================================================

#ifndef __CH32V307_VENDOR_H
#define __CH32V307_VENDOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t FEATURE_SIGN;
} FEATURE_TypeDef;

#define FEATURE     ((EXTEN_TypeDef *)FEATURE_BASE)

typedef struct
{
    __I  uint16_t ESIG_FLACAP;
         uint16_t :16;
         uint32_t :32;
    __I  uint32_t ESIG_UNIID[3];
} ESIG_TypeDef;

#define ESIG        ((ESIG_TypeDef *)EXTEND_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//=================  Bit definition for FEATURE_SIGN register  =================
#define FEATURE_SIGN_VLEVEL ((uint32_t)0x00000001)

//=================  Bit definition for ESIG_FLACAP register  ==================
#define ESIG_FLACAP         ((uint16_t)0xFFFF) // Flash capacity in unit of Kbyte

//=================  Bit definition for ESIG_UNIID1 register  ==================
#define ESIG_UNIID1         ((uint32_t)0xFFFFFFFF) // Bits  0 to 31 of UID
#define ESIG_UNIID2         ((uint32_t)0xFFFFFFFF) // Bits 32 to 63 of UID
#define ESIG_UNIID3         ((uint32_t)0xFFFFFFFF) // Bits 64 to 95 of UID

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_VENDOR_H
