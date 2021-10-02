# Preperation Task

## 1. Draw two basic ways to connect a LED to the output pin of the microcontroller: LED active-low, LED active-high.

![alt text](Images/Pic4.jpg)

## 2. Calculate LED resistor value for typical red and blue LEDs.
 
![alt text](Images/Pic9.png)


![alt text](Images/Pic1.png)


![alt text](Images/Pic2.png)

## 3. Draw the basic ways to connect a push button to the microcontroller input pin: button active-low, button active-high.

### Table
LED color | Supply voltage | LED current | LED current | Resistor value
------------ | -------------| -------------| -------------| ------------- |
red | 5V | 20 mA | 2V | 150 Ω | 
blue | 5V | 20 mA | 4V | 50 Ω | 



![alt text](Images/Pic5.jpg)

# Part 2

DDRB | Description
------------ | -------------
0 | Input pin
1 | Content in the second column



# Lab 2: Samuel Turák

Link to your `Digital-electronics-2` GitHub repository:

https://github.com/Samuelturak/Digital-Electronic-2



### Active-low and active-high LEDs

1. Complete tables according to the AVR manual.

| **DDRB** | **Description** |
| :-: | :-- |
| 0 | Input pin |
| 1 | Output pin |

| **PORTB** | **Description** |
| :-: | :-- |
| 0 | Output low value |
| 1 | Pull-up |

| **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
| :-: | :-: | :-: | :-: | :-- |
| 0 | 0 | input | no | Tri-state, high-impedance |
| 0 | 1 | input | yes | PORTB will source current |
| 1 | 0 | output | no | Output Low (Sink) |
| 1 | 1 | output | no | Output High (Source) |

2. Part of the C code listing with syntax highlighting, which blinks alternately with a pair of LEDs; let one LED is connected to port B and the other to port C:

```c
int main(void)
{
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    DDRB = DDRB | (1<<LED_GREEN);
    
    // ...and turn LED off in Data Register
    PORTB = PORTB & ~(1<<LED_GREEN);
    

    // Configure the second LED at port C
    DDRC = DDRC | (1<<LED_WHITE);
    
    // ...and turn LED off in Data Register
    
    PORTC = PORTC & ~(1<<LED_WHITE);
    

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        
        PORTB = PORTB ^ (1<<LED_GREEN);
	_delay_ms(BLINK_DELAY);
        PORTC = PORTC ^ (1<<LED_WHITE);
        
        // WRITE YOUR CODE HERE
    }

    // Will never reach this
    return 0;
}
```


### Push button

1. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Let the push button is connected to port D:

```c
 // Configure Push button at port D and enable internal pull-up resistor
	
    DDRD = DDRD & ~(1<<BUTTON);
	
	PORTD = PORTD |	(1<<BUTTON); 

    
	PORTC = PORTC | (1<<LED_WHITE); // Turning one LED on
	
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds

        // WRITE YOUR CODE HERE
        
        if (bit_is_clear(PIND, 5))
        {
            PORTB = PORTB ^ (1<<LED_GREEN);
            PORTC = PORTC ^ (1<<LED_WHITE);
	    _delay_ms(BLINK_DELAY);
        }
        
    }

    // Will never reach this
    return 0;
}
```


### Knight Rider

1. Scheme of Knight Rider application, i.e. connection of AVR device, five LEDs, resistors, one push button, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure](Images/KnightRider.PNG)