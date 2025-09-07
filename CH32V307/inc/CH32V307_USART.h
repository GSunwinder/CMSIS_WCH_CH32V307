//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307.h
// Version     : V1.0
// Date        : 17-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Universal Synchronous Asynchronous Receiver
//               Transmitter Header File.
//==============================================================================

#ifndef __CH32V307_USART_H
#define __CH32V307_USART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint32_t STATR;
    __IO uint32_t DATAR;
    __IO uint32_t BRR;
    __IO uint32_t CTLR1;
    __IO uint32_t CTLR2;
    __IO uint32_t CTLR3;
    __IO uint32_t GPR;
    __IO uint32_t CTLR4;
} USART_TypeDef;

#define USART1      ((USART_TypeDef *)USART1_BASE)
#define USART2      ((USART_TypeDef *)USART2_BASE)
#define USART3      ((USART_TypeDef *)USART3_BASE)
#define UART4       ((USART_TypeDef *)UART4_BASE)
#define UART5       ((USART_TypeDef *)UART5_BASE)
#define UART6       ((USART_TypeDef *)UART6_BASE)
#define UART7       ((USART_TypeDef *)UART7_BASE)
#define UART8       ((USART_TypeDef *)UART8_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for USART_STATR register  =================
#define USART_STATR_MS_ERR      ((uint32_t)0x00000800) // MARK or SPACE checksum error flag
#define USART_STATR_RX_BUSY     ((uint32_t)0x00000400) // Receive status indication
#define USART_STATR_CTS         ((uint32_t)0x00000200) // CTS flag
#define USART_STATR_LBD         ((uint32_t)0x00000100) // LIN Break Detection flag
#define USART_STATR_TXE         ((uint32_t)0x00000080) // Transmit Data Register Empty
#define USART_STATR_TC          ((uint32_t)0x00000040) // Transmission Complete
#define USART_STATR_RXNE        ((uint32_t)0x00000020) // Read Data Register Not Empty
#define USART_STATR_IDLE        ((uint32_t)0x00000010) // IDLE line detected
#define USART_STATR_ORE         ((uint32_t)0x00000008) // OverRun Error
#define USART_STATR_NE          ((uint32_t)0x00000004) // Noise Error flag
#define USART_STATR_FE          ((uint32_t)0x00000002) // Framing Error
#define USART_STATR_PE          ((uint32_t)0x00000001) // Parity Error

//==================  Bit definition for USART_DATAR register  =================
#define USART_DATAR_DR          ((uint32_t)0x000001FF) // Data value

//==================  Bit definition for USART_BRR register  ===================
#define USART_BRR_DIV_Mant      ((uint32_t)0x0000FFF0) // Mantissa of USARTDIV
#define USART_BRR_DIV_Frac      ((uint32_t)0x0000000F) // Fraction of USARTDIV

//==================  Bit definition for USART_CTLR1 register  =================
#define USART_CTLR1_M_EXT       ((uint32_t)0x0000C000) // Word length extension bits
#define USART_CTLR1_M_EXTM      ((uint32_t)0x00000000) // M bit determines data length
#define USART_CTLR1_M_EXT7      ((uint32_t)0x00004000) // 7 data bits
#define USART_CTLR1_M_EXT6      ((uint32_t)0x00008000) // 6 data bits
#define USART_CTLR1_M_EXT5      ((uint32_t)0x0000C000) // 5 data bits

#define USART_CTLR1_UE          ((uint32_t)0x00002000) // USART Enable
#define USART_CTLR1_M           ((uint32_t)0x00001000) // Word length
#define USART_CTLR1_WAKE        ((uint32_t)0x00000800) // Wakeup method
#define USART_CTLR1_PCE         ((uint32_t)0x00000400) // Parity Control Enable
#define USART_CTLR1_PS          ((uint32_t)0x00000200) // Parity Selection
#define USART_CTLR1_PEIE        ((uint32_t)0x00000100) // PE Interrupt Enable
#define USART_CTLR1_TXEIE       ((uint32_t)0x00000080) // PE Interrupt Enable
#define USART_CTLR1_TCIE        ((uint32_t)0x00000040) // Transmission Complete Interrupt Enable
#define USART_CTLR1_RXNEIE      ((uint32_t)0x00000020) // RXNE Interrupt Enable
#define USART_CTLR1_IDLEIE      ((uint32_t)0x00000010) // IDLE Interrupt Enable
#define USART_CTLR1_TE          ((uint32_t)0x00000008) // Transmitter Enable
#define USART_CTLR1_RE          ((uint32_t)0x00000004) // Receiver Enable
#define USART_CTLR1_RWU         ((uint32_t)0x00000002) // Receiver wakeup
#define USART_CTLR1_SBK         ((uint32_t)0x00000001) // Send Break

//==================  Bit definition for USART_CTLR2 register  ===================
#define USART_CTLR2_LINEN       ((uint32_t)0x00004000) // LIN mode enable

#define USART_CTLR2_STOP        ((uint32_t)0x00003000) // STOP[1:0] bits (STOP bits)
#define USART_CTLR2_STOP_1b     ((uint32_t)0x00000000) // 1 Stop bit
#define USART_CTLR2_STOP_05b    ((uint32_t)0x00001000) // 0.5 Stop bit
#define USART_CTLR2_STOP_2b     ((uint32_t)0x00002000) // 2 Stop bit
#define USART_CTLR2_STOP_15b    ((uint32_t)0x00003000) // 1.5 Stop bit

#define USART_CTLR2_CLKEN       ((uint32_t)0x00000800) // Clock Enable
#define USART_CTLR2_CPOL        ((uint32_t)0x00000400) // Clock Polarity
#define USART_CTLR2_CPHA        ((uint32_t)0x00000200) // Clock Phase
#define USART_CTLR2_LBCL        ((uint32_t)0x00000100) // Last Bit Clock pulse
#define USART_CTLR2_LBDIE       ((uint32_t)0x00000040) // LIN Break Detection Interrupt Enable
#define USART_CTLR2_LBDL        ((uint32_t)0x00000020) // LIN Break Detection Length
#define USART_CTLR2_ADD         ((uint32_t)0x0000000F) // Address of the USART node

//==================  Bit definition for USART_CTLR3 register  =================
#define USART_CTLR3_CTSIE       ((uint32_t)0x00000400) // CTS Interrupt Enable
#define USART_CTLR3_CTSE        ((uint32_t)0x00000200) // CTS Enable
#define USART_CTLR3_RTSE        ((uint32_t)0x00000100) // RTS Enable
#define USART_CTLR3_DMAT        ((uint32_t)0x00000080) // DMA Enable Transmitter
#define USART_CTLR3_DMAR        ((uint32_t)0x00000040) // DMA Enable Receiver
#define USART_CTLR3_SCEN        ((uint32_t)0x00000020) // Smartcard mode enable
#define USART_CTLR3_NACK        ((uint32_t)0x00000010) // Smartcard NACK enable
#define USART_CTLR3_HDSEL       ((uint32_t)0x00000008) // Half-Duplex Selection
#define USART_CTLR3_IRLP        ((uint32_t)0x00000004) // IrDA Low-Power
#define USART_CTLR3_IREN        ((uint32_t)0x00000002) // IrDA mode Enable
#define USART_CTLR3_EIE         ((uint32_t)0x00000001) // Error Interrupt Enable

//==================  Bit definition for USART_GPR register  ===================
#define USART_GPR_GT            ((uint32_t)0x0000FF00) // Guard time value
#define USART_GPR_PSC           ((uint32_t)0x000000FF) // PSC[7:0] bits (Prescaler value)

//==================  Bit definition for USART_CTLR4 register  =================
#define USART_CTLR4_CHECK_SEL       ((uint32_t)0x0000000C) // Checksum function select
#define USART_CTLR4_CHECK_SEL_DIS   ((uint32_t)0x00000000) // Disable MARK and SPACE checksum
#define USART_CTLR4_CHECK_SEL_ENM   ((uint32_t)0x00000008) // Enable MARK checksum
#define USART_CTLR4_CHECK_SEL_ENS   ((uint32_t)0x0000000C) // Enable SPACE checksum

#define USART_CTLR4_MS_ERRIE        ((uint32_t)0x00000002) // Enable generation SPACE or MARK
                                                           // checksum error interrupt

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_USART_H
