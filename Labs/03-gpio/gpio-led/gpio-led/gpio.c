/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"
#include "gpio.h"

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: GPIO_config_output()
 * Purpose:  Configure one output pin in Data Direction Register.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name | (1<<pin_num);
}

/**********************************************************************
 * Function: GPIO_config_input_nopull()
 **********************************************************************/

void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    reg_name++;								// Change pointer to Data Register
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Register
}

/**********************************************************************
 * Function: GPIO_config_input_pullup()
 * Purpose:  Configure one input pin and enable pull-up.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_config_input_no_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    reg_name++;								// Change pointer to Data Register
    *reg_name = *reg_name | (1<<pin_num);   // Data Register
}

/**********************************************************************
 * Function: GPIO_write_low()
 * Purpose:  Write one pin to a low value.
 * Input:    reg_name - Address of Port Register, such as &PORTB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);
}

/**********************************************************************
 * Function: GPIO_write_high()
 **********************************************************************/
void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name | (1<<pin_num);
}

/**********************************************************************
 * Function: GPIO_toggle()
 **********************************************************************/
void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num)
{   
    *reg_name = *reg_name ^ (1<<pin_num);
}

/**********************************************************************
 * Function: GPIO_read()
 **********************************************************************/

uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num)
{
    if ((*reg_name & (1<<pin_num)) == 0)
    {
        return(1);
    }
        else
    {
        return(0);
    }
    // next method, but include library
    //return (bit_is_set(*reg_name, pin_num));
    
}    

uint8_t GPIO_set0(volatile uint8_t *reg_name, uint8_t pin_num)
{
		return(0);
}
uint8_t GPIO_set1(volatile uint8_t *reg_name, uint8_t pin_num)
{
		return(1);
}