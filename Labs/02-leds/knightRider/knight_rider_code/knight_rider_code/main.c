#define LED_1   PB1
#define LED_2   PB2
#define LED_3   PB3
#define LED_4   PB4
#define LED_5   PB5
     

#define BUTTON		PD5
#define BLINK_DELAY 100

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
	PORTB = PORTB & ~(1<<LED_1);
	//_delay_ms(BLINK_DELAY);
	PORTB = PORTB & ~(1<<LED_2);
	PORTB = PORTB & ~(1<<LED_3);
	PORTB = PORTB & ~(1<<LED_4);
	PORTB = PORTB & ~(1<<LED_5);
	_delay_ms(BLINK_DELAY);
	
	PORTD = PORTD |	(1<<BUTTON);
	
	
	int i;
	int go;
	go = 0;
	
	// Infinite loop
	while (1)
	{
		// Pause several milliseconds

		// WRITE YOUR CODE HERE
		if(!go && bit_is_set(PIND, 5))
		{
			go = 1;
			PORTB = PORTB | (1<<LED_1);
			_delay_ms(BLINK_DELAY);
		}
		
		if (go)
		{
			for (i = 1; i < 5; ++i)
			{
				PORTB  = (PORTB << 1) ;
				_delay_ms(BLINK_DELAY);
			}
			
			for (i = 1; i < 5; ++i)
			{
				PORTB  = (PORTB >> 1);
				_delay_ms(BLINK_DELAY);
			}
		}
				
		if(go && bit_is_set(PIND, 5))
		{
			go = 0;
			PORTB = PORTB & ~(1<<LED_1);
			_delay_ms(BLINK_DELAY);
			_delay_ms(BLINK_DELAY);
			_delay_ms(BLINK_DELAY);
		}
		
		
	}

	// Will never reach this
	return 0;
}
