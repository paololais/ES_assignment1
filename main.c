/*
 * File:   main.c
 * Author: paolo
 *
 * Created on February 28, 2025, 2:01 PM
 */


#include "xc.h"
#include "timer.h"

int main(void) {
    // initialization code
    // [...]
    tmr_setup_period(TIMER1, 200);
    while (1) {
        // code to blink LED
        tmr_wait_period(TIMER1);
    }
    return 0;
}
