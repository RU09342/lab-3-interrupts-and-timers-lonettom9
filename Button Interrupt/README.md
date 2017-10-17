# Button Interrupt
## Objective
The goal of this lab was to use interrupts as opposed to polling to implement an LED toggle with the press of a button. 
## Summary
The pins are initialized and pull up/pull down resitors are enabled the same way as in the lab 2 button polling problem. The major difference in the two styles comes in the form of the pragma vector interrupt that is placed underneath all of the initializations and below the main section. Interrupts also allow us to enable low power mode which is done here as well using "_BIS_SR(LPMx + GIE)". The GIE part of the code enables interrupts. The interrupt occurs upon the press of a button and then the code inside the pragma vector is executed.  
## Board Differences
Pins all change of course, but the line of code "PM5CTL0 &= ~LOCKLPM5;"is required in order to disable the GPIO power-on default high-impedance mode for the 2311 and 6989.
