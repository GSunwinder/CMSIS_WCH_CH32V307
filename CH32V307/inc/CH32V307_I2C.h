//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_I2C.h
// Version     : V1.0
// Date        : 22-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Inter Integrated Circuit Interface Header File.
//==============================================================================

#ifndef __CH32V307_I2C_H
#define __CH32V307_I2C_H

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
    __IO uint16_t OAR1;
         uint16_t :16;
    __IO uint16_t OAR2;
         uint16_t :16;
    __IO uint16_t DATAR;
         uint16_t :16;
    __IO uint16_t STAR1;
         uint16_t :16;
    __I  uint16_t STAR2;
         uint16_t :16;
    __IO uint16_t CKCFGR;
         uint16_t :16;
    __IO uint16_t RTR;
} I2C_TypeDef;

#define I2C1        ((I2C_TypeDef *)I2C1_BASE)
#define I2C2        ((I2C_TypeDef *)I2C2_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for I2C_CTLR1 register  ===================
#define I2C_CTLR1_SWRST     ((uint16_t)0x8000) // Software Reset
#define I2C_CTLR1_ALERT     ((uint16_t)0x2000) // SMBus alert
#define I2C_CTLR1_PEC       ((uint16_t)0x1000) // Packet Error Checking
#define I2C_CTLR1_POS       ((uint16_t)0x0800) // Acknowledge/PEC Position (data recept.)
#define I2C_CTLR1_ACK       ((uint16_t)0x0400) // Acknowledge Enable
#define I2C_CTLR1_STOP      ((uint16_t)0x0200) // Stop Generation
#define I2C_CTLR1_START     ((uint16_t)0x0100) // Start Generation
#define I2C_CTLR1_NOSTRETCH ((uint16_t)0x0080) // Clock Stretching Disable (Slave mode)
#define I2C_CTLR1_ENGC      ((uint16_t)0x0040) // General Call Enable
#define I2C_CTLR1_ENPEC     ((uint16_t)0x0020) // PEC Enable
#define I2C_CTLR1_ENARP     ((uint16_t)0x0010) // ARP Enable
#define I2C_CTLR1_SMBTYPE   ((uint16_t)0x0008) // SMBus device type
#define I2C_CTLR1_SMBUS     ((uint16_t)0x0002) // SMBus mode selection
#define I2C_CTLR1_PE        ((uint16_t)0x0001) // Peripheral Enable

//==================  Bit definition for I2C_CTLR2 register  ===================
#define I2C_CTLR2_LAST      ((uint16_t)0x1000) // DMA Last Transfer
#define I2C_CTLR2_DMAEN     ((uint16_t)0x0800) // DMA Requests Enable
#define I2C_CTLR2_ITBUFEN   ((uint16_t)0x0400) // Buffer Interrupt Enable
#define I2C_CTLR2_ITEVTEN   ((uint16_t)0x0200) // Event Interrupt Enable
#define I2C_CTLR2_ITERREN   ((uint16_t)0x0100) // Error Interrupt Enable

#define I2C_CTLR2_FREQ      ((uint16_t)0x003F) // Peripheral Clock Frequency

//==================  Bit definition for I2C_OAR1 register  ====================
#define I2C_OADDR1_ADDMODE  ((uint16_t)0x8000) // Addressing Mode (Slave mode)

#define I2C_OAR1_ADD7       ((uint16_t)0x00FE) // Interface Address 7-bit
#define I2C_OAR1_ADD10      ((uint16_t)0x03FF) // Interface Address 10-bit

//==================  Bit definition for I2C_OAR2 register  ====================
#define I2C_OADDR2_ADD2     ((uint16_t)0x00FE) // Interface address
#define I2C_OADDR2_ENDUAL   ((uint16_t)0x0001) // Dual addressing mode enable

//==================  Bit definition for I2C_DATAR register  ===================
#define I2C_DR_DATAR        ((uint16_t)0x00FF) // 8-bit Data Register

//==================  Bit definition for I2C_STAR1 register  ===================
#define I2C_STAR1_SMBALERT  ((uint16_t)0x8000) // SMBus alert
#define I2C_STAR1_TIMEOUT   ((uint16_t)0x4000) // Timeout or Tlow error flag
#define I2C_STAR1_PECERR    ((uint16_t)0x1000) // PEC Error in reception
#define I2C_STAR1_OVR       ((uint16_t)0x0800) // Overrun/Underrun
#define I2C_STAR1_AF        ((uint16_t)0x0400) // Acknowledge Failure
#define I2C_STAR1_ARLO      ((uint16_t)0x0200) // Arbitration Lost (master mode)
#define I2C_STAR1_BERR      ((uint16_t)0x0100) // Bus Error
#define I2C_STAR1_TXE       ((uint16_t)0x0080) // Data Register Empty (transmitters)
#define I2C_STAR1_RXNE      ((uint16_t)0x0040) // Data Register not Empty (receivers)
#define I2C_STAR1_STOPF     ((uint16_t)0x0010) // Stop detection (Slave mode)
#define I2C_STAR1_ADD10     ((uint16_t)0x0008) // 10-bit header sent (Master mode)
#define I2C_STAR1_BTF       ((uint16_t)0x0004) // Byte Transfer Finished
#define I2C_STAR1_ADDR      ((uint16_t)0x0002) // Address sent (master)/matched (slave)
#define I2C_STAR1_SB        ((uint16_t)0x0001) // Start Bit (Master mode)

//==================  Bit definition for I2C_STAR2 register  ===================
#define I2C_STAR2_PEC       ((uint16_t)0xFF00) // Packet Error Checking Register
#define I2C_STAR2_DUALF     ((uint16_t)0x0080) // Dual Flag (Slave mode)
#define I2C_STAR2_SMBHOST   ((uint16_t)0x0040) // SMBus host header flag
#define I2C_STAR2_SMBDEF    ((uint16_t)0x0020) // SMBus device default address flag
#define I2C_STAR2_GENCALL   ((uint16_t)0x0010) // General Call Address (Slave mode)
#define I2C_STAR2_TRA       ((uint16_t)0x0004) // Transmitter/Receiver
#define I2C_STAR2_BUSY      ((uint16_t)0x0002) // Bus Busy
#define I2C_STAR2_MSL       ((uint16_t)0x0001) // Master/Slave

//==================  Bit definition for I2C_CKCFGR register  ==================
#define I2C_CKCFGR_FS       ((uint16_t)0x8000) // I2C Master Mode Selection
#define I2C_CKCFGR_DUTY     ((uint16_t)0x4000) // Fast Mode Duty Cycle

#define I2C_CKCFGR_CCR      ((uint16_t)0x0FFF) // Clock Control Reg.

//===================  Bit definition for I2C_RTR register  ====================
#define I2C_RTR_TRISE       ((uint16_t)0x003F) // Maximum rise time domain

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_I2C_H
