#include "Stepper.h"
#include"PWM.h"

void Stepper_Setup(void) {
    //Make B7,B8 and B9 an output
    TRISBbits.TRISB7 = 0; //M0
    TRISBbits.TRISB8 = 0; //M1
    TRISBbits.TRISB9 = 0; //M2

    //    TRISBbits.TRISB15 = 0; //Blue
    //Set Mode to 1/8 Step
    LATBbits.LATB7 = 1;
    LATBbits.LATB8 = 1;
    LATBbits.LATB9 = 0;

    //    LATBbits.LATB15 = 0;
}

void Step_60(void) {
    _CP0_SET_COUNT(0);
    setDuty(50);
    while (_CP0_GET_COUNT() < 15000000) {

    }
    setDuty(0);

}