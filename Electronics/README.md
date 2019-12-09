## Electrical Design

This directory holds the EAGLE `.sch` files used to develop the schematics of the electronics used in the project. It further holds images of those schematics. The electronics used are described below<span>&#58;</span>

### Microcontroller

The brains of the project allowing for the electromagnet to be triggered at the right time and controlling the rotation and timing of the stepper motor is a [PIC32MX250F128B](../Docs/PIC32MX1XX2XX-28-36-44-PIN-DS60001168K.pdf) microcontoller. 

The breakout schematic of this microcontroller, necessary for programming as well as interaction at a 3.3V logic level, is shown below. It includes a 3.3V voltage regulator, a [Pololu](https://www.pololu.com/) breakout board of a micro-usb connector as well as a MPLAB Snap for programming.

![PIC32_BREAKOUT](/PIC32_BREAKOUT.png)

### Electromagnet Driver
The circuitry that is used to drive the [electromagnet](../Docs/Electromagnets_McMaster-Carr.pdf) consists of a GPIO pin from the microcontroller going through a 1 kilo Ohm resistor to the base of an NPN Darlington transistor. The collector of which is connected to a 12V power supply through a parallel combination of the electromagnet being activated and a flyback diode. The emmitter of the transistor is connected to ground. This allows the GPIO pin to be used as a simple on/off switch for the electromagnet.

![Electromagnet Driver](/ELECTROMAGNET_DRIVER.png)

### Stepper Motor Driver

The circuitry used to control the stepper motor is the Adafruit [TB6612](adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout.pdf) chip. This chip is a dual H-bridge along with some protective circuitry. This chip allows the stepper to be simply controlled by 4 GPIO pins - this is done by setting the relevant GPIO pins high and low in the right order, according to [this documentation](../Docs/steps.png). This chip also allows for 3.3V logic to be used from the microcontroller while supplying the motor with the 12V necesarry to use it. 

![STEPPER_MOTOR_DRIVER](/STEPPER_MOTOR_DRIVER.png)