# TimerA
## Objective
The goal of this lab was to become familiar with the timers at the disposal of the MSP430. The task at hand was to use the timer peripherals to control the speed of two LEDs.
## Summary
The pins are initialized and pull up/pull down resitors are enabled the same way as in the first part of the lab. The timer TA0 is set using the line "TA0CTL = TASSELx + MC_x;"(x being 0,1,or2). The value of X determines whether the counter is in up mode, continuous mode, or up/down mode; also specifies which clock is used (ACLK, SMCLK, MCLK). TA0CCTL0 sets the mode to either capture or compare if up or up/down is used; TA0CCR0 is the period for the counter and sets the speed of the blink because the frequency of the blink is determined by the speed of the clock/TA0CCR0. 
## Board Differences
Pins all change of course, but the line of code "PM5CTL0 &= ~LOCKLPM5;"is required in order to disable the GPIO power-on default high-impedance mode for the 2311 and 6989. The 2311 has no TimerA so TimerB was used for that implementation.