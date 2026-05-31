#include "stm32l476xx.h"

#define LED_PIN 5

void delay(int ms){
    for(volatile int i = 0; i <= ms; i++){}
}

int main(){

    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    GPIOA->MODER &= ~(3 << (LED_PIN * 2));
    GPIOA->MODER |= (1 << (LED_PIN * 2));

    while (1) {
        
        GPIOA->BSRR = (1 << LED_PIN);
        delay(100000);

        GPIOA->BSRR = (1 << (LED_PIN + 16));
        delay(100000);
    }

    return 0;
}