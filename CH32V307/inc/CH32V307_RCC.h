//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_RCC.h
// Version     : V1.0
// Date        : 15-0-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Reset and Clock Control Header File.
//==============================================================================

#ifndef __CH32V307_RCC_H
#define __CH32V307_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <RISC-V_QingKe_V4F.h>

typedef struct
{
    __IO uint32_t CTLR;
    __IO uint32_t CFGR0;
    __IO uint32_t INTR;
    __IO uint32_t APB2PRSTR;
    __IO uint32_t APB1PRSTR;
    __IO uint32_t AHBPCENR;
    __IO uint32_t APB2PCENR;
    __IO uint32_t APB1PCENR;
    __IO uint32_t BDCTLR;
    __IO uint32_t RSTSCKR;
    __IO uint32_t AHBRSTR;
    __IO uint32_t CFGR2;
} RCC_TypeDef;

#define RCC         ((RCC_TypeDef *)RCC_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//===================  Bit definition for RCC_CTLR register  ===================
#define RCC_PLL3RDY             ((uint32_t)0x20000000) // PLL3 clock ready flag
#define RCC_PLL3ON              ((uint32_t)0x10000000) // PLL3 enable
#define RCC_PLL2RDY             ((uint32_t)0x08000000) // PLL2 clock ready flag
#define RCC_PLL2ON              ((uint32_t)0x04000000) // PLL2 enable
#define RCC_PLLRDY              ((uint32_t)0x02000000) // PLL clock ready flag
#define RCC_PLLON               ((uint32_t)0x01000000) // PLL enable
#define RCC_CSSON               ((uint32_t)0x00080000) // Clock Security System enable
#define RCC_HSEBYP              ((uint32_t)0x00040000) // External High Speed clock Bypass
#define RCC_HSERDY              ((uint32_t)0x00020000) // External High Speed clock ready flag
#define RCC_HSEON               ((uint32_t)0x00010000) // External High Speed clock enable
#define RCC_HSICAL              ((uint32_t)0x0000FF00) // Internal High Speed clock Calibration
#define RCC_HSITRIM             ((uint32_t)0x000000F8) // Internal High Speed clock trimming
#define RCC_HSIRDY              ((uint32_t)0x00000002) // Internal High Speed clock ready flag
#define RCC_HSION               ((uint32_t)0x00000001) // Internal High Speed clock enable

//==================  Bit definition for RCC_CFGR0 register  ===================
#define RCC_CFGR0_ADCDUTY       ((uint32_t)0x80000000) // ADC clock duty cycle adjustment
#define RCC_CFGR0_ADCDUTY_50    ((uint32_t)0x00000000) // ADC clock duty cycle is 50%
#define RCC_CFGR0_ADCDUTY_LLL   ((uint32_t)0x80000000) // ADC clock at low level for longer

#define RCC_CFGR0_ADCDUTYSEL    ((uint32_t)0x40000000) // ADC clock duty cycle selection
#define RCC_CFGR0_ADCDUTYSEL_50 ((uint32_t)0x00000000) // ADC clock duty cycle is 50%
#define RCC_CFGR0_ADCDUTYSEL_75 ((uint32_t)0x40000000) // ADC clock duty cycle is 75%

#define RCC_CFGR0_MCO           ((uint32_t)0x0F000000) // MCO[3:0] bits (Microcontroller Clock Output)
#define RCC_MCO_NOCLOCK         ((uint32_t)0x00000000) // No clock
#define RCC_CFGR0_MCO_SYSCLK    ((uint32_t)0x04000000) // System clock selected as MCO source
#define RCC_CFGR0_MCO_HSI       ((uint32_t)0x05000000) // HSI clock selected as MCO source
#define RCC_CFGR0_MCO_HSE       ((uint32_t)0x06000000) // HSE clock selected as MCO source 
#define RCC_CFGR0_MCO_PLL_DIV2  ((uint32_t)0x07000000) // PLL clock divided by 2 selected as MCO source
#define RCC_CFGR0_MCO_PLL2      ((uint32_t)0x08000000) // PLL2 clock selected as MCO source
#define RCC_CFGR0_MCO_PLL3_DIV2 ((uint32_t)0x09000000) // PLL3 clock divided by 2 selected as MCO source
#define RCC_CFGR0_MCO_XTI       ((uint32_t)0x0A000000) // XTI externa oscillator clock selected as MCO source
#define RCC_CFGR0_MCO_PLL3      ((uint32_t)0x0B000000) // PLL3 clock divided by 2 selected as MCO source

#define RCC_USBPRE              ((uint32_t)0x00C00000) // USB OTGFS clock prescaler configuration
#define RCC_USBPRE_NODIV        ((uint32_t)0x00000000) // Not divided (When PLLCLK=48MHz)
#define RCC_USBPRE_DIV2         ((uint32_t)0x00400000) // Divided by 2 (When PLLCLK=96MHz)
#define RCC_USBPRE_DIV3         ((uint32_t)0x00800000) // Divided by 3 (When PLLCLK=144MHz)

#define RCC_PLLMUL              ((uint32_t)0x003C0000) // PLL multiplication factor
#define RCC_PLLMUL_x2           ((uint32_t)0x00000000) // PLL input clock x 2
#define RCC_PLLMUL_x3           ((uint32_t)0x00040000) // PLL input clock x 3
#define RCC_PLLMUL_x4           ((uint32_t)0x00080000) // PLL input clock x 4
#define RCC_PLLMUL_x5           ((uint32_t)0x000C0000) // PLL input clock x 5
#define RCC_PLLMUL_x6           ((uint32_t)0x00100000) // PLL input clock x 6
#define RCC_PLLMUL_x7           ((uint32_t)0x00140000) // PLL input clock x 7
#define RCC_PLLMUL_x8           ((uint32_t)0x00180000) // PLL input clock x 8
#define RCC_PLLMUL_x9           ((uint32_t)0x001C0000) // PLL input clock x 9
#define RCC_PLLMUL_x10          ((uint32_t)0x00200000) // PLL input clock x 10
#define RCC_PLLMUL_x11          ((uint32_t)0x00240000) // PLL input clock x 11
#define RCC_PLLMUL_x12          ((uint32_t)0x00280000) // PLL input clock x 12
#define RCC_PLLMUL_x13          ((uint32_t)0x002C0000) // PLL input clock x 13
#define RCC_PLLMUL_x14          ((uint32_t)0x00300000) // PLL input clock x 14
#define RCC_PLLMUL_x15          ((uint32_t)0x00340000) // PLL input clock x 15
#define RCC_PLLMUL_x16          ((uint32_t)0x00380000) // PLL input clock x 16
#define RCC_PLLMUL_x18          ((uint32_t)0x003C0000) // PLL input clock x 18

#define RCC_PLLXTPRE            ((uint32_t)0x00020000) // HSE divider for PLL entry (reserved)

#define RCC_PLLSRC              ((uint32_t)0x00010000) // PLL entry clock source
#define RCC_PLLSRC_HSIx2        ((uint32_t)0x00000000) // HSI not divided or divided by 2 fed to PLL
#define RCC_PLLSRC_HSEx2        ((uint32_t)0x00010000) // PREDIV1 output fed to PLL

#define RCC_ADCPRE              ((uint32_t)0x0000C000) // ADC clock source prescaler control
#define RCC_ADCPRE_DIV2         ((uint32_t)0x00000000) // PCLK2 divided by 2
#define RCC_ADCPRE_DIV4         ((uint32_t)0x00004000) // HBCLK divided by 4
#define RCC_ADCPRE_DIV6         ((uint32_t)0x00008000) // HBCLK divided by 6
#define RCC_ADCPRE_DIV8         ((uint32_t)0x0000C000) // HBCLK divided by 8

#define RCC_PPRE2               ((uint32_t)0x00003800) // PB2 clock source prescaler control
#define RCC_PPRE2_NODIV         ((uint32_t)0x00000000) // HCLK not divided
#define RCC_PPRE2_DIV2          ((uint32_t)0x00002000) // HCLK divided by 2
#define RCC_PPRE2_DIV4          ((uint32_t)0x00002800) // HCLK divided by 4
#define RCC_PPRE2_DIV8          ((uint32_t)0x00003000) // HCLK divided by 8
#define RCC_PPRE2_DIV16         ((uint32_t)0x00003800) // HCLK divided by 16

#define RCC_PPRE1               ((uint32_t)0x00000700) // PB1 clock source prescaler control
#define RCC_PPRE1_NODIV         ((uint32_t)0x00000000) // HCLK not divided
#define RCC_PPRE1_DIV2          ((uint32_t)0x00000400) // HCLK divided by 2
#define RCC_PPRE1_DIV4          ((uint32_t)0x00000500) // HCLK divided by 4
#define RCC_PPRE1_DIV8          ((uint32_t)0x00000600) // HCLK divided by 8
#define RCC_PPRE1_DIV16         ((uint32_t)0x00000700) // HCLK divided by 16

#define RCC_HPRE                ((uint32_t)0x000000F0) // HB clock source prescaler control
#define RCC_HPRE_NODIV          ((uint32_t)0x00000000) // SYSCLK not divided
#define RCC_HPRE_DIV2           ((uint32_t)0x00000080) // SYSCLK divided by 2
#define RCC_HPRE_DIV4           ((uint32_t)0x00000090) // SYSCLK divided by 4
#define RCC_HPRE_DIV8           ((uint32_t)0x000000A0) // SYSCLK divided by 8
#define RCC_HPRE_DIV16          ((uint32_t)0x000000B0) // SYSCLK divided by 16
#define RCC_HPRE_DIV64          ((uint32_t)0x000000C0) // SYSCLK divided by 64
#define RCC_HPRE_DIV128         ((uint32_t)0x000000D0) // SYSCLK divided by 128
#define RCC_HPRE_DIV256         ((uint32_t)0x000000E0) // SYSCLK divided by 256
#define RCC_HPRE_DIV512         ((uint32_t)0x000000F0) // SYSCLK divided by 512

#define RCC_SWS                 ((uint32_t)0x0000000C) // System Clock Switch Status
#define RCC_SWS_HSI             ((uint32_t)0x00000000) // HSI oscillator used as system clock
#define RCC_SWS_HSE             ((uint32_t)0x00000004) // HSE oscillator used as system clock
#define RCC_SWS_PLL             ((uint32_t)0x00000008) // PLL used as system clock

#define RCC_SW                  ((uint32_t)0x00000003) // System clock Switch
#define RCC_SW_HSI              ((uint32_t)0x00000000) // HSI selected as system clock
#define RCC_SW_HSE              ((uint32_t)0x00000001) // HSE selected as system clock
#define RCC_SW_PLL              ((uint32_t)0x00000002) // PLL selected as system clock

//===================  Bit definition for RCC_INTR register  ===================
#define RCC_CSSC                ((uint32_t)0x00800000) // Clock Security System Interrupt Clear
#define RCC_PLL3RDYC            ((uint32_t)0x00400000) // PLL3 Ready Interrupt Clear
#define RCC_PLL2RDYC            ((uint32_t)0x00200000) // PLL2 Ready Interrupt Clear
#define RCC_PLLRDYC             ((uint32_t)0x00100000) // PLL Ready Interrupt Clear
#define RCC_HSERDYC             ((uint32_t)0x00080000) // HSE Ready Interrupt Clear
#define RCC_HSIRDYC             ((uint32_t)0x00040000) // HSI Ready Interrupt Clear
#define RCC_LSERDYC             ((uint32_t)0x00020000) // LSE Ready Interrupt Clear
#define RCC_LSIRDYC             ((uint32_t)0x00010000) // LSI Ready Interrupt Clear
#define RCC_PLL3RDYIE           ((uint32_t)0x00004000) // PLL3 Ready Interrupt Enable
#define RCC_PLL2RDYIE           ((uint32_t)0x00002000) // PLL2 Ready Interrupt Enable
#define RCC_PLLRDYIE            ((uint32_t)0x00001000) // PLL Ready Interrupt Enable
#define RCC_HSERDYIE            ((uint32_t)0x00000800) // HSE Ready Interrupt Enable
#define RCC_HSIRDYIE            ((uint32_t)0x00000400) // HSI Ready Interrupt Enable
#define RCC_LSERDYIE            ((uint32_t)0x00000200) // LSE Ready Interrupt Enable
#define RCC_LSIRDYIE            ((uint32_t)0x00000100) // LSI Ready Interrupt Enable
#define RCC_CSSF                ((uint32_t)0x00000080) // Clock Security System Interrupt flag
#define RCC_PLL3RDYF            ((uint32_t)0x00000040) // PLL3 Ready Interrupt flag
#define RCC_PLL2RDYF            ((uint32_t)0x00000020) // PLL2 Ready Interrupt flag
#define RCC_PLLRDYF             ((uint32_t)0x00000010) // PLL Ready Interrupt flag
#define RCC_HSERDYF             ((uint32_t)0x00000008) // HSE Ready Interrupt flag
#define RCC_HSIRDYF             ((uint32_t)0x00000004) // HSI Ready Interrupt flag
#define RCC_LSERDYF             ((uint32_t)0x00000002) // LSE Ready Interrupt flag
#define RCC_LSIRDYF             ((uint32_t)0x00000001) // LSI Ready Interrupt flag

//=================  Bit definition for RCC_APB2PRSTR register  ================
#define RCC_TIM10RST            ((uint32_t)0x00100000) // TIM10 Timer reset
#define RCC_TIM9RST             ((uint32_t)0x00080000) // TIM9 Timer reset
#define RCC_USART1RST           ((uint32_t)0x00004000) // USART1 reset
#define RCC_TIM8RST             ((uint32_t)0x00002000) // TIM8 Timer reset
#define RCC_SPI1RST             ((uint32_t)0x00001000) // SPI1 reset
#define RCC_TIM1RST             ((uint32_t)0x00000800) // TIM1 Timer reset
#define RCC_ADC2RST             ((uint32_t)0x00000400) // ADC2 interface reset
#define RCC_ADC1RST             ((uint32_t)0x00000200) // ADC1 interface reset
#define RCC_IOPERST             ((uint32_t)0x00000040) // I/O port E reset
#define RCC_IOPDRST             ((uint32_t)0x00000020) // I/O port D reset
#define RCC_IOPCRST             ((uint32_t)0x00000010) // I/O port C reset
#define RCC_IOPBRST             ((uint32_t)0x00000008) // I/O port B reset
#define RCC_IOPARST             ((uint32_t)0x00000004) // I/O port A reset
#define RCC_AFIORST             ((uint32_t)0x00000001) // Alternate Function I/O reset

//================  Bit definition for RCC_APB1PRSTR register  =================
#define RCC_DACRST              ((uint32_t)0x20000000) // DAC module reset
#define RCC_PWRRST              ((uint32_t)0x10000000) // Power interface reset
#define RCC_BKPRST              ((uint32_t)0x08000000) // Backup interface reset
#define RCC_CAN2RST             ((uint32_t)0x04000000) // CAN2 module reset
#define RCC_CAN1RST             ((uint32_t)0x02000000) // CAN1 module reset
#define RCC_USBDRST             ((uint32_t)0x00800000) // USBD module reset
#define RCC_I2C2RST             ((uint32_t)0x00400000) // I2C2 interface reset
#define RCC_I2C1RST             ((uint32_t)0x00200000) // I2C1 interface reset
#define RCC_UART5RST            ((uint32_t)0x00100000) // UART5 reset
#define RCC_UART4RST            ((uint32_t)0x00080000) // UART4 reset
#define RCC_USART3RST           ((uint32_t)0x00040000) // USART3 reset
#define RCC_USART2RST           ((uint32_t)0x00020000) // USART2 reset
#define RCC_SPI3RST             ((uint32_t)0x00008000) // SPI3 reset
#define RCC_SPI2RST             ((uint32_t)0x00004000) // SPI2 reset
#define RCC_WWDGRST             ((uint32_t)0x00000800) // Window Watchdog reset
#define RCC_UART8RST            ((uint32_t)0x00000100) // UART8 reset
#define RCC_UART7RST            ((uint32_t)0x00000080) // UART7 reset
#define RCC_UART6RST            ((uint32_t)0x00000040) // UART6 reset
#define RCC_TIM7RST             ((uint32_t)0x00000020) // Timer 7 reset
#define RCC_TIM6RST             ((uint32_t)0x00000010) // Timer 6 reset
#define RCC_TIM5RST             ((uint32_t)0x00000008) // Timer 5 reset
#define RCC_TIM4RST             ((uint32_t)0x00000004) // Timer 4 reset
#define RCC_TIM3RST             ((uint32_t)0x00000002) // Timer 3 reset
#define RCC_TIM2RST             ((uint32_t)0x00000001) // Timer 2 reset

//=================  Bit definition for RCC_AHBPCENR register  =================
#define RCC_ETHMACRXEN          ((uint32_t)0x00010000) // Ethernet MAC receive clock enable
#define RCC_ETHMACTXEN          ((uint32_t)0x00008000) // Ethernet MAC transmit clock enable
#define RCC_ETHMACEN            ((uint32_t)0x00004000) // Ethernet MAC clock enable
#define RCC_DVPEN               ((uint32_t)0x00002000) // DVP module clock enable
#define RCC_OTGFSEN             ((uint32_t)0x00001000) // USB OTGFS module clock enable
#define RCC_USBHSEN             ((uint32_t)0x00000800) // USBHS module clock enable
#define RCC_SDIOEN              ((uint32_t)0x00000400) // SDIO module clock enable
#define RCC_RNGEN               ((uint32_t)0x00000200) // RNG module clock enable
#define RCC_FSMCEN              ((uint32_t)0x00000100) // FSMCEN module clock enable
#define RCC_CRCEN               ((uint32_t)0x00000040) // CRC module clock enable
#define RCC_SRAMEN              ((uint32_t)0x00000004) // SRAM interface clock enable
#define RCC_DMA2EN              ((uint32_t)0x00000002) // DMA2 clock enable
#define RCC_DMA1EN              ((uint32_t)0x00000001) // DMA1 clock enable

//================  Bit definition for RCC_APB2PCENR register  =================
#define RCC_TIM10EN             ((uint32_t)0x00100000) // TIM10 Timer clock enable
#define RCC_TIM9EN              ((uint32_t)0x00080000) // TIM9 Timer clock enable
#define RCC_USART1EN            ((uint32_t)0x00004000) // USART1 clock enable
#define RCC_TIM8EN              ((uint32_t)0x00002000) // TIM8 Timer clock enable
#define RCC_SPI1EN              ((uint32_t)0x00001000) // SPI1 clock enable
#define RCC_TIM1EN              ((uint32_t)0x00000800) // TIM1 Timer clock enable
#define RCC_ADC2EN              ((uint32_t)0x00000400) // ADC2 interface clock enable
#define RCC_ADC1EN              ((uint32_t)0x00000200) // ADC1 interface clock enable
#define RCC_IOPEEN              ((uint32_t)0x00000040) // I/O port E clock enable
#define RCC_IOPDEN              ((uint32_t)0x00000020) // I/O port D clock enable
#define RCC_IOPCEN              ((uint32_t)0x00000010) // I/O port C clock enable
#define RCC_IOPBEN              ((uint32_t)0x00000008) // I/O port B clock enable
#define RCC_IOPAEN              ((uint32_t)0x00000004) // I/O port A clock enable
#define RCC_AFIOEN              ((uint32_t)0x00000001) // Alternate Function I/O clock enable

//================  Bit definition for RCC_APB1PCENR register  =================
#define RCC_DACEN               ((uint32_t)0x20000000) // DAC module clock enable
#define RCC_PWREN               ((uint32_t)0x10000000) // Power interface clock enable
#define RCC_BKPEN               ((uint32_t)0x08000000) // Backup interface clock enable
#define RCC_CAN2EN              ((uint32_t)0x04000000) // CAN2 module clock enable
#define RCC_CAN1EN              ((uint32_t)0x02000000) // CAN1 module clock enable
#define RCC_USBDEN              ((uint32_t)0x00800000) // USBD module clock enable
#define RCC_I2C2EN              ((uint32_t)0x00400000) // I2C2 interface clock enable
#define RCC_I2C1EN              ((uint32_t)0x00200000) // I2C1 interface clock enable
#define RCC_UART5EN             ((uint32_t)0x00100000) // UART5 clock enable
#define RCC_UART4EN             ((uint32_t)0x00080000) // UART4 clock enable
#define RCC_USART3EN            ((uint32_t)0x00040000) // USART3 clock enable
#define RCC_USART2EN            ((uint32_t)0x00020000) // USART2 clock enable
#define RCC_SPI3EN              ((uint32_t)0x00008000) // SPI3 clock enable
#define RCC_SPI2EN              ((uint32_t)0x00004000) // SPI2 clock enable
#define RCC_WWDGEN              ((uint32_t)0x00000800) // Window Watchdog clock enable
#define RCC_UART8EN             ((uint32_t)0x00000100) // UART8 clock enable
#define RCC_UART7EN             ((uint32_t)0x00000080) // UART7 clock enable
#define RCC_UART6EN             ((uint32_t)0x00000040) // UART6 clock enable
#define RCC_TIM7EN              ((uint32_t)0x00000020) // Timer 7 clock enable
#define RCC_TIM6EN              ((uint32_t)0x00000010) // Timer 6 clock enable
#define RCC_TIM5EN              ((uint32_t)0x00000008) // Timer 5 clock enable
#define RCC_TIM4EN              ((uint32_t)0x00000004) // Timer 4 clock enable
#define RCC_TIM3EN              ((uint32_t)0x00000002) // Timer 3 clock enable
#define RCC_TIM2EN              ((uint32_t)0x00000001) // Timer 2 clock enable

//=================  Bit definition for RCC_BDCTLR register  ===================
#define RCC_BDRST               ((uint32_t)0x00010000) // Backup domain software reset
#define RCC_RTCEN               ((uint32_t)0x00008000) // RTC clock enable

#define RCC_RTCSEL              ((uint32_t)0x00030000) // RTC clock source selection
#define RCC_RTCSEL_NOCLK        ((uint32_t)0x00000000) // No clock
#define RCC_RTCSEL_LSE          ((uint32_t)0x00010000) // LSE oscillator clock
#define RCC_RTCSEL_LSI          ((uint32_t)0x00020000) // LSI oscillator clock
#define RCC_RTCSEL_HSE          ((uint32_t)0x00030000) // HSE oscillator clock divided by 128

#define RCC_LSEBYP              ((uint32_t)0x00000004) // LSE oscillator bypass
#define RCC_LSERDY              ((uint32_t)0x00000002) // LSE oscillator ready flag
#define RCC_LSEON               ((uint32_t)0x00000001) // LSE oscillator enable

//=================  Bit definition for RCC_RSTSCKR register  ==================
#define RCC_LPWRRSTF            ((uint32_t)0x80000000) // Low-Power reset flag
#define RCC_WWDGRSTF            ((uint32_t)0x40000000) // Window watchdog reset flag
#define RCC_IWDGRSTF            ((uint32_t)0x20000000) // Independent Watchdog reset flag
#define RCC_SFTRSTF             ((uint32_t)0x10000000) // Software Reset flag
#define RCC_PORRSTF             ((uint32_t)0x08000000) // POR/PDR reset flag
#define RCC_PINRSTF             ((uint32_t)0x04000000) // PIN reset flag
#define RCC_RMVF                ((uint32_t)0x01000000) // Remove reset flag
#define RCC_LSIRDY              ((uint32_t)0x00000002) // LSI oscillator ready
#define RCC_LSION               ((uint32_t)0x00000001) // LSI oscillator enable

//=================  Bit definition for RCC_AHBRSTR register  ==================
#define RCC_ETHMACRST           ((uint32_t)0x00004000) // Ethernet MAC reset
#define RCC_DVPRST              ((uint32_t)0x00002000) // DVP reset
#define RCC_OTGFSRST            ((uint32_t)0x00001000) // USB OTGFS module reset

//==================  Bit definition for RCC_CFGR2 register  ===================
#define RCC_USBHSSRC            ((uint32_t)0x80000000) // USBHS 48MHz clock source selection
#define RCC_USBHSSRC_PLL        ((uint32_t)0x00000000) // PLL clock
#define RCC_USBHSSRC_PHY        ((uint32_t)0x80000000) // USB PHY clock

#define RCC_USBHSPLLEN          ((uint32_t)0x40000000) // USBHS PHY internal PLL enable

#define RCC_USBHSCLK            ((uint32_t)0x30000000) // USBHSPLL reference clock selection
#define RCC_USBHSCLK_3M         ((uint32_t)0x00000000) // 3 MHz
#define RCC_USBHSCLK_4M         ((uint32_t)0x10000000) // 4 MHz
#define RCC_USBHSCLK_8M         ((uint32_t)0x20000000) // 8 MHz
#define RCC_USBHSCLK_5M         ((uint32_t)0x30000000) // 5 MHz

#define RCC_USBHSPLLSRC         ((uint32_t)0x08000000) // USBHSPLL reference source selection
#define RCC_USBHSPLLSRC_HSE     ((uint32_t)0x00000000) // HSE
#define RCC_USBHSPLLSRC_HSI     ((uint32_t)0x08000000) // HSI

#define RCC_USBHSDIV            ((uint32_t)0x07000000) // USBHSPLL reference source prescaler
#define RCC_USBHSDIV_NODIV      ((uint32_t)0x00000000) // Not divided
#define RCC_USBHSDIV_DIV2       ((uint32_t)0x01000000) // Divided by 2
#define RCC_USBHSDIV_DIV3       ((uint32_t)0x02000000) // Divided by 3
#define RCC_USBHSDIV_DIV4       ((uint32_t)0x03000000) // Divided by 4
#define RCC_USBHSDIV_DIV5       ((uint32_t)0x04000000) // Divided by 5
#define RCC_USBHSDIV_DIV6       ((uint32_t)0x05000000) // Divided by 6
#define RCC_USBHSDIV_DIV7       ((uint32_t)0x06000000) // Divided by 7
#define RCC_USBHSDIV_DIV8       ((uint32_t)0x07000000) // Divided by 8

#define RCC_ETH1G_125M_EN       ((uint32_t)0x00400000) // Gigabit Ethernet 125M clock enable

#define RCC_ETH1GSRC            ((uint32_t)0x00300000) // Gigabit Ethernet 125M clock selection
#define RCC_ETH1GSRC_PLL2       ((uint32_t)0x00000000) // PLL2 VCO
#define RCC_ETH1GSRC_PLL3       ((uint32_t)0x00100000) // PLL3 VCO
#define RCC_ETH1GSRC_PB1        ((uint32_t)0x00200000) // External PB1 pin input

#define RCC_RNG_SRC             ((uint32_t)0x00080000) // RNG clock source selection
#define RCC_RNG_SRC_SYS         ((uint32_t)0x00000000) // SYSCLK
#define RCC_RNG_SRC_PLL3        ((uint32_t)0x00080000) // PLL3 VCO

#define RCC_I2S3SRC             ((uint32_t)0x00040000) // I2S3 clock source
#define RCC_I2S3SRC_SYS         ((uint32_t)0x00000000) // SYSCLK
#define RCC_I2S3SRC_PLL3        ((uint32_t)0x00040000) // PLL3 VCO

#define RCC_I2S2SRC             ((uint32_t)0x00020000) // I2S2 clock source
#define RCC_I2S2SRC_SYS         ((uint32_t)0x00000000) // SYSCLK
#define RCC_I2S2SRC_PLL3        ((uint32_t)0x00020000) // PLL3 VCO

#define RCC_PREDIV1SRC          ((uint32_t)0x00010000) // PREDIV1 clock source
#define RCC_PREDIV1SRC_HSE      ((uint32_t)0x00000000) // HSE
#define RCC_PREDIV1SRC_PLL2     ((uint32_t)0x00010000) // PLL2 VCO

#define RCC_PLL3MUL             ((uint32_t)0x0000F000) // PLL3 multiplication factor
#define RCC_PLL3MUL_x2_5        ((uint32_t)0x00000000) // PLL3 input clock x 2.5
#define RCC_PLL3MUL_x12_5       ((uint32_t)0x00001000) // PLL3 input clock x 12.5
#define RCC_PLL3MUL_x4          ((uint32_t)0x00002000) // PLL3 input clock x 4
#define RCC_PLL3MUL_x5          ((uint32_t)0x00003000) // PLL3 input clock x 5
#define RCC_PLL3MUL_x6          ((uint32_t)0x00004000) // PLL3 input clock x 6
#define RCC_PLL3MUL_x7          ((uint32_t)0x00005000) // PLL3 input clock x 7
#define RCC_PLL3MUL_x8          ((uint32_t)0x00006000) // PLL3 input clock x 8
#define RCC_PLL3MUL_x9          ((uint32_t)0x00007000) // PLL3 input clock x 9
#define RCC_PLL3MUL_x10         ((uint32_t)0x00008000) // PLL3 input clock x 10
#define RCC_PLL3MUL_x11         ((uint32_t)0x00009000) // PLL3 input clock x 11
#define RCC_PLL3MUL_x12         ((uint32_t)0x0000A000) // PLL3 input clock x 12
#define RCC_PLL3MUL_x13         ((uint32_t)0x0000B000) // PLL3 input clock x 13
#define RCC_PLL3MUL_x14         ((uint32_t)0x0000C000) // PLL3 input clock x 14
#define RCC_PLL3MUL_x15         ((uint32_t)0x0000D000) // PLL3 input clock x 15
#define RCC_PLL3MUL_x16         ((uint32_t)0x0000E000) // PLL3 input clock x 16
#define RCC_PLL3MUL_x20         ((uint32_t)0x0000F000) // PLL3 input clock x 20

#define RCC_PLL2MUL             ((uint32_t)0x00000F00) // PLL2 multiplication factor
#define RCC_PLL2MUL_x2_5        ((uint32_t)0x00000000) // PLL2 input clock x 2.5
#define RCC_PLL2MUL_x12_5       ((uint32_t)0x00000100) // PLL2 input clock x 12.5
#define RCC_PLL2MUL_x4          ((uint32_t)0x00000200) // PLL2 input clock x 4
#define RCC_PLL2MUL_x5          ((uint32_t)0x00000300) // PLL2 input clock x 5
#define RCC_PLL2MUL_x6          ((uint32_t)0x00000400) // PLL2 input clock x 6
#define RCC_PLL2MUL_x7          ((uint32_t)0x00000500) // PLL2 input clock x 7
#define RCC_PLL2MUL_x8          ((uint32_t)0x00000600) // PLL2 input clock x 8
#define RCC_PLL2MUL_x9          ((uint32_t)0x00000700) // PLL2 input clock x 9
#define RCC_PLL2MUL_x10         ((uint32_t)0x00000800) // PLL2 input clock x 10
#define RCC_PLL2MUL_x11         ((uint32_t)0x00000900) // PLL2 input clock x 11
#define RCC_PLL2MUL_x12         ((uint32_t)0x00000A00) // PLL2 input clock x 12
#define RCC_PLL2MUL_x13         ((uint32_t)0x00000B00) // PLL2 input clock x 13
#define RCC_PLL2MUL_x14         ((uint32_t)0x00000C00) // PLL2 input clock x 14
#define RCC_PLL2MUL_x15         ((uint32_t)0x00000D00) // PLL2 input clock x 15
#define RCC_PLL2MUL_x16         ((uint32_t)0x00000E00) // PLL2 input clock x 16
#define RCC_PLL2MUL_x20         ((uint32_t)0x00000F00) // PLL2 input clock x 20

#define RCC_PREDIV2             ((uint32_t)0x000000F0) // PREDIV2 prescaler factor
#define RCC_PREDIV2_NODIV       ((uint32_t)0x00000000) // PREDIV2 not divided
#define RCC_PREDIV2_DIV2        ((uint32_t)0x00000010) // PREDIV2 input clock divided by 2
#define RCC_PREDIV2_DIV3        ((uint32_t)0x00000020) // PREDIV2 input clock divided by 3
#define RCC_PREDIV2_DIV4        ((uint32_t)0x00000030) // PREDIV2 input clock divided by 4
#define RCC_PREDIV2_DIV5        ((uint32_t)0x00000040) // PREDIV2 input clock divided by 5
#define RCC_PREDIV2_DIV6        ((uint32_t)0x00000050) // PREDIV2 input clock divided by 6
#define RCC_PREDIV2_DIV7        ((uint32_t)0x00000060) // PREDIV2 input clock divided by 7
#define RCC_PREDIV2_DIV8        ((uint32_t)0x00000070) // PREDIV2 input clock divided by 8
#define RCC_PREDIV2_DIV9        ((uint32_t)0x00000080) // PREDIV2 input clock divided by 9
#define RCC_PREDIV2_DIV10       ((uint32_t)0x00000090) // PREDIV2 input clock divided by 10
#define RCC_PREDIV2_DIV11       ((uint32_t)0x000000A0) // PREDIV2 input clock divided by 11
#define RCC_PREDIV2_DIV12       ((uint32_t)0x000000B0) // PREDIV2 input clock divided by 12
#define RCC_PREDIV2_DIV13       ((uint32_t)0x000000C0) // PREDIV2 input clock divided by 13
#define RCC_PREDIV2_DIV14       ((uint32_t)0x000000D0) // PREDIV2 input clock divided by 14
#define RCC_PREDIV2_DIV15       ((uint32_t)0x000000E0) // PREDIV2 input clock divided by 15
#define RCC_PREDIV2_DIV16       ((uint32_t)0x000000F0) // PREDIV2 input clock divided by 16

#define RCC_PREDIV1             ((uint32_t)0x0000000F) // PREDIV1 prescaler factor
#define RCC_PREDIV1_NODIV       ((uint32_t)0x00000000) // PREDIV1 not divided
#define RCC_PREDIV1_DIV2        ((uint32_t)0x00000001) // PREDIV1 input clock divided by 2
#define RCC_PREDIV1_DIV3        ((uint32_t)0x00000002) // PREDIV1 input clock divided by 3
#define RCC_PREDIV1_DIV4        ((uint32_t)0x00000003) // PREDIV1 input clock divided by 4
#define RCC_PREDIV1_DIV5        ((uint32_t)0x00000004) // PREDIV1 input clock divided by 5
#define RCC_PREDIV1_DIV6        ((uint32_t)0x00000005) // PREDIV1 input clock divided by 6
#define RCC_PREDIV1_DIV7        ((uint32_t)0x00000006) // PREDIV1 input clock divided by 7
#define RCC_PREDIV1_DIV8        ((uint32_t)0x00000007) // PREDIV1 input clock divided by 8
#define RCC_PREDIV1_DIV9        ((uint32_t)0x00000008) // PREDIV1 input clock divided by 9
#define RCC_PREDIV1_DIV10       ((uint32_t)0x00000009) // PREDIV1 input clock divided by 10
#define RCC_PREDIV1_DIV11       ((uint32_t)0x0000000A) // PREDIV1 input clock divided by 11
#define RCC_PREDIV1_DIV12       ((uint32_t)0x0000000B) // PREDIV1 input clock divided by 12
#define RCC_PREDIV1_DIV13       ((uint32_t)0x0000000C) // PREDIV1 input clock divided by 13
#define RCC_PREDIV1_DIV14       ((uint32_t)0x0000000D) // PREDIV1 input clock divided by 14
#define RCC_PREDIV1_DIV15       ((uint32_t)0x0000000E) // PREDIV1 input clock divided by 15
#define RCC_PREDIV1_DIV16       ((uint32_t)0x0000000F) // PREDIV1 input clock divided by 16

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_RCC_H
