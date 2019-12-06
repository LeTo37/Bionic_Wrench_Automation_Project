#include "Setup.h"      //PIC
#include "Stepper.h"    //STEPPER MOTOR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {    
    __builtin_disable_interrupts();
    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);
    // 0 data RAM access wait states
    BMXCONbits.BMXWSDRM = 0x0;
    // enable multi vector interrupts
    INTCONbits.MVEC = 0x1;
    // disable JTAG to get pins back
    DDPCONbits.JTAGEN = 0;
    //Make B4 an input (USER)
    TRISBbits.TRISB4 = 1;
    //Stepper Motor Setup
    Stepper_Setup();
    __builtin_enable_interrupts();
    
     _CP0_SET_COUNT(0);

    while (1) {
//        // use _CP0_SET_COUNT(0) and _CP0_GET_COUNT() to test the PIC timing
//        // remember the core timer runs at half the sysclk
//        //pushbutton pressed - do nothing
//        while (PORTBbits.RB4 == 0) {
//            LATAbits.LATA4 = 0; // Keep light off
//        }
//        //1kHz LED toggle
//        if (_CP0_GET_COUNT() > 24000) {
//            LATAbits.LATA4 = !LATAbits.LATA4;
//            _CP0_SET_COUNT(0);
//        }
    }
    
}

