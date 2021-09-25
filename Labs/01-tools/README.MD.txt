# Part 4

# Experiments on your own

```C

/***********************************************************************
 * 
 * Blink a LED and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
/* The preprocessor will process directives that are inserted into the C
 * source code. These directives allow additional actions to be taken on
 * the C source code before it is compiled into object code. Directives
 * are not part of the C language itself.
 *
 * Preprocessor directives begin with a pound (#) symbol and may have 
 * several arguments. Do NOT put a semicolon character at the end of 
 * directives. This is a common mistake.
 */
#define LED_GREEN   PB5 // AVR pin where green LED is connected
// Delay in milliseconds
#define DOT_DELAY 250		// . blink time
#define DASH_DELAY 500		// - blink time
#define PAUSE_DELAY 250		// time between 2 symbols 
#define LETTER_DELAY 1000	// time between 2 letters
#define WORD_DELAY 2000		// time between 2 words (at the end) 


#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

/* Includes ----------------------------------------------------------*/
/* Include another C language file into the current file at the location
 * of the #include statement prior to compiling the source code.
 */
#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/


int info[] = {DASH_DELAY,DOT_DELAY,DOT_DELAY,LETTER_DELAY,DOT_DELAY,LETTER_DELAY,DOT_DELAY,DOT_DELAY,DASH_DELAY,DASH_DELAY,DASH_DELAY,WORD_DELAY};
int i;

int main(void)
{
	
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);
    PORTB = PORTB | (1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
		
		for (i = 0; i < 12; ++i)
		{
			switch (info[i])
			{
				case DASH_DELAY:
				_delay_ms(DASH_DELAY);
				 PORTB = PORTB ^ (1<<LED_GREEN);
				 _delay_ms(PAUSE_DELAY);
				break;
				
				case DOT_DELAY:
				_delay_ms(DOT_DELAY);
				 PORTB = PORTB ^ (1<<LED_GREEN);
				 _delay_ms(PAUSE_DELAY);
				break;
				
				case LETTER_DELAY:
				 PORTB = PORTB ^ (1<<LED_GREEN);
				_delay_ms(LETTER_DELAY);
				break;
				
				case WORD_DELAY:
				 PORTB = PORTB ^ (1<<LED_GREEN);
				_delay_ms(WORD_DELAY);
				break;
				
				default:
				;
			}
			
			 PORTB = PORTB ^ (1<<LED_GREEN);
		} 
		
		
        //// Longer method :
		//
		//_delay_ms(DASH_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DOT_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DOT_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(LETTER_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DOT_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(LETTER_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DOT_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DOT_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DASH_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DASH_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(PAUSE_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(DASH_DELAY);
		//
		//PORTB = PORTB ^ (1<<LED_GREEN);
		//_delay_ms(WORD_DELAY);
		
    }

    // Will never reach this
    return 0;
}

