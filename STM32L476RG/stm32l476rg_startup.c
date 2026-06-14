#include <stdint.h>

/* Linker script symbols */
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* Function declarations */
int main(void);
void Reset_Handler(void);
void Default_Handler(void);

/* ARM Cortex-M4 core exception handlers */
void NMI_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)              __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)          __attribute__((weak, alias("Default_Handler")));

/* STM32L476 peripheral interrupt handlers (IRQ0 - IRQ81) */
/* RM0351 Table 47 */
void WWDG_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ0  */
void PVD_PVM_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ1  */
void TAMP_STAMP_IRQHandler(void)            __attribute__((weak, alias("Default_Handler"))); /* IRQ2  */
void RTC_WKUP_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ3  */
void FLASH_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ4  */
void RCC_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ5  */
void EXTI0_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ6  */
void EXTI1_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ7  */
void EXTI2_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ8  */
void EXTI3_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ9  */
void EXTI4_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ10 */
void DMA1_Channel1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ11 */
void DMA1_Channel2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ12 */
void DMA1_Channel3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ13 */
void DMA1_Channel4_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ14 */
void DMA1_Channel5_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ15 */
void DMA1_Channel6_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ16 */
void DMA1_Channel7_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ17 */
void ADC1_2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ18 */
void CAN1_TX_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ19 */
void CAN1_RX0_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ20 */
void CAN1_RX1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ21 */
void CAN1_SCE_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ22 */
void EXTI9_5_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ23 */
void TIM1_BRK_TIM15_IRQHandler(void)        __attribute__((weak, alias("Default_Handler"))); /* IRQ24 */
void TIM1_UP_TIM16_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ25 */
void TIM1_TRG_COM_TIM17_IRQHandler(void)    __attribute__((weak, alias("Default_Handler"))); /* IRQ26 */
void TIM1_CC_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ27 */
void TIM2_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ28 */
void TIM3_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ29 */
void TIM4_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ30 */
void I2C1_EV_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ31 */
void I2C1_ER_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ32 */
void I2C2_EV_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ33 */
void I2C2_ER_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ34 */
void SPI1_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ35 */
void SPI2_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ36 */
void USART1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ37 */
void USART2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ38 */
void USART3_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ39 */
void EXTI15_10_IRQHandler(void)             __attribute__((weak, alias("Default_Handler"))); /* IRQ40 */
void RTC_Alarm_IRQHandler(void)             __attribute__((weak, alias("Default_Handler"))); /* IRQ41 */
void DFSDM1_FLT3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler"))); /* IRQ42 */
void TIM8_BRK_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ43 */
void TIM8_UP_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ44 */
void TIM8_TRG_COM_IRQHandler(void)          __attribute__((weak, alias("Default_Handler"))); /* IRQ45 */
void TIM8_CC_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ46 */
void ADC3_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ47 */
void FMC_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ48 */
void SDMMC1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ49 */
void TIM5_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ50 */
void SPI3_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ51 */
void UART4_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ52 */
void UART5_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler"))); /* IRQ53 */
void TIM6_DAC_IRQHandler(void)              __attribute__((weak, alias("Default_Handler"))); /* IRQ54 */
void TIM7_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ55 */
void DMA2_Channel1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ56 */
void DMA2_Channel2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ57 */
void DMA2_Channel3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ58 */
void DMA2_Channel4_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ59 */
void DMA2_Channel5_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ60 */
void DFSDM1_FLT0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler"))); /* IRQ61 */
void DFSDM1_FLT1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler"))); /* IRQ62 */
void DFSDM1_FLT2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler"))); /* IRQ63 */
void COMP_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ64 */
void LPTIM1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ65 */
void LPTIM2_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ66 */
void OTG_FS_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ67 */
void DMA2_Channel6_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ68 */
void DMA2_Channel7_IRQHandler(void)         __attribute__((weak, alias("Default_Handler"))); /* IRQ69 */
void LPUART1_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ70 */
void QUADSPI_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ71 */
void I2C3_EV_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ72 */
void I2C3_ER_IRQHandler(void)               __attribute__((weak, alias("Default_Handler"))); /* IRQ73 */
void SAI1_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ74 */
void SAI2_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler"))); /* IRQ75 */
void SWPMI1_IRQHandler(void)                __attribute__((weak, alias("Default_Handler"))); /* IRQ76 */
void TSC_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ77 */
void LCD_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ78 */
void AES_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ79 */
void RNG_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ80 */
void FPU_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler"))); /* IRQ81 */

/*
 * Vector table — must be placed at 0x00000000 (start of flash).
 * Layout per ARM Cortex-M4 TRM + STM32L476 RM0351 Table 47.
 *
 * Offset  Position  Name
 * 0x0000  -         Initial MSP
 * 0x0004  -1        Reset
 * 0x0008  -14       NMI
 * 0x000C  -13       HardFault
 * 0x0010  -12       MemManage
 * 0x0014  -11       BusFault
 * 0x0018  -10       UsageFault
 * 0x001C  -         Reserved x4
 * 0x002C  -5        SVCall
 * 0x0030  -4        DebugMon
 * 0x0034  -         Reserved
 * 0x0038  -2        PendSV
 * 0x003C  -1        SysTick
 * 0x0040  IRQ0      WWDG
 * ...
 * 0x00E8  IRQ81     FPU
 */
__attribute__((section(".isr_vector"), used))
const void * const vector_table[] = {
    /* ARM core */
    (void *)&_estack,              /* 0x0000 Initial stack pointer          */
    Reset_Handler,                 /* 0x0004 Reset                          */
    NMI_Handler,                   /* 0x0008 NMI                            */
    HardFault_Handler,             /* 0x000C Hard fault                     */
    MemManage_Handler,             /* 0x0010 MPU fault                      */
    BusFault_Handler,              /* 0x0014 Bus fault                      */
    UsageFault_Handler,            /* 0x0018 Usage fault                    */
    0,                             /* 0x001C Reserved                       */
    0,                             /* 0x0020 Reserved                       */
    0,                             /* 0x0024 Reserved                       */
    0,                             /* 0x0028 Reserved                       */
    SVC_Handler,                   /* 0x002C SVCall                         */
    DebugMon_Handler,              /* 0x0030 Debug monitor                  */
    0,                             /* 0x0034 Reserved                       */
    PendSV_Handler,                /* 0x0038 PendSV                         */
    SysTick_Handler,               /* 0x003C SysTick                        */

    /* Peripheral interrupts — IRQ0 onwards */
    WWDG_IRQHandler,               /* 0x0040 IRQ0  Window watchdog          */
    PVD_PVM_IRQHandler,            /* 0x0044 IRQ1  PVD/PVM through EXTI     */
    TAMP_STAMP_IRQHandler,         /* 0x0048 IRQ2  Tamper, TimeStamp        */
    RTC_WKUP_IRQHandler,           /* 0x004C IRQ3  RTC wakeup               */
    FLASH_IRQHandler,              /* 0x0050 IRQ4  Flash global             */
    RCC_IRQHandler,                /* 0x0054 IRQ5  RCC global               */
    EXTI0_IRQHandler,              /* 0x0058 IRQ6  EXTI line 0              */
    EXTI1_IRQHandler,              /* 0x005C IRQ7  EXTI line 1              */
    EXTI2_IRQHandler,              /* 0x0060 IRQ8  EXTI line 2              */
    EXTI3_IRQHandler,              /* 0x0064 IRQ9  EXTI line 3              */
    EXTI4_IRQHandler,              /* 0x0068 IRQ10 EXTI line 4              */
    DMA1_Channel1_IRQHandler,      /* 0x006C IRQ11 DMA1 channel 1           */
    DMA1_Channel2_IRQHandler,      /* 0x0070 IRQ12 DMA1 channel 2           */
    DMA1_Channel3_IRQHandler,      /* 0x0074 IRQ13 DMA1 channel 3           */
    DMA1_Channel4_IRQHandler,      /* 0x0078 IRQ14 DMA1 channel 4           */
    DMA1_Channel5_IRQHandler,      /* 0x007C IRQ15 DMA1 channel 5           */
    DMA1_Channel6_IRQHandler,      /* 0x0080 IRQ16 DMA1 channel 6           */
    DMA1_Channel7_IRQHandler,      /* 0x0084 IRQ17 DMA1 channel 7           */
    ADC1_2_IRQHandler,             /* 0x0088 IRQ18 ADC1 and ADC2            */
    CAN1_TX_IRQHandler,            /* 0x008C IRQ19 CAN1 TX                  */
    CAN1_RX0_IRQHandler,           /* 0x0090 IRQ20 CAN1 RX0                 */
    CAN1_RX1_IRQHandler,           /* 0x0094 IRQ21 CAN1 RX1                 */
    CAN1_SCE_IRQHandler,           /* 0x0098 IRQ22 CAN1 SCE                 */
    EXTI9_5_IRQHandler,            /* 0x009C IRQ23 EXTI lines 5-9           */
    TIM1_BRK_TIM15_IRQHandler,     /* 0x00A0 IRQ24 TIM1 break, TIM15        */
    TIM1_UP_TIM16_IRQHandler,      /* 0x00A4 IRQ25 TIM1 update, TIM16       */
    TIM1_TRG_COM_TIM17_IRQHandler, /* 0x00A8 IRQ26 TIM1 trigger, TIM17      */
    TIM1_CC_IRQHandler,            /* 0x00AC IRQ27 TIM1 capture compare     */
    TIM2_IRQHandler,               /* 0x00B0 IRQ28 TIM2                     */
    TIM3_IRQHandler,               /* 0x00B4 IRQ29 TIM3                     */
    TIM4_IRQHandler,               /* 0x00B8 IRQ30 TIM4                     */
    I2C1_EV_IRQHandler,            /* 0x00BC IRQ31 I2C1 event               */
    I2C1_ER_IRQHandler,            /* 0x00C0 IRQ32 I2C1 error               */
    I2C2_EV_IRQHandler,            /* 0x00C4 IRQ33 I2C2 event               */
    I2C2_ER_IRQHandler,            /* 0x00C8 IRQ34 I2C2 error               */
    SPI1_IRQHandler,               /* 0x00CC IRQ35 SPI1                     */
    SPI2_IRQHandler,               /* 0x00D0 IRQ36 SPI2                     */
    USART1_IRQHandler,             /* 0x00D4 IRQ37 USART1                   */
    USART2_IRQHandler,             /* 0x00D8 IRQ38 USART2                   */
    USART3_IRQHandler,             /* 0x00DC IRQ39 USART3                   */
    EXTI15_10_IRQHandler,          /* 0x00E0 IRQ40 EXTI lines 10-15         */
    RTC_Alarm_IRQHandler,          /* 0x00E4 IRQ41 RTC alarm (A and B)      */
    DFSDM1_FLT3_IRQHandler,        /* 0x00E8 IRQ42 DFSDM1 filter 3         */
    TIM8_BRK_IRQHandler,           /* 0x00EC IRQ43 TIM8 break               */
    TIM8_UP_IRQHandler,            /* 0x00F0 IRQ44 TIM8 update              */
    TIM8_TRG_COM_IRQHandler,       /* 0x00F4 IRQ45 TIM8 trigger/commutation */
    TIM8_CC_IRQHandler,            /* 0x00F8 IRQ46 TIM8 capture compare     */
    ADC3_IRQHandler,               /* 0x00FC IRQ47 ADC3                     */
    FMC_IRQHandler,                /* 0x0100 IRQ48 FMC                      */
    SDMMC1_IRQHandler,             /* 0x0104 IRQ49 SDMMC1                   */
    TIM5_IRQHandler,               /* 0x0108 IRQ50 TIM5                     */
    SPI3_IRQHandler,               /* 0x010C IRQ51 SPI3                     */
    UART4_IRQHandler,              /* 0x0110 IRQ52 UART4                    */
    UART5_IRQHandler,              /* 0x0114 IRQ53 UART5                    */
    TIM6_DAC_IRQHandler,           /* 0x0118 IRQ54 TIM6 and DAC underrun    */
    TIM7_IRQHandler,               /* 0x011C IRQ55 TIM7                     */
    DMA2_Channel1_IRQHandler,      /* 0x0120 IRQ56 DMA2 channel 1           */
    DMA2_Channel2_IRQHandler,      /* 0x0124 IRQ57 DMA2 channel 2           */
    DMA2_Channel3_IRQHandler,      /* 0x0128 IRQ58 DMA2 channel 3           */
    DMA2_Channel4_IRQHandler,      /* 0x012C IRQ59 DMA2 channel 4           */
    DMA2_Channel5_IRQHandler,      /* 0x0130 IRQ60 DMA2 channel 5           */
    DFSDM1_FLT0_IRQHandler,        /* 0x0134 IRQ61 DFSDM1 filter 0         */
    DFSDM1_FLT1_IRQHandler,        /* 0x0138 IRQ62 DFSDM1 filter 1         */
    DFSDM1_FLT2_IRQHandler,        /* 0x013C IRQ63 DFSDM1 filter 2         */
    COMP_IRQHandler,               /* 0x0140 IRQ64 COMP1 and COMP2          */
    LPTIM1_IRQHandler,             /* 0x0144 IRQ65 LPTIM1                   */
    LPTIM2_IRQHandler,             /* 0x0148 IRQ66 LPTIM2                   */
    OTG_FS_IRQHandler,             /* 0x014C IRQ67 USB OTG FS               */
    DMA2_Channel6_IRQHandler,      /* 0x0150 IRQ68 DMA2 channel 6           */
    DMA2_Channel7_IRQHandler,      /* 0x0154 IRQ69 DMA2 channel 7           */
    LPUART1_IRQHandler,            /* 0x0158 IRQ70 LPUART1                  */
    QUADSPI_IRQHandler,            /* 0x015C IRQ71 QuadSPI                  */
    I2C3_EV_IRQHandler,            /* 0x0160 IRQ72 I2C3 event               */
    I2C3_ER_IRQHandler,            /* 0x0164 IRQ73 I2C3 error               */
    SAI1_IRQHandler,               /* 0x0168 IRQ74 SAI1                     */
    SAI2_IRQHandler,               /* 0x016C IRQ75 SAI2                     */
    SWPMI1_IRQHandler,             /* 0x0170 IRQ76 SWPMI1                   */
    TSC_IRQHandler,                /* 0x0174 IRQ77 TSC                      */
    LCD_IRQHandler,                /* 0x0178 IRQ78 LCD                      */
    AES_IRQHandler,                /* 0x017C IRQ79 AES                      */
    RNG_IRQHandler,                /* 0x0180 IRQ80 RNG                      */
    FPU_IRQHandler,                /* 0x0184 IRQ81 FPU                      */
};

void Default_Handler(void) {
    while (1) {}
}

void Reset_Handler(void) {
    uint32_t *pSrc  = &_sidata;
    uint32_t *pDest = &_sdata;

    /* Copy .data from flash (LMA) to RAM (VMA) */
    while (pDest < &_edata) {
        *pDest++ = *pSrc++;
    }

    /* Zero .bss */
    pDest = &_sbss;
    while (pDest < &_ebss) {
        *pDest++ = 0;
    }

    main();
    while (1) {}
}