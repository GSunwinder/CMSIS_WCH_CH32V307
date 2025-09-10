//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_CRC.h
// Version     : V1.0
// Date        : 10-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 CRC register Header File.
//==============================================================================

#ifndef __CH32V307_CRC_H
#define __CH32V307_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t DATAR;
    __IO uint8_t IDATAR;
         uint8_t :8;
         uint16_t :16;
    __IO uint32_t CTLR;
} CRC_TypeDef;

#define CRC     ((CRC_TypeDef *)CRC_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for CRC_CTLR register  ===================
#define CRC_RST     ((uint32_t)0x00000001) // CRC calculation unit reset control

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_CRC_H
