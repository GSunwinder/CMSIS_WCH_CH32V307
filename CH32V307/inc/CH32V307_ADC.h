//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_ADC.h
// Version     : V1.0
// Date        : 01-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Analog to Digital Converter (ADC) Header File.
//==============================================================================

#ifndef __CH32V307_ADC_H
#define __CH32V307_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"
//#include "CH32V307_TKEY.h"

typedef struct
{
    __IO uint32_t STATR;
    __IO uint32_t CTLR1;
    __IO uint32_t CTLR2;
    __IO uint32_t SAMPTR1;
    __IO uint32_t SAMPTR2;
    __IO uint32_t IOFR1;
    __IO uint32_t IOFR2;
    __IO uint32_t IOFR3;
    __IO uint32_t IOFR4;
    __IO uint32_t WDHTR;
    __IO uint32_t WDLTR;
    __IO uint32_t RSQR1;
    __IO uint32_t RSQR2;
    __IO uint32_t RSQR3;
    __IO uint32_t ISQR;
    __I  uint32_t IDATAR1;
    __I  uint32_t IDATAR2;
    __I  uint32_t IDATAR3;
    __I  uint32_t IDATAR4;
    __I  uint32_t RDATAR;
         uint32_t :32;
    __IO uint32_t AUX;
} ADC_TypeDef;

#define ADC1    ((ADC_TypeDef *)ADC1_BASE)
#define ADC2    ((ADC_TypeDef *)ADC2_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for ADC_STATR register  ===================
#define ADC_STRT                ((uint32_t)0x00000010) // Regular channel Start flag
#define ADC_JSTRT               ((uint32_t)0x00000008) // Injected channel Start flag
#define ADC_JEOC                ((uint32_t)0x00000004) // Injected channel end of conversion
#define ADC_EOC                 ((uint32_t)0x00000002) // End of conversion
#define ADC_AWD                 ((uint32_t)0x00000001) // Analog watchdog flag

//==================  Bit definition for ADC_CTLR1 register  ===================
#define ADC_PGA                 ((uint32_t)0x18000000) // ADC channel gain configuration
#define ADC_PGA_x1              ((uint32_t)0x00000000) // No gain 
#define ADC_PGA_x4              ((uint32_t)0x08000000) // Gain = 4
#define ADC_PGA_x16             ((uint32_t)0x10000000) // Gain = 16
#define ADC_PGA_x64             ((uint32_t)0x18000000) // Gain = 64

#define ADC_BUFEN               ((uint32_t)0x04000000) // ADC buffer enable
#define ADC_TKITUNE             ((uint32_t)0x04000000) // TKEY module charging current config.
#define ADC_TKIEN               ((uint32_t)0x04000000) // TKEY module enable
#define ADC_AWDEN               ((uint32_t)0x00800000) // Analog watchdog enable on regular channels
#define ADC_JAWDEN              ((uint32_t)0x00400000) // Analog watchdog enable on injected channels

#define ADC_DUALMOD             ((uint32_t)0x000F0000) // Dual mode selection
#define ADC_DUALMOD_INDEP       ((uint32_t)0x00000000) // Independent mode
#define ADC_DUALMOD_REG_INJ     ((uint32_t)0x00010000) // Regular + injected mode
#define ADC_DUALMOD_REG_ALT     ((uint32_t)0x00020000) // Regular + alternate trigger mode
#define ADC_DUALMOD_INJ_FINT    ((uint32_t)0x00030000) // Injected + fast interleaved mode
#define ADC_DUALMOD_INJ_SINT    ((uint32_t)0x00040000) // Injected + slow interleaved mode
#define ADC_DUALMOD_INJ         ((uint32_t)0x00050000) // Injected mode
#define ADC_DUALMOD_REG         ((uint32_t)0x00060000) // Regular mode
#define ADC_DUALMOD_FINT        ((uint32_t)0x00070000) // Fast interleaved mode
#define ADC_DUALMOD_SINT        ((uint32_t)0x00080000) // Slow interleaved mode
#define ADC_DUALMOD_ALT         ((uint32_t)0x00090000) // Alernate trigger mode

#define ADC_DISCNUM             ((uint32_t)0x0000E000) // DISCNUM[2:0] bits (Discontinuous mode channel count)
#define ADC_JDISCEN             ((uint32_t)0x00001000) // Discontinuous mode on injected channels
#define ADC_DISCEN              ((uint32_t)0x00000800) // Discontinuous mode on regular channels
#define ADC_JAUTO               ((uint32_t)0x00000400) // Automatic injected group conversion
#define ADC_AWDSGL              ((uint32_t)0x00000200) // Enable the watchdog on a single channel in scan mode
#define ADC_SCAN                ((uint32_t)0x00000100) // Scan mode
#define ADC_JEOCIE              ((uint32_t)0x00000080) // Interrupt enable for injected channels
#define ADC_AWDIE               ((uint32_t)0x00000040) // Analog Watchdog interrupt enable
#define ADC_EOCIE               ((uint32_t)0x00000020) // Interrupt enable for EOC
#define ADC_AWDCH               ((uint32_t)0x0000001F) // AWDCH[4:0] bits (Analog watchdog channel select bits)

//==================  Bit definition for ADC_CTLR2 register  ===================
#define ADC_TSVREFE             ((uint32_t)0x00800000) // Temperature sensor and internal voltage enable
#define ADC_SWSTART             ((uint32_t)0x00400000) // Start Conversion of regular channels
#define ADC_JSWSTART            ((uint32_t)0x00200000) // Start Conversion of injected channels
#define ADC_EXTTRIG             ((uint32_t)0x00100000) // External Trigger Conversion mode for regular channels

#define ADC_EXTSEL              ((uint32_t)0x000E0000) // EXTSEL[2:0] bits (External Event Select for regular group)
#define ADC_EXTSEL_T1TRGO       ((uint32_t)0x00000000) // TRGO event for Timer1
#define ADC_EXTSEL_T1CC1        ((uint32_t)0x00020000) // CC1 event for Timer1
#define ADC_EXTSEL_T1CC2        ((uint32_t)0x00040000) // CC2 event for Timer1
#define ADC_EXTSEL_T2TRGO       ((uint32_t)0x00060000) // TRGO event for Timer2
#define ADC_EXTSEL_T2CC1        ((uint32_t)0x00080000) // CC1 event for Timer2
#define ADC_EXTSEL_T2CC2        ((uint32_t)0x000A0000) // CC2 event for Timer2
#define ADC_EXTSEL_PD3_PC2      ((uint32_t)0x000C0000) // PD3/PC2 event
#define ADC_EXTSEL_SWSTART      ((uint32_t)0x000E0000) // SWSTART software trigger

#define ADC_JEXTTRIG            ((uint32_t)0x00008000) // External Trigger Conversion mode for injected channels

#define ADC_JEXTSEL             ((uint32_t)0x00007000) // JEXTSEL[2:0] bits (External event select for injected group)
#define ADC_JEXTSEL_T1CC3       ((uint32_t)0x00000000) // CC3 event of Timer1
#define ADC_JEXTSEL_T1CC4       ((uint32_t)0x00001000) // CC4 event of Timer1
#define ADC_JEXTSEL_T2CC3       ((uint32_t)0x00002000) // CC3 event of Timer2
#define ADC_JEXTSEL_T2CC4       ((uint32_t)0x00003000) // CC4 event of Timer2
#define ADC_JEXTSEL_PD1_PA2     ((uint32_t)0x00006000) // PD1/PA2 event
#define ADC_JEXTSEL_JSWSTART    ((uint32_t)0x00007000) // JSWSTART software trigger

#define ADC_ALIGN               ((uint32_t)0x00000800) // Data Alignment
#define ADC_DMA                 ((uint32_t)0x00000100) // Direct Memory access mode
#define ADC_RSTCAL              ((uint32_t)0x00000008) // Reset Calibration
#define ADC_CAL                 ((uint32_t)0x00000004) // A/D Calibration
#define ADC_CONT                ((uint32_t)0x00000002) // Continuous Conversion
#define ADC_ADON                ((uint32_t)0x00000001) // A/D Converter ON / OFF

//=================  Bit definition for ADC_SAMPTR1 register  ==================
#define ADC_SMP17               ((uint32_t)0x00E00000) // SMP17[2:0] bits (Channel 7 Sample time selection)
#define ADC_SMP16               ((uint32_t)0x001C0000) // SMP16[2:0] bits (Channel 6 Sample time selection)
#define ADC_SMP15               ((uint32_t)0x00038000) // SMP15[2:0] bits (Channel 5 Sample time selection)
#define ADC_SMP14               ((uint32_t)0x00007000) // SMP14[2:0] bits (Channel 4 Sample time selection)
#define ADC_SMP13               ((uint32_t)0x00000E00) // SMP13[2:0] bits (Channel 3 Sample time selection)
#define ADC_SMP12               ((uint32_t)0x000001C0) // SMP12[2:0] bits (Channel 2 Sample time selection)
#define ADC_SMP11               ((uint32_t)0x00000038) // SMP11[2:0] bits (Channel 1 Sample time selection)
#define ADC_SMP10               ((uint32_t)0x00000007) // SMP10[2:0] bits (Channel 0 Sample time selection)

//=================  Bit definition for ADC_SAMPTR2 register  ==================
#define ADC_SMP9                ((uint32_t)0x38000000) // SMP9[2:0] bits (Channel 9 Sample time selection)
#define ADC_SMP8                ((uint32_t)0x07000000) // SMP8[2:0] bits (Channel 8 Sample time selection)
#define ADC_SMP7                ((uint32_t)0x00E00000) // SMP7[2:0] bits (Channel 7 Sample time selection)
#define ADC_SMP6                ((uint32_t)0x001C0000) // SMP6[2:0] bits (Channel 6 Sample time selection)
#define ADC_SMP5                ((uint32_t)0x00038000) // SMP5[2:0] bits (Channel 5 Sample time selection)
#define ADC_SMP4                ((uint32_t)0x00007000) // SMP4[2:0] bits (Channel 4 Sample time selection)
#define ADC_SMP3                ((uint32_t)0x00000E00) // SMP3[2:0] bits (Channel 3 Sample time selection)
#define ADC_SMP2                ((uint32_t)0x000001C0) // SMP2[2:0] bits (Channel 2 Sample time selection)
#define ADC_SMP1                ((uint32_t)0x00000038) // SMP1[2:0] bits (Channel 1 Sample time selection)
#define ADC_SMP0                ((uint32_t)0x00000007) // SMP0[2:0] bits (Channel 0 Sample time selection)

#define ADC_1H_ccls             ((uint32_t)0x00000000)
#define ADC_7H_ccls             ((uint32_t)0x00000001)
#define ADC_13H_ccls            ((uint32_t)0x00000002)
#define ADC_28H_ccls            ((uint32_t)0x00000003)
#define ADC_41H_ccls            ((uint32_t)0x00000004)
#define ADC_55H_ccls            ((uint32_t)0x00000005)
#define ADC_71H_ccls            ((uint32_t)0x00000006)
#define ADC_239H_ccls           ((uint32_t)0x00000007)
// with set ADC_SMP_SELx bit
#define ADC_2H_ccls             ((uint32_t)0x00000004)
#define ADC_3H_ccls             ((uint32_t)0x00000005)
#define ADC_4H_ccls             ((uint32_t)0x00000006)
#define ADC_5H_ccls             ((uint32_t)0x00000007)

#define ADC_TIME(Channel, Cycles)   ((uint32_t)(Cycles << (Channel * 3)))

//============  Bit definition for ADC_IOFR[1, 2, 3, 4] register  ==============
#define ADC_JOFFSET             ((uint32_t)0x000003FF) // Data offset for injected channel

//==================  Bit definition for ADC_WDHTR register  ===================
#define ADC_HT                  ((uint32_t)0x000003FF) // Analog watchdog high threshold

//==================  Bit definition for ADC_WDLTR register  ===================
#define ADC_LT                  ((uint32_t)0x000003FF) // Analog watchdog low threshold

//==================  Bit definition for ADC_RSQR1 register  ===================
#define ADC_L                   ((uint32_t)0x00F00000) // L[3:0] bits (Regular channel sequence length)
#define ADC_SQ16                ((uint32_t)0x000F8000) // SQ16[4:0] bits (16th conversion in regular sequence)
#define ADC_SQ15                ((uint32_t)0x00007C00) // SQ15[4:0] bits (15th conversion in regular sequence)
#define ADC_SQ14                ((uint32_t)0x000003E0) // SQ14[4:0] bits (14th conversion in regular sequence)
#define ADC_SQ13                ((uint32_t)0x0000001F) // SQ13[4:0] bits (13th conversion in regular sequence)

//==================  Bit definition for ADC_RSQR2 register  ===================
#define ADC_SQ12                ((uint32_t)0x3E000000) // SQ12[4:0] bits (12th conversion in regular sequence)
#define ADC_SQ11                ((uint32_t)0x01F00000) // SQ11[4:0] bits (11th conversion in regular sequence)
#define ADC_SQ10                ((uint32_t)0x000F8000) // SQ10[4:0] bits (10th conversion in regular sequence)
#define ADC_SQ9                 ((uint32_t)0x00007C00) // SQ9[4:0] bits (9th conversion in regular sequence)
#define ADC_SQ8                 ((uint32_t)0x000003E0) // SQ8[4:0] bits (8th conversion in regular sequence)
#define ADC_SQ7                 ((uint32_t)0x0000001F) // SQ7[4:0] bits (7th conversion in regular sequence)

//==================  Bit definition for ADC_RSQR3 register  ====================
#define ADC_SQ6                 ((uint32_t)0x3E000000) // SQ6[4:0] bits (6th conversion in regular sequence)
#define ADC_SQ5                 ((uint32_t)0x01F00000) // SQ5[4:0] bits (5th conversion in regular sequence)
#define ADC_SQ4                 ((uint32_t)0x000F8000) // SQ4[4:0] bits (4th conversion in regular sequence)
#define ADC_SQ3                 ((uint32_t)0x00007C00) // SQ3[4:0] bits (3rd conversion in regular sequence)
#define ADC_SQ2                 ((uint32_t)0x000003E0) // SQ2[4:0] bits (2nd conversion in regular sequence)
#define ADC_SQ1                 ((uint32_t)0x0000001F) // SQ1[4:0] bits (1st conversion in regular sequence)

//==================  Bit definition for ADC_ISQR register  ====================
#define ADC_JL                  ((uint32_t)0x00300000) // JL[1:0] bits (Injected Sequence length)
#define ADC_JSQ4                ((uint32_t)0x000F8000) // JSQ4[4:0] bits (4th conversion in injected sequence)
#define ADC_JSQ3                ((uint32_t)0x00007C00) // JSQ3[4:0] bits (3rd conversion in injected sequence)
#define ADC_JSQ2                ((uint32_t)0x000003E0) // JSQ2[4:0] bits (2nd conversion in injected sequence)
#define ADC_JSQ1                ((uint32_t)0x0000001F) // JSQ1[4:0] bits (1st conversion in injected sequence)

//==========  Bit definition for ADC_ADC_IDATAR[1, 2, 3, 4] register  ==========
#define ADC_IDATAR_JDATA        ((uint32_t)0x0000FFFF) // Injected data

//===================  Bit definition for ADC_RDATAR register  =================
#define ADC_RDATAR_ADC2DATA     ((uint32_t)0xFFFF0000) // ADC2 converted data
#define ADC_RDATAR_DATA         ((uint32_t)0x0000FFFF) // Regular data

//====================  Bit definition for ADC_AUX register  ===================
#define ADC_AUX_ADCSMPSEL       ((uint32_t)0x0003FFFF)

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_ADC_H
