# Lab 7: Samuel Turák

Link to this file in your GitHub repository:

https://github.com/Samuelturak/Digital-Electronic-2

### Preperation Task

   1. The push buttons are connected to PC0[A0] PIN.

   2.

   ![Equation: Voltage divider](Images/eq_divider1.png)

   ![Equation: Voltage divider](Images/eq_divider2.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider3.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider4.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider5.png)

   &nbsp;

3. Calculate the voltage value if none of the push buttons is pressed.

   ![Equation: Voltage divider](Images/eq_divider6.png)

   &nbsp;


### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   |  |
   | Up     | 0.495&nbsp;V | 101 |  |
   | Down   |       |     |  |
   | Left   |       |     |  |
   | Select |       |     |  |
   | none   |       |     |  |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string

    // WRITE YOUR CODE HERE

}
```


### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![your figure]()

2. Flowchart figure for function `get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()