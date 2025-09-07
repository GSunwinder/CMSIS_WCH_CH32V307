//========================================================  (C) COPYRIGHT  =====
// File Name   : RISC-V_QingKe_V2A_csr.h
// Version     : V1.0
// Date        : 14-07-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V QingKe V4F core CSR registers access layer header file
//==============================================================================

#ifndef __CORE_RISCV_CSR_H__
#define __CORE_RISCV_CSR_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
//       RISC-V architecture Control and Status Register's (CSR)
//==============================================================================

//===========================  RISC-V Standard CSR  ============================
#define fflags      ((uint16_t)0x001)
#define frm         ((uint16_t)0x002)
#define fcsr        ((uint16_t)0x003)

#define mstatus     ((uint16_t)0x300)
#define misa        ((uint16_t)0x301)
#define mtvec       ((uint16_t)0x305)
#define mscratch    ((uint16_t)0x340)
#define mepc        ((uint16_t)0x341)
#define mcause      ((uint16_t)0x342)
#define mtval       ((uint16_t)0x343)

#define pmpcfg      ((uint16_t)0x3a0)
#define pmpaddr     ((uint16_t)0x3b0)

#define dcsr        ((uint16_t)0x7b0)
#define dpc         ((uint16_t)0x7b1)
#define dscratch0   ((uint16_t)0x7b2)
#define dscratch1   ((uint16_t)0x7b3)

#define marchid     ((uint16_t)0xf12)
#define mimpid      ((uint16_t)0xf13)

//============================  Vendor defined CSR  ============================
#define gintenr     ((uint16_t)0x800)
#define intsyscr    ((uint16_t)0x804)
#define corecfgr    ((uint16_t)0xbc0)

//===================  RISC-V Standard CSR Bits Definition  ====================

//===================  Bit definition for fcsr register  =======================
#define FCSR_FRM            ((uint32_t)0x80000000) // Floating-point rounding mode
#define FCSR_FRM_RNE        ((uint32_t)0x80000000) // Rounding to the nearest value, even value are preferred
#define FCSR_FRM_RTZ        ((uint32_t)0x80000000) // Rounding to zero
#define FCSR_FRM_RDN        ((uint32_t)0x80000000) // Rounding to down (to -infinity)
#define FCSR_FRM_RUP        ((uint32_t)0x80000000) // Rounding to up (to +infinity)
#define FCSR_FRM_RMM        ((uint32_t)0x80000000) // Rounding to the nearest value, first maximum
#define FCSR_FRM_DYN        ((uint32_t)0x80000000) // Dynamic rounding
#define FCSR_NV             ((uint32_t)0x80000000) // Illegal operation exception
#define FCSR_DZ             ((uint32_t)0x80000000) // De-zeroing exception
#define FCSR_OF             ((uint32_t)0x80000000) // Upper overflow exception
#define FCSR_UF             ((uint32_t)0x80000000) // Under overflow exception
#define FCSR_NX             ((uint32_t)0x80000000) // Non-precision exeption

//===================  Bit definition for mstatus register  ====================
#define MSTATUS_MIE         ((uint32_t)0x00000008) // Machine mode interrupt enable
#define MSTATUS_MPIE        ((uint32_t)0x00000080) // Interrupt enable state before entering interrupt

#define MSTATUS_MPP         ((uint32_t)0x00001800) // Privileged mode before entering break
#define MSTATUS_MPP_USER    ((uint32_t)0x00000000) // User mode
#define MSTATUS_MPP_MACHINE ((uint32_t)0x00001800) // Machine mode

#define MSTATUS_FS          ((uint32_t)0x00006000) // Floating-point unit status
#define MSTATUS_FS_OFF      ((uint32_t)0x00000000) // OFF
#define MSTATUS_FS_Initial  ((uint32_t)0x00002000) // Initial
#define MSTATUS_FS_Clean    ((uint32_t)0x00004000) // Clean
#define MSTATUS_FS_Dirty    ((uint32_t)0x00006000) // Dirty

//===================  Bit definition for misa register  =======================
#define MISA_MXL            ((uint32_t)0xC0000000) // Machine word length
#define MISA_EXT            ((uint32_t)0x03FFFFFF) // Instruction set extensions

//===================  Bit definition for mcause register  =====================
#define MCAUSE_INT          ((uint32_t)0x80000000) // Interrupt indication field
#define MCAUSE_INT_INT      ((uint32_t)0x00000000) // Exception
#define MCAUSE_INT_EXC      ((uint32_t)0x80000000) // Interruption
#define MCAUSE_EXC_CODE     ((uint32_t)0x7FFFFFFF) // Exception code

//===================  Bit definition for marchid register  ====================
#define MARCHID_VENDOR0     ((uint32_t)0x7C000000) // Manufacturer code 0
#define MARCHID_VENDOR1     ((uint32_t)0x03E00000) // Manufacturer code 1
#define MARCHID_VENDOR2     ((uint32_t)0x001F0000) // Manufacturer code 2
#define MARCHID_ARCH        ((uint32_t)0x00007C00) // Architecture code
#define MARCHID_SERIAS      ((uint32_t)0x000003E0) // Series code
#define MARCHID_VERSION     ((uint32_t)0x0000001F) // Version code

//===================  Bit definition for mimpid register  =====================
#define MIMPID_VENDOR0      ((uint32_t)0x7C000000) // Manufacturer code 0
#define MIMPID_VENDOR1      ((uint32_t)0x03E00000) // Manufacturer code 1
#define MIMPID_VENDOR2      ((uint32_t)0x001F0000) // Manufacturer code 2

//==================  Bit definition for pmpcfg register  ======================
#define PMPCFG_L            ((uint32_t)0x00000080) // Lock enable

#define PMPCFG_A            ((uint32_t)0x00000018) // Address alignment and protection area range selection
#define PMPCFG_A_OFF        ((uint32_t)0x00000018) // PMP off
#define PMPCFG_A_TOR        ((uint32_t)0x00000018) // Top Alignment Protection
#define PMPCFG_A_NA4        ((uint32_t)0x00000018) // Fixed four-byte protection
#define PMPCFG_A_NAPOT      ((uint32_t)0x00000018) // 2 ** (G + 2)

#define PMPCFG_X            ((uint32_t)0x00000004) // Executable property
#define PMPCFG_W            ((uint32_t)0x00000002) // Writable property
#define PMPCFG_R            ((uint32_t)0x00000001) // Readable Properties

//===================  Bit definition for intsyscr register  ===================
#define INTSYSCR_PMTSTA     ((uint32_t)0x0000FF00) // Preemption status indication
#define INTSYSCR_PMTSTA_NI  ((uint32_t)0x00000000) // No interrupt nesting occurs
#define INTSYSCR_PMTSTA_L2  ((uint32_t)0x00008000) // With 2 levels of interrupt nesting
#define INTSYSCR_PMTSTA_L4  ((uint32_t)0x0000C000) // With 4 levels of interrupt nesting
#define INTSYSCR_PMTSTA_L8  ((uint32_t)0x0000E000) // With 8 levels of interrupt nesting

#define INTSYSCR_GIHWSTKNEN ((uint32_t)0x00000020) // Global interrupt and HPE off enable
#define INTSYSCR_HWSTKOVEN  ((uint32_t)0x00000010) // Interrupt enable after HPE overflow

#define INTSYSCR_PMTCFG     ((uint32_t)0x0000000C) // Interrupt nesting depth configuration
#define INTSYSCR_PMTCFG_NN  ((uint32_t)0x00000000) // No nesting
#define INTSYSCR_PMTCFG_L2  ((uint32_t)0x00000004) // 2 levels of nesting
#define INTSYSCR_PMTCFG_L4  ((uint32_t)0x00000008) // 4 levels of nesting
#define INTSYSCR_PMTCFG_L8  ((uint32_t)0x0000000C) // 8 levels of nesting

#define INTSYSCR_INESTEN    ((uint32_t)0x00000002) // Interrupt nesting enable
#define INTSYSCR_HWSTKEN    ((uint32_t)0x00000001) // HPE enable

//====================  Macros for access to CSR Registers  ====================
#define __GET_CSR(reg) \
RV_STATIC_INLINE uint32_t __get_##reg(void) \
{ uint32_t result; \
    __asm volatile("csrr %0, %1" : "=r"(result) : "n"(reg) : ); \
    return (result); }

#define __SET_CSR(reg) \
RV_STATIC_INLINE void __set_##reg(uint32_t value) \
{ __asm volatile("csrw %0, %1" : : "n"(reg), "r"(value) : ); }

//===================  Function for access to CSR Registers  ===================
__GET_CSR(mstatus)
__SET_CSR(mstatus)
__GET_CSR(misa)
__SET_CSR(misa)
__GET_CSR(mtvec)
__SET_CSR(mtvec)
__GET_CSR(mscratch)
__SET_CSR(mscratch)
__GET_CSR(mepc)
__SET_CSR(mepc)
__GET_CSR(mcause)
__SET_CSR(mcause)

__GET_CSR(intsyscr)
__SET_CSR(intsyscr)

#ifdef __cplusplus
}
#endif

#endif // __CORE_RISCV_CSR_H__
