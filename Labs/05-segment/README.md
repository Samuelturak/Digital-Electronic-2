# Lab 5: Samuel Turák

Link to your `Digital-electronics-2` GitHub repository:

   https://github.com/Samuelturak/Digital-Electronic-2


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD: All cathode connections are connected to the ground. The segments are illuminated by the High state.
   * CA SSD: All anode connections are connected to logic "1". The segments are illuminated by a logic "0" signal.

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER1_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
	if (num0 < 9)
	{
		num0++;
	}
	else
	{
		num0 = 0;
		num1++;
		if (num1 > 5)
		{
			num1 = 0;
		}
	}
}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{	
	// WRITE YOUR CODE HERE
	uint8_t static pos = 0;
	if (pos == 0)
	{
		SEG_update_shift_regs(num0, pos);
		pos++;
	}
	else
	{
		SEG_update_shift_regs(num1, pos);
		pos--;
	}
}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](Images/FLOWCHART.png)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure](Images/Kitchenalarm.PNG)