//========================================================  (C) COPYRIGHT  =====
// File Name   : RISC-V_QingKe_V4F_pfic.h
// Version     : V1.0
// Date        : 14-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V QingKe V4F core PFIC peripheral access layer header file
//==============================================================================

#ifndef __CORE_RISCV_PFIC_H__
#define __CORE_RISCV_PFIC_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
//                  Programmable Fast Interrupt Controller (PFIC)
//==============================================================================

//===  Memory mapped structure for Program Fast Interrupt Controller (PFIC)  ===
typedef struct{                     // Offset
    __I  uint32_t ISR[8];           // 0000
    __I  uint32_t IPR[8];           // 0020
    __IO uint32_t ITHRESDR;         // 0040
         uint32_t RESERVED0;        // 0044
    __O  uint32_t CFGR;             // 0048
    __I  uint32_t GISR;             // 004C
    __IO uint32_t VTFIDR;           // 0050
         uint32_t RESERVED1[3];     // 0054
    __IO uint32_t VTFADDRR[4];      // 0060
         uint32_t RESERVED2[36];    // 0070
    __O  uint32_t IENR[8];          // 0100
         uint32_t RESERVED3[24];    // 0120
    __O  uint32_t IRER[8];          // 0180
         uint32_t RESERVED4[24];    // 01A0
    __O  uint32_t IPSR[8];          // 0200
         uint32_t RESERVED5[24];    // 0220
    __O  uint32_t IPRR[8];          // 0280
         uint32_t RESERVED6[24];    // 02A0
    __I  uint32_t IACTR[8];         // 0300
         uint32_t RESERVED7[56];    // 0320
    __IO uint8_t  IPRIOR[256];      // 0400
         uint32_t RESERVED8[516];   // 0500
    __IO uint32_t SCTLR;            // 0D10
} PFIC_Type;

//====================  Address definition for PFIC structure  =================
#define PFIC            ((PFIC_Type *)0xE000E000)
#define NVIC            PFIC

//=====================  Other definition for PFIC structure  ==================
#define PFIC_KEY1       ((uint32_t)0xFA050000)
#define PFIC_KEY2       ((uint32_t)0xBCAF0000)
#define PFIC_KEY3       ((uint32_t)0xBEEF0000)

//===================  RISC-V Standard PFIC Bits Definition  ===================

//===================  Bit definition for ITHRESDR register  ===================
#define PFIC_ITHRESDR   ((uint32_t)0x000000F0) // Priority threshold

//=====================  Bit definition for CFGR register  =====================
#define PFIC_CFGR_KEYCODE   ((uint32_t)0xFFFF0000) // Unlock code
#define PFIC_CFGR_SYSRESET  ((uint32_t)0x00000080) // System Reset

//=====================  Bit definition for GISR register  =====================
#define PFIC_GISR_GPENDSTA  ((uint32_t)0x00000200) // Interrupt is currently pending
#define PFIC_GISR_GACTSTA   ((uint32_t)0x00000100) // Interrupt is currently being executed

#define PFIC_GISR_NESTSTA       ((uint32_t)0x000000FF) // Current interrupt nesting status
#define PFIC_GISR_NESTSTA_NI    ((uint32_t)0x00000000) // No interrupt occur
#define PFIC_GISR_NESTSTA_L1    ((uint32_t)0x00000001) // In level 1 interrupt
#define PFIC_GISR_NESTSTA_L2    ((uint32_t)0x00000003) // In level 2 interrupt
#define PFIC_GISR_NESTSTA_L3    ((uint32_t)0x00000007) // In level 3 interrupt
#define PFIC_GISR_NESTSTA_L4    ((uint32_t)0x0000000F) // In level 4 interrupt
#define PFIC_GISR_NESTSTA_L5    ((uint32_t)0x0000001F) // In level 5 interrupt
#define PFIC_GISR_NESTSTA_L6    ((uint32_t)0x0000003F) // In level 6 interrupt
#define PFIC_GISR_NESTSTA_L7    ((uint32_t)0x0000007F) // In level 7 interrupt
#define PFIC_GISR_NESTSTA_L8    ((uint32_t)0x000000FF) // In level 8 interrupt

//====================  Bit definition for VTFIDR register  ====================
#define PFIC_VTFID_VTF0     ((uint32_t)0x000000FF) // VTF 0 channel
#define PFIC_VTFID_VTF1     ((uint32_t)0x0000FF00) // VTF 1 channel
#define PFIC_VTFID_VTF2     ((uint32_t)0x00FF0000) // VTF 2 channel
#define PFIC_VTFID_VTF3     ((uint32_t)0xFF000000) // VTF 3 channel

//================  Bit definition for VTFADDRR[0...3] register  ===============
#define PFIC_VTFADDRR_ADDR  ((uint32_t)0xFFFFFFFE) // Address service program
#define PFIC_VTFADDRR_EN    ((uint32_t)0x00000001) // Enable channel

//=====================  Bit definition for SCTLR register  ====================
#define PFIC_SCTLR_SYSRESET     ((uint32_t)0x80000000) // System Reset
#define PFIC_SCTLR_SETEVENT     ((uint32_t)0x00000020)
#define PFIC_SCTLR_SEVONPEND    ((uint32_t)0x00000010)
#define PFIC_SCTLR_WFITOWFE     ((uint32_t)0x00000008)
#define PFIC_SCTLR_SLEEPDEEP    ((uint32_t)0x00000004) // Low power mode
#define PFIC_SCTLR_SLEEPONEXIT  ((uint32_t)0x00000002) // Status after leave interrupt

//=========================  PFIC Core Functions  ==============================

//==============================================================================
// Global enable IRQ

RV_STATIC_INLINE void __enable_irq(void)
{
    __asm volatile("csrs mstatus, %0" : : "r"(MSTATUS_MPIE | MSTATUS_MIE));
}

//==============================================================================
// Global disable IRQ

RV_STATIC_INLINE void __disable_irq(void)
{
    __asm volatile("csrc mstatus, %0" : : "r"(MSTATUS_MPIE | MSTATUS_MIE));
}

//==============================================================================
// Enable Interrupt

RV_STATIC_INLINE void PFIC_EnableIRQ(IRQn_Type IRQn)
{
    PFIC->IENR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

//==============================================================================
// Disable Interrupt

RV_STATIC_INLINE void PFIC_DisableIRQ(IRQn_Type IRQn)
{
    PFIC->IRER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

//==============================================================================
// Set Interrupt Priority
//
// IRQn - Interrupt Numbers
// interrupt nesting disable(CSR - INTSYSCR INESTEN = 0)
// priority - bit[7:4] - Sub priority
//            bit[3:0] - Reserve
// interrupt nesting enable(CSR - INTSYSCR INESTEN = 1)
// Level 0 (CSR - INTSYSCR PMTCFG = 0)
// priority - bit[7:4] - Sub priority
//            bit[3:0] - Reserve
// Level 2 (CSR - INTSYSCR PMTCFG = 1)
// priority - bit[7] - Preemption Priority
//            bit[6:4] - Sub priority
//            bit[3:0] - Reserve
// Level 4 (CSR - INTSYSCR PMTCFG = 2)
// priority - bit[7:6] - Preemption Priority
//            bit[5:4] - Sub priority
//            bit[3:0] - Reserve
// Level 8 (CSR - INTSYSCR PMTCFG = 3)
// priority - bit[7:5] - Preemption Priority
//            bit[4] - Sub priority
//            bit[3:0] - Reserve

RV_STATIC_INLINE void PFIC_SetPriority(IRQn_Type IRQn, uint8_t priority)
{
    PFIC->IPRIOR[(uint32_t)(IRQn)] = priority << 4;
}

//==============================================================================
// Enable/disable nesting interrupt

void PFIC_SetNesting(PermitState NewState);

//==============================================================================
// Get Interrupt Active State
//
// IRQn - Interrupt Numbers
// 1 - Interrupt Active
// 0 - Interrupt No Active

RV_STATIC_INLINE uint32_t PFIC_GetActive(IRQn_Type IRQn)
{
    return ((uint32_t)((PFIC->IACTR[(uint32_t)(IRQn) >> 5] &
            (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

//==============================================================================
// Set VTF Interrupt
// addr - VTF interrupt service function base address.
// IRQn - Interrupt Numbers
// num  - VTF Interrupt Numbers
// NewState -  DISABLE or ENABLE

void SetVTFIRQ(uint32_t addr, IRQn_Type IRQn, uint8_t num, PermitState NewState);

//==============================================================================
// Get Interrupt Enable State

RV_STATIC_INLINE uint32_t PFIC_GetStatusIRQ(IRQn_Type IRQn)
{
    return ((uint32_t)((PFIC->ISR[(uint32_t)(IRQn) >> 5] &
            (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

//==============================================================================
// Get Interrupt Pending State

RV_STATIC_INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
    return ((uint32_t)((PFIC->IPR[(uint32_t)(IRQn) >> 5] &
            (1 << ((uint32_t)(IRQn) & 0x1F))) ? 1 : 0));
}

//==============================================================================
// Set Interrupt Pending

RV_STATIC_INLINE void PFIC_SetPendingIRQ(IRQn_Type IRQn)
{
    PFIC->IPSR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

//==============================================================================
// Clear Interrupt Pending

RV_STATIC_INLINE void PFIC_ClearPendingIRQ(IRQn_Type IRQn)
{
    PFIC->IPRR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}

#ifdef __cplusplus
}
#endif

#endif // __CORE_RISCV_PFIC_H__
