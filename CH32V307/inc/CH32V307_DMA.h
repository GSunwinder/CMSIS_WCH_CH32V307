//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_DMA.h
// Version     : V1.0
// Date        : 18-08-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 DMA Controller Header File.
//==============================================================================

#ifndef __CH32V307_DMA_H
#define __CH32V307_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct DMA_Channel_TypeDef
{
    __IO uint32_t CFGR;
    __IO uint32_t CNTR;
    __IO uint32_t PADDR;
    __IO uint32_t MADDR;
} DMA_Channel_Type;

typedef struct
{
    __I  uint32_t INTFR;
    __O  uint32_t INTFCR;
         DMA_Channel_Type CH1;
         uint32_t :32;
         DMA_Channel_Type CH2;
         uint32_t :32;
         DMA_Channel_Type CH3;
         uint32_t :32;
         DMA_Channel_Type CH4;
         uint32_t :32;
         DMA_Channel_Type CH5;
         uint32_t :32;
         DMA_Channel_Type CH6;
         uint32_t :32;
         DMA_Channel_Type CH7;
} DMA1_TypeDef;

typedef struct
{
    __I  uint32_t INTFR;
    __O  uint32_t INTFCR;
         DMA_Channel_Type CH1;
         uint32_t :32;
         DMA_Channel_Type CH2;
         uint32_t :32;
         DMA_Channel_Type CH3;
         uint32_t :32;
         DMA_Channel_Type CH4;
         uint32_t :32;
         DMA_Channel_Type CH5;
         uint32_t :32;
         DMA_Channel_Type CH6;
         uint32_t :32;
         DMA_Channel_Type CH7;
         // CH8..CH11 for DMA2 only
         DMA_Channel_Type CH8;
         DMA_Channel_Type CH9;
         DMA_Channel_Type CH10;
         DMA_Channel_Type CH11;
    __I  uint32_t EXTEM_INTFR;
    __O  uint32_t EXTEM_INTFCR;
} DMA_TypeDef;

#define DMA1                    ((DMA_TypeDef *)DMA1_BASE)
#define DMA2                    ((DMA_TypeDef *)DMA2_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for DMA_INTFR register  ===================
#define DMA_TEIF7           ((uint32_t)0x08000000) // Channel 7 Transfer Error flag   
#define DMA_HTIF7           ((uint32_t)0x04000000) // Channel 7 Half Transfer flag    
#define DMA_TCIF7           ((uint32_t)0x02000000) // Channel 7 Transfer Complete flag
#define DMA_GIF7            ((uint32_t)0x01000000) // Channel 7 Global interrupt flag 
#define DMA_TEIF6           ((uint32_t)0x00800000) // Channel 6 Transfer Error flag   
#define DMA_HTIF6           ((uint32_t)0x00400000) // Channel 6 Half Transfer flag    
#define DMA_TCIF6           ((uint32_t)0x00200000) // Channel 6 Transfer Complete flag
#define DMA_GIF6            ((uint32_t)0x00100000) // Channel 6 Global interrupt flag 
#define DMA_TEIF5           ((uint32_t)0x00080000) // Channel 5 Transfer Error flag   
#define DMA_HTIF5           ((uint32_t)0x00040000) // Channel 5 Half Transfer flag    
#define DMA_TCIF5           ((uint32_t)0x00020000) // Channel 5 Transfer Complete flag
#define DMA_GIF5            ((uint32_t)0x00010000) // Channel 5 Global interrupt flag 
#define DMA_TEIF4           ((uint32_t)0x00008000) // Channel 4 Transfer Error flag   
#define DMA_HTIF4           ((uint32_t)0x00004000) // Channel 4 Half Transfer flag    
#define DMA_TCIF4           ((uint32_t)0x00002000) // Channel 4 Transfer Complete flag
#define DMA_GIF4            ((uint32_t)0x00001000) // Channel 4 Global interrupt flag 
#define DMA_TEIF3           ((uint32_t)0x00000800) // Channel 3 Transfer Error flag   
#define DMA_HTIF3           ((uint32_t)0x00000400) // Channel 3 Half Transfer flag    
#define DMA_TCIF3           ((uint32_t)0x00000200) // Channel 3 Transfer Complete flag
#define DMA_GIF3            ((uint32_t)0x00000100) // Channel 3 Global interrupt flag 
#define DMA_TEIF2           ((uint32_t)0x00000080) // Channel 2 Transfer Error flag   
#define DMA_HTIF2           ((uint32_t)0x00000040) // Channel 2 Half Transfer flag    
#define DMA_TCIF2           ((uint32_t)0x00000020) // Channel 2 Transfer Complete flag
#define DMA_GIF2            ((uint32_t)0x00000010) // Channel 2 Global interrupt flag 
#define DMA_TEIF1           ((uint32_t)0x00000008) // Channel 1 Transfer Error flag   
#define DMA_HTIF1           ((uint32_t)0x00000004) // Channel 1 Half Transfer flag    
#define DMA_TCIF1           ((uint32_t)0x00000002) // Channel 1 Transfer Complete flag
#define DMA_GIF1            ((uint32_t)0x00000001) // Channel 1 Global interrupt flag 

//==================  Bit definition for DMA_INTFCR register  ==================
#define DMA_CTEIF7          ((uint32_t)0x08000000) // Channel 7 Transfer Error clear   
#define DMA_CHTIF7          ((uint32_t)0x04000000) // Channel 7 Half Transfer clear    
#define DMA_CTCIF7          ((uint32_t)0x02000000) // Channel 7 Transfer Complete clear
#define DMA_CGIF7           ((uint32_t)0x01000000) // Channel 7 Global interrupt clear 
#define DMA_CTEIF6          ((uint32_t)0x00800000) // Channel 6 Transfer Error clear   
#define DMA_CHTIF6          ((uint32_t)0x00400000) // Channel 6 Half Transfer clear    
#define DMA_CTCIF6          ((uint32_t)0x00200000) // Channel 6 Transfer Complete clear
#define DMA_CGIF6           ((uint32_t)0x00100000) // Channel 6 Global interrupt clear 
#define DMA_CTEIF5          ((uint32_t)0x00080000) // Channel 5 Transfer Error clear   
#define DMA_CHTIF5          ((uint32_t)0x00040000) // Channel 5 Half Transfer clear    
#define DMA_CTCIF5          ((uint32_t)0x00020000) // Channel 5 Transfer Complete clear
#define DMA_CGIF5           ((uint32_t)0x00010000) // Channel 5 Global interrupt clear 
#define DMA_CTEIF4          ((uint32_t)0x00008000) // Channel 4 Transfer Error clear   
#define DMA_CHTIF4          ((uint32_t)0x00004000) // Channel 4 Half Transfer clear    
#define DMA_CTCIF4          ((uint32_t)0x00002000) // Channel 4 Transfer Complete clear
#define DMA_CGIF4           ((uint32_t)0x00001000) // Channel 4 Global interrupt clear 
#define DMA_CTEIF3          ((uint32_t)0x00000800) // Channel 3 Transfer Error clear   
#define DMA_CHTIF3          ((uint32_t)0x00000400) // Channel 3 Half Transfer clear    
#define DMA_CTCIF3          ((uint32_t)0x00000200) // Channel 3 Transfer Complete clear
#define DMA_CGIF3           ((uint32_t)0x00000100) // Channel 3 Global interrupt clear 
#define DMA_CTEIF2          ((uint32_t)0x00000080) // Channel 2 Transfer Error clear   
#define DMA_CHTIF2          ((uint32_t)0x00000040) // Channel 2 Half Transfer clear    
#define DMA_CTCIF2          ((uint32_t)0x00000020) // Channel 2 Transfer Complete clear
#define DMA_CGIF2           ((uint32_t)0x00000010) // Channel 2 Global interrupt clear 
#define DMA_CTEIF1          ((uint32_t)0x00000008) // Channel 1 Transfer Error clear   
#define DMA_CHTIF1          ((uint32_t)0x00000004) // Channel 1 Half Transfer clear    
#define DMA_CTCIF1          ((uint32_t)0x00000002) // Channel 1 Transfer Complete clear
#define DMA_CGIF1           ((uint32_t)0x00000001) // Channel 1 Global interrupt clear 

//==================  Bit definition for DMA_CFGRx register  ===================
#define DMA_CFGR_MEM2MEM    ((uint32_t)0x00004000) // Memory to memory mode

#define DMA_CFGR_PL         ((uint32_t)0x00003000) // PL[1:0] bits(Channel Priority level)
#define DMA_CFGR_PL_LOW     ((uint32_t)0x00000000) // Low                                 
#define DMA_CFGR_PL_MED     ((uint32_t)0x00001000) // Medium                              
#define DMA_CFGR_PL_HIGH    ((uint32_t)0x00002000) // High                                
#define DMA_CFGR_PL_VHGH    ((uint32_t)0x00003000) // Very high                           

#define DMA_CFGR_MSIZE      ((uint32_t)0x00000C00) // MSIZE[1:0] bits (Memory size)
#define DMA_CFGR_MSIZE_8    ((uint32_t)0x00000000) //  8 bit data width            
#define DMA_CFGR_MSIZE_16   ((uint32_t)0x00000400) // 16 bit data width            
#define DMA_CFGR_MSIZE_32   ((uint32_t)0x00000800) // 32 bit data width            

#define DMA_CFGR_PSIZE      ((uint32_t)0x00000300) // PSIZE[1:0] bits (Peripheral size)
#define DMA_CFGR_PSIZE_8    ((uint32_t)0x00000000) //  8 bit data width                
#define DMA_CFGR_PSIZE_16   ((uint32_t)0x00000100) // 16 bit data width                
#define DMA_CFGR_PSIZE_32   ((uint32_t)0x00000200) // 32 bit data width                

#define DMA_CFGR_MINC       ((uint32_t)0x00000080) // Memory increment mode             
#define DMA_CFGR_PINC       ((uint32_t)0x00000040) // Peripheral increment mode         
#define DMA_CFGR_CIRC       ((uint32_t)0x00000020) // Circular mode                     
#define DMA_CFGR_DIR        ((uint32_t)0x00000010) // Data transfer direction           
#define DMA_CFGR_TEIE       ((uint32_t)0x00000008) // Transfer error interrupt enable   
#define DMA_CFGR_HTIE       ((uint32_t)0x00000004) // Half Transfer interrupt enable    
#define DMA_CFGR_TCIE       ((uint32_t)0x00000002) // Transfer complete interrupt enable
#define DMA_CFGR_EN         ((uint32_t)0x00000001) // Channel enable                    

//==================  Bit definition for DMA_CNTRx register  ===================
#define DMA_CNTR_NDT        ((uint32_t)0x0000FFFF) // Number of data to Transfer

//==================  Bit definition for DMA_PADDRx register  ==================
#define DMA_PADDR_PA        ((uint32_t)0xFFFFFFFF) // Peripheral Address

//==================  Bit definition for DMA_MADDRx register  ==================
#define DMA_MADDR_MA        ((uint32_t)0xFFFFFFFF) // Memory Address

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_DMA_H
