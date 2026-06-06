#include "led.h"
#include "button.h"

int main(){
    
    led_init();
    button_init();
    
    int time_passed = 0;

    while (1) {
        if(button_pressed()){
            led_off();
            time_passed = 0;
        }else {
            if (time_passed >= 200){
                led_blink();
                time_passed = 0;
            }
            time_passed++;
        }
    }
    return 0;
}