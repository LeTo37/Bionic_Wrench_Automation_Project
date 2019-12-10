#ifndef _STEPPER_H   
#define _STEPPER_H

#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro

#define STEPS 19

void Stepper_Setup(void); //Set up the GPIO pins to control motor.
void Step_60(void);          //Step 60 degrees

#endif