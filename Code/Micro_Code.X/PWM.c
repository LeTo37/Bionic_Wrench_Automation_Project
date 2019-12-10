#include"PWM.h"

void PWM_init(void) {
    //Open pins for OC1 and OC2
    RPB15Rbits.RPB15R = 0b0101; //Set B15 as OC1 (PIN 2)

    //***************TIMER 3 PWM********************
    T3CONbits.TCKPS = 0; //Prescaler N=1
    // period = (PR3+1) * N * 20.83 ns
    PR3 = 47999; //With prescaler of 1 give a 1 kHz signal
    TMR3 = 0; //reset the timer  
    T3CONbits.ON = 1; //Turn on the timer
    //********************

    //OC1
    OC1CONbits.OCM = 0b110; //PWM mode without fault pin; other OC1CON bits are defaults
    OC1RS = 0; //0% duty Cycle
    OC1R = 0; //0% duty Cycle
    OC1CONbits.OCTSEL = 1; //Use timer 3
    OC1CONbits.ON = 1; // turn on OC1

}

void setDuty(float percent) //0 = forward, 1 = back
{
    int duty;
    percent = percent / 100;
    duty = (int) (percent * 2400);
    OC1RS = duty;

}

