#include <stdio.h>
#include <time.h> 

#include "RCOutput_AioPRU.h"

static uint16_t pwm = 1500;
static int8_t delta = 1;

void delay(int milli_seconds) 
{ 
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 

int main(){
    RCOutput_AioPRU rc;
    rc.init();
    for (uint8_t i = 0; i < 12; i++) {
        rc.enable_ch(i);
    }
    while (1)
    {
        for (uint8_t i=0; i < 12; i++) {
            rc.write(i, pwm);
        }
        pwm += delta;
        if (delta > 0 && pwm >= 19000) {
            delta = -1;
            printf("reversing\n");
        } else if (delta < 0 && pwm <= 1000) {
            delta = 1;
            printf("reversing\n");
        }
        delay(100); 
    }
}