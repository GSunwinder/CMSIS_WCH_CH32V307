//========================================================  (C) COPYRIGHT  =====
// File Name   : system_ch32v00x.h
// Version     : V1.0
// Date        : 17-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : System startup procedure for MCU CH32V307 header file
//==============================================================================

#ifndef __SYSTEM_CH32V307_H
#define __SYSTEM_CH32V307_H

#ifdef __cplusplus
 extern "C" {
#endif 

#define HSI 0
#define HSE 1

extern uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)

// System_Exported_Functions
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif //__CH32V307_SYSTEM_H



