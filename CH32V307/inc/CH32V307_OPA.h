//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_OPA.h
// Version     : V1.0
// Date        : 11-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Opeational amplifier register Header File.
//==============================================================================

#ifndef __CH32V307_OPA_H
#define __CH32V307_OPA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
         uint32_t :32;
    __IO uint32_t CTLR;
} OPA_TypeDef;

#define OPA     ((OPA_TypeDef *)OPA_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for OPA_CTLR register  ===================
#define OPA_PSEL4   ((uint32_t)0x00008000) // OPA4 positive input selection
#define OPA_NSEL4   ((uint32_t)0x00004000) // OPA4 negative input selection
#define OPA_MOD4    ((uint32_t)0x00002000) // OPA4 output channel selection
#define OPA_EN4     ((uint32_t)0x00001000) // OPA4 enable
#define OPA_PSEL3   ((uint32_t)0x00000800) // OPA3 positive input selection
#define OPA_NSEL3   ((uint32_t)0x00000400) // OPA3 negative input selection
#define OPA_MOD3    ((uint32_t)0x00000200) // OPA3 output channel selection
#define OPA_EN3     ((uint32_t)0x00000100) // OPA3 enable
#define OPA_PSEL2   ((uint32_t)0x00000080) // OPA2 positive input selection
#define OPA_NSEL2   ((uint32_t)0x00000040) // OPA2 negative input selection
#define OPA_MOD2    ((uint32_t)0x00000020) // OPA2 output channel selection
#define OPA_EN2     ((uint32_t)0x00000010) // OPA2 enable
#define OPA_PSEL1   ((uint32_t)0x00000008) // OPA1 positive input selection
#define OPA_NSEL1   ((uint32_t)0x00000004) // OPA1 negative input selection
#define OPA_MOD1    ((uint32_t)0x00000002) // OPA1 output channel selection
#define OPA_EN1     ((uint32_t)0x00000001) // OPA1 enable

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_OPA_H
