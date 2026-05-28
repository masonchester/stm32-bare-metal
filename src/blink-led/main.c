#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000
#define PIN_NUM 5

#define RCC_AHB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x4c))
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_BSRR (*(volatile uint32_t *)(GPIOA_BASE + 0x18))


int main(){

    RCC_AHB2ENR |= (1 << 0);

    GPIOA_MODER &= ~(0x03 << (PIN_NUM * 2));
    GPIOA_MODER |= (1 << (PIN_NUM * 2));

    while(1){
        
        GPIOA_BSRR |= (1 << PIN_NUM);
        for(volatile int i = 0; i < 10000; i++) {}

        GPIOA_BSRR |= (1 << (PIN_NUM + 16));
        for(volatile int i = 0; i < 10000; i++) {}
    }

    return 0;
}