#include "gpio_mapping.h"
#include "gpio_handler.h"

volatile bool button_pressed = false;

void button_init(){
    gpio_init_input(BUTTON_PORT, BUTTON_PIN);
    gpio_init_interrupt(BUTTON_PORT,BUTTON_PIN, TRIGGER_TYPE);
}

void EXTI15_10_IRQHandler(){
    if (EXTI->PR1 & (1 << BUTTON_PIN)){
        EXTI->PR1 |= (1 << BUTTON_PIN);

        button_pressed = !button_pressed;
    }
}

bool is_pressed(){
    return button_pressed;
}


