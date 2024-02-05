/* 
 * File:   keypad.c
 * Author: Mr_Alsaied
 *
 * Created on 04 February, 2024, 05:35 PM
 */

#include "keypad.h"

static const uint8 keypad_values[KEYPAD_ROWS_NUMBER][KEYPAD_COLUMNS_NUMBER] = {
    {'7' , '8' , '9' , '/'},
    {'4' , '5' , '6' , '*'},
    {'1' , '2' , '3' , '-'},
    {'#' , '0' , '=' , '+'}
};


/**
 * 
 * @param kpd
 * @return 
 */
Std_ReturnType keypad_initialize(const keypad_t* kpd)
{
    Std_ReturnType ret = E_OK;
    uint8 i;
    if(kpd == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(i = 0; i < KEYPAD_ROWS_NUMBER; i++)
        {
            ret = gpio_pin_initialize(&(kpd->keypad_rows_pin[i]));
        }
        
        for(i = 0; i < KEYPAD_COLUMNS_NUMBER; i++)
        {
            ret = gpio_pin_initialize(&(kpd->keypad_columns_pin[i]));           
        }
        
        ret = E_OK;
    }
    return ret;
}

/**
 * 
 * @param kpd
 * @param value
 * @return 
 */
Std_ReturnType keypad_get_value(const keypad_t* kpd, uint8* value)
{
    Std_ReturnType ret = E_OK;
    uint8 i ,j;
    logic_t column_logic = GPIO_LOGIC_LOW;
    if(kpd == NULL || value == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = 0;
        for(i = 0; i < KEYPAD_ROWS_NUMBER; i++)
        {
            for(j = 0; j < KEYPAD_ROWS_NUMBER; j++)
            {
                gpio_pin_write_logic(&(kpd->keypad_rows_pin[j]), GPIO_LOGIC_LOW);
            }
            gpio_pin_write_logic(&(kpd->keypad_rows_pin[i]), GPIO_LOGIC_HIGH);
            for(j = 0; j < KEYPAD_COLUMNS_NUMBER; j++)
            {
                
                ret = gpio_pin_read_logic(&(kpd->keypad_columns_pin[j]), &column_logic);
                
                if(column_logic == GPIO_LOGIC_HIGH)
                {
                    *value = keypad_values[i][j];
                    break;
                }
                
            }
        }
        
        ret = E_OK;
    }
    return ret;
    
}
