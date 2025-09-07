//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_AFIO.h
// Version     : V1.0
// Date        : 18-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Alternate Function Header File.
//==============================================================================

#ifndef __CH32V307_AFIO_H
#define __CH32V307_AFIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t ECR;
    __IO uint32_t PCFR1;
    __IO uint32_t EXTICR1;
    __IO uint32_t EXTICR2;
    __IO uint32_t EXTICR3;
    __IO uint32_t EXTICR4;
    __IO uint32_t PCFR2;
} AFIO_TypeDef;

#define AFIO        ((AFIO_TypeDef *)AFIO_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for AFIO_PCFR1 register  ==================
#define AFIO_ECR_EVOE       ((uint32_t)0x00000080) // Event output enable

#define AFIO_ECR_PORT       ((uint32_t)0x00000070) // Select port of core output EVENTOUT
#define AFIO_ECR_PORT_PA    ((uint32_t)0x00000000) // PA port
#define AFIO_ECR_PORT_PB    ((uint32_t)0x00000010) // PB port
#define AFIO_ECR_PORT_PC    ((uint32_t)0x00000020) // PC port
#define AFIO_ECR_PORT_PD    ((uint32_t)0x00000030) // PD port

#define AFIO_ECR_PIN        ((uint32_t)0x0000000F) // Select number bit of port

//==================  Bit definition for AFIO_PCFR1 register  ==================
#define AFIO_PCFR1_PTP_PPS_RM           ((uint32_t)0x40000000) // Ethernet PTP PPS remap
#define AFIO_PCFR1_TIM2ITR1_RM          ((uint32_t)0x20000000) // TIM2 internal trigger1 remap

#define AFIO_PCFR1_SPI3_RM              ((uint32_t)0x10000000) // SPI3 remap
#define AFIO_PCFR1_SPI3_RM_DEF          ((uint32_t)0x00000000) // SPI3 no remap (PA15/PB3/PB4/PB5)
#define AFIO_PCFR1_SPI3_RM_FULL         ((uint32_t)0x10000000) // SPI3 remap (PA4/PC10/PC11/PC12)

#define AFIO_PCFR1_SW_CFG               ((uint32_t)0x07000000) // Configure IO port with SW function
#define AFIO_PCFR1_SW_CFG_SWDEN         ((uint32_t)0x00000000) // SWD enabled (SDI)
#define AFIO_PCFR1_SW_CFG_SWDDIS        ((uint32_t)0x04000000) // SWD disabled (SDI), served as GPIO

#define AFIO_PCFR1_MII_RMII_SEL         ((uint32_t)0x00800000) // MII or RMII selection
#define AFIO_PCFR1_MII_SEL              ((uint32_t)0x00000000) // MII select
#define AFIO_PCFR1_RMII_SEL             ((uint32_t)0x00800000) // RMII select

#define AFIO_PCFR1_CAN2_RM              ((uint32_t)0x00400000) // CAN2 remap
#define AFIO_PCFR1_CAN2_RM_DEF          ((uint32_t)0x00000000) // CAN no remap (PB12/PB13)
#define AFIO_PCFR1_CAN2_RM_FULL         ((uint32_t)0x00400000) // CAN remap (PB5/PB6)

#define AFIO_PCFR1_ETH_RM               ((uint32_t)0x00200000) // ETH remap
#define AFIO_PCFR1_ETH_RM_DEF           ((uint32_t)0x00000000) // ETH no remap (PA7/PC4/PC5/PB0/PB1)
#define AFIO_PCFR1_ETH_RM_FULL          ((uint32_t)0x00200000) // ETH remap (PD8/PD9/PD10/PD11/PD12)

#define AFIO_PCFR1_ADC2_REG_RM          ((uint32_t)0x00100000) // Remap ADC2 external trigger regular conv.
#define AFIO_PCFR1_ADC2_REG_RM_EXTI11   ((uint32_t)0x00000000) // EXTI11
#define AFIO_PCFR1_ADC2_REG_RM_T8TRGO   ((uint32_t)0x00100000) // TIM8_TRGO

#define AFIO_PCFR1_ADC2_INJ_RM          ((uint32_t)0x00080000) // Remap ADC2 external trigger injection conv.
#define AFIO_PCFR1_ADC2_INJ_RM_EXTI15   ((uint32_t)0x00000000) // EXTI15
#define AFIO_PCFR1_ADC2_INJ_RM_T8CH4    ((uint32_t)0x00080000) // TIM8_CH4

#define AFIO_PCFR1_ADC1_REG_RM          ((uint32_t)0x00040000) // Remap ADC1 external trigger regular conv.
#define AFIO_PCFR1_ADC1_REG_RM_EXTI11   ((uint32_t)0x00000000) // EXTI11
#define AFIO_PCFR1_ADC1_REG_RM_T8TRGO   ((uint32_t)0x00040000) // TIM8_TRGO

#define AFIO_PCFR1_ADC1_INJ_RM          ((uint32_t)0x00020000) // Remap ADC1 external trigger injection conv.
#define AFIO_PCFR1_ADC1_INJ_RM_EXTI15   ((uint32_t)0x00000000) // EXTI15
#define AFIO_PCFR1_ADC1_INJ_RM_T8CH4    ((uint32_t)0x00020000) // TIM8_CH4

#define AFIO_PCFR1_TIM5CH4_RM           ((uint32_t)0x00010000) // TIM5 channel 4 remap
#define AFIO_PCFR1_TIM5CH4_RM_DEF       ((uint32_t)0x00000000) // Default mapping
#define AFIO_PCFR1_TIM5CH4_RM_LSI       ((uint32_t)0x00010000) // TIM5 channel 4 mapped to the LSI clock

#define AFIO_PCFR1_PD01_RM              ((uint32_t)0x00008000) // Pins PD0/PD1 remap
#define AFIO_PCFR1_PD01_RM_XO           ((uint32_t)0x00000000) // Pins is used as oscillator
#define AFIO_PCFR1_PD01_RM_GPIO         ((uint32_t)0x00008000) // Pins are used as GPIO ports

#define AFIO_PCFR1_CAN1_RM              ((uint32_t)0x00006000) // CAN1 remapping (RX/TX)
#define AFIO_PCFR1_CAN1_RM_DEF          ((uint32_t)0x00000000) // Default mapping PA11/PA12
#define AFIO_PCFR1_CAN1_RM_F1           ((uint32_t)0x00004000) // Full remapping PB8/PB9
#define AFIO_PCFR1_CAN1_RM_F2           ((uint32_t)0x00006000) // Full remapping PD0/PD1

#define AFIO_PCFR1_TIM4_RM              ((uint32_t)0x00001000) // TIM4 remap (CH1/CH2/CH3/CH4)
#define AFIO_PCFR1_TIM4_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PB6/PB7/PB8/PB9)
#define AFIO_PCFR1_TIM4_RM_FULL         ((uint32_t)0x00001000) // Full remapping (PD12/PD13/PD14/PD15)

#define AFIO_PCFR1_TIM3_RM              ((uint32_t)0x00000C00) // TIM3 remapping (CH1/CH2/CH3/CH4)
#define AFIO_PCFR1_TIM3_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA6/PA7/PB0/PB1)
#define AFIO_PCFR1_TIM3_RM_PART         ((uint32_t)0x00000800) // Partial remapping (PB4/PB5/PB0/PB1)
#define AFIO_PCFR1_TIM3_RM_FULL         ((uint32_t)0x00000C00) // Complete remapping (PC6/PC7/PC8/PC9)

#define AFIO_PCFR1_TIM2_RM              ((uint32_t)0x00000300) // TIM2 remapping (ETR/CH1/CH2/CH3/CH4)
#define AFIO_PCFR1_TIM2_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA0/PA0/PA1/PA2/PA3)
#define AFIO_PCFR1_TIM2_RM_P1           ((uint32_t)0x00000100) // Partial remapping (PA15/PA15/PB3/PA2/PA3)
#define AFIO_PCFR1_TIM2_RM_P2           ((uint32_t)0x00000200) // Partial remapping (PA0/PA0/PA1/PB10/PB11)
#define AFIO_PCFR1_TIM2_RM_FULL         ((uint32_t)0x00000300) // Complete remapping (PA15/PA15/PB3/PB10/PB11)

#define AFIO_PCFR1_TIM1_RM              ((uint32_t)0x000000C0) // TIM1 remapping (ETR/CH1/CH2/CH3/CH4/BKIN/CH1N/CH2N/CH3N)
#define AFIO_PCFR1_TIM1_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA12/PA8/PA9/PA10/PA11/PB12/PB13/PB14/PB15)
#define AFIO_PCFR1_TIM1_RM_PART         ((uint32_t)0x00000040) // Partial remapping (PA12/PA8/PA9/PA10/PA11/PA6/PA7/PB0/PB1)
#define AFIO_PCFR1_TIM1_RM_FULL         ((uint32_t)0x000000C0) // Complete remapping (PE7/PE9/PE11/PE13/PE14/PE15/PE8/PE10/PB1)

#define AFIO_PCFR1_USART3_RM            ((uint32_t)0x00000030) // USART3 remapping (TX/RX/CK/CTS/RTS)
#define AFIO_PCFR1_USART3_RM_DEF        ((uint32_t)0x00000000) // Default mapping (PB10/PB11/PB12/PB13/PB14)
#define AFIO_PCFR1_USART3_RM_P1         ((uint32_t)0x00000010) // Partial remapping (PC10/PC11/PC12/PB13/PB14)
#define AFIO_PCFR1_USART3_RM_P2         ((uint32_t)0x00000020) // Partial remapping (PA13/PA14/PD10/PD11/PD12)
#define AFIO_PCFR1_USART3_RM_FULL       ((uint32_t)0x00000030) // Complete remapping (PD8/PD9/PD10/PD11/PD12)

#define AFIO_PCFR1_USART2_RM            ((uint32_t)0x00000008) // USART2 remapping (TX/RX/CK/CTS/RTS)
#define AFIO_PCFR1_USART2_RM_DEF        ((uint32_t)0x00000000) // Default mapping (PA2/PA3/PA4/PA0/PA1)
#define AFIO_PCFR1_USART2_RM_FULL       ((uint32_t)0x00000008) // Complete remapping (PD5/PD6/PD7/PD3/PD4)

#define AFIO_PCFR1_USART1_RM0           ((uint32_t)0x00000004) // USART1 remapping (with AFIO_PCFR2_USART1_RM1 reg.)

#define AFIO_PCFR1_I2C1_RM              ((uint32_t)0x00000002) // I2C1 remapping (SCL/SDA)
#define AFIO_PCFR1_I2C1_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PB6/PB7)
#define AFIO_PCFR1_I2C1_RM_FULL         ((uint32_t)0x00000002) // Complete remapping (PB8/PB9)

#define AFIO_PCFR1_SPI1_RM              ((uint32_t)0x00000001) // SPI1 remapping (NSS/SCK/MISO/MOSI)
#define AFIO_PCFR1_SPI1_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA4/PA5/PA6/PA7)
#define AFIO_PCFR1_SPI1_RM_FULL         ((uint32_t)0x00000001) // Complete remapping (PA15/PB3/PB4/PB5)

//=================  Bit definition for AFIO_EXTICR1 register  =================
#define AFIO_EXTICR1_EXTI3              ((uint32_t)0x0000F000) // EXTI 3 configuration
#define AFIO_EXTICR1_EXTI3_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR1_EXTI3_PB           ((uint32_t)0x00001000) // PB[3] pin
#define AFIO_EXTICR1_EXTI3_PC           ((uint32_t)0x00002000) // PC[3] pin
#define AFIO_EXTICR1_EXTI3_PD           ((uint32_t)0x00003000) // PD[3] pin
#define AFIO_EXTICR1_EXTI3_PE           ((uint32_t)0x00004000) // PE[3] pin

#define AFIO_EXTICR1_EXTI2              ((uint32_t)0x00000F00) // EXTI 2 configuration
#define AFIO_EXTICR1_EXTI2_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR1_EXTI2_PB           ((uint32_t)0x00000100) // PB[3] pin
#define AFIO_EXTICR1_EXTI2_PC           ((uint32_t)0x00000200) // PC[3] pin
#define AFIO_EXTICR1_EXTI2_PD           ((uint32_t)0x00000300) // PD[3] pin
#define AFIO_EXTICR1_EXTI2_PE           ((uint32_t)0x00000400) // PE[3] pin

#define AFIO_EXTICR1_EXTI1              ((uint32_t)0x000000F0) // EXTI 1 configuration
#define AFIO_EXTICR1_EXTI1_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR1_EXTI1_PB           ((uint32_t)0x00000010) // PB[3] pin
#define AFIO_EXTICR1_EXTI1_PC           ((uint32_t)0x00000020) // PC[3] pin
#define AFIO_EXTICR1_EXTI1_PD           ((uint32_t)0x00000030) // PD[3] pin
#define AFIO_EXTICR1_EXTI1_PE           ((uint32_t)0x00000040) // PE[3] pin

#define AFIO_EXTICR1_EXTI0              ((uint32_t)0x0000000F) // EXTI 0 configuration
#define AFIO_EXTICR1_EXTI0_PA           ((uint32_t)0x00000000) // PA[0] pin
#define AFIO_EXTICR1_EXTI0_PB           ((uint32_t)0x00000001) // PB[3] pin
#define AFIO_EXTICR1_EXTI0_PC           ((uint32_t)0x00000002) // PC[3] pin
#define AFIO_EXTICR1_EXTI0_PD           ((uint32_t)0x00000003) // PD[3] pin
#define AFIO_EXTICR1_EXTI0_PE           ((uint32_t)0x00000004) // PE[3] pin

//=================  Bit definition for AFIO_EXTICR2 register  =================
#define AFIO_EXTICR2_EXTI7              ((uint32_t)0x0000F000) // EXTI 7 configuration
#define AFIO_EXTICR2_EXTI7_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR2_EXTI7_PB           ((uint32_t)0x00001000) // PB[3] pin
#define AFIO_EXTICR2_EXTI7_PC           ((uint32_t)0x00002000) // PC[3] pin
#define AFIO_EXTICR2_EXTI7_PD           ((uint32_t)0x00003000) // PD[3] pin
#define AFIO_EXTICR2_EXTI7_PE           ((uint32_t)0x00004000) // PE[3] pin

#define AFIO_EXTICR2_EXTI6              ((uint32_t)0x00000F00) // EXTI 6 configuration
#define AFIO_EXTICR2_EXTI6_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR2_EXTI6_PB           ((uint32_t)0x00000100) // PB[3] pin
#define AFIO_EXTICR2_EXTI6_PC           ((uint32_t)0x00000200) // PC[3] pin
#define AFIO_EXTICR2_EXTI6_PD           ((uint32_t)0x00000300) // PD[3] pin
#define AFIO_EXTICR2_EXTI6_PE           ((uint32_t)0x00000400) // PE[3] pin

#define AFIO_EXTICR2_EXTI5              ((uint32_t)0x000000F0) // EXTI 5 configuration
#define AFIO_EXTICR2_EXTI5_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR2_EXTI5_PB           ((uint32_t)0x00000010) // PB[3] pin
#define AFIO_EXTICR2_EXTI5_PC           ((uint32_t)0x00000020) // PC[3] pin
#define AFIO_EXTICR2_EXTI5_PD           ((uint32_t)0x00000030) // PD[3] pin
#define AFIO_EXTICR2_EXTI5_PE           ((uint32_t)0x00000040) // PE[3] pin

#define AFIO_EXTICR2_EXTI4              ((uint32_t)0x0000000F) // EXTI 4 configuration
#define AFIO_EXTICR2_EXTI4_PA           ((uint32_t)0x00000000) // PA[0] pin
#define AFIO_EXTICR2_EXTI4_PB           ((uint32_t)0x00000001) // PB[3] pin
#define AFIO_EXTICR2_EXTI4_PC           ((uint32_t)0x00000002) // PC[3] pin
#define AFIO_EXTICR2_EXTI4_PD           ((uint32_t)0x00000003) // PD[3] pin
#define AFIO_EXTICR2_EXTI4_PE           ((uint32_t)0x00000004) // PE[3] pin

//=================  Bit definition for AFIO_EXTICR3 register  =================
#define AFIO_EXTICR3_EXTI11             ((uint32_t)0x0000F000) // EXTI 11 configuration
#define AFIO_EXTICR3_EXTI11_PA          ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR3_EXTI11_PB          ((uint32_t)0x00001000) // PB[3] pin
#define AFIO_EXTICR3_EXTI11_PC          ((uint32_t)0x00002000) // PC[3] pin
#define AFIO_EXTICR3_EXTI11_PD          ((uint32_t)0x00003000) // PD[3] pin
#define AFIO_EXTICR3_EXTI11_PE          ((uint32_t)0x00004000) // PE[3] pin

#define AFIO_EXTICR3_EXTI10             ((uint32_t)0x00000F00) // EXTI 10 configuration
#define AFIO_EXTICR3_EXTI10_PA          ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR3_EXTI10_PB          ((uint32_t)0x00000100) // PB[3] pin
#define AFIO_EXTICR3_EXTI10_PC          ((uint32_t)0x00000200) // PC[3] pin
#define AFIO_EXTICR3_EXTI10_PD          ((uint32_t)0x00000300) // PD[3] pin
#define AFIO_EXTICR3_EXTI10_PE          ((uint32_t)0x00000400) // PE[3] pin

#define AFIO_EXTICR3_EXTI9              ((uint32_t)0x000000F0) // EXTI 9 configuration
#define AFIO_EXTICR3_EXTI9_PA           ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR3_EXTI9_PB           ((uint32_t)0x00000010) // PB[3] pin
#define AFIO_EXTICR3_EXTI9_PC           ((uint32_t)0x00000020) // PC[3] pin
#define AFIO_EXTICR3_EXTI9_PD           ((uint32_t)0x00000030) // PD[3] pin
#define AFIO_EXTICR3_EXTI9_PE           ((uint32_t)0x00000040) // PE[3] pin

#define AFIO_EXTICR3_EXTI8              ((uint32_t)0x0000000F) // EXTI 8 configuration
#define AFIO_EXTICR3_EXTI8_PA           ((uint32_t)0x00000000) // PA[0] pin
#define AFIO_EXTICR3_EXTI8_PB           ((uint32_t)0x00000001) // PB[3] pin
#define AFIO_EXTICR3_EXTI8_PC           ((uint32_t)0x00000002) // PC[3] pin
#define AFIO_EXTICR3_EXTI8_PD           ((uint32_t)0x00000003) // PD[3] pin
#define AFIO_EXTICR3_EXTI8_PE           ((uint32_t)0x00000004) // PE[3] pin

//=================  Bit definition for AFIO_EXTICR4 register  =================
#define AFIO_EXTICR4_EXTI15             ((uint32_t)0x0000F000) // EXTI 15 configuration
#define AFIO_EXTICR4_EXTI15_PA          ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR4_EXTI15_PB          ((uint32_t)0x00001000) // PB[3] pin
#define AFIO_EXTICR4_EXTI15_PC          ((uint32_t)0x00002000) // PC[3] pin
#define AFIO_EXTICR4_EXTI15_PD          ((uint32_t)0x00003000) // PD[3] pin
#define AFIO_EXTICR4_EXTI15_PE          ((uint32_t)0x00004000) // PE[3] pin

#define AFIO_EXTICR4_EXTI14             ((uint32_t)0x00000F00) // EXTI 14 configuration
#define AFIO_EXTICR4_EXTI14_PA          ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR4_EXTI14_PB          ((uint32_t)0x00000100) // PB[3] pin
#define AFIO_EXTICR4_EXTI14_PC          ((uint32_t)0x00000200) // PC[3] pin
#define AFIO_EXTICR4_EXTI14_PD          ((uint32_t)0x00000300) // PD[3] pin
#define AFIO_EXTICR4_EXTI14_PE          ((uint32_t)0x00000400) // PE[3] pin

#define AFIO_EXTICR4_EXTI13             ((uint32_t)0x000000F0) // EXTI 13 configuration
#define AFIO_EXTICR4_EXTI13_PA          ((uint32_t)0x00000000) // PA[3] pin
#define AFIO_EXTICR4_EXTI13_PB          ((uint32_t)0x00000010) // PB[3] pin
#define AFIO_EXTICR4_EXTI13_PC          ((uint32_t)0x00000020) // PC[3] pin
#define AFIO_EXTICR4_EXTI13_PD          ((uint32_t)0x00000030) // PD[3] pin
#define AFIO_EXTICR4_EXTI13_PE          ((uint32_t)0x00000040) // PE[3] pin

#define AFIO_EXTICR4_EXTI12             ((uint32_t)0x0000000F) // EXTI 12 configuration
#define AFIO_EXTICR4_EXTI12_PA          ((uint32_t)0x00000000) // PA[0] pin
#define AFIO_EXTICR4_EXTI12_PB          ((uint32_t)0x00000001) // PB[3] pin
#define AFIO_EXTICR4_EXTI12_PC          ((uint32_t)0x00000002) // PC[3] pin
#define AFIO_EXTICR4_EXTI12_PD          ((uint32_t)0x00000003) // PD[3] pin
#define AFIO_EXTICR4_EXTI12_PE          ((uint32_t)0x00000004) // PE[3] pin

//==================  Bit definition for AFIO_PCFR2 register  ==================
#define AFIO_PCFR2_USART1_RM1           ((uint32_t)0x04000000) // USART1 remapping (with AFIO_PCFR1_USART1_RM0 reg.)

#define AFIO_PCFR2_UART8_RM             ((uint32_t)0x03000000) // UART8 remapping (TX/RX)
#define AFIO_PCFR2_UART8_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC4/PC5)
#define AFIO_PCFR2_UART8_RM_F1          ((uint32_t)0x01000000) // Remapping (PA14/PA15)
#define AFIO_PCFR2_UART8_RM_F2          ((uint32_t)0x02000000) // Remapping (PE14/PE15)

#define AFIO_PCFR2_UART7_RM             ((uint32_t)0x00C00000) // UART7 remapping (TX/RX)
#define AFIO_PCFR2_UART7_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC2/PC3)
#define AFIO_PCFR2_UART7_RM_F1          ((uint32_t)0x00400000) // Remapping (PA6/PA7)
#define AFIO_PCFR2_UART7_RM_F2          ((uint32_t)0x00800000) // Remapping (PE12/PE13)

#define AFIO_PCFR2_UART6_RM             ((uint32_t)0x00300000) // UART6 remapping (TX/RX)
#define AFIO_PCFR2_UART6_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC0/PC1)
#define AFIO_PCFR2_UART6_RM_F1          ((uint32_t)0x00100000) // Remapping (PB8/PB9)
#define AFIO_PCFR2_UART6_RM_F2          ((uint32_t)0x00200000) // Remapping (PE10/PE11)

#define AFIO_PCFR2_UART5_RM             ((uint32_t)0x000C0000) // UART5 remapping (TX/RX)
#define AFIO_PCFR2_UART5_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC12/PD2)
#define AFIO_PCFR2_UART5_RM_F1          ((uint32_t)0x00040000) // Remapping (PB4/PB5)
#define AFIO_PCFR2_UART5_RM_F2          ((uint32_t)0x00080000) // Remapping (PE8/PE9)

#define AFIO_PCFR2_UART4_RM             ((uint32_t)0x00030000) // UART4 remapping (TX/RX)
#define AFIO_PCFR2_UART4_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC10/PC11)
#define AFIO_PCFR2_UART4_RM_F1          ((uint32_t)0x00010000) // Remapping (PB0/PB1)
#define AFIO_PCFR2_UART4_RM_F2          ((uint32_t)0x00020000) // Remapping (PE0/PE1)

#define AFIO_PCFR2_FSMC_NADV_RM         ((uint32_t)0x00004000) // FSMC_NADV remap
#define AFIO_PCFR2_FSMC_NADV_RM_PB7     ((uint32_t)0x00000000) // FSMC_NADV is mapped to PB7
#define AFIO_PCFR2_FSMC_NADV_RM_DIS     ((uint32_t)0x00004000) // FSMC_NADV output disabled

#define AFIO_PCFR2_TIM10_RM             ((uint32_t)0x00000060) // TIM10 remapping (ETR/CH1/CH2/CH3/CH4/BKIN/CH1N/CH2N/CH3N)
#define AFIO_PCFR2_TIM10_RM_DEF         ((uint32_t)0x00000000) // Default mapping (PC10/PB8/PB9/PC3/PC11/PC12/PA12/PA13/PA14)
#define AFIO_PCFR2_TIM10_RM_PART        ((uint32_t)0x00000020) // Partial remapping (PB11/PB3/PB4/PB5/PC15/PB10/PA5/PA6/PA7)
#define AFIO_PCFR2_TIM10_RM_FULL        ((uint32_t)0x00000040) // Complete remapping (PD0/PD1/PD3/PD5/PD7/PE2/PE3/PE4/PE5)

#define AFIO_PCFR2_TIM9_RM              ((uint32_t)0x00000018) // TIM9 remapping (ETR/CH1/CH2/CH3/CH4/BKIN/CH1N/CH2N/CH3N)
#define AFIO_PCFR2_TIM9_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA2/PA2/PA3/PA4/PC4/PC5/PC0/PC1/PC2)
#define AFIO_PCFR2_TIM9_RM_PART         ((uint32_t)0x00000008) // Partial remapping (PA2/PA2/PA3/PA4/PC14/PA1/PB0/PB1/PB2)
#define AFIO_PCFR2_TIM9_RM_FULL         ((uint32_t)0x00000010) // Complete remapping (PD9/PD9/PD11/PD13/PD15/PD14/PD8/PD10/PD12)

#define AFIO_PCFR2_TIM8_RM              ((uint32_t)0x00000004) // TIM9 remapping (ETR/CH1/CH2/CH3/CH4/BKIN/CH1N/CH2N/CH3N)
#define AFIO_PCFR2_TIM8_RM_DEF          ((uint32_t)0x00000000) // Default mapping (PA0/PC6/PC7/PC8/PC9/PA6/PA7/PB0/PB1)
#define AFIO_PCFR2_TIM8_RM_FULL         ((uint32_t)0x00000004) // Complete remapping (PA0/PB6/PB7/PB8/PC13/PB9/PA13/PA14/PA15)

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_AFIO_H
