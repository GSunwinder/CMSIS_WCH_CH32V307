//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_GPIO.h
// Version     : V1.0
// Date        : 18-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 General Purpose I/O Header File.
//==============================================================================

#ifndef __CH32V307_GPIO_H
#define __CH32V307_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t CFGLR;
    __IO uint32_t CFGHR;
    __I  uint32_t INDR;
    __IO uint32_t OUTDR;
    __O  uint32_t BSHR;
    __O  uint32_t BCR;
    __IO uint32_t LCKR;
} GPIO_TypeDef;

#define GPIOA       ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD       ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE       ((GPIO_TypeDef *)GPIOE_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//===============  Bit definition for GPIO_CFGLR/CFGHR register  ===============
//  GPI_CFG(PortNumber, {AN, FL, PUD}
//  GPO_CFG(PortNumber, {UPP, UOD, MPP, MOD}, {2MHz, 10MHz, 50MHz})

// CNF
#define AN      ((uint32_t)(0b00 << 2))
#define FL      ((uint32_t)(0b01 << 2))
#define PUD     ((uint32_t)(0b10 << 2))

#define UPP     ((uint32_t)(0b00 << 2))
#define UOD     ((uint32_t)(0b01 << 2))
#define MPP     ((uint32_t)(0b10 << 2))
#define MOD     ((uint32_t)(0b11 << 2))

// MODE
#define _2MHz   ((uint32_t)0x2)
#define _10MHz  ((uint32_t)0x1)
#define _50MHz  ((uint32_t)0x3)

//?#define GPIO_MASK(PortNumber)                   ((uint32_t)(0x0F << (PortNumber * 4)))
//?#define GPI_CFG(PortNumber, TypeInput)          ((uint32_t)(TypeInput << (PortNumber * 4)))
//?#define GPO_CFG(PortNumber, TypeOutput, Freq)   ((uint32_t)((TypeOutput | Freq) << (PortNumber * 4)))

//==================  Bit definition for GPIO_INDR register  ===================
#define GPIO_INDR_IDR15     ((uint32_t)0x00008000) // Port input data, bit 15
#define GPIO_INDR_IDR14     ((uint32_t)0x00004000) // Port input data, bit 14
#define GPIO_INDR_IDR13     ((uint32_t)0x00002000) // Port input data, bit 13
#define GPIO_INDR_IDR12     ((uint32_t)0x00001000) // Port input data, bit 12
#define GPIO_INDR_IDR11     ((uint32_t)0x00000800) // Port input data, bit 11
#define GPIO_INDR_IDR10     ((uint32_t)0x00000400) // Port input data, bit 10
#define GPIO_INDR_IDR9      ((uint32_t)0x00000200) // Port input data, bit 9
#define GPIO_INDR_IDR8      ((uint32_t)0x00000100) // Port input data, bit 8
#define GPIO_INDR_IDR7      ((uint32_t)0x00000080) // Port input data, bit 7
#define GPIO_INDR_IDR6      ((uint32_t)0x00000040) // Port input data, bit 6
#define GPIO_INDR_IDR5      ((uint32_t)0x00000020) // Port input data, bit 5
#define GPIO_INDR_IDR4      ((uint32_t)0x00000010) // Port input data, bit 4
#define GPIO_INDR_IDR3      ((uint32_t)0x00000008) // Port input data, bit 3
#define GPIO_INDR_IDR2      ((uint32_t)0x00000004) // Port input data, bit 2
#define GPIO_INDR_IDR1      ((uint32_t)0x00000002) // Port input data, bit 1
#define GPIO_INDR_IDR0      ((uint32_t)0x00000001) // Port input data, bit 0

//==================  Bit definition for GPIO_OUTDR register  ==================
#define GPIO_OUTDR_ODR15    ((uint32_t)0x00008000) // Port output data, bit 15
#define GPIO_OUTDR_ODR14    ((uint32_t)0x00004000) // Port output data, bit 14
#define GPIO_OUTDR_ODR13    ((uint32_t)0x00002000) // Port output data, bit 13
#define GPIO_OUTDR_ODR12    ((uint32_t)0x00001000) // Port output data, bit 12
#define GPIO_OUTDR_ODR11    ((uint32_t)0x00000800) // Port output data, bit 11
#define GPIO_OUTDR_ODR10    ((uint32_t)0x00000400) // Port output data, bit 10
#define GPIO_OUTDR_ODR9     ((uint32_t)0x00000200) // Port output data, bit 9
#define GPIO_OUTDR_ODR8     ((uint32_t)0x00000100) // Port output data, bit 8
#define GPIO_OUTDR_ODR7     ((uint32_t)0x00000080) // Port output data, bit 7
#define GPIO_OUTDR_ODR6     ((uint32_t)0x00000040) // Port output data, bit 6
#define GPIO_OUTDR_ODR5     ((uint32_t)0x00000020) // Port output data, bit 5
#define GPIO_OUTDR_ODR4     ((uint32_t)0x00000010) // Port output data, bit 4
#define GPIO_OUTDR_ODR3     ((uint32_t)0x00000008) // Port output data, bit 3
#define GPIO_OUTDR_ODR2     ((uint32_t)0x00000004) // Port output data, bit 2
#define GPIO_OUTDR_ODR1     ((uint32_t)0x00000002) // Port output data, bit 1
#define GPIO_OUTDR_ODR0     ((uint32_t)0x00000001) // Port output data, bit 0

//==================  Bit definition for GPIO_BSHR register  ===================
#define GPIO_BSHR_BR15      ((uint32_t)0x80000000) // Port x Reset bit 15
#define GPIO_BSHR_BR14      ((uint32_t)0x40000000) // Port x Reset bit 14
#define GPIO_BSHR_BR13      ((uint32_t)0x20000000) // Port x Reset bit 13
#define GPIO_BSHR_BR12      ((uint32_t)0x10000000) // Port x Reset bit 12
#define GPIO_BSHR_BR11      ((uint32_t)0x08000000) // Port x Reset bit 11
#define GPIO_BSHR_BR10      ((uint32_t)0x04000000) // Port x Reset bit 10
#define GPIO_BSHR_BR9       ((uint32_t)0x02000000) // Port x Reset bit 9
#define GPIO_BSHR_BR8       ((uint32_t)0x01000000) // Port x Reset bit 8
#define GPIO_BSHR_BR7       ((uint32_t)0x00800000) // Port x Reset bit 7
#define GPIO_BSHR_BR6       ((uint32_t)0x00400000) // Port x Reset bit 6
#define GPIO_BSHR_BR5       ((uint32_t)0x00200000) // Port x Reset bit 5
#define GPIO_BSHR_BR4       ((uint32_t)0x00100000) // Port x Reset bit 4
#define GPIO_BSHR_BR3       ((uint32_t)0x00080000) // Port x Reset bit 3
#define GPIO_BSHR_BR2       ((uint32_t)0x00040000) // Port x Reset bit 2
#define GPIO_BSHR_BR1       ((uint32_t)0x00020000) // Port x Reset bit 1
#define GPIO_BSHR_BR0       ((uint32_t)0x00010000) // Port x Reset bit 0

#define GPIO_BSHR_BS15      ((uint32_t)0x00008000) // Port x Set bit 15
#define GPIO_BSHR_BS14      ((uint32_t)0x00004000) // Port x Set bit 14
#define GPIO_BSHR_BS13      ((uint32_t)0x00002000) // Port x Set bit 13
#define GPIO_BSHR_BS12      ((uint32_t)0x00001000) // Port x Set bit 12
#define GPIO_BSHR_BS11      ((uint32_t)0x00000800) // Port x Set bit 11
#define GPIO_BSHR_BS10      ((uint32_t)0x00000400) // Port x Set bit 10
#define GPIO_BSHR_BS9       ((uint32_t)0x00000200) // Port x Set bit 9
#define GPIO_BSHR_BS8       ((uint32_t)0x00000100) // Port x Set bit 8
#define GPIO_BSHR_BS7       ((uint32_t)0x00000080) // Port x Set bit 7
#define GPIO_BSHR_BS6       ((uint32_t)0x00000040) // Port x Set bit 6
#define GPIO_BSHR_BS5       ((uint32_t)0x00000020) // Port x Set bit 5
#define GPIO_BSHR_BS4       ((uint32_t)0x00000010) // Port x Set bit 4
#define GPIO_BSHR_BS3       ((uint32_t)0x00000008) // Port x Set bit 3
#define GPIO_BSHR_BS2       ((uint32_t)0x00000004) // Port x Set bit 2
#define GPIO_BSHR_BS1       ((uint32_t)0x00000002) // Port x Set bit 1
#define GPIO_BSHR_BS0       ((uint32_t)0x00000001) // Port x Set bit 0

//==================  Bit definition for GPIO_BCR register  ====================
#define GPIO_BCR_BR15       ((uint32_t)0x00008000) // Port x Reset bit 15
#define GPIO_BCR_BR14       ((uint32_t)0x00004000) // Port x Reset bit 14
#define GPIO_BCR_BR13       ((uint32_t)0x00002000) // Port x Reset bit 13
#define GPIO_BCR_BR12       ((uint32_t)0x00001000) // Port x Reset bit 12
#define GPIO_BCR_BR11       ((uint32_t)0x00000800) // Port x Reset bit 11
#define GPIO_BCR_BR10       ((uint32_t)0x00000400) // Port x Reset bit 10
#define GPIO_BCR_BR9        ((uint32_t)0x00000200) // Port x Reset bit 9
#define GPIO_BCR_BR8        ((uint32_t)0x00000100) // Port x Reset bit 8
#define GPIO_BCR_BR7        ((uint32_t)0x00000080) // Port x Reset bit 7
#define GPIO_BCR_BR6        ((uint32_t)0x00000040) // Port x Reset bit 6
#define GPIO_BCR_BR5        ((uint32_t)0x00000020) // Port x Reset bit 5
#define GPIO_BCR_BR4        ((uint32_t)0x00000010) // Port x Reset bit 4
#define GPIO_BCR_BR3        ((uint32_t)0x00000008) // Port x Reset bit 3
#define GPIO_BCR_BR2        ((uint32_t)0x00000004) // Port x Reset bit 2
#define GPIO_BCR_BR1        ((uint32_t)0x00000002) // Port x Reset bit 1
#define GPIO_BCR_BR0        ((uint32_t)0x00000001) // Port x Reset bit 0

//==================  Bit definition for GPIO_LCKR register  ===================
#define GPIO_LCKK           ((uint32_t)0x00010000) // Lock key
#define GPIO_LCK15          ((uint32_t)0x00008000) // Port x Lock bit 15
#define GPIO_LCK14          ((uint32_t)0x00004000) // Port x Lock bit 14
#define GPIO_LCK13          ((uint32_t)0x00002000) // Port x Lock bit 13
#define GPIO_LCK12          ((uint32_t)0x00001000) // Port x Lock bit 12
#define GPIO_LCK11          ((uint32_t)0x00000800) // Port x Lock bit 11
#define GPIO_LCK10          ((uint32_t)0x00000400) // Port x Lock bit 10
#define GPIO_LCK9           ((uint32_t)0x00000200) // Port x Lock bit 9
#define GPIO_LCK8           ((uint32_t)0x00000100) // Port x Lock bit 8
#define GPIO_LCK7           ((uint32_t)0x00000080) // Port x Lock bit 7
#define GPIO_LCK6           ((uint32_t)0x00000040) // Port x Lock bit 6
#define GPIO_LCK5           ((uint32_t)0x00000020) // Port x Lock bit 5
#define GPIO_LCK4           ((uint32_t)0x00000010) // Port x Lock bit 4
#define GPIO_LCK3           ((uint32_t)0x00000008) // Port x Lock bit 3
#define GPIO_LCK2           ((uint32_t)0x00000004) // Port x Lock bit 2
#define GPIO_LCK1           ((uint32_t)0x00000002) // Port x Lock bit 1
#define GPIO_LCK0           ((uint32_t)0x00000001) // Port x Lock bit 0

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_GPIO_H
