#include "gpio_handler.h"

static GPIO_TypeDef *const port_map[] = {
    ['A'] = GPIOA,
    ['B'] = GPIOB,
    ['C'] = GPIOC,
};

static uint32_t const clocken_map[] = {
    ['A'] = RCC_AHB2ENR_GPIOAEN,
    ['B'] = RCC_AHB2ENR_GPIOBEN,
    ['C'] = RCC_AHB2ENR_GPIOCEN
};

void gpio_init(unsigned char port, uint8_t pin){
    RCC->AHB2ENR |= clocken_map[(port)];
    port_map[port]->MODER &= ~(3 << (pin * 2));
    port_map[port]->MODER |= (1 << (pin * 2));
}

uint32_t is_output_set(unsigned char port, uint8_t pin){
    return port_map[port]->ODR & (1 << pin);
}

void gpio_set(unsigned char port, uint8_t pin){
    port_map[port]->BSRR = (1 << (pin));
}

void gpio_reset(unsigned char port, uint8_t pin){
    port_map[port]->BSRR = (1 << (pin + 16));
}
