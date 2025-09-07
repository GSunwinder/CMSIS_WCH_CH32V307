//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_EXTEN.h
// Version     : V1.0
// Date        : 04-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Extended configuration Header File.
//==============================================================================

#ifndef __CH32V307_EXTEN_H
#define __CH32V307_EXTEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t EXTEN_CTR;
         uint32_t :32;
    __IO uint32_t EXTEN_CTR2;
} EXTEN_TypeDef;

#define EXTEND      ((EXTEN_TypeDef *)EXTEND_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for EXTEN_CTR register  ===================
#define EXTEN_HSEKPLP       ((uint32_t)0x00001000) // HSE control in low-power mode

#define EXTEN_LDO_TRIM      ((uint32_t)0x00000C00) // Digital core voltage value
#define EXTEN_LDO_TRIM_13   ((uint32_t)0x00000000) // 1.3V
#define EXTEN_LDO_TRIM_12   ((uint32_t)0x00000400) // 1.2V
#define EXTEN_LDO_TRIM_11   ((uint32_t)0x00000800) // 1.1V (reset value)
#define EXTEN_LDO_TRIM_10   ((uint32_t)0x00000C00) // 1.0V

#define EXTEN_ULLDOTRIM     ((uint32_t)0x00000300) // ULLDO voltage in low-power mode

#define EXTEN_LKUPRST       ((uint32_t)0x00000080) // LOCKUP reset
#define EXTEN_LKUPEN        ((uint32_t)0x00000040) // LOCKUP monitor function enable

#define EXTEN_HSIPRE        ((uint32_t)0x00000010) // HSI clock source for PLL
#define EXTEN_ETHRGMII      ((uint32_t)0x00000008) // RGMII interface enable
#define EXTEN_ETH10M        ((uint32_t)0x00000004) // 10M Ethernet and clock enable
#define EXTEN_USBDPU        ((uint32_t)0x00000002) // USBD internal pull-up enable
#define EXTEN_USBDLS        ((uint32_t)0x00000001) // USBD operation mode select

//==================  Bit definition for EXTEN_CTR2 register  ==================
#define EXTEN_OPA4_HSMD     ((uint32_t)0x00000008) // OPA4 high-speed mode enable
#define EXTEN_OPA3_HSMD     ((uint32_t)0x00000004) // OPA3 high-speed mode enable
#define EXTEN_OPA2_HSMD     ((uint32_t)0x00000002) // OPA2 high-speed mode enable
#define EXTEN_OPA1_HSMD     ((uint32_t)0x00000001) // OPA1 high-speed mode enable

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_EXTEN_H
