#define LED_1   PB1
#define LED_2   PB2
#define LED_3   PB3
#define LED_4   PB4
#define LED_5   PB5
     

#define BUTTON		PD5
#define BLINK_DELAY 500

#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>

int main(void)
{
	// Green LED at port B
	// Set pin as output in Data Direction Register...
	
	DDRB = DDRB | (1<<LED_1);
	DDRB = DDRB | (1<<LED_2);
	DDRB = DDRB | (1<<LED_3);
	DDRB = DDRB | (1<<LED_4);
	DDRB = DDRB | (1<<LED_5);
	
	DDRD = DDRD & ~(1<<BUTTON);
	
	// ...and turn LED off in Data Register
	//PORTB = PORTB | 62;
	//_delay_ms(BLINK_DELAY);
	PORTB = PORTB & ~(1<<LED_2);
	PORTB = PORTB & ~(1<<LED_3);
	PORTB = PORTB & ~(1<<LED_4);
	PORTB = PORTB & ~(1<<LED_5);
	_delay_ms(BLINK_DELAY);
	
	PORTD = PORTD |	(1<<BUTTON);
	
	int i;
	
	
	// Infinite loop
	while (1)
	{
		// Pause several milliseconds

		// WRITE YOUR CODE HERE
		
		
		
		for (i = 1; i < 6; ++i)
		{	
			PORTB  = PORTB | 193 | 2^i;
			_delay_ms(BLINK_DELAY);
		}
		
		for (i = 1; i < 6; ++i)
		{
			//PORTB  = (1 >> PORTB);
			//_delay_ms(BLINK_DELAY);
		}
		
		
			//PORTB = PORTB ^ (1<<LED_GREEN);
			
			//PORTC = PORTC ^ (1<<LED_WHITE);
			//_delay_ms(BLINK_DELAY);
		
		
	}

	// Will never reach this
	return 0;
}
