#include "gpio_handler.h"

static GPIO_TypeDef *const port_map[] = {
    ['A'] = GPIOA,
    ['B'] = GPIOB,
    ['C'] = GPIOC,
    ['D'] = GPIOD,
    ['E'] = GPIOE,
    ['F'] = GPIOF,
    ['G'] = GPIOG,
    ['H'] = GPIOH
};

static uint32_t const clocken_map[] = {
    ['A'] = RCC_AHB2ENR_GPIOAEN,
    ['B'] = RCC_AHB2ENR_GPIOBEN,
    ['C'] = RCC_AHB2ENR_GPIOCEN,
    ['D'] = RCC_AHB2ENR_GPIODEN,
    ['E'] = RCC_AHB2ENR_GPIOEEN,
    ['F'] = RCC_AHB2ENR_GPIOFEN,
    ['G'] = RCC_AHB2ENR_GPIOGEN,
    ['H'] = RCC_AHB2ENR_GPIOHEN
};

void gpio_init(unsigned char port, uint8_t pin){
    if(port <= 'H'){
        RCC->AHB2ENR |= clocken_map[(port)];
        port_map[port]->MODER &= ~(3 << (pin * 2));
        port_map[port]->MODER |= (1 << (pin * 2));
    }
}

uint32_t is_output_set(unsigned char port, uint8_t pin){
    return port <= 'H' ? port_map[port]->ODR & (1 << pin) : -1;
}

void gpio_set(unsigned char port, uint8_t pin){
    if (port <= 'H'){
        port_map[port]->BSRR = (1 << (pin));
    }
}

void gpio_reset(unsigned char port, uint8_t pin){
 if (port <= 'H'){
        port_map[port]->BSRR = (1 << (pin + 16));
    }
}
