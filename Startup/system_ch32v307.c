//========================================================  (C) COPYRIGHT  =====
// File Name   : system_ch32v307.h
// Version     : V1.0
// Date        : 017-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : System startup procedure for MCU CH32V307 source file
// TODO: Update function other of SetSysClockTo_48MHZ_HSI
//==============================================================================

#include <CH32V307.h>

#define TYPE_OSC    HSE

#ifdef TYPE_OSC

    #if TYPE_OSC == HSI

        #ifndef HSI_VALUE
        #error "HSI_VALUE not defined"
        #endif

    #elif TYPE_OSC == HSE

        #ifndef HSE_VALUE
        #define HSE_VALUE ((uint32_t)8000000) // Value of the External oscillator in Hz
        #endif

    // External High Speed oscillator (HSE) Startup Timeout value
    #define HSE_STARTUP_TIMEOUT ((uint32_t)1000)

    #else
    #error "Unknown type oscillator (TYPE_OSC)"
    #endif

#else
#error "Not define HSI or HSE oscillator"
#endif

//==============================================================================
// Define clock oscillator

#if TYPE_OSC == HSI
#define SYSCLK_FREQ_8MHz_HSI    HSI_VALUE
//#define SYSCLK_FREQ_16MHZ_HSI   16000000

#elif TYPE_OSC == HSE
//#define SYSCLK_FREQ_8MHz_HSE    HSE_VALUE
#define SYSCLK_FREQ_144MHz_HSE   144000000

#else
#endif

#ifdef SYSCLK_FREQ_8MHz_HSI
  uint32_t SystemCoreClock         = SYSCLK_FREQ_8MHz_HSI;
#elif defined SYSCLK_FREQ_16MHZ_HSI
  uint32_t SystemCoreClock         = SYSCLK_FREQ_16MHZ_HSI;

#elif defined SYSCLK_FREQ_8MHz_HSE
  uint32_t SystemCoreClock         = SYSCLK_FREQ_8MHz_HSE;
#elif defined SYSCLK_FREQ_144MHz_HSE
  uint32_t SystemCoreClock         = SYSCLK_FREQ_144MHz_HSE;
#else
  uint32_t SystemCoreClock         = HSI_VALUE;
#endif

#ifdef SYSCLK_FREQ_8MHz_HSI
  static void SetSysClockTo_8MHz_HSI(void);
#elif defined SYSCLK_FREQ_16MHZ_HSI
  static void SetSysClockTo_16MHZ_HSI(void);
#elif defined SYSCLK_FREQ_8MHz_HSE
  static void SetSysClockTo_8MHz_HSE(void);
#elif defined SYSCLK_FREQ_144MHz_HSE
  static void SetSysClockTo_144MHz_HSE(void);
#endif


//==============================================================================
// Update SystemCoreClock variable according to Clock Register Values.

void SystemCoreClockUpdate(void)
{
    __I uint8_t AHBPrescTable[16] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
    uint32_t tmp;

    switch (RCC->CFGR0 & RCC_SWS)
    {
        case RCC_SWS_HSI:
            SystemCoreClock = HSI_VALUE;
            break;
        case RCC_SWS_HSE:
#ifdef HSE_VALUE
            SystemCoreClock = HSE_VALUE;
#else
            SystemCoreClock = 0;
#endif
            break;
        case RCC_SWS_PLL:
            if ((RCC->CFGR0 & RCC_PLLSRC) == RCC_PLLSRC_HSIx2)
                SystemCoreClock = HSI_VALUE * 2;
            else
#ifdef HSE_VALUE
                SystemCoreClock = HSE_VALUE * 2;
#else
                SystemCoreClock = 0;
#endif
            break;
        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    tmp = (RCC->CFGR0 & RCC_HPRE) >> 4;
    if(tmp < 8)
        SystemCoreClock /= AHBPrescTable[tmp];
    else
        SystemCoreClock >>= AHBPrescTable[tmp];
}

//==============================================================================
// Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.

static void SetSysClock(void)
{
#ifdef SYSCLK_FREQ_8MHz_HSI
    SetSysClockTo_8MHz_HSI();
#elif defined SYSCLK_FREQ_24MHZ_HSI
    SetSysClockTo_24MHZ_HSI();
#elif defined SYSCLK_FREQ_48MHZ_HSI
    SetSysClockTo_48MHZ_HSI();
#elif defined SYSCLK_FREQ_8MHz_HSE
    SetSysClockTo_8MHz_HSE();
#elif defined SYSCLK_FREQ_24MHz_HSE
    SetSysClockTo_24MHz_HSE();
#elif defined SYSCLK_FREQ_48MHz_HSE
    SetSysClockTo_48MHz_HSE();
#endif
// If none of the define above is enabled, the HSI is used as System clock.
// source (default after reset)
}

#ifdef SYSCLK_FREQ_8MHz_HSI

/*********************************************************************
 * @fn      SetSysClockTo_8MHz_HSI
 *
 * @brief   Sets HSI as System clock source and configure HCLK, PCLK2 and PCLK1 prescalers.
 *
 * @return  none
 */
static void SetSysClockTo_8MHz_HSI(void)
{
    /* Flash 0 wait state */
    FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
    FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_0;

    /* HCLK = SYSCLK = APB1 */
    RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV3;
}

#elif defined SYSCLK_FREQ_24MHZ_HSI

/*********************************************************************
 * @fn      SetSysClockTo_24MHZ_HSI
 *
 * @brief   Sets System clock frequency to 24MHz and configure HCLK, PCLK2 and PCLK1 prescalers.
 *
 * @return  none
 */
static void SetSysClockTo_24MHZ_HSI(void)
{
    /* Flash 0 wait state */
    FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
    FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_0;

    /* HCLK = SYSCLK = APB1 */
    RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV1;
}

#elif defined SYSCLK_FREQ_48MHZ_HSI

//==============================================================================
// Sets System clock frequency to 48MHz and configure HCLK, PCLK2 and PCLK1 prescalers.

static void SetSysClockTo_48MHZ_HSI(void)
{
    uint8_t tmp, trim;

    trim = *(uint8_t*)CFG0_PLL_TRIM;

    if (trim != 0xFF)
    {
        tmp = RCC->CTLR;
        tmp &= ~RCC_HSITRIM;
        tmp |= ((uint32_t)(trim + HSI_TRIM_VALUE) << 3) & RCC_HSITRIM;
        RCC->CTLR = tmp;
    }

    // Flash 0 wait state
    FLASH->ACTLR &= ~FLASH_ACTLR_LATENCY;
    FLASH->ACTLR |=  FLASH_ACTLR_LATENCY_1WAIT;

    // HCLK = SYSCLK = APB1
    RCC->CFGR0 |= RCC_HPRE_DIV1;

    // PLL configuration: PLLCLK = HSI * 2 = 48 MHz
    RCC->CFGR0 &= ~RCC_PLLSRC;
    RCC->CFGR0 |=  RCC_PLLSRC_HSIx2;

    // Enable PLL
    RCC->CTLR |= RCC_PLLON;
    // Wait till PLL is ready
    while((RCC->CTLR & RCC_PLLRDY) == 0)
    {
        __NOP();
    }
    // Select PLL as system clock source
    RCC->CFGR0 &= ~RCC_SW;
    RCC->CFGR0 |=  RCC_SW_PLL;
    // Wait till PLL is used as system clock source
    while ((RCC->CFGR0 & RCC_SWS) != RCC_SWS_PLL)
    {
        __NOP();
    }
}

#elif defined SYSCLK_FREQ_8MHz_HSE

/*********************************************************************
 * @fn      SetSysClockTo_8MHz_HSE
 *
 * @brief   Sets System clock frequency to 8MHz and configure HCLK, PCLK2 and PCLK1 prescalers.
 *
 * @return  none
 */
static void SetSysClockTo_8MHz_HSE(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /* Close PA0-PA1 GPIO function */
    RCC->APB2PCENR |= RCC_AFIOEN;
    AFIO->PCFR1 |= (1<<15);

    RCC->CTLR |= ((uint32_t)RCC_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CTLR & RCC_HSERDY;
        StartUpCounter++;
    } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CTLR & RCC_HSERDY) != RESET)
    {
        HSEStatus = (uint32_t)0x01;
    }
    else
    {
        HSEStatus = (uint32_t)0x00;
    }

    if (HSEStatus == (uint32_t)0x01)
    {
        /* Flash 0 wait state */
        FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
        FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_0;

        /* HCLK = SYSCLK = APB1 */
        RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV3;

        /* Select HSE as system clock source */
        RCC->CFGR0 &= (uint32_t)((uint32_t)~(RCC_SW));
        RCC->CFGR0 |= (uint32_t)RCC_SW_HSE;
        /* Wait till HSE is used as system clock source */
        while ((RCC->CFGR0 & (uint32_t)RCC_SWS) != (uint32_t)0x04)
        {
        }
    }
    else
    {
        // If HSE fails to start-up, the application will have wrong clock
        // configuration. User can add here some code to deal with this error
    }
}

#elif defined SYSCLK_FREQ_24MHz_HSE

/*********************************************************************
 * @fn      SetSysClockTo_24MHz_HSE
 *
 * @brief   Sets System clock frequency to 24MHz and configure HCLK, PCLK2 and PCLK1 prescalers.
 *
 * @return  none
 */
static void SetSysClockTo_24MHz_HSE(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /* Close PA0-PA1 GPIO function */
    RCC->APB2PCENR |= RCC_AFIOEN;
    AFIO->PCFR1 |= (1<<15);

    RCC->CTLR |= ((uint32_t)RCC_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CTLR & RCC_HSERDY;
        StartUpCounter++;
    } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CTLR & RCC_HSERDY) != RESET)
    {
        HSEStatus = (uint32_t)0x01;
    }
    else
    {
        HSEStatus = (uint32_t)0x00;
    }

    if (HSEStatus == (uint32_t)0x01)
    {
        /* Flash 0 wait state */
        FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
        FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_0;

        /* HCLK = SYSCLK = APB1 */
        RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV1;

        /* Select HSE as system clock source */
        RCC->CFGR0 &= (uint32_t)((uint32_t)~(RCC_SW));
        RCC->CFGR0 |= (uint32_t)RCC_SW_HSE;
        /* Wait till HSE is used as system clock source */
        while ((RCC->CFGR0 & (uint32_t)RCC_SWS) != (uint32_t)0x04)
        {
        }
    }
    else
    {
        // If HSE fails to start-up, the application will have wrong clock
        //configuration. User can add here some code to deal with this error
    }
}

#elif defined SYSCLK_FREQ_48MHz_HSE

/*********************************************************************
 * @fn      SetSysClockTo_48MHz_HSE
 *
 * @brief   Sets System clock frequency to 48MHz and configure HCLK, PCLK2 and PCLK1 prescalers.
 *
 * @return  none
 */
static void SetSysClockTo_48MHz_HSE(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /* Close PA0-PA1 GPIO function */
    RCC->APB2PCENR |= RCC_AFIOEN;
    AFIO->PCFR1 |= (1<<15);

    RCC->CTLR |= ((uint32_t)RCC_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CTLR & RCC_HSERDY;
        StartUpCounter++;
    } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CTLR & RCC_HSERDY) != RESET)
    {
        HSEStatus = (uint32_t)0x01;
    }
    else
    {
        HSEStatus = (uint32_t)0x00;
    }

    if (HSEStatus == (uint32_t)0x01)
    {
        /* Flash 0 wait state */
        FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
        FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_1;

        /* HCLK = SYSCLK = APB1 */
        RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV1;

        /* PLL configuration: PLLCLK = HSE * 2 = 48 MHz */
        RCC->CFGR0 &= (uint32_t)((uint32_t)~(RCC_PLLSRC));
        RCC->CFGR0 |= (uint32_t)(RCC_PLLSRC_HSE_Mul2);

        /* Enable PLL */
        RCC->CTLR |= RCC_PLLON;
        /* Wait till PLL is ready */
        while((RCC->CTLR & RCC_PLLRDY) == 0)
        {
        }
        /* Select PLL as system clock source */
        RCC->CFGR0 &= (uint32_t)((uint32_t)~(RCC_SW));
        RCC->CFGR0 |= (uint32_t)RCC_SW_PLL;
        /* Wait till PLL is used as system clock source */
        while ((RCC->CFGR0 & (uint32_t)RCC_SWS) != (uint32_t)0x08)
        {
        }
    }
    else
    {
        // If HSE fails to start-up, the application will have wrong clock
        //configuration. User can add here some code to deal with this error
    }
}
#endif

//==============================================================================
// - Setup default clocks
// - Reset peripheral
// - Update the SystemCoreClock variable

void SystemInit (void)
{
    uint32_t tmp;

    // Setup default clocks
    tmp = RCC->CFGR0;
    tmp &= ~(RCC_CFGR0_MCO | RCC_PLLSRC | RCC_ADCPRE | RCC_HPRE | RCC_SW);
    tmp |= RCC_MCO_NOCLOCK | RCC_PLLSRC_HSIx2 | RCC_ADCPRE_DIV128 | RCC_HPRE_DIV1 | RCC_SW_HSI;
    RCC->CFGR0 = tmp;

    tmp = RCC->CTLR;
    tmp &= ~(RCC_PLLON | RCC_CSSON | RCC_HSEBYP | RCC_HSEON | RCC_HSITRIM);
    tmp |= (HSI_TRIM_VALUE << 3) | RCC_HSION;
    RCC->CTLR = tmp;

    RCC->INTR = RCC_CSSC | RCC_PLLRDYC | RCC_HSERDYC | RCC_HSIRDYC | RCC_LSIRDYC;

    // Reset peripheral
    tmp = RCC->APB1PRSTR;
    tmp |= /*RCC_PWRRST |*/ RCC_I2CRST | RCC_WWDGRST | RCC_TIM2RST; // PWRRST halt MCU!!!
    RCC->APB1PRSTR = tmp;
    tmp &= ~(RCC_PWRRST | RCC_I2CRST | RCC_WWDGRST | RCC_TIM2RST);
    RCC->APB1PRSTR = tmp;

    tmp = RCC->APB2PRSTR;
    tmp |= RCC_USARTRST | RCC_SPIRST | RCC_TIM1RST | RCC_ADCRST |
           RCC_IOPDRST | RCC_IOPCRST | RCC_IOPARST | RCC_AFIORST;
    RCC->APB2PRSTR = tmp;
    tmp &= ~(RCC_USARTRST | RCC_SPIRST | RCC_TIM1RST | RCC_ADCRST |
             RCC_IOPDRST | RCC_IOPCRST | RCC_IOPARST | RCC_AFIORST);
    RCC->APB2PRSTR = tmp;

    SetSysClock();

    /* Enable interrupt nesting and hardware stack */
    __asm("li t0, %0\n\t"
          "csrw %1, t0" : : "i"(INTSYSCR_ENESTEN | INTSYSCR_HWSTKEN), "i"(intsyscr) : );
}
