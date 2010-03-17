#include "config.h"

uint16 adc (uint8 pinnumber)     //measure
{            

	uint16 result = 0;
	  
	//initialize ADC, prescaler: 8
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);    
	  
	//Pin: ADC3
	ADMUX = pinnumber; //ADMUX = 0x03;
	  
	//Vin = Vref

	  
	//dummy measure
		// do adc
		ADCSRA |= (1<<ADSC);
		  
		// wait for finish ADIF-bit       
		while(!(ADCSRA & (1<<ADIF))); 

		// clear ADIF     
		ADCSRA |= (1<<ADIF);           
	  
	// measure value
		// single conversion
		ADCSRA |= (1<<ADSC);   
		// wait for finish ADIF-bit      
		while(!(ADCSRA & (1<<ADIF)));
		// save result    
		result = ADCW;   
		// clear ADIF          
		ADCSRA |= (1<<ADIF);        
		// deactivate ADC
		ADCSRA &= ~(1<<ADEN);
		// clear ADMUX           
		ADMUX = 0x00;              
	// send result to requester
	return result;              
}
