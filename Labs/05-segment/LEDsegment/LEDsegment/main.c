/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "segment.h"        // Seven-segment display library for AVR-GCC
int num2 = 0;
int num3 = 0;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display decimal counter values on SSD (Seven-segment 
 *           display) when 16-bit Timer/Counter1 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Configure SSD signals
    SEG_init();

    // Test of SSD: display number '3' at position 0
    //SEG_update_shift_regs(5, 1);
    

    // Configure 16-bit Timer/Counter1 for Decimal counter
    // Set the overflow prescaler to 262 ms and enable interrupt
	 TIM1_overflow_262ms();
	 TIM0_overflow_4ms();
	 TIM1_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
	sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
		//TIM1_overflow_262ms();
		//TIM1_overflow_4ms();
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment decimal counter value and display it on SSD.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
	static volatile num0 = 0;
	static volatile num1 = 0;
	//SEG_update_shift_regs(num0, 0);
	num0++;
	if (num0 > 9)
	{
		num0 = 0;
		num1++;
		
		if (num1 > 6);
		{
			num1 = 0;
		}
	}
}

ISR(TIMER0_OVF_vect)
{	
	// WRITE YOUR CODE HERE
	static pos = 0;
	volatile num0;
	volatile num1;
	if (pos == 0)
	{
		SEG_update_shift_regs(num0, pos);
	}
	else
	{
		SEG_update_shift_regs(num1, pos);
	}
	pos ++;
	if (pos > 1)
	{
		pos = 0;
	}
}