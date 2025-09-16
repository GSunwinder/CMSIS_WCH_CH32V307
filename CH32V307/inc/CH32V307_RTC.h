//========================================================  (C) COPYRIGHT  =====
// File Name   : CH32V307_RTC.h
// Version     : V1.0
// Date        : 11-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : CH32V307 Real-Time Clock (RTC) Header File.
//==============================================================================

#ifndef __CH32V307_RTC_H
#define __CH32V307_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CH32V307.h"

typedef struct
{
    __IO uint16_t CTLRH;
    __IO uint16_t CTLRL;
    __O  uint16_t PSCRH;
    __O  uint16_t PSCRL;
    __I  uint16_t DIVH;
    __I  uint16_t DIVL;
    __IO uint16_t CNTH;
    __IO uint16_t CNTL;
    __O  uint16_t ALARMH;
    __O  uint16_t ALARML;
} RTC_TypeDef;

#define RTC     ((RTC_TypeDef *)RTC_BASE)

//==============================================================================
//                        Peripheral Registers Bits Definition
//==============================================================================

//==================  Bit definition for RTC_CTLRH register  ===================
#define RTC_CTLRH_OWIE          ((uint16_t)0x0004) // Overflow interrupt enable
#define RTC_CTLRH_ALRIE         ((uint16_t)0x0002) // Alarm interrupt enable
#define RTC_CTLRH_SECIE         ((uint16_t)0x0001) // Second interrupt enable

//==================  Bit definition for SPI_CTLRL register  ===================
#define RTC_CTLRL_RTOFF         ((uint16_t)0x0020) // RTC operation off
#define RTC_CTLRL_CNF           ((uint16_t)0x0010) // Configuration flag
#define RTC_CTLRL_RSF           ((uint16_t)0x0008) // Registers synchronized flag
#define RTC_CTLRL_OWF           ((uint16_t)0x0004) // Counter overflow flag
#define RTC_CTLRL_ALRF          ((uint16_t)0x0002) // Alarm flag
#define RTC_CTLRL_SECF          ((uint16_t)0x0001) // Second flag

//==================  Bit definition for RTC_PSCRH register  ===================
#define RTC_PSCRH_PRL           ((uint16_t)0x000F) // Prescaler reload reg. high

//==================  Bit definition for RTC_PSCRL register  ===================
#define RTC_PSCRL_PRL           ((uint16_t)0xFFFF) // Prescaler reload reg. low

//==================  Bit definition for RTC_DIVH register  ====================
#define RTC_DIVH_DIV            ((uint16_t)0x000F) // Prescaler divider reg. high

//==================  Bit definition for RTC_DIVL register  ====================
#define RTC_DIVL_DIV            ((uint16_t)0xFFFF) // Prescaler divider reg. low

//==================  Bit definition for RTC_CNTH register  ====================
#define RTC_CNTH_DIV            ((uint16_t)0xFFFF) // RTC counter register high

//==================  Bit definition for RTC_DIVL register  ====================
#define RTC_CNTL_DIV            ((uint16_t)0xFFFF) // RTC counter register low

//==================  Bit definition for RTC_ALRMH register  ===================
#define RTC_ALRMH_DIV           ((uint16_t)0xFFFF) // Alarm register high

//==================  Bit definition for RTC_ALRML register  ===================
#define RTC_ALRML_DIV           ((uint16_t)0xFFFF) // Alarm register low

#ifdef __cplusplus
}
#endif

#endif // __CH32V307_RTC_H
