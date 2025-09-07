//========================================================  (C) COPYRIGHT  =====
// File Name   : RISC-V_QingKe_V4F.h
// Version     : V1.0
// Date        : 14-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V QingKe V4F core peripheral access layer header file
//==============================================================================

#ifndef __CORE_RISCV_H__
#define __CORE_RISCV_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include <stdint.h>
#include "CH32V307_IRQ.h"

// define compiler specific symbols
#define __INLINE    inline
#define RV_STATIC_INLINE __attribute__((always_inline)) inline

//==============================================================================
//                      Definitions Global type variable
//==============================================================================

//=============================  IO definitions  ===============================
#ifdef __cplusplus
    #define __I  volatile       /* defines 'read only' permissions  */
#else
    #define __I  volatile const /* defines 'read only' permissions  */
#endif
#define     __O  volatile       /* defines 'write only' permissions */
#define     __IO volatile       /* defines 'read/write' permissions */

//==  Standard Peripheral Library old types (maintained for legacy purpose)  ===
typedef __I uint32_t vuc32;   /* Read Only */
typedef __I uint16_t vuc16;   /* Read Only */
typedef __I uint8_t  vuc8;    /* Read Only */

typedef const uint32_t uc32;  /* Read Only */
typedef const uint16_t uc16;  /* Read Only */
typedef const uint8_t  uc8;   /* Read Only */

typedef __I int32_t vsc32;    /* Read Only */
typedef __I int16_t vsc16;    /* Read Only */
typedef __I int8_t  vsc8;     /* Read Only */

typedef const int32_t sc32;   /* Read Only */
typedef const int16_t sc16;   /* Read Only */
typedef const int8_t  sc8;    /* Read Only */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t  vu16;
typedef __IO uint8_t   vu8;

typedef uint32_t  u32;
typedef uint16_t  u16;
typedef uint8_t   u8;

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef int32_t  s32;
typedef int16_t  s16;
typedef int8_t   s8;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} PermitState;

//==============================================================================
// include parts of core RISC-V
#include <RISC-V_QingKe_V4F_csr.h>
#include <RISC-V_QingKe_V4F_pfic.h>
#include <RISC-V_QingKe_V4F_systick.h>

//==============================================================================
// Not operation

RV_STATIC_INLINE void __NOP()
{
    __asm volatile("nop");
}

//==============================================================================
// Get Stack Pointer

RV_STATIC_INLINE uint32_t __get_SP(void)
{
    uint32_t result;

    __asm volatile("mv %0, sp" : "=r"(result) : : );
    return (result);
}

//==============================================================================
// System Reset MCU

RV_STATIC_INLINE void PFIC_SystemReset(void)
{
    PFIC->CFGR = PFIC_KEY3 | PFIC_CFGR_SYSRESET;
}

//==============================================================================
// Wait for Interrupt

RV_STATIC_INLINE void __WFI(void)
{
    PFIC->SCTLR &= ~PFIC_SCTLR_WFITOWFE;
    __asm volatile("wfi");
}

//==============================================================================
// Wait for Events

RV_STATIC_INLINE void __WFE(void)
{
    uint32_t tmp;

    tmp = PFIC->SCTLR;
    PFIC->SCTLR |= PFIC_SCTLR_SETEVENT | PFIC_SCTLR_WFITOWFE;
    PFIC->SCTLR  = (PFIC->SCTLR & ~PFIC_SCTLR_SETEVENT) | ( tmp & PFIC_SCTLR_SETEVENT);

    PFIC->SCTLR |= PFIC_SCTLR_WFITOWFE;
    __asm volatile("wfi");
    PFIC->SCTLR |= PFIC_SCTLR_WFITOWFE;
    __asm volatile("wfi");
}

#ifdef __cplusplus
}
#endif

#endif // __CORE_RISCV_H__





