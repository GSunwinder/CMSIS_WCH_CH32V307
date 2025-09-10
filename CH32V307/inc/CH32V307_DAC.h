//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_DAC.h
// Version     : V1.0
// Date        : 10-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 DAC register Header File.
//==============================================================================

#ifndef __CH32V307_DAC_H
#define __CH32V307_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t CTLR;
    __O  uint32_t SWTR;
    __IO uint32_t R12BDHR1;
    __IO uint32_t L12BDHR1;
    __IO uint32_t R8BDHR1;
    __IO uint32_t R12BDHR2;
    __IO uint32_t L12BDHR2;
    __IO uint32_t R8BDHR2;
    __IO uint32_t RD12BDHR;
    __IO uint32_t LD12BDHR;
    __IO uint32_t RD8BDHR;
    __I  uint32_t DAC_DOR1;
    __I  uint32_t DAC_DOR2;
} DAC_TypeDef;

#define DAC     ((DAC_TypeDef *)DAC_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for DAC_CTLR register  ===================
#define DAC_DMAEN2          ((uint32_t)0x10000000) // DMA enable of DAC channel 2

#define DAC_MAMP2           ((uint32_t)0x0F000000) // DAC channel 2 amplitude setting
#define DAC_MAMP2_TA1       ((uint32_t)0x00000000) // Triangle amplitude equal to 1
#define DAC_MAMP2_TA3       ((uint32_t)0x01000000) // Triangle amplitude equal to 3
#define DAC_MAMP2_TA7       ((uint32_t)0x02000000) // Triangle amplitude equal to 7
#define DAC_MAMP2_TA15      ((uint32_t)0x03000000) // Triangle amplitude equal to 15
#define DAC_MAMP2_TA31      ((uint32_t)0x04000000) // Triangle amplitude equal to 31
#define DAC_MAMP2_TA63      ((uint32_t)0x05000000) // Triangle amplitude equal to 63
#define DAC_MAMP2_TA127     ((uint32_t)0x06000000) // Triangle amplitude equal to 127
#define DAC_MAMP2_TA255     ((uint32_t)0x07000000) // Triangle amplitude equal to 255
#define DAC_MAMP2_TA511     ((uint32_t)0x08000000) // Triangle amplitude equal to 511
#define DAC_MAMP2_TA1023    ((uint32_t)0x09000000) // Triangle amplitude equal to 1023
#define DAC_MAMP2_TA2047    ((uint32_t)0x0A000000) // Triangle amplitude equal to 2047
#define DAC_MAMP2_TA4095    ((uint32_t)0x0B000000) // Triangle amplitude equal to 4095

#define DAC_WAVE2           ((uint32_t)0x00C00000) // DAC channel 2 wave generation
#define DAC_WAVE2_DIS       ((uint32_t)0x00000000) // DAC channel 2 generator disable
#define DAC_WAVE2_NOISE     ((uint32_t)0x00400000) // DAC channel 2 noise generator
#define DAC_WAVE2_TRIAN     ((uint32_t)0x00800000) // DAC channel 2 triangle generator enable

#define DAC_TSEL2           ((uint32_t)0x00380000) // Trigger event selection of DAC channel 2
#define DAC_TSEL2_TIM6      ((uint32_t)0x00000000) // TIM6 TRGO event
#define DAC_TSEL2_TIM8      ((uint32_t)0x00080000) // TIM8 TRGO event
#define DAC_TSEL2_TIM7      ((uint32_t)0x00100000) // TIM7 TRGO event
#define DAC_TSEL2_TIM5      ((uint32_t)0x00180000) // TIM5 TRGO event
#define DAC_TSEL2_TIM2      ((uint32_t)0x00200000) // TIM2 TRGO event
#define DAC_TSEL2_TIM4      ((uint32_t)0x00280000) // TIM4 TRGO event
#define DAC_TSEL2_EXT9      ((uint32_t)0x00300000) // External interrupt line 9
#define DAC_TSEL2_SWTG      ((uint32_t)0x00380000) // Software trigger

#define DAC_TEN2            ((uint32_t)0x00040000) // External trigger mode enable of DAC ch.2
#define DAC_BOFF2           ((uint32_t)0x00020000) // DAC channel 2 output buffer disable
#define DAC_EN2             ((uint32_t)0x00010000) // DAC channel 2 enable

#define DAC_DMAEN1          ((uint32_t)0x00001000) // DMA enable of DAC channel 1

#define DAC_MAMP1           ((uint32_t)0x00000F00) // DAC channel 1 amplitude setting
#define DAC_MAMP1_TA1       ((uint32_t)0x00000000) // Triangle amplitude equal to 1
#define DAC_MAMP1_TA3       ((uint32_t)0x00000100) // Triangle amplitude equal to 3
#define DAC_MAMP1_TA7       ((uint32_t)0x00000200) // Triangle amplitude equal to 7
#define DAC_MAMP1_TA15      ((uint32_t)0x00000300) // Triangle amplitude equal to 15
#define DAC_MAMP1_TA31      ((uint32_t)0x00000400) // Triangle amplitude equal to 31
#define DAC_MAMP1_TA63      ((uint32_t)0x00000500) // Triangle amplitude equal to 63
#define DAC_MAMP1_TA127     ((uint32_t)0x00000600) // Triangle amplitude equal to 127
#define DAC_MAMP1_TA255     ((uint32_t)0x00000700) // Triangle amplitude equal to 255
#define DAC_MAMP1_TA511     ((uint32_t)0x00000800) // Triangle amplitude equal to 511
#define DAC_MAMP1_TA1023    ((uint32_t)0x00000900) // Triangle amplitude equal to 1023
#define DAC_MAMP1_TA2047    ((uint32_t)0x00000A00) // Triangle amplitude equal to 2047
#define DAC_MAMP1_TA4095    ((uint32_t)0x00000B00) // Triangle amplitude equal to 4095

#define DAC_WAVE1           ((uint32_t)0x000000C0) // DAC channel 1 wave generation
#define DAC_WAVE1_DIS       ((uint32_t)0x00000000) // DAC channel 1 generator disable
#define DAC_WAVE1_NOISE     ((uint32_t)0x00000040) // DAC channel 1 noise generator
#define DAC_WAVE1_TRIAN     ((uint32_t)0x00000080) // DAC channel 1 triangle generator enable

#define DAC_TSEL1           ((uint32_t)0x00000038) // Trigger event selection of DAC channel 1
#define DAC_TSEL1_TIM6      ((uint32_t)0x00000000) // TIM6 TRGO event
#define DAC_TSEL1_TIM8      ((uint32_t)0x00000008) // TIM8 TRGO event
#define DAC_TSEL1_TIM7      ((uint32_t)0x00000010) // TIM7 TRGO event
#define DAC_TSEL1_TIM5      ((uint32_t)0x00000018) // TIM5 TRGO event
#define DAC_TSEL1_TIM2      ((uint32_t)0x00000020) // TIM2 TRGO event
#define DAC_TSEL1_TIM4      ((uint32_t)0x00000028) // TIM4 TRGO event
#define DAC_TSEL1_EXT9      ((uint32_t)0x00000030) // External interrupt line 9
#define DAC_TSEL1_SWTG      ((uint32_t)0x00000038) // Software trigger

#define DAC_TEN1            ((uint32_t)0x00000004) // External trigger mode enable of DAC ch.1
#define DAC_BOFF1           ((uint32_t)0x00000002) // DAC channel 1 output buffer disable
#define DAC_EN1             ((uint32_t)0x00000001) // DAC channel 1 enable

//==================  Bit definition for DAC_SWTR register  ====================
#define DAC_SWTIG2          ((uint32_t)0x00000002) // Software trigger of DAC channel 2
#define DAC_SWTIG1          ((uint32_t)0x00000001) // Software trigger of DAC channel 1

//================  Bit definition for DAC_R12BDHR1 register  ==================
#define DAC_DACC1RDHR       ((uint32_t)0x00000FFF) // 12-bit right-aligned data of DAC ch.1

//================  Bit definition for DAC_L12BDHR1 register  ==================
#define DAC_DACC1LDHR       ((uint32_t)0x0000FFF0) // 12-bit left-aligned data of DAC ch.1

//================  Bit definition for DAC_R8BDHR1 register  ===================
#define DAC_DACC18DHR       ((uint32_t)0x000000FF) // 8-bit right-aligned data of DAC ch.1

//================  Bit definition for DAC_R12BDHR2 register  ==================
#define DAC_DACC2RDHR       ((uint32_t)0x00000FFF) // 12-bit right-aligned data of DAC ch.2

//================  Bit definition for DAC_L12BDHR2 register  ==================
#define DAC_DACC2LDHR       ((uint32_t)0x0000FFF0) // 12-bit left-aligned data of DAC ch.2

//================  Bit definition for DAC_R8BDHR2 register  ===================
#define DAC_DACC28DHR       ((uint32_t)0x000000FF) // 8-bit right-aligned data of DAC ch.2

//================  Bit definition for DAC_RD12BDHR register  ==================
#define DAC_DACC2RDDHR      ((uint32_t)0x0FFF0000) // 12-bit right-aligned data of DAC ch.2
#define DAC_DACC1RDDHR      ((uint32_t)0x00000FFF) // 12-bit right-aligned data of DAC ch.1

//================  Bit definition for DAC_LD12BDHR register  ==================
#define DAC_DACC2LDDHR      ((uint32_t)0xFFF00000) // 12-bit left-aligned data of DAC ch.2
#define DAC_DACC1LDDHR      ((uint32_t)0x0000FFF0) // 12-bit left-aligned data of DAC ch.1

//================  Bit definition for DAC_RD8BDHR2 register  ==================
#define DAC_DACC28DDHR      ((uint32_t)0x0000FF00) // 8-bit right-aligned data of DAC ch.2
#define DAC_DACC18DDHR      ((uint32_t)0x000000FF) // 8-bit right-aligned data of DAC ch.1

//=================  Bit definition for DAC_DOR1 register  =====================
#define DAC_DACC1DOR        ((uint32_t)0x00000FFF) // Output data of DAC channel 1

//=================  Bit definition for DAC_DOR2 register  =====================
#define DAC_DACC2DOR        ((uint32_t)0x00000FFF) // Output data of DAC channel 2

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_DAC_H
