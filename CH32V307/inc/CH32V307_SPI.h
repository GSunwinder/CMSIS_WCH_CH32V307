//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_SPI.h
// Version     : V1.0
// Date        : 17-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Serial Peripheral Interface Header File.
//==============================================================================

#ifndef __CH32V307_SPI_H
#define __CH32V307_SPI_H

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
    __IO uint16_t STATR;
         uint16_t :16;
    __IO uint16_t DATAR;
         uint16_t :16;
    __IO uint16_t CRCR;
         uint16_t :16;
    __I  uint16_t RCRCR;
         uint16_t :16;
    __I  uint16_t TCRCR;
         uint16_t :16;
    __IO uint16_t I2S_CFGR;
         uint16_t :16;
    __IO uint16_t I2SSPR; // SPI2 and SPI3 only
         uint16_t :16;
    __O  uint16_t HSCR;
} SPI_TypeDef;

#define SPI1        ((SPI_TypeDef *)SPI1_BASE)
#define SPI2        ((SPI_TypeDef *)SPI2_BASE)
#define SPI3        ((SPI_TypeDef *)SPI3_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for SPI_CTLR1 register  ===================
#define SPI_CTLR1_BIDIMODE      ((uint16_t)0x8000) // Bidirectional data mode enable
#define SPI_CTLR1_BIDIOE        ((uint16_t)0x4000) // Output enable in bidirectional mode
#define SPI_CTLR1_CRCEN         ((uint16_t)0x2000) // Hardware CRC calculation enable
#define SPI_CTLR1_CRCNEXT       ((uint16_t)0x1000) // Transmit CRC next
#define SPI_CTLR1_DFF           ((uint16_t)0x0800) // Data Frame Format
#define SPI_CTLR1_RXONLY        ((uint16_t)0x0400) // Receive only
#define SPI_CTLR1_SSM           ((uint16_t)0x0200) // Software slave management
#define SPI_CTLR1_SSI           ((uint16_t)0x0100) // Internal slave select
#define SPI_CTLR1_LSBFIRST      ((uint16_t)0x0080)
#define SPI_CTLR1_SPE           ((uint16_t)0x0040) // SPI Enable

#define SPI_CTLR1_BR            ((uint16_t)0x0038) // BR[2:0] bits (Baud Rate Control)
#define SPI_CTLR1_BR_DIV2       ((uint16_t)0x0000) // HCLK / 2
#define SPI_CTLR1_BR_DIV4       ((uint16_t)0x0008) // HCLK / 4
#define SPI_CTLR1_BR_DIV8       ((uint16_t)0x0010) // HCLK / 8
#define SPI_CTLR1_BR_DIV16      ((uint16_t)0x0018) // HCLK / 16
#define SPI_CTLR1_BR_DIV32      ((uint16_t)0x0020) // HCLK / 32
#define SPI_CTLR1_BR_DIV64      ((uint16_t)0x0028) // HCLK / 64
#define SPI_CTLR1_BR_DIV128     ((uint16_t)0x0030) // HCLK / 128
#define SPI_CTLR1_BR_DIV256     ((uint16_t)0x0038) // HCLK / 256

#define SPI_CTLR1_MSTR          ((uint16_t)0x0004) // Master Selection
#define SPI_CTLR1_CPOL          ((uint16_t)0x0002) // Clock Polarity
#define SPI_CTLR1_CPHA          ((uint16_t)0x0001) // Clock Phase

//==================  Bit definition for SPI_CTLR2 register  ===================
#define SPI_CTLR2_TXEIE         ((uint16_t)0x0080) // Tx buffer Empty Interrupt Enable
#define SPI_CTLR2_RXNEIE        ((uint16_t)0x0040) // RX buffer Not Empty Interrupt Enable
#define SPI_CTLR2_ERRIE         ((uint16_t)0x0020) // Error Interrupt Enable
#define SPI_CTLR2_SSOE          ((uint16_t)0x0004) // SS Output Enable
#define SPI_CTLR2_TXDMAEN       ((uint16_t)0x0002) // Tx Buffer DMA Enable
#define SPI_CTLR2_RXDMAEN       ((uint16_t)0x0001) // Rx Buffer DMA Enable

//==================  Bit definition for SPI_STATR register  ===================
#define SPI_STATR_BSY           ((uint16_t)0x0080) // Busy flag
#define SPI_STATR_OVR           ((uint16_t)0x0040) // Overrun flag
#define SPI_STATR_MODF          ((uint16_t)0x0020) // Mode fault
#define SPI_STATR_CRCERR        ((uint16_t)0x0010) // CRC Error flag
#define SPI_STATR_UDR           ((uint16_t)0x0008) // Underrun flag
#define SPI_STATR_CHSIDE        ((uint16_t)0x0004) // Channel side
#define SPI_STATR_TXE           ((uint16_t)0x0002) // Transmit buffer Empty
#define SPI_STATR_RXNE          ((uint16_t)0x0001) // Receive buffer Not Empty

//==================  Bit definition for SPI_DATAR register  ===================
#define SPI_DATAR_DR            ((uint16_t)0xFFFF) // Data Register

//==================  Bit definition for SPI_CRCR register  ====================
#define SPI_CRCR_CRCPOLY        ((uint16_t)0xFFFF) // CRC polynomial register

//==================  Bit definition for SPI_RCRCR register  ===================
#define SPI_RCRCR_RXCRC         ((uint16_t)0xFFFF) // Rx CRC Register

//==================  Bit definition for SPI_TCRCR register  ===================
#define SPI_TCRCR_TXCRC         ((uint16_t)0xFFFF) // Tx CRC Register

//=================  Bit definition for SPI_I2S_CFGR register  =================
#define SPI_I2S_CFGR_I2SMOD     ((uint16_t)0x0800) // I2S mode selection
#define SPI_I2S_CFGR_I2SE       ((uint16_t)0x0400) // I2S enable

#define SPI_I2S_CFGR_I2SCFG     ((uint16_t)0x0300) // I2S mode selection
#define SPI_I2S_CFGR_I2SCFG_ST  ((uint16_t)0x0000) // Slave device transmits
#define SPI_I2S_CFGR_I2SCFG_SR  ((uint16_t)0x0100) // Slave device receives
#define SPI_I2S_CFGR_I2SCFG_MT  ((uint16_t)0x0200) // Master device transmits
#define SPI_I2S_CFGR_I2SCFG_MR  ((uint16_t)0x0300) // Master device receives

#define SPI_I2S_CFGR_PCMSYNC    ((uint16_t)0x0080) // PCM frame synchronization

#define SPI_I2S_CFGR_I2SSTD     ((uint16_t)0x0030) // I2S standard selection
#define SPI_I2S_CFGR_I2SSTD_PH  ((uint16_t)0x0000) // I2S Philips standard
#define SPI_I2S_CFGR_I2SSTD_HBA ((uint16_t)0x0010) // High byte alignment standard
#define SPI_I2S_CFGR_I2SSTD_LBA ((uint16_t)0x0020) // Low byte alignment standard
#define SPI_I2S_CFGR_I2SSTD_PCM ((uint16_t)0x0030) // PCM standard

#define SPI_I2S_CFGR_CKPOL      ((uint16_t)0x0008) // Quiescent clock polarity

#define SPI_I2S_CFGR_DATLEN     ((uint16_t)0x0006) // Length of the data to be transmitted
#define SPI_I2S_CFGR_DATLEN_16  ((uint16_t)0x0000) // 16-bit data length
#define SPI_I2S_CFGR_DATLEN_24  ((uint16_t)0x0002) // 24-bit data length
#define SPI_I2S_CFGR_DATLEN_32  ((uint16_t)0x0004) // 32-bit data length

#define SPI_I2S_CFGR_CHLEN      ((uint16_t)0x0001) // Channel length
#define SPI_I2S_CFGR_CHLEN_16   ((uint16_t)0x0000) // 16 bits wide
#define SPI_I2S_CFGR_CHLEN_32   ((uint16_t)0x0001) // 32 bits wide

//==================  Bit definition for SPI_I2SPR register  ===================
#define SPI_I2SPR_MCKOE         ((uint16_t)0x0200) // Master clock output enable
#define SPI_I2SPR_ODD           ((uint16_t)0x0100) // Odd coefficient prescaler

#define SPI_I2SPR_I2SDIV        ((uint16_t)0x00FF) // I2S linear prescaler

//==================  Bit definition for SPI_HSCR register  ====================
#define SPI_HSCR_HSRXEN2        ((uint16_t)0x0003) // SPI high-speed read mode 2
#define SPI_HSCR_HSRXEN         ((uint16_t)0x0001) // High-speed read mode enable

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_SPI_H
