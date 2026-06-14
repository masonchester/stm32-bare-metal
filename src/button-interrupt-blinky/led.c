#include "gpio_mapping.h"
#include "gpio_handler.h"

void delay(int ms){
    for(volatile int i = 0; i <= ms; i++){}
}

void led_init(){
    gpio_init_output(LED_PORT, LED_PIN);
}

void led_blink(){
    if(!is_output_set(LED_PORT, LED_PIN)){
        gpio_set(LED_PORT, LED_PIN);
    } else {
        gpio_reset(LED_PORT, LED_PIN);
    }
    delay(100000);
}

void led_off(){
    gpio_reset(LED_PORT, LED_PIN);
}

void led_on(){
    gpio_set(LED_PORT, LED_PIN);
}