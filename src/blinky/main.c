#include "led.h"

int main(){
    led_init();
    while (1) {
        led_blink();
    }
    return 0;
}