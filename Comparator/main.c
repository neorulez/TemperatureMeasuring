// ***********************************************************

// Project:  Analog Comparator example	

// Author: winavr.scienceprog.com	

// Module description: Analog comparator example with positive comparator

// input connected to Vref 1.23V. When compared voltage exceed 1.23V LED lighst on.

// When voltage drops bellow - LED turns OFF. Comparator inputis connected to ADC3 pin.

// ***********************************************************

#include <avr\io.h>       

#include <avr\interrupt.h>  

#define AIN0 PB0
#define AIN1 PB1

#define LED1 PB5
#define LED2 PB4

void Init(){

	DDRB = 0x34; 

	PORTB|= (1<<AIN0); //no Pull-up
	PORTB|= (1<<AIN1);
	PORTB|= (0<<PB2);

	PORTB|=(1<<LED1); //Initally LED is OFF
	PORTB|=(1<<LED2); //Initally LED is OFF

	//SFIOR|=(1<<ACME);//enable multiplexer

	//ADCSRB&=~(1<<ADEN);//make sure ADC is OFF

	//ADMUX|=(0<<MUX2)|(1<<MUX1)|(1<<MUX0); //select ADC3 as negative AIN

	ACSR|=

	(0<<ACD)|	//Comparator ON

	(0<<ACBG)|	//Connect ext reference to AIN0

	(1<<ACIE)|	//Comparator Interrupt enable

	//(0<<ACIC)|	//input capture disabled

	(0<<ACIS1)| //set interrupt on output toggle

	(0<<ACIS0);

	sei();//enable global interrupts



}

// Interrupt handler for ANA_COMP_vect


ISR(ANA_COMP_vect) {

	if bit_is_clear(ACSR, ACO)
		{
			PORTB = (0<<PB4);
		}
	if bit_is_set(ACSR, ACO)
		{
			PORTB = (1<<PB4);
		}
}

// ***********************************************************

// Main program

//

int main(void) {

	 
	Init();
	while(1) {  
	    // Infinite loop; interrupts do the rest

   }

}
