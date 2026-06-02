#ifndef GPIO_HANDLER_H
#define GPIO_HANDLER_H

#include "stm32l476xx.h"
#include <stdint.h>

void gpio_init(unsigned char port, uint8_t pin);
uint32_t is_output_set(unsigned char port, uint8_t pin);
void gpio_set(unsigned char port, uint8_t pin);
void gpio_reset(unsigned char port, uint8_t pin);

#endif