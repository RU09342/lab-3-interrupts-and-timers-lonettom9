#include <msp430.h> 


/**
 * main.c
 */
int main(void) {
WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer
P1SEL = 0;
//PM5CTL0 &= ~LOCKLPM5; //disable high impedance mode
P1DIR |=BIT0; //set Port 1.0 output ---LED
P1DIR &=~(BIT1); //set Port 1.1 input --- pushbutton
P1REN|=BIT1;//enable pull-up resistor on
P1OUT|=BIT1;
P1IE |=BIT1;//enable the interrupt on Port 1.1
P1IES |=BIT1;//set as falling edge
P1IFG &=~(BIT1);//clear interrupt flag
//enter LPM4 mode and enable global interrupt
_BIS_SR(LPM4_bits + GIE);
}
volatile unsigned int duration = 1000;
//Port 1 ISR
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
{
P1OUT ^=BIT0;
do (duration--);
while (duration != 0);
P1IFG &=~(BIT1); // Clear flag
}
