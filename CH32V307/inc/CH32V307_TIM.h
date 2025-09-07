//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_TIM.h
// Version     : V1.0
// Date        : 24-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 TIM Header File.
//==============================================================================

#ifndef __CH32V307_TIM_H
#define __CH32V307_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint16_t CTLR1;
         uint16_t :16;
    __IO uint16_t CTLR2;
         uint16_t :16;
    __IO uint16_t SMCFGR;
         uint16_t :16;
    __IO uint16_t DMAINTENR;
         uint16_t :16;
    __IO uint16_t INTFR;
         uint16_t :16;
    __O  uint16_t SWEVGR;
         uint16_t :16;
    __IO uint16_t CHCTLR1;
         uint16_t :16;
    __IO uint16_t CHCTLR2;
         uint16_t :16;
    __IO uint16_t CCER;
         uint16_t :16;
    __IO uint16_t CNT;
         uint16_t :16;
    __IO uint16_t PSC;
         uint16_t :16;
    __IO uint16_t ATRLR;
         uint16_t :16;
    __IO uint16_t RPTCR;
         uint16_t :16;
    __IO uint32_t CH1CVR;
    __IO uint32_t CH2CVR;
    __IO uint32_t CH3CVR;
    __IO uint32_t CH4CVR;
    __IO uint16_t BDTR;
         uint16_t :16;
    __IO uint16_t DMACFGR;
         uint16_t :16;
    __IO uint16_t DMAADR;
         uint16_t :16;
         uint16_t AUX;
} TIM_ADTM_TypeDef;

typedef struct
{
    __IO uint16_t CTLR1;
         uint16_t :16;
    __IO uint16_t CTLR2;
         uint16_t :16;
    __IO uint16_t SMCFGR;
         uint16_t :16;
    __IO uint16_t DMAINTENR;
         uint16_t :16;
    __IO uint16_t INTFR;
         uint16_t :16;
    __O  uint16_t SWEVGR;
         uint16_t :16;
    __IO uint16_t CHCTLR1;
         uint16_t :16;
    __IO uint16_t CHCTLR2;
         uint16_t :16;
    __IO uint16_t CCER;
         uint16_t :16;
    __IO uint16_t CNT;
         uint16_t :16;
    __IO uint16_t PSC;
         uint16_t :16;
    __IO uint16_t ATRLR;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
    __IO uint32_t CH1CVR;
    __IO uint32_t CH2CVR;
    __IO uint32_t CH3CVR;
    __IO uint32_t CH4CVR;
         uint16_t :16;
         uint16_t :16;
    __IO uint16_t DMACFGR;
         uint16_t :16;
    __IO uint16_t DMAADR;
         uint16_t :16;
         uint16_t AUX;
} TIM_GPTM_TypeDef;

typedef struct
{
    __IO uint16_t CTLR1;
         uint16_t :16;
    __IO uint16_t CTLR2;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
    __IO uint16_t DMAINTENR;
         uint16_t :16;
    __IO uint16_t INTFR;
         uint16_t :16;
    __O  uint16_t SWEVGR;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
    __IO uint16_t CNT;
         uint16_t :16;
    __IO uint16_t PSC;
         uint16_t :16;
    __IO uint16_t ATRLR;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
         uint16_t :16;
} TIM_BCTM_TypeDef;

#define TIM1                                    ((TIM_ADTM_TypeDef *)TIM1_BASE)
#define TIM8                                    ((TIM_ADTM_TypeDef *)TIM8_BASE)
#define TIM9                                    ((TIM_ADTM_TypeDef *)TIM9_BASE)
#define TIM10                                   ((TIM_ADTM_TypeDef *)TIM10_BASE)

#define TIM2                                    ((TIM_GPTM_TypeDef *)TIM2_BASE)
#define TIM3                                    ((TIM_GPTM_TypeDef *)TIM3_BASE)
#define TIM4                                    ((TIM_GPTM_TypeDef *)TIM4_BASE)
#define TIM5                                    ((TIM_GPTM_TypeDef *)TIM5_BASE)

#define TIM6                                    ((TIM_BCTM_TypeDef *)TIM6_BASE)
#define TIM7                                    ((TIM_BCTM_TypeDef *)TIM7_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for TIM_CTLR1 register  ===================
#define TIM_CTLR1_CKD        ((uint16_t)0x0300) // CKD[1:0] bits (clock division)
#define TIM_CKD_x1           ((uint16_t)0x0000) // Tdts = Tck_int
#define TIM_CKD_x2           ((uint16_t)0x0100) // Tdts = 2 x Tck_int
#define TIM_CKD_x4           ((uint16_t)0x0200) // Tdts = 4 x Tck_int

#define TIM_ARPE             ((uint16_t)0x0080) // Auto-reload preload enable

#define TIM_CMS              ((uint16_t)0x0060) // CMS[1:0] bits (Center-aligned mode selection)
#define TIM_CMS_Edge_mode    ((uint16_t)0x0000) // Edge-aligned mode
#define TIM_CMS_Cent1_mode   ((uint16_t)0x0020) // Central alignment mode 1
#define TIM_CMS_Cent2_mode   ((uint16_t)0x0040) // Central alignment mode 2
#define TIM_CMS_Cent3_mode   ((uint16_t)0x0060) // Central alignment mode 3

#define TIM_DIR              ((uint16_t)0x0010) // Direction
#define TIM_OPM              ((uint16_t)0x0008) // One pulse mode
#define TIM_URS              ((uint16_t)0x0004) // Update request source
#define TIM_UDIS             ((uint16_t)0x0002) // Update disable
#define TIM_CEN              ((uint16_t)0x0001) // Counter enable

//==================  Bit definition for TIM_CTLR2 register  ===================
#define TIM_OIS4             ((uint16_t)0x4000) // Output Idle state 4 (OC4 output)
#define TIM_OIS3N            ((uint16_t)0x2000) // Output Idle state 3 (OC3N output)
#define TIM_OIS3             ((uint16_t)0x1000) // Output Idle state 3 (OC3 output)
#define TIM_OIS2N            ((uint16_t)0x0800) // Output Idle state 2 (OC2N output)
#define TIM_OIS2             ((uint16_t)0x0400) // Output Idle state 2 (OC2 output)
#define TIM_OIS1N            ((uint16_t)0x0200) // Output Idle state 1 (OC1N output)
#define TIM_OIS1             ((uint16_t)0x0100) // Output Idle state 1 (OC1 output)

#define TIM_TI1S             ((uint16_t)0x0080) // TI1 Selection

#define TIM_MMS              ((uint16_t)0x0070) // MMS[2:0] bits (Master Mode Selection)
#define TIM_MMS_UG           ((uint16_t)0x0000) // UG bit used as the TRGO
#define TIM_MMS_CNT_EN       ((uint16_t)0x0010) // The counter enable signal is used as TRGO
#define TIM_MMS_Update       ((uint16_t)0x0020) // The update event is selected as TRGO
#define TIM_MMS_CC1IF        ((uint16_t)0x0030) // CC1IF flag used as TRGO
#define TIM_MMS_OC1REF       ((uint16_t)0x0040) // OC1REF signal used as TRGO
#define TIM_MMS_OC2REF       ((uint16_t)0x0050) // OC2REF signal used as TRGO
#define TIM_MMS_OC3REF       ((uint16_t)0x0060) // OC3REF signal used as TRGO
#define TIM_MMS_OC4REF       ((uint16_t)0x0070) // OC4REF signal used as TRGO

#define TIM_CCDS             ((uint16_t)0x0008) // Capture/Compare DMA Selection
#define TIM_CCUS             ((uint16_t)0x0004) // Capture/Compare Control Update Selection
#define TIM_CCPC             ((uint16_t)0x0001) // Capture/Compare Preloaded Control

//==================  Bit definition for TIM_SMCFGR register  ==================
#define TIM_ETP              ((uint16_t)0x8000) // External trigger polarity
#define TIM_ECE              ((uint16_t)0x4000) // External clock enable

#define TIM_ETPS             ((uint16_t)0x3000) // ETPS[1:0] bits (External trigger prescaler)
#define TIM_ETPS_OFF         ((uint16_t)0x0000) // Prescaler off
#define TIM_ETPS_DIV2        ((uint16_t)0x1000) // ETRP frequency divicder by 2
#define TIM_ETPS_DIV4        ((uint16_t)0x2000) // ETRP frequency divicder by 4
#define TIM_ETPS_DIV8        ((uint16_t)0x3000) // ETRP frequency divicder by 8

#define TIM_ETF              ((uint16_t)0x0F00) // ETF[3:0] bits (External trigger filter)
#define TIM_ETF_OFF          ((uint16_t)0x0000) // Filter off
#define TIM_ETF_INT_2        ((uint16_t)0x0100) // Sampling frequency Fsampling = Fck_int, N = 2
#define TIM_ETF_INT_4        ((uint16_t)0x0200) // Sampling frequency Fsampling = Fck_int, N = 4
#define TIM_ETF_INT_8        ((uint16_t)0x0300) // Sampling frequency Fsampling = Fck_int, N = 8
#define TIM_ETF_DTS_2_6      ((uint16_t)0x0400) // Sampling frequency Fsampling = Fdts/2,  N = 6
#define TIM_ETF_DTS_2_8      ((uint16_t)0x0500) // Sampling frequency Fsampling = Fdts/2,  N = 8
#define TIM_ETF_DTS_4_6      ((uint16_t)0x0600) // Sampling frequency Fsampling = Fdts/4,  N = 6
#define TIM_ETF_DTS_4_8      ((uint16_t)0x0700) // Sampling frequency Fsampling = Fdts/4,  N = 8
#define TIM_ETF_DTS_8_6      ((uint16_t)0x0800) // Sampling frequency Fsampling = Fdts/8,  N = 6
#define TIM_ETF_DTS_8_8      ((uint16_t)0x0900) // Sampling frequency Fsampling = Fdts/8,  N = 8
#define TIM_ETF_DTS_16_5     ((uint16_t)0x0A00) // Sampling frequency Fsampling = Fdts/16, N = 5
#define TIM_ETF_DTS_16_6     ((uint16_t)0x0B00) // Sampling frequency Fsampling = Fdts/16, N = 6
#define TIM_ETF_DTS_16_8     ((uint16_t)0x0C00) // Sampling frequency Fsampling = Fdts/16, N = 8
#define TIM_ETF_DTS_32_5     ((uint16_t)0x0D00) // Sampling frequency Fsampling = Fdts/32, N = 5
#define TIM_ETF_DTS_32_6     ((uint16_t)0x0E00) // Sampling frequency Fsampling = Fdts/32, N = 6
#define TIM_ETF_DTS_32_8     ((uint16_t)0x0F00) // Sampling frequency Fsampling = Fdts/32, N = 8

#define TIM_MSM              ((uint16_t)0x0080) // Master/slave mode

#define TIM_TS               ((uint16_t)0x0070) // TS[2:0] bits (Trigger selection)
#define TIM_TS_ITR0          ((uint16_t)0x0000) // Internal trigger 0 (ITR0)
#define TIM_TS_ITR1          ((uint16_t)0x0010) // Internal trigger 1 (ITR1)
#define TIM_TS_ITR2          ((uint16_t)0x0020) // Internal trigger 2 (ITR2)
#define TIM_TS_ITR3          ((uint16_t)0x0030) // Internal trigger 3 (ITR3)
#define TIM_TS_TI1F_ED       ((uint16_t)0x0040) // Edge detector of TI1 (TI1F_ED)
#define TIM_TS_TI1FP1        ((uint16_t)0x0050) // Filtered timer input 1 (TI1FP1)
#define TIM_TS_TI1FP2        ((uint16_t)0x0060) // Filtered timer input 2 (TI1FP2)
#define TIM_TS_ETRF          ((uint16_t)0x0070) // External trigger input (ETRF)

#define TIM_SMS              ((uint16_t)0x0007) // SMS[2:0] bits (Slave mode selection)
#define TIM_SMS_CKINT        ((uint16_t)0x0000) // Driver by the internal clock CK_INT
#define TIM_SMS_ENCM1        ((uint16_t)0x0001) // Encoder mode 1
#define TIM_SMS_ENCM2        ((uint16_t)0x0002) // Encoder mode 2
#define TIM_SMS_ENCM3        ((uint16_t)0x0003) // Encoder mode 3
#define TIM_SMS_GATE         ((uint16_t)0x0005) // Gated mode
#define TIM_SMS_TRIG         ((uint16_t)0x0006) // Trigger mode
#define TIM_SMS_CKEXT        ((uint16_t)0x0007) // External clock mode 1

//================  Bit definition for TIM_DMAINTENR register  =================
#define TIM_TDE              ((uint16_t)0x4000) // Trigger DMA request enable
#define TIM_COMDE            ((uint16_t)0x2000) // COM DMA request enable
#define TIM_CC4DE            ((uint16_t)0x1000) // Capture/Compare 4 DMA request enable
#define TIM_CC3DE            ((uint16_t)0x0800) // Capture/Compare 3 DMA request enable
#define TIM_CC2DE            ((uint16_t)0x0400) // Capture/Compare 2 DMA request enable
#define TIM_CC1DE            ((uint16_t)0x0200) // Capture/Compare 1 DMA request enable
#define TIM_UDE              ((uint16_t)0x0100) // Update DMA request enable
#define TIM_BIE              ((uint16_t)0x0080) // Break interrupt enable
#define TIM_TIE              ((uint16_t)0x0040) // Trigger interrupt enable
#define TIM_COMIE            ((uint16_t)0x0020) // COM interrupt enable
#define TIM_CC4IE            ((uint16_t)0x0010) // Capture/Compare 4 interrupt enable
#define TIM_CC3IE            ((uint16_t)0x0008) // Capture/Compare 3 interrupt enable
#define TIM_CC2IE            ((uint16_t)0x0004) // Capture/Compare 2 interrupt enable
#define TIM_CC1IE            ((uint16_t)0x0002) // Capture/Compare 1 interrupt enable
#define TIM_UIE              ((uint16_t)0x0001) // Update interrupt enable

//==================  Bit definition for TIM_INTFR register  ===================
#define TIM_CC4OF            ((uint16_t)0x1000) // Capture/Compare 4 Overcapture Flag
#define TIM_CC3OF            ((uint16_t)0x0800) // Capture/Compare 3 Overcapture Flag
#define TIM_CC2OF            ((uint16_t)0x0400) // Capture/Compare 2 Overcapture Flag
#define TIM_CC1OF            ((uint16_t)0x0200) // Capture/Compare 1 Overcapture Flag
#define TIM_BIF              ((uint16_t)0x0080) // Break interrupt Flag
#define TIM_TIF              ((uint16_t)0x0040) // Trigger interrupt Flag
#define TIM_COMIF            ((uint16_t)0x0020) // COM interrupt Flag
#define TIM_CC4IF            ((uint16_t)0x0010) // Capture/Compare 4 interrupt Flag
#define TIM_CC3IF            ((uint16_t)0x0008) // Capture/Compare 3 interrupt Flag
#define TIM_CC2IF            ((uint16_t)0x0004) // Capture/Compare 2 interrupt Flag
#define TIM_CC1IF            ((uint16_t)0x0002) // Capture/Compare 1 interrupt Flag
#define TIM_UIF              ((uint16_t)0x0001) // Update interrupt Flag

//==================  Bit definition for TIM_SWEVGR register  ==================
#define TIM_BG               ((uint16_t)0x0080) // Break Generation
#define TIM_TG               ((uint16_t)0x0040) // Trigger Generation
#define TIM_COMG             ((uint16_t)0x0020) // Capture/Compare Control Update Generation
#define TIM_CC4G             ((uint16_t)0x0010) // Capture/Compare 4 Generation
#define TIM_CC3G             ((uint16_t)0x0008) // Capture/Compare 3 Generation
#define TIM_CC2G             ((uint16_t)0x0004) // Capture/Compare 2 Generation
#define TIM_CC1G             ((uint16_t)0x0002) // Capture/Compare 1 Generation
#define TIM_UG               ((uint16_t)0x0001) // Update Generation

//==============  Bit definition for TIM_CHCTLR[1, 2] register  ===============
#define TIM_OC_CE            ((uint16_t)0x0080) // Output Compare Clear Enable

#define TIM_OCM              ((uint16_t)0x0070) // OCM[2:0] bits (Output Compare Mode)
#define TIM_OCM_FREEZE       ((uint16_t)0x0000) // Freeze
#define TIM_OCM_COMP_HIGH    ((uint16_t)0x0010) //
#define TIM_OCM_COMP_LOW     ((uint16_t)0x0020) //
#define TIM_OCM_FLIP         ((uint16_t)0x0030) // Flip
#define TIM_OCM_REF_LOW      ((uint16_t)0x0040) // Forces OC_REF to low
#define TIM_OCM_REF_HIGH     ((uint16_t)0x0050) // Forces OC_REF to high
#define TIM_OCM_PWM1         ((uint16_t)0x0060) // PWM mode 1
#define TIM_OCM_PWM2         ((uint16_t)0x0070) // PWM mode 2

#define TIM_ICF              ((uint16_t)0x00F0) // IC_F[3:0] bits (Input Capture Filter)
#define TIM_ICF_DTS_NF       ((uint16_t)0x0000) // No filter, sampled at DTS frequency
#define TIM_ICF_INT_1_2      ((uint16_t)0x0010) // Sampling frequency Fsampling = Fck_int, N = 2
#define TIM_ICF_INT_1_4      ((uint16_t)0x0020) // Sampling frequency Fsampling = Fck_int, N = 4
#define TIM_ICF_INT_1_8      ((uint16_t)0x0030) // Sampling frequency Fsampling = Fck_int, N = 8
#define TIM_ICF_DTS_2_6      ((uint16_t)0x0040) // Sampling frequency Fsampling = Fdts/2,  N = 6
#define TIM_ICF_DTS_2_8      ((uint16_t)0x0050) // Sampling frequency Fsampling = Fdts/2,  N = 8
#define TIM_ICF_DTS_4_6      ((uint16_t)0x0060) // Sampling frequency Fsampling = Fdts/4,  N = 6
#define TIM_ICF_DTS_4_8      ((uint16_t)0x0070) // Sampling frequency Fsampling = Fdts/4,  N = 8
#define TIM_ICF_DTS_8_6      ((uint16_t)0x0080) // Sampling frequency Fsampling = Fdts/8,  N = 6
#define TIM_ICF_DTS_8_8      ((uint16_t)0x0090) // Sampling frequency Fsampling = Fdts/8,  N = 8
#define TIM_ICF_DTS_16_5     ((uint16_t)0x00A0) // Sampling frequency Fsampling = Fdts/16, N = 5
#define TIM_ICF_DTS_16_6     ((uint16_t)0x00B0) // Sampling frequency Fsampling = Fdts/16, N = 6
#define TIM_ICF_DTS_16_8     ((uint16_t)0x00C0) // Sampling frequency Fsampling = Fdts/16, N = 8
#define TIM_ICF_DTS_32_5     ((uint16_t)0x00D0) // Sampling frequency Fsampling = Fdts/32, N = 5
#define TIM_ICF_DTS_32_6     ((uint16_t)0x00E0) // Sampling frequency Fsampling = Fdts/32, N = 6
#define TIM_ICF_DTS_32_8     ((uint16_t)0x00F0) // Sampling frequency Fsampling = Fdts/32, N = 8

#define TIM_OC_PE            ((uint16_t)0x0008) // Output Compare Preload enable
#define TIM_OC_FE            ((uint16_t)0x0004) // Output Compare Fast enable

#define TIM_IC_PSC           ((uint16_t)0x000C) // IC_PSC[1:0] bits (Input Capture Prescaler)
#define TIM_IC_PSC_DIV1      ((uint16_t)0x0000) // capture triggered each event
#define TIM_IC_PSC_DIV2      ((uint16_t)0x0004) // capture triggered every 2 events
#define TIM_IC_PSC_DIV4      ((uint16_t)0x0008) // capture triggered every 4 events
#define TIM_IC_PSC_DIV8      ((uint16_t)0x000C) // capture triggered every 8 events

#define TIM_CCS              ((uint16_t)0x0003) // CCS[1:0] bits (Capture/Compare Selection)
#define TIM_CCS_OUT          ((uint16_t)0x0000) // Channel configured as an output
#define TIM_CCS_IN_SELF      ((uint16_t)0x0001) // Channel configured as input and IC is mapped on self number input
#define TIM_CCS_IN_OPPS      ((uint16_t)0x0002) // Channel configured as input and IC is mapped on opposite number input
#define TIM_CCS_IN_TRC       ((uint16_t)0x0003) // Channel configured as input and IC is mapped on TRC

//===================  Bit definition for TIM_CCER register  ===================
#define TIM_CC4P             ((uint16_t)0x2000) // Capture/Compare 4 output Polarity
#define TIM_CC4E             ((uint16_t)0x1000) // Capture/Compare 4 output enable
#define TIM_CC3NP            ((uint16_t)0x0800) // Capture/Compare 3 Complementary output Polarity
#define TIM_CC3NE            ((uint16_t)0x0400) // Capture/Compare 3 Complementary output enable
#define TIM_CC3P             ((uint16_t)0x0200) // Capture/Compare 3 output Polarity
#define TIM_CC3E             ((uint16_t)0x0100) // Capture/Compare 3 output enable
#define TIM_CC2NP            ((uint16_t)0x0080) // Capture/Compare 2 Complementary output Polarity
#define TIM_CC2NE            ((uint16_t)0x0040) // Capture/Compare 2 Complementary output enable
#define TIM_CC2P             ((uint16_t)0x0020) // Capture/Compare 2 output Polarity
#define TIM_CC2E             ((uint16_t)0x0010) // Capture/Compare 2 output enable
#define TIM_CC1NP            ((uint16_t)0x0008) // Capture/Compare 1 Complementary output Polarity
#define TIM_CC1NE            ((uint16_t)0x0004) // Capture/Compare 1 Complementary output enable
#define TIM_CC1P             ((uint16_t)0x0002) // Capture/Compare 1 output Polarity
#define TIM_CC1E             ((uint16_t)0x0001) // Capture/Compare 1 output enable

//===================  Bit definition for TIM_CNT register  ===================
#define TIM_CNT              ((uint16_t)0xFFFF) // Counter Value

//===================  Bit definition for TIM_PSC register  ===================
#define TIM_PSC              ((uint16_t)0xFFFF) // Prescaler Value

//==================  Bit definition for TIM_ATRLR register  ==================
#define TIM_ARR              ((uint16_t)0xFFFF) // actual auto-reload Value

//==================  Bit definition for TIM_RPTCR register  ===================
#define TIM_REP              ((uint16_t)0x00FF) // Repetition Counter Value

//============  Bit definition for TIM_CH[1, 2, 3, 4]CVR register  =============
#define TIM_CCR              ((uint16_t)0xFFFF) // Capture/Compare Value

//==================  Bit definition for TIM_BDTR register  ====================
#define TIM_MOE              ((uint16_t)0x8000) // Main Output enable
#define TIM_AOE              ((uint16_t)0x4000) // Automatic Output enable
#define TIM_BKP              ((uint16_t)0x2000) // Break Polarity
#define TIM_BKE              ((uint16_t)0x1000) // Break enable
#define TIM_OSSR             ((uint16_t)0x0800) // Off-State Selection for Run mode
#define TIM_OSSI             ((uint16_t)0x0400) // Off-State Selection for Idle mode

#define TIM_LOCK             ((uint16_t)0x0300) // LOCK[1:0] bits (Lock Configuration)
#define TIM_LOCK_DIS         ((uint16_t)0x0000) // Disable the locking function
#define TIM_LOCK_LEV1        ((uint16_t)0x0100) // Lock level 1
#define TIM_LOCK_LEV2        ((uint16_t)0x0200) // Lock level 2
#define TIM_LOCK_LEV3        ((uint16_t)0x0300) // Lock level 3

#define TIM_DTG              ((uint16_t)0x00FF) // DTG[0:7] bits (Dead-Time Generator set-up)
#define TIM_DTG_CALC1        ((uint16_t)0x0000) // DT = DTG[7:0] * Tdtg, Tdtg = TDTS
#define TIM_DTG_CALC2        ((uint16_t)0x0080) // DT = (64 + DTG[5:0]) * Tdtg, Tdtg = TDTS * 2
#define TIM_DTG_CALC3        ((uint16_t)0x00C0) // DT = (32 + DTG[4:0]) * Tdtg, Tdtg = TDTS * 8
#define TIM_DTG_CALC4        ((uint16_t)0x00E0) // DT = (32 + DTG[4:0]) * Tdtg, Tdtg = TDTS * 16


//=================  Bit definition for TIM_DMACFGR register  ==================
#define TIM_DBL              ((uint16_t)0x1F00) // DBL[4:0] bits (DMA Burst Length)

#define TIM_DBA              ((uint16_t)0x001F) // DBA[4:0] bits (DMA Base Address)

//==================  Bit definition for TIM_DMAADR register  ==================
#define TIM_DMAR_DMAB        ((uint16_t)0xFFFF) // DMA register for burst accesses

//====================  Bit definition for TIM_AUX register  ===================
#define TIM_CAP_ED_CH4       ((uint16_t)0x0004) // Dual-edge capture CH4 enable
#define TIM_CAP_ED_CH3       ((uint16_t)0x0002) // Dual-edge capture CH3 enable
#define TIM_CAP_ED_CH1       ((uint16_t)0x0001) // Dual-edge capture CH2 enable

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_TIM_H
