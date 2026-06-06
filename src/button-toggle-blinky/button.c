#include "gpio_mapping.h"
#include "gpio_handler.h"


void button_init(){
    gpio_init_input(BUTTON_PORT, BUTTON_PIN);
}

bool button_pressed(){
    if (!gpio_get_input(BUTTON_PORT, BUTTON_PIN)){
        return true;
    } else {
        return false;
    }
}
