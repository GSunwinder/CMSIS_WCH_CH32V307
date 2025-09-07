//========================================================  (C) COPYRIGHT  =====
// File Name   : RISC-V_QingKe_V4F.c
// Version     : V1.0
// Date        : 15-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V QingKe V4F core peripheral access layer source file
//==============================================================================

#include <RISC-V_QingKe_V4F.h>

//==============================================================================
// Enable/disable nesting interrupt

void PFIC_SetNesting(PermitState NewState)
{
    __set_intsyscr((__get_intsyscr() & ~INTSYSCR_INESTEN) | (NewState) ?
            INTSYSCR_INESTEN : 0);
}

//==============================================================================
// Set VTF Interrupt
// addr - VTF interrupt service function base address.
// IRQn - Interrupt Numbers
// num  - VTF Interrupt Numbers [0...3]
// NewState -  DISABLE or ENABLE

void SetVTFIRQ(uint32_t addr, IRQn_Type IRQn, uint8_t num, PermitState NewState)
{
    uint32_t tmp;

    if (num > 3) return;

    tmp = PFIC->VTFIDR;
    tmp &= ~((uint32_t)(0xFF << (num * 8)));
    if (NewState == ENABLE)
        tmp |=  ((uint32_t)(IRQn << (num * 8)));
    PFIC->VTFIDR = tmp;

    PFIC->VTFADDRR[num] = (NewState == ENABLE) ?
        (addr & PFIC_VTFADDRR_ADDR) | PFIC_VTFADDRR_EN : 0;
}
