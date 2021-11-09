# Lab 7: Samuel Turák

Link to this file in your GitHub repository:

https://github.com/Samuelturak/Digital-Electronic-2

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 101 |
   | Down   | 1.2&nbsp;V    |  246   | 245 |
   | Left   | 1.97&nbsp;V    |  403   | 402 |
   | Select | 3.18&nbsp;V    |   651  | 650 |
   | none   | 5&nbsp;V   |  1023   | 1022 |


2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
  uint16_t value = 0;
  char lcd_string[] = "0000";

  lcd_gotoxy(8, 0);
  lcd_puts("    ");
  value = ADC;                  // Copy ADC result to 16-bit variable
  itoa(value, lcd_string, 10);  // Convert decimal value to string
  lcd_gotoxy(8, 0);
  lcd_puts(lcd_string);
  
  lcd_gotoxy(13, 0);
  lcd_puts("    ");
  itoa(value, lcd_string, 16);  // Convert decimal value to string
  lcd_gotoxy(13, 0);
  lcd_puts(lcd_string);
  
  // WRITE YOUR CODE HERE
  uart_puts(lcd_string);
  uart_puts("r\n");
  uart_putc('\n');
  uart_putc('\r');
  
}
```


### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![your figure](Images/UART_signal.jpg)

2. Flowchart figure for function `get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](Images/FlowChart)


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.
   
   ![your figure](Images/Scheme.png)