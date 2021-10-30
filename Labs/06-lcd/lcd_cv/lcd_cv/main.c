/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Variables ---------------------------------------------------------*/
// Custom character definition using https://omerk.github.io/lcdchargen/
uint8_t customChar[16] = {
	0b00000,
	0b11111,
	0b00000,
	0b11111,
	0b00000,
	0b11111,
	0b00000,
	0b00000,
	0b00100,
	0b01010,
	0b10001,
	0b01010,
	0b00100,
	0b00100,
	0b01010,
	0b10001
};

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD display when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
	
	// Initialize LCD display
	lcd_init(LCD_DISP_ON);
	
	// Set pointer to beginning of CGRAM memory
	lcd_command(1 << LCD_CGRAM);
	for (uint8_t i = 0; i < 16; i++)
	{
		// Store all new chars to memory line by line
		lcd_data(customChar[i]);
	}
	// Set DDRAM address
	lcd_command(1 << LCD_DDRAM);
	
	// Display first custom character
	lcd_putc(1);

    // Put string(s) at LCD display
    
	lcd_gotoxy(1, 0);
	lcd_puts("00:00:0");
	
	lcd_gotoxy(11, 0);
    lcd_putc('a');
	lcd_gotoxy(1, 1);
	lcd_putc('b');
	lcd_gotoxy(11, 1);
	lcd_putc('c');
	
	
    // Configure 8-bit Timer/Counter2 for Stopwatch
	TIM2_overflow_16ms();
	TIM2_overflow_interrupt_enable();
    // Set the overflow prescaler to 16 ms and enable interrupt


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD display every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t number_of_overflows = 0;
	static uint8_t tenths = 0;
	static uint8_t secs = 0;
	char lcd_string[2] = "  ";
	
	char lcd_str_sqr[] = "0000";
	uint16_t sqr_sec;
	
    number_of_overflows++;
    if (number_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;
		
        // WRITE YOUR CODE HERE
		tenths++;
		if (tenths >= 10)
		{
			secs++;
			tenths = 0;
			
		}
		
		if (secs >= 60)
		{
			secs = 0;
		}
		sqr_sec = secs * secs;
		
		lcd_gotoxy(4, 0);
		itoa(secs, lcd_string, 10);     // Convert decimal value to string
		lcd_puts(lcd_string);
		
		lcd_gotoxy(7, 0);
		itoa(tenths, lcd_string, 10);
		lcd_puts(lcd_string);
		
		lcd_gotoxy(11, 0);
		itoa(sqr_sec, lcd_str_sqr, 10);
		lcd_puts(lcd_str_sqr);
		
    }
    // Else do nothing and exit the ISR
}
