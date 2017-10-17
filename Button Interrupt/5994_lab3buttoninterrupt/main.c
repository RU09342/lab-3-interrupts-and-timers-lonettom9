#include <msp430.h> 


/**
 * main.c
 */
int main(void) {
WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer
PM5CTL0 &= ~LOCKLPM5; //disable high impedance mode

P1DIR |=BIT0; //set Port 1.0 output ---LED
P5DIR &= ~(BIT6); //set Port 1.1 input --- pushbutton
P5REN|=BIT6;//enable pull-up resistor on
P5OUT|=BIT6;
P5IE |=BIT6;//enable the interrupt on Port 1.1
P5IES |=BIT6;//set as falling edge
P5IFG &=~(BIT6);//clear interrupt flag
//enter LPM4 mode and enable global interrupt
_BIS_SR(LPM4_bits + GIE);
} //Port 1 ISR
#pragma vector = PORT5_VECTOR
__interrupt void Port_5(void)
{
P1OUT ^=0x01;
P5IFG &=~(BIT6);
}

