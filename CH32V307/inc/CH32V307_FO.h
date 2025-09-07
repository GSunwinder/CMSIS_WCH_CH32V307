//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_FO.h
// Version     : V1.0
// Date        : 06-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 FLASH and Option bytes Header File.
//==============================================================================

#ifndef __CH32V307_FO_H
#define __CH32V307_FO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

// FLASH Registers
typedef struct
{
         uint32_t :32;
    __O  uint32_t KEYR;
    __O  uint32_t OBKEYR;
    __IO uint32_t STATR;
    __IO uint32_t CTLR;
    __O  uint32_t ADDR;
         uint32_t :32;
    __I  uint32_t OBR;
    __I  uint32_t WPR;
    __O  uint32_t MODEKEYR;
} FLASH_TypeDef;

// Option bytes Registers
typedef struct
{
    __IO uint16_t RDPR;
    __IO uint16_t USER;
    __IO uint16_t Data0;
    __IO uint16_t Data1;
    __IO uint16_t WRPR0;
    __IO uint16_t WRPR1;
} OB_TypeDef;

#define FLASH       ((FLASH_TypeDef *)FLASH_REG_BASE)
#define OB          ((OB_TypeDef *)OB_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for FLASH_KEYR register  ==================
#define FLASH_KEYR_RDPRT            ((uint32_t)0x000000A5)
#define FLASH_KEYR_KEY1             ((uint32_t)0x45670123)
#define FLASH_KEYR_KEY2             ((uint32_t)0xCDEF89AB)

//=================  Bit definition for FLASH_OBKEYR register  =================
#define FLASH_OBKEYR_OBKEYR         ((uint32_t)0xFFFFFFFF) // Option Byte Key

//==================  Bit definition for FLASH_STATR register  =================
#define FLASH_STATR_EHMODS          ((uint32_t)0x00000080) // FLASH enhanced read mode
#define FLASH_STATR_EOP             ((uint32_t)0x00000020) // End of erased of programmed
#define FLASH_STATR_WRPRTERR        ((uint32_t)0x00000010) // Write Protection Error
#define FLASH_STATR_BSY             ((uint32_t)0x00000001) // Busy

//==================  Bit definition for FLASH_CTLR register  ==================
#define FLASH_CTLR_SCKMOD           ((uint32_t)0x02000000) // FLASH access clock config
#define FLASH_CTLR_EHMOD            ((uint32_t)0x01000000) // FLASH enhanced read mode
#define FLASH_CTLR_RSENACT          ((uint32_t)0x00400000) // Exit from enhanced read mode
#define FLASH_CTLR_PGSTRT           ((uint32_t)0x00200000) // Start a page programming
#define FLASH_CTLR_BER64            ((uint32_t)0x00080000) // Perform a 64 kbyte
#define FLASH_CTLR_BER32            ((uint32_t)0x00040000) // Perform a 32 kbyte
#define FLASH_CTLR_FTER             ((uint32_t)0x00020000) // Page Erase 256 byte
#define FLASH_CTLR_FTPG             ((uint32_t)0x00010000) // Page Programming 256 byte
#define FLASH_CTLR_FLOCK            ((uint32_t)0x00008000)
#define FLASH_CTLR_EOPIE            ((uint32_t)0x00001000) // End of operation interrupt enable
#define FLASH_CTLR_ERRIE            ((uint32_t)0x00000400) // Error Interrupt Enable
#define FLASH_CTLR_OBWRE            ((uint32_t)0x00000200) // Option Bytes Write Enable
#define FLASH_CTLR_LOCK             ((uint32_t)0x00000080) // Lock
#define FLASH_CTLR_STRT             ((uint32_t)0x00000040) // Start
#define FLASH_CTLR_OBER             ((uint32_t)0x00000020) // Option Byte Erase
#define FLASH_CTLR_OBPG             ((uint32_t)0x00000010) // Option Byte Programming
#define FLASH_CTLR_MER              ((uint32_t)0x00000004) // Mass Erase
#define FLASH_CTLR_PER              ((uint32_t)0x00000002) // Page Erase 4 kbyte
#define FLASH_CTLR_PG               ((uint32_t)0x00000001) // Programming

//==================  Bit definition for FLASH_ADDR register  ==================
#define FLASH_ADDR_FAR              ((uint32_t)0xFFFFFFFF) // Flash Address

//==================  Bit definition for FLASH_OBR register  ===================
#define FLASH_OBR_SRAM_CODE_MODE    ((uint32_t)0x00000380) // FLASH/SRAM resize
#define FLASH_OBR_STANDY_RST        ((uint32_t)0x00000010) // System reset control in Standby mode
#define FLASH_OBR_STOP_RST          ((uint32_t)0x00000008) // System reset control in Stop mode
#define FLASH_OBR_IWDG_SW           ((uint32_t)0x00000004) // IWDG hardware enable bit
#define FLASH_OBR_RDPRT             ((uint32_t)0x00000002) // Read protection
#define FLASH_OBR_OPTERR            ((uint32_t)0x00000001) // Option Byte Error

//==================  Bit definition for FLASH_WPR register  ===================
#define FLASH_WPR_WRP               ((uint32_t)0x0000FFFF) // Write Protect

//=================  Bit definition for FLASH_MODEKEYR register  ===============
#define FLASH_MODEKEYR_KEY1         ((uint32_t)0x45670123)
#define FLASH_MODEKEYR_KEY2         ((uint32_t)0xCDEF89AB)


//===================  Bit definition for OB_RDPR register  ====================
#define FLASH_RDPR_RDPR             ((uint32_t)0x000000FF) // Read protection option byte
#define FLASH_RDPR_nRDPR            ((uint32_t)0x0000FF00) // Read protection complemented option byte

//===================  Bit definition for OB_USER register  ====================
#define FLASH_USER_USER             ((uint32_t)0x00FF0000) // User option byte
#define FLASH_USER_nUSER            ((uint32_t)0xFF000000) // User complemented option byte

//===================  Bit definition for OB_Data0 register  ===================
#define FLASH_Data0_Data0           ((uint32_t)0x000000FF) // User data storage option byte
#define FLASH_Data0_nData0          ((uint32_t)0x0000FF00) // User data storage complemented option byte

//==================  Bit definition for OB_Data1 register  ====================
#define FLASH_Data1_Data1           ((uint32_t)0x00FF0000) // User data storage option byte
#define FLASH_Data1_nData1          ((uint32_t)0xFF000000) // User data storage complemented option byte

//===================  Bit definition for OB_WRPR0 register  ===================
#define FLASH_WRPR0_WRPR0           ((uint32_t)0x000000FF) // Flash memory write protection option bytes
#define FLASH_WRPR0_nWRPR0          ((uint32_t)0x0000FF00) // Flash memory write protection complemented option bytes

//===================  Bit definition for OB_WRPR1 register  ===================
#define FLASH_WRPR1_WRPR1           ((uint32_t)0x00FF0000) // Flash memory write protection option bytes
#define FLASH_WRPR1_nWRPR1          ((uint32_t)0xFF000000) // Flash memory write protection complemented option bytes

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_FO_H
