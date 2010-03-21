#include "config.h"

void init_tiny(void);

uint16 result1 = 0;
uint16 result2 = 0;
uint16 diff = 0;
uint8 x=0;
int main (void) 
{
	init_tiny();
	
	
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
