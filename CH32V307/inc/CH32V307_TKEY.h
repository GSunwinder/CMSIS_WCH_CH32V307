//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_TKEY.h
// Version     : V1.0
// Date        : 08-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Touch key detection Header File.
//==============================================================================

#ifndef __CH32V307_TKEY_H
#define __CH32V307_TKEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
    __IO uint32_t CHARGE1;
    __IO uint32_t CHARGE2;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
    __O  uint32_t CHGOFFSET;
         uint32_t :32;
         uint32_t :32;
         uint32_t :32;
         union
         {
            __I uint32_t ACT_DCG;
            __O uint32_t DR;
         }
         uint32_t :32;
         uint32_t :32;
} TKEY_TypeDef;

#define TKEY1   ((ADC_TypeDef *)TKEY1_BASE)
#define TKEY2   ((ADC_TypeDef *)TKEY2_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//=================  Bit definition for TKEY_CHARGE1 register  =================
#define TKEY_TKCG17         ((uint32_t)0x00E00000) // TKCG17[2:0] bits (Channel 17 Sample time selection)
#define TKEY_TKCG16         ((uint32_t)0x001C0000) // TKCG16[2:0] bits (Channel 16 Sample time selection)
#define TKEY_TKCG15         ((uint32_t)0x00038000) // TKCG15[2:0] bits (Channel 15 Sample time selection)
#define TKEY_TKCG14         ((uint32_t)0x00007000) // TKCG14[2:0] bits (Channel 14 Sample time selection)
#define TKEY_TKCG13         ((uint32_t)0x00000E00) // TKCG13[2:0] bits (Channel 13 Sample time selection)
#define TKEY_TKCG12         ((uint32_t)0x000001C0) // TKCG12[2:0] bits (Channel 12 Sample time selection)
#define TKEY_TKCG11         ((uint32_t)0x00000038) // TKCG11[2:0] bits (Channel 11 Sample time selection)
#define TKEY_TKCG10         ((uint32_t)0x00000007) // TKCG10[2:0] bits (Channel 10 Sample time selection)

//=================  Bit definition for TKEY_CHARGE2 register  =================
#define TKEY_TKCG9          ((uint32_t)0x38000000) // TKCG9[2:0] bits (Channel 9 Sample time selection)
#define TKEY_TKCG8          ((uint32_t)0x07000000) // TKCG8[2:0] bits (Channel 8 Sample time selection)
#define TKEY_TKCG7          ((uint32_t)0x00E00000) // TKCG7[2:0] bits (Channel 7 Sample time selection)
#define TKEY_TKCG6          ((uint32_t)0x001C0000) // TKCG6[2:0] bits (Channel 6 Sample time selection)
#define TKEY_TKCG5          ((uint32_t)0x00038000) // TKCG5[2:0] bits (Channel 5 Sample time selection)
#define TKEY_TKCG4          ((uint32_t)0x00007000) // TKCG4[2:0] bits (Channel 4 Sample time selection)
#define TKEY_TKCG3          ((uint32_t)0x00000E00) // TKCG3[2:0] bits (Channel 3 Sample time selection)
#define TKEY_TKCG2          ((uint32_t)0x000001C0) // TKCG2[2:0] bits (Channel 2 Sample time selection)
#define TKEY_TKCG1          ((uint32_t)0x00000038) // TKCG1[2:0] bits (Channel 1 Sample time selection)
#define TKEY_TKCG0          ((uint32_t)0x00000007) // TKCG0[2:0] bits (Channel 0 Sample time selection)

#define TKCG_1H_ccls        ((uint32_t)0x00000000) // 1.5 cycles
#define TKCG_7H_ccls        ((uint32_t)0x00000001) // 7.5 cycles
#define TKCG_13H_ccls       ((uint32_t)0x00000002) // 13.5 cycles
#define TKCG_28H_ccls       ((uint32_t)0x00000003) // 28.5 cycles
#define TKCG_41H_ccls       ((uint32_t)0x00000004) // 41.5 cycles
#define TKCG_55H_ccls       ((uint32_t)0x00000005) // 55.5 cycles
#define TKCG_71H_ccls       ((uint32_t)0x00000006) // 71.5 cycles
#define TKCG_239H_ccls      ((uint32_t)0x00000007) // 239.5 cycles

#define TKCG_TIME(Channel, Cycles)   ((uint32_t)(Cycles << (Channel * 3)))

//================  Bit definition for TKEY_CHGOFFSET register  ================
#define TKEY_TKCGOFFSET     ((uint32_t)0x000000FF) // Charge time offset config. value

//==================  Bit definition for TKEY_ACT_DCG register  ================
#define TKEY_TKACT_DCG      ((uint32_t)0x000000FF) // Discharge time and activate detection

//====================  Bit definition for TKEY_DR register  ===================
#define TKEY_DR             ((uint32_t)0x0000FFFF) // Converted data

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_TKEY_H
