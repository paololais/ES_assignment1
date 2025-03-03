/*
 * File:   main.c
 * Author: paolo
 *
 * Created on February 28, 2025, 2:01 PM
 */


#include "xc.h"
#include "timer.h"
#include <unistd.h>

int main(void) {
    // initialization code
    ANSELA = ANSELB = ANSELC = ANSELD = ANSELE = ANSELG = 0x0000;
     TRISAbits.TRISA0 = 0;
    LATAbits.LATA0 = 0;
    int status = 0;
    
    tmr_setup_period(TIMER1, 200);
    
    while (1) {
        // code to blink LED
        /*
         Assignment 1
         if(status == 0){
            LATAbits.LATA0 = 1;
            status = 1;
        } else{
            LATAbits.LATA0 = 0;
            status = 0;
        }
        tmr_wait_period(TIMER1);
         */
        
        LATAbits.LATA0 = 1;
        tmr_wait_ms(TIMER2, 20);
        LATAbits.LATA0 = 0;
        tmr_wait_ms(TIMER2, 200);
    }
    return 0;
}
