/* 
 * File:   application.c
 * Author: Mazen Omar
 * Created on February, 2024, 11:10 PM
 */

#include "application.h"


/*------------------------ Hardware initialization ------------------------*/
Button_t start =
{
    .button.port = PORTC_INDEX,
    .button.pin = GPIO_PIN4,
    .button.direction = GPIO_DIRECTION_INPUT,
    .button.logic = GPIO_LOW,
    .active = BUTTON_ACTIVE_HIGH,
    .state = BUTTON_RELEASED,
};
Button_t stop =
{
    .button.port = PORTD_INDEX,
    .button.pin = GPIO_PIN6,
    .button.direction = GPIO_DIRECTION_INPUT,
    .button.logic = GPIO_LOW,
    .active = BUTTON_ACTIVE_HIGH,
    .state = BUTTON_RELEASED,
};

Button_t speed_up = 
{
    .button.port = PORTC_INDEX,
    .button.pin = GPIO_PIN5,
    .button.direction = GPIO_DIRECTION_INPUT,
    .button.logic = GPIO_LOW,
    .active = BUTTON_ACTIVE_HIGH,
    .state = BUTTON_RELEASED,
    
};

Button_t pause = 
{
    .button.port = PORTC_INDEX,
    .button.pin = GPIO_PIN6,
    .button.direction = GPIO_DIRECTION_INPUT,
    .button.logic = GPIO_LOW,
    .active = BUTTON_ACTIVE_HIGH,
    .state = BUTTON_RELEASED,
    
};

Button_t reset = 
{
    .button.port = PORTC_INDEX,
    .button.pin = GPIO_PIN7,
    .button.direction = GPIO_DIRECTION_INPUT,
    .button.logic = GPIO_LOW,
    .active = BUTTON_ACTIVE_HIGH,
    .state = BUTTON_RELEASED,
};

segment_t seg = 
{
  .segment_pin[0].port = PORTC_INDEX,
  .segment_pin[0].pin = GPIO_PIN0,
  .segment_pin[0].direction = GPIO_DIRECTION_OUTPUT,
  .segment_pin[0].logic = GPIO_LOW,
  .segment_pin[1].port = PORTC_INDEX,
  .segment_pin[1].pin = GPIO_PIN1,
  .segment_pin[1].direction = GPIO_DIRECTION_OUTPUT,
  .segment_pin[1].logic = GPIO_LOW,
  .segment_pin[2].port = PORTC_INDEX,
  .segment_pin[2].pin = GPIO_PIN2,
  .segment_pin[2].direction = GPIO_DIRECTION_OUTPUT,
  .segment_pin[2].logic = GPIO_LOW,
  .segment_pin[3].port = PORTC_INDEX,
  .segment_pin[3].pin = GPIO_PIN3,
  .segment_pin[3].direction = GPIO_DIRECTION_OUTPUT,
  .segment_pin[3].logic = GPIO_LOW,
  .segment_type = SEGMENT_COMMON_ANODE,
};

pin_config_t control_1 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN0,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

pin_config_t control_2 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN1,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

pin_config_t control_3 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN2,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

pin_config_t control_4 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN3,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

pin_config_t control_5 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN4,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

pin_config_t control_6 = 
{
    .port = PORTD_INDEX,
    .pin = GPIO_PIN5,
    .direction = GPIO_DIRECTION_OUTPUT,
    .logic = GPIO_LOW,
};

/*------------------------ Global variables ------------------------*/
Std_ReturnType ret;
Button_state_t start_state = BUTTON_RELEASED; 
Button_state_t stop_state =  BUTTON_RELEASED; 
Button_state_t reset_state = BUTTON_RELEASED; 
Button_state_t pause_state = BUTTON_RELEASED; 
Button_state_t speed_state = BUTTON_RELEASED; 
uint8 seconds = 0, minutes = 0, hours = 0;

/*------------------------ Function declaration ------------------------*/
void application_initialize();
void close(void);
void open(void);


int main() 
{
    application_initialize();
    uint8 counter;
    uint8 start_flag = 0;
    uint8 delay_time = 35;
    while(1)
    {
       ret = Button_read(&start, &start_state);
       if(start_state == BUTTON_PRESSED)
       {
           start_flag = 1;
       }
       if(start_flag == 1)
        {
            for(counter = 0; counter <= delay_time; counter++)
            {
                
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_1, GPIO_HIGH);
                ret = segment_write_number(&seg, hours/10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_1, GPIO_LOW);
            
                ret = gpio_pin_write_logic(&control_2, GPIO_HIGH);
                ret = segment_write_number(&seg, hours%10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_2, GPIO_LOW);
            
                ret = gpio_pin_write_logic(&control_3, GPIO_HIGH);
                ret = segment_write_number(&seg, minutes/10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_3, GPIO_LOW);
            
                ret = gpio_pin_write_logic(&control_4, GPIO_HIGH);
                ret = segment_write_number(&seg, minutes%10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_4, GPIO_LOW);
            
                ret = gpio_pin_write_logic(&control_5, GPIO_HIGH);
                ret = segment_write_number(&seg, seconds/10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_5, GPIO_LOW);
            
                ret = gpio_pin_write_logic(&control_6, GPIO_HIGH);
                ret = segment_write_number(&seg, seconds%10);
                __delay_us(3333);
                ret = gpio_pin_write_logic(&control_6, GPIO_LOW);
                
                            /* speed up button */
                ret = Button_read(&speed_up, &speed_state); 
                if(speed_state == BUTTON_PRESSED)
                {
                    delay_time = 5;
                }
                else if(speed_state == BUTTON_RELEASED)
                {
                    delay_time = 35;
                }
                
                            /* pause button */
                ret = Button_read(&pause, &pause_state);
                if(pause_state == BUTTON_PRESSED)
                {
                         pause();  
                        if(start_state == BUTTON_PRESSED || reset_state == BUTTON_PRESSED)
                        {
                            break;
                        }
                    }
                }
                
                            /* stop button */
                ret = Button_read(&stop, &stop_state);
                if(stop_state == BUTTON_PRESSED)
                {
                        close();
                        ret = Button_read(&start, &start_state);
                        if(start_state == BUTTON_PRESSED)
                        {
                            break;
                        }
                    }
                }
                
                            /* reset button */
                ret = Button_read(&reset, &reset_state);
                if(reset_state == BUTTON_PRESSED)
                {
                    hours = 0;
                    minutes = 0;
                    seconds = 0;
                }
            }
 
            seconds++;
            if(seconds == 60)
            {
                minutes++;
                seconds = 0;
            }
            if(minutes == 60)
            {
                hours++;
                minutes = 0;
            }
            if(hours > 99)
            {
                hours = 0;
            }

        }
    }
    
    return (EXIT_SUCCESS);
}

void application_initialize()
{
    Std_ReturnType ret;
    /* Initialization of control pins */
    ret = gpio_pin_initialize(&control_1);
    ret = gpio_pin_initialize(&control_2);
    ret = gpio_pin_initialize(&control_3);
    ret = gpio_pin_initialize(&control_4);
    ret = gpio_pin_initialize(&control_5);
    ret = gpio_pin_initialize(&control_6);
    
    /* Initialization of 7-segment */
    ret = segment_inititalize(&seg);
    
    /* Initialization of  buttons */
    ret = Button_initialize(&start);
    ret = Button_initialize(&stop);
    ret = Button_initialize(&pause);
    ret = Button_initialize(&speed_up);
    ret = Button_initialize(&reset);    
}
    
void pause(void)
{
     while(1)
    {
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_1, GPIO_HIGH);
        ret = segment_write_number(&seg, hours/10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_1, GPIO_LOW);

        ret = gpio_pin_write_logic(&control_2, GPIO_HIGH);
        ret = segment_write_number(&seg, hours%10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_2, GPIO_LOW);

        ret = gpio_pin_write_logic(&control_3, GPIO_HIGH);
        ret = segment_write_number(&seg, minutes/10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_3, GPIO_LOW);

        ret = gpio_pin_write_logic(&control_4, GPIO_HIGH);
        ret = segment_write_number(&seg, minutes%10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_4, GPIO_LOW);

        ret = gpio_pin_write_logic(&control_5, GPIO_HIGH);
        ret = segment_write_number(&seg, seconds/10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_5, GPIO_LOW);

        ret = gpio_pin_write_logic(&control_6, GPIO_HIGH);
        ret = segment_write_number(&seg, seconds%10);
        __delay_us(3333);
        ret = gpio_pin_write_logic(&control_6, GPIO_LOW);

        ret = Button_read(&start, &start_state);
        ret = Button_read(&reset, &reset_state);
    }
}


void close(void)
{
     while(1)
     {
        ret = gpio_pin_write_logic(&control_1, GPIO_LOW);   
        ret = gpio_pin_write_logic(&control_2, GPIO_LOW);   
        ret = gpio_pin_write_logic(&control_3, GPIO_LOW);   
        ret = gpio_pin_write_logic(&control_4, GPIO_LOW);   
        ret = gpio_pin_write_logic(&control_5, GPIO_LOW);   
        ret = gpio_pin_write_logic(&control_6, GPIO_LOW);   
        hours = 0;
        minutes = 0;
        seconds = 0;
      }
}
