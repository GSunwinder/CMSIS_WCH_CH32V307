//========================================================  (C) COPYRIGHT  =====
// File Name   : RISC-V_QingKe_V4F_systick.h
// Version     : V1.0
// Date        : 14-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V QingKe V4F core SysTick peripheral access layer header file
//==============================================================================

#ifndef __CORE_RISCV_SYSTICK_H__
#define __CORE_RISCV_SYSTICK_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
//                           System Timer (SysTick)
//==============================================================================

//==================  Memory mapped structure for SysTick  =====================
typedef struct
{
    __IO uint32_t CTLR;
    __IO uint32_t SR;
    __IO uint32_t CNTL;
    __IO uint32_t CNTH;
    __IO uint32_t CMPLR;
    __IO uint32_t CMPHR;
} SysTick_Type;

//===================  Bit definition for STK_CTLR register  ===================
#define STK_SWIE    ((uint32_t)0x80000000) // Software interrupt trigger enable
#define STK_INIT    ((uint32_t)0x00000020) // Counter initial value update

#define STK_MODE    ((uint32_t)0x00000010) // Counting mode
#define STK_MODE_UP ((uint32_t)0x00000000) // Counting up
#define STK_MODE_DN ((uint32_t)0x00000010) // Counting down

#define STK_STRE    ((uint32_t)0x00000008) // Auto Reload Count enable bit

#define STK_STCLK   ((uint32_t)0x00000004) // Counter clock source selection bit
#define STK_STCLK_8 ((uint32_t)0x00000000) // HCLK/8 for time base
#define STK_STCLK_1 ((uint32_t)0x00000004) // HCLK/1 for time base

#define STK_STIE    ((uint32_t)0x00000002) // Counter interrupt enable
#define STK_STE     ((uint32_t)0x00000001) // System counter enable

//===================  Bit definition for STK_CTLR register  ===================
#define STK_CNTIF   ((uint32_t)0x00000001) // Counting value comparison flag

//===================  Address definition for SysTick structure  ===============
#define SysTick     ((SysTick_Type *)0xE000F000)

#ifdef __cplusplus
}
#endif

#endif // __CORE_RISCV_SYSTICK_H__





