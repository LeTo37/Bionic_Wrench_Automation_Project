# Code

The code for this project was done in C in the [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide). This code is written for and loaded onto a [PIC32MX250F128B](../Docs/PIC32MX1XX2XX-28-36-44-PIN-DS60001168K.pdf) microcontoller.

The purpose of this code is to control how the electromagnet and stepper motor get triggered and rotated respectively. The code controls GPIO pins on the microcontroller to be set high and low so as to rotate the stepper motor the necessary amount at the correct time and turn the electromagnet on and off at the correct times. 