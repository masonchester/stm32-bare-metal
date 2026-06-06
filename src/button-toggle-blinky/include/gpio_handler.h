#ifndef GPIO_HANDLER_H
#define GPIO_HANDLER_H

#include "stm32l476xx.h"
#include <stdint.h>
#include <stdbool.h>

void gpio_init_output(unsigned char port, uint8_t pin);
void gpio_init_input(unsigned char port, uint8_t pin);
bool is_output_set(unsigned char port, uint8_t pin);
void gpio_set(unsigned char port, uint8_t pin);
void gpio_reset(unsigned char port, uint8_t pin);
bool gpio_get_input(unsigned char port, uint8_t pin);

#endif