//========================================================  (C) COPYRIGHT  =====
// File Name   : core_startup.c
// Version     : V1.0
// Date        : 20-09-2025
// Author      : Sunwinder
// E-mail      : gisi@sunwinder.ru
// Description : RISC-V core startup procedure and
//               define interrupt table for MCU CH32V307
//==============================================================================

#include "RISC-V_QingKe_V4F.h"

extern void *_sinit;
extern void *_eusrstack;
extern void *__global_pointer$;
extern void *_data_lma, *_data_vma, *_edata;
extern void *_sbss, *_ebss;

__attribute__((naked, noreturn)) void Reset_Init(void);
__attribute__((naked, noreturn)) void main(void);
void SystemInit(void);

void NMI_Handler(void)              __attribute__((weak, alias ("Default_Handler")));
void HardFault_Handler(void)        __attribute__((weak, alias ("Default_Handler")));
void SysTick_Handler(void)          __attribute__((weak, alias ("Default_Handler")));
void SW_Handler(void)               __attribute__((weak, alias ("Default_Handler")));

void WWDG_IRQHandler(void)          __attribute__((weak, alias ("Default_Handler")));
void PVD_IRQHandler(void)           __attribute__((weak, alias ("Default_Handler")));
void FLASH_IRQHandler(void)         __attribute__((weak, alias ("Default_Handler")));
void RCC_IRQHandler(void)           __attribute__((weak, alias ("Default_Handler")));
void EXTI7_0_IRQHandler(void)       __attribute__((weak, alias ("Default_Handler")));
void AWU_IRQHandler(void)           __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel1_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel2_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel3_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel4_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel5_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel6_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void DMA_Channel7_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void ADC_IRQHandler(void)           __attribute__((weak, alias ("Default_Handler")));
void I2C_EV_IRQHandler(void)        __attribute__((weak, alias ("Default_Handler")));
void I2C_ER_IRQHandler(void)        __attribute__((weak, alias ("Default_Handler")));
void USART_IRQHandler(void)         __attribute__((weak, alias ("Default_Handler")));
void SPI_IRQHandler(void)           __attribute__((weak, alias ("Default_Handler")));
void TIM1_BRK_IRQHandler(void)      __attribute__((weak, alias ("Default_Handler")));
void TIM1_UP_IRQHandler(void)       __attribute__((weak, alias ("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void)  __attribute__((weak, alias ("Default_Handler")));
void TIM1_CC_IRQHandler(void)       __attribute__((weak, alias ("Default_Handler")));
void TIM2_IRQHandler(void)          __attribute__((weak, alias ("Default_Handler")));

__attribute__((section("jmp.init"), naked, noreturn, used)) void Reset_Handler(void)
{
    Reset_Init();
}

__attribute__((section("vec.init"))) const uint32_t vectors[38] =
{
        // Core handlers
        (uint32_t)0,
        (uint32_t)&NMI_Handler,
        (uint32_t)&HardFault_Handler,
        (uint32_t)0,
        (uint32_t)Ecall-M_Handler,
        (uint32_t)0,
        (uint32_t)0,
        (uint32_t)Ecall-U_Handler,
        (uint32_t)BreakPoint_Handler,
        (uint32_t)0,
        (uint32_t)0,
        (uint32_t)SysTick_Handler,
        (uint32_t)0,
        (uint32_t)SW_Handler,
        (uint32_t)0,

        // Peripheral handlers
        (uint32_t)WWDG_IRQHandler,
        (uint32_t)PVD_IRQHandler,
        (uint32_t)TAMPER_IRQHandler,
        (uint32_t)RTC_IRQHandler,
        (uint32_t)FLASH_IRQHandler,
        (uint32_t)RCC_IRQHandler,
        (uint32_t)EXTI0_IRQHandler,
        (uint32_t)EXTI1_IRQHandler,
        (uint32_t)EXTI2_IRQHandler,
        (uint32_t)EXTI3_IRQHandler,
        (uint32_t)EXTI4_IRQHandler,
        (uint32_t)DMA1_Channel1_IRQHandler,
        (uint32_t)DMA1_Channel2_IRQHandler,
        (uint32_t)DMA1_Channel3_IRQHandler,
        (uint32_t)DMA1_Channel4_IRQHandler,
        (uint32_t)DMA1_Channel5_IRQHandler,
        (uint32_t)DMA1_Channel6_IRQHandler,
        (uint32_t)DMA1_Channel7_IRQHandler,
        (uint32_t)ADC1_2_IRQHandler,
        (uint32_t)USB_HP_CAN1_TX_IRQHandler,
        (uint32_t)USB_LP_CAN1_RX0_IRQHandler,
        (uint32_t)CAN1_RX1_IRQHandler,
        (uint32_t)CAN1_SCE_IRQHandler,
        (uint32_t)EXTI5_9_IRQHandler,
        (uint32_t)TIM1_BRK_IRQHandler,
        (uint32_t)TIM1_UP_IRQHandler,
        (uint32_t)TIM1_TRG_COM_IRQHandler,
        (uint32_t)TIM1_CC_IRQHandler,
        (uint32_t)TIM2_IRQHandler,
        (uint32_t)TIM3_IRQHandler,
        (uint32_t)TIM4_IRQHandler,
        (uint32_t)I2C1_EV_IRQHandler,
        (uint32_t)I2C1_ER_IRQHandler,
        (uint32_t)I2C2_EV_IRQHandler,
        (uint32_t)I2C2_ER_IRQHandler,
        (uint32_t)SPI1_IRQHandler,
        (uint32_t)SPI2_IRQHandler,
        (uint32_t)USART1_IRQHandler,
        (uint32_t)USART2_IRQHandler,
        (uint32_t)USART3_IRQHandler,
        (uint32_t)EXTI10_15_IRQHandler,
        (uint32_t)RTCALARM_IRQHandler,
        (uint32_t)USBWAKEUP_IRQHandler,
        (uint32_t)TIM8_BRK_IRQHandler,
        (uint32_t)TIM8_UP_IRQHandler,
        (uint32_t)TIM8_TRG_COM_IRQHandler,
        (uint32_t)TIM8_CC_IRQHandler,
        (uint32_t)RNG_IRQHandler,
        (uint32_t)0,
        (uint32_t)SDIO_IRQHandler,
        (uint32_t)TIM5_IRQHandler,
        (uint32_t)SPI3_IRQHandler,
        (uint32_t)UART4_IRQHandler,
        (uint32_t)UART5_IRQHandler,
        (uint32_t)TIM6_IRQHandler,
        (uint32_t)TIM7_IRQHandler,
        (uint32_t)DMA2_Channel1_IRQHandler,
        (uint32_t)DMA2_Channel2_IRQHandler,
        (uint32_t)DMA2_Channel3_IRQHandler,
        (uint32_t)DMA2_Channel4_IRQHandler,
        (uint32_t)DMA2_Channel5_IRQHandler,
        (uint32_t)ETH_IRQHandler,
        (uint32_t)ETH_WKUP_IRQHandler,
        (uint32_t)CAN2_TX_IRQHandler,
        (uint32_t)CAN2_RX0_IRQHandler,
        (uint32_t)CAN2_RX1_IRQHandler,
        (uint32_t)CAN2_SCE_IRQHandler,
        (uint32_t)OTG_FS_IRQHandler,
        (uint32_t)USBHSWAKEUP_IRQHandler,
        (uint32_t)USBHS_IRQHandler,
        (uint32_t)DVP_IRQHandler,
        (uint32_t)UART6_IRQHandler,
        (uint32_t)UART7_IRQHandler,
        (uint32_t)UART8_IRQHandler,
        (uint32_t)TIM9_BRK_IRQHandler,
        (uint32_t)TIM9_UP_IRQHandler,
        (uint32_t)TIM9_TRG_COM_IRQHandler,
        (uint32_t)TIM9_CC_IRQHandler,
        (uint32_t)TIM10_BRK_IRQHandler,
        (uint32_t)TIM10_UP_IRQHandler,
        (uint32_t)TIM10_TRG_COM_IRQHandler,
        (uint32_t)TIM10_CC_IRQHandler,
        (uint32_t)DMA2_Channel6_IRQHandler,
        (uint32_t)DMA2_Channel7_IRQHandler,
        (uint32_t)DMA2_Channel8_IRQHandler,
        (uint32_t)DMA2_Channel9_IRQHandler,
        (uint32_t)DMA2_Channel10_IRQHandler,
        (uint32_t)DMA2_Channel11_IRQHandler
};

__attribute__((naked, noreturn)) void Default_Handler(void)
{
    while(1);
}

void __attribute__((naked, noreturn)) Reset_Init(void)
{
    // load global and stack pointers
    __asm(".option push\n\t"
          ".option norelax\n\t"
          "la gp, %0\n\t"
          ".option pop" : : "i"(&__global_pointer$) : );
    __asm("la sp, %0" : : "i"(&_eusrstack) : );

    // disable interrupt and set Machine mode
    __asm ("li t0, %0" : : "i"(MSTATUS_MPP_MACHINE) : );
    __asm ("csrw %0, t0" : : "i"(mstatus) : );

    // load interrupt vector table address and config address mode
    __asm("la t0, %0" : : "i"(&_sinit) : );

    //__asm("ori t0, t0, %0" : : "i"(MSTATUS_MPIE) : );
    __asm("ori t0, t0, %0" : : "i"(0x3 /*MTVEC_MODE1 | MTVEC_MODE0*/) : );
    __asm("csrw %0, t0" : : "i"(mtvec) : );

    void **pSource, **pDest;
    for (pSource = &_data_lma, pDest = &_data_vma; pDest != &_edata; pSource++, pDest++)
        *pDest = *pSource;

    for (pDest = &_sbss; pDest != &_ebss; pDest++)
        *pDest = 0;

    SystemInit();
    main();

    while(1);
}
