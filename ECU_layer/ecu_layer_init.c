/* 
 * File:   ecu_layer_init.c
 * Author: Mr_Alsaied
 *
 * Created on 04 February, 2024, 07:47 PM
 */

#include "ecu_layer_init.h"

keypad_t keypad1 = {
    .keypad_rows_pin[0].port = PORTC_INDEX,
    .keypad_rows_pin[0].pin = GPIO_PIN0,
    .keypad_rows_pin[0].logic = GPIO_LOGIC_LOW,
    .keypad_rows_pin[0].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pin[1].port = PORTC_INDEX,
    .keypad_rows_pin[1].pin = GPIO_PIN1,
    .keypad_rows_pin[1].logic = GPIO_LOGIC_LOW,
    .keypad_rows_pin[1].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pin[2].port = PORTC_INDEX,
    .keypad_rows_pin[2].pin = GPIO_PIN2,
    .keypad_rows_pin[2].logic = GPIO_LOGIC_LOW,
    .keypad_rows_pin[2].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_rows_pin[3].port = PORTC_INDEX,
    .keypad_rows_pin[3].pin = GPIO_PIN3,
    .keypad_rows_pin[3].logic = GPIO_LOGIC_LOW,
    .keypad_rows_pin[3].direction = GPIO_DIRECTION_OUTPUT,
    .keypad_columns_pin[0].port = PORTC_INDEX,
    .keypad_columns_pin[0].pin = GPIO_PIN4,
    .keypad_columns_pin[0].logic = GPIO_LOGIC_LOW,
    .keypad_columns_pin[0].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pin[1].port = PORTC_INDEX,
    .keypad_columns_pin[1].pin = GPIO_PIN5,
    .keypad_columns_pin[1].logic = GPIO_LOGIC_LOW,
    .keypad_columns_pin[1].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pin[2].port = PORTC_INDEX,
    .keypad_columns_pin[2].pin = GPIO_PIN6,
    .keypad_columns_pin[2].logic = GPIO_LOGIC_LOW,
    .keypad_columns_pin[2].direction = GPIO_DIRECTION_INPUT,
    .keypad_columns_pin[3].port = PORTC_INDEX,
    .keypad_columns_pin[3].pin = GPIO_PIN7,
    .keypad_columns_pin[3].logic = GPIO_LOGIC_LOW,
    .keypad_columns_pin[3].direction = GPIO_DIRECTION_INPUT,
};


void ecu_layer_initailize()
{
    Std_ReturnType ret = E_NOT_OK;
   
}