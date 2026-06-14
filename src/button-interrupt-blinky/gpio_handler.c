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

static uint8_t const port_val_map[] = {
    ['A'] = 0x0,
    ['B'] = 0x1,
    ['C'] = 0x2,
    ['D'] = 0x3,
    ['E'] = 0x4,
    ['F'] = 0x5,
    ['G'] = 0x6,
    ['H'] = 0x7
};

static IRQn_Type const interrupt_map[] = {
    [0] = EXTI0_IRQn,
    [1] = EXTI1_IRQn,
    [2] = EXTI2_IRQn,
    [3] = EXTI3_IRQn,
    [4] = EXTI4_IRQn,
    [5] = EXTI9_5_IRQn,
    [6] = EXTI9_5_IRQn,
    [7] = EXTI9_5_IRQn,
    [8] = EXTI9_5_IRQn,
    [9] = EXTI9_5_IRQn,
    [10] = EXTI15_10_IRQn,
    [11] = EXTI15_10_IRQn,
    [12] = EXTI15_10_IRQn,
    [13] = EXTI15_10_IRQn,
    [14] = EXTI15_10_IRQn,
    [15] = EXTI15_10_IRQn
};

void gpio_init_output(unsigned char port, uint8_t pin){
    if(port <= 'H'){
        RCC->AHB2ENR |= clocken_map[(port)];
        port_map[port]->MODER &= ~(3 << (pin * 2));
        port_map[port]->MODER |= (1 << (pin * 2));
    }
}

void gpio_init_input(unsigned char port, uint8_t pin){
    if(port <= 'H'){
        RCC->AHB2ENR |= clocken_map[(port)];
        port_map[port]->MODER &= ~(3 << (pin * 2));
        port_map[port]->MODER |= (0 << (pin * 2));

        port_map[port]->PUPDR &= ~(3 << (pin * 2));
        port_map[port]->PUPDR |= (1 << (pin * 2));

    }
}

void gpio_init_interrupt(unsigned char port, uint8_t pin, unsigned char trigger){
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    SYSCFG->EXTICR[(pin/4)] &= ~(0xF << ((pin % 4) * 4));
    SYSCFG->EXTICR[(pin/4)] |= (port_val_map[port] << ((pin % 4) * 4));
    EXTI->IMR1 |= (1 << pin);

    if (trigger == 'R'){
        EXTI->RTSR1 |= (1 << pin);
        EXTI->FTSR1 &= (1 << pin);
    } else {
        EXTI->FTSR1 |= (1 << pin);
        EXTI->RTSR1 &= (1 << pin);
    }

    __NVIC_SetPriority(interrupt_map[pin], 0x3);
    __NVIC_EnableIRQ(interrupt_map[pin]);
}

bool is_output_set(unsigned char port, uint8_t pin){
    return port_map[port]->ODR & (1 << pin);
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

bool gpio_get_input(unsigned char port, uint8_t pin){
    return port_map[port]->IDR & (1 << (pin));
}