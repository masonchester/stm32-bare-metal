
#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void Default_Handler(void);

void NMI_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void HardFault_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void MemManager_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void BusFault_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void UsageFault_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void SVCall_IRQHandler(void )       __attribute__((weak, alias("Default_Handler")));
void Debug_IRQHandler(void )       __attribute__((weak, alias("Default_Handler")));
void PendSV_IRQHandler(void )       __attribute__((weak, alias("Default_Handler")));
void SysTick_IRQHandler(void )       __attribute__((weak, alias("Default_Handler")));

// setup vector table of function pointers
__attribute__((section(".isr_vector"), used))
const void * const vector_table [] = {
    (void *)&_estack,
    Reset_Handler,
    NMI_IRQHandler,
    HardFault_IRQHandler,
    MemManager_IRQHandler,
    BusFault_IRQHandler,
    UsageFault_IRQHandler,
    0,0,0,0,
    SVCall_IRQHandler,
    Debug_IRQHandler,
    0,
    PendSV_IRQHandler,
    SysTick_IRQHandler,
};

void Default_Handler(){
    while(1) {}
}

void Reset_Handler(){

    uint32_t *pSrc = &_sidata;
    uint32_t *pDest = &_sdata;

    // Copy initialized data from ROM to RAM
    while(pDest < &_edata){
        *pDest++ = *pSrc++;
    }

    pDest = &_sbss;

    // Zero out unintialized memory region
    while(pDest < &_ebss){
        *pDest++ = 0;
    }

    // Call main function
    main();

    while (1) {}
}