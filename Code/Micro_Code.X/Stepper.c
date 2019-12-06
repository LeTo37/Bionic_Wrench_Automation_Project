#include "Stepper.h"

void Stepper_Setup(void){
    //Make B8 and B9 an output
    TRISBbits.TRISB8 = 0; //Black
    TRISBbits.TRISB9 = 0; //Green
    //Make B14 and B15 an output
    TRISBbits.TRISB14 = 0; //Red
    TRISBbits.TRISB15 = 0; //Blue
}

void One_Step(void)
{
    // Can add some set and get counts for delays if necessary
    LATBbits.LATB8 = 1;
    LATBbits.LATB9 = 0;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 0;
    //********************
    LATBbits.LATB8 = 0;
    LATBbits.LATB9 = 1;
    LATBbits.LATB14 = 1;
    LATBbits.LATB15 = 0;
    //********************
    LATBbits.LATB8 = 0;
    LATBbits.LATB9 = 1;
    LATBbits.LATB14 = 0;
    LATBbits.LATB15 = 1;
    //********************
    LATBbits.LATB8 = 1;
    LATBbits.LATB9 = 0;
    LATBbits.LATB14 = 0;
    LATBbits.LATB15 = 1;
    //********************




}

void Step(void){
    int i = 0;
    while(i < STEPS)
    {
        Step();
        i++;
    }
}