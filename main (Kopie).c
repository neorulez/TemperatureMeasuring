#include "config.h"

void init_tiny(void);

uint16 result1 = 0;
uint16 result2 = 0;
uint16 diff = 0;
uint8 x=0;
int main (void) 
{
	init_tiny();
	bool errorflag =0;
	while(errorflag != 1)
	{
		/****LED-BLINKING-TEST****/
		
		
		for(x = 10;x<=1000;x=+10)
		{
			PORTB= (0 << PB4);
			//PORTB= (1 << PB5);
			_delay_ms(x);
			PORTB= (1 << PB4);
			//PORTB= (0 << PB5);
			_delay_ms(x);
		}
		/***won't work because PB0 and PB1 can't do ADC...only compare*****
		result1 = result2 = diff = 0;
		result1 = adc(ADC1);
		result2 = adc(ADC2);
		uint16 diff = result1 - result2;*/
	}
return 0;
}

void init_tiny(void)
{
	/*Port-Konfiguration
	* RB0 = RB1 = RB3 = Input
	* RB2 = RB4 = RB5 = Output
	*/
	DDRB = 0x34;
}
