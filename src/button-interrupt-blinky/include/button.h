#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>

void button_init();
void EXTI15_10_IRQHandler();
bool is_pressed();
#endif
