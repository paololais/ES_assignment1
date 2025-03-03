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
    TRISGbits.TRISG9 = 0;
    LATAbits.LATA0 = 0;
    LATGbits.LATG9 = 0;
    int status = 0;
    
    tmr_setup_period(TIMER1, 200);
    int ret;
    int delay = 2000;
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
        
        /* assignment 2
        LATAbits.LATA0 = 1;
        tmr_wait_ms(TIMER2, 20);
        LATAbits.LATA0 = 0;
        tmr_wait_ms(TIMER2, 200);
         * */
        tmr_wait_ms(TIMER2, delay);
        // code to blink LD1
        if(status == 0){
            LATAbits.LATA0 = 1;
            status = 1;
        } else{
            LATAbits.LATA0 = 0;
            status = 0;
        }
        ret = tmr_wait_period(TIMER1);
        if (ret) {
        	// turn on LD2
            LATGbits.LATG9 = 1;
        } else {
        // turn off LD2
            LATGbits.LATG9 = 0;
        }
        
        

    }
    return 0;
}
