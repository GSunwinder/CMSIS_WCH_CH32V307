//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307.h
// Version     : V1.0
// Date        : 15-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Device Peripheral Access Layer Header File.
//==============================================================================

#ifndef __CH32V307_H
#define __CH32V307_H

#ifdef __cplusplus
extern "C" {
#endif

#define CH32V30x_D8C // CH32V307RC, CH32V307WC, CH32V307VC
#define __MPU_PRESENT   0

#define HSI_VALUE       ((uint32_t)8000000) // Value of the Internal oscillator in Hz
#define HSI_TRIM_VALUE  ((uint8_t)16)       // adjusted about 20 kHz/step at 8 MHz HSI

#include <RISC-V_QingKe_V4F.h>

#include "CH32V307_ADC.h"
#include "CH32V307_AFIO.h"
#include "CH32V307_DMA.h"
//#include "CH32V003_EXTEN.h"
#include "CH32V003_EXTI.h"
//#include "CH32V003_FO.h"
#include "CH32V307_GPIO.h"
#include "CH32V307_I2C.h"
#include "CH32V307_IRQ.h"
#include "CH32V307_IWDG.h"
//#include "CH32V003_MISC.h"
#include "CH32V307_PWR.h"
#include "CH32V307_RCC.h"
#include "CH32V307_SPI.h"
#include "CH32V307_TIM.h"
#include "CH32V307_USART.h"
#include "CH32V307_WWDG.h"

//==============================================================================
//                          Peripheral memory map
//==============================================================================
#define FLASH_BASE          ((uint32_t)0x00000000) // FLASH base address
#define SRAM_BASE           ((uint32_t)0x20000000) // SRAM base address
#define PERIPH_BASE         ((uint32_t)0x40000000) // Peripheral base address
#define FSMC_B1_BASE        ((uint32_t)0x60000000) // FSMC bus bank1 base address (NOR/PSRAM)
#define FSMC_B2_BASE        ((uint32_t)0x70000000) // FSMC bus bank2 base address (NAND)
#define FSMC_BASE           ((uint32_t)0xA0000000) // FSMC registers base address
// Core Private Peripherals see in RISC-V_QingKe_V4F.h

// FLASH region
#define CODE_FLASH_BASE     (FLASH_BASE + 0x08000000)
#define SYSTEM_FLASH_BASE   (FLASH_BASE + 0x1FFF8000) // Boot flash memory (28 kbytes)
#define VENDOR_BASE         (FLASH_BASE + 0x1FFFF700)
#define ESIG_BASE           (FLASH_BASE + 0x1FFFF7E0) // Electronic Signature
#define OB_BASE             (FLASH_BASE + 0x1FFFF800) // Flash Option Bytes base address

// Peripheral region
#define APB1PERIPH_BASE     (PERIPH_BASE + 0x00000)
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE      (PERIPH_BASE + 0x20000)

#define TIM2_BASE           (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE           (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE           (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE           (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE           (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE           (APB1PERIPH_BASE + 0x1400)
#define UART6_BASE          (APB2PERIPH_BASE + 0x1800)
#define UART7_BASE          (APB2PERIPH_BASE + 0x1C00)
#define UART8_BASE          (APB2PERIPH_BASE + 0x2000)
#define RTC_BASE            (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE           (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE           (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE           (APB2PERIPH_BASE + 0x3800)
#define SPI3_BASE           (APB2PERIPH_BASE + 0x3C00)
#define USART2_BASE         (APB2PERIPH_BASE + 0x4400)
#define USART3_BASE         (APB2PERIPH_BASE + 0x4800)
#define UART4_BASE          (APB2PERIPH_BASE + 0x4C00)
#define UART5_BASE          (APB2PERIPH_BASE + 0x5000)
#define I2C1_BASE           (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE           (APB1PERIPH_BASE + 0x5800)
#define CAN_RAM_BASE        (APB1PERIPH_BASE + 0x6000)
#define CAN1_BASE           (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASE           (APB1PERIPH_BASE + 0x6800)
#define BKP_BASE            (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE            (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE            (APB1PERIPH_BASE + 0x7400)

#define AFIO_BASE           (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE           (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE          (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE          (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE          (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE          (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE          (APB2PERIPH_BASE + 0x1800)
#define ADC1_BASE           (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE           (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE           (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE           (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE           (APB1PERIPH_BASE + 0x3400)
#define USART1_BASE         (APB2PERIPH_BASE + 0x3800)
#define TIM9_BASE           (APB1PERIPH_BASE + 0x4C00)
#define TIM10_BASE          (APB1PERIPH_BASE + 0x5000)
#define SDIO_BASE           (APB1PERIPH_BASE + 0x8000)

#define DMA1_BASE           (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE  (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE  (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE  (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE  (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE  (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE  (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE  (AHBPERIPH_BASE + 0x0080)
#define DMA1_Channel8_BASE  (AHBPERIPH_BASE + 0x0094)
#define DMA2_BASE           (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE  (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE  (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE  (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE  (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE  (AHBPERIPH_BASE + 0x0458)
#define DMA2_Channel6_BASE  (AHBPERIPH_BASE + 0x046C)
#define DMA2_Channel7_BASE  (AHBPERIPH_BASE + 0x0480)
#define DMA2_Channel8_BASE  (AHBPERIPH_BASE + 0x0490)
#define DMA2_Channel9_BASE  (AHBPERIPH_BASE + 0x04A0)
#define DMA2_Channel10_BASE (AHBPERIPH_BASE + 0x04B0)
#define DMA2_Channel11_BASE (AHBPERIPH_BASE + 0x04C0)
#define RCC_BASE            (AHBPERIPH_BASE + 0x1000)
#define FLASH_REG_BASE      (AHBPERIPH_BASE + 0x2000) // Flash registers base address
#define CRC_BASE            (AHBPERIPH_BASE + 0x3000)
#define USBHS_BASE          (AHBPERIPH_BASE + 0x3400)
#define EXTEND_BASE         (AHBPERIPH_BASE + 0x3800)
#define TRNG_BASE           (AHBPERIPH_BASE + 0x3C00)
#define ETH_BASE            (AHBPERIPH_BASE + 0x8000)
#define OTGFS_BASE          (AHBPERIPH_BASE + 0x10000000)
#define DVP_BASE            (AHBPERIPH_BASE + 0x10050000)

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_H
