/*
 * File:   timer.c
 * Author: paolo
 *
 * Created on February 28, 2025, 2:04 PM
 */


#include "xc.h"
#include "timer.h"

void tmr_setup_period(int timer, int ms){
    //the first function setups the timer timer to count for the specified number of milliseconds. 
    //The function should support values up to 200 millisecond. 
    //It should start the timer
    if(ms > 200) return;
    
    
    // Fcy = Fosc / 2 = 8000000 / 2 = 4000000 (number of clocks in one second)
    // in 0.1 second there would be 400000 clocks steps
    // this is too high to be put in a 16 bit register (max 65535)
    // If we set a prescaler of 1:8 we have 400000/8 = 50000 clock steps, OK!
    float Fcy = 72000000;
    float s = ms/1000;
    
    T1CONbits.TCS = 0;
    PR1 = 56250;
    //PR1 = Fcy * s /256; // (8 MHz / 2) / 8 / 10 < 65535!
    TMR1 = 0; // reset timer counter
    T1CONbits.TCKPS = 3; // prescaler 1:256
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 1; // starts the timer!
    
}

void tmr_wait_period(int timer){
    while (IFS0bits.T1IF == 0); // Aspetta che il flag di Timer 1 venga settato
    
    IFS0bits.T1IF = 0; // Pulisci il flag di interrupt di Timer 1
    T1CONbits.TON = 0;
}