# Lab 3: YOUR_FIRSTNAME FAMILYNAME

Link to your `Digital-electronics-2` GitHub repository:

   https://github.com/Samuelturak/Digital-Electronic-2


### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -128 to 127 | 8-bit integer |
| `uint16_t` | 16 | 0 to 65,535 | Unsigned 16-bit integer |
| `int16_t`  | 16 | -32768 to 32767 | 16-bit integer |
| `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0 | 0 | Won't return any value |

### Code

```c
#include <avr/io.h>

// Function declaration (prototype)
uint16_t calculate(uint8_t, uint8_t);

int main(void)
{
    uint8_t a = 156;
    uint8_t b = 14;
    uint16_t c;

    // Function call
    c = calculate(a, b);

    while (1)
    {
    }
    return 0;
}

// Function definition (body)
int calculate(uint8_t x, uint8_t y)
{
    uint16_t result;    // result = x^2 + 2xy + y^2

    result = x*x + 2xy + y*y;
   
    return result;
}
```
### GPIO library

1. In your words, describe the difference between the declaration and the definition of the function in C.
   * Function declaration: The function declaration specifies the name of the function, it's parameters and the type that is being returned from the function. It let's the compilar know, that there is a function to work with.
   * Function definition: The function definition defines what the function is supposed to do (the code of the function is there). It takes the input arguments from the function declaration, uses them in the code and specifies what is being returned. It is being used when the function gets called.

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c
     // Configure Push button at port D and enable internal pull-up resistor
	
    GPIO_config_input_pullup(&DDRD, BUTTON);
	
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        

        // WRITE YOUR CODE HERE

		if (GPIO_read(&PIND, 5))
		{		
			 GPIO_toggle(&PORTB, LED_GREEN);
			 GPIO_toggle(&PORTC, LED_WHITE);
			 _delay_ms(BLINK_DELAY);
		}
       
    }

    // Will never reach this
    return 0;
    }
```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure](Images/Traffic.png)