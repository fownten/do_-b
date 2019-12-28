#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set arduino pin 13 (internal led) to output
	DDRB = DDRB | 0B00100100;
	// Write HIGH to pin 13
	PORTB = PORTB | 0B00100100;
	
    /* Replace with your application code */
    while (1) 
    {
//		_delay_ms(1000);
		PORTB = PORTB & 0B11011011;
//		_delay_ms(1000);
		PORTB = PORTB | 0B00100100;
    }
}

