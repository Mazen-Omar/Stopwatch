/* 
 * File:   hal_gpio.h
 * Author: Mr_Alsaied
 *
 * Created on November 15, 2023, 11:39 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/* Section : includes  */
//#include <pic18f4620.h>
#include <xc.h>
#include "../mcal_std_types.h"
#include "../../MCAL_layer/device_config.h"
#include "hal_gpio_cnfg.h"

/* Section : Macro Declaration */
#define BIT_MASK                             1
#define PORTC_MASK                          0xFF
#define PORT_PIN_MAX_NUMBER                  8
#define PORT_MAX_NUMBER                      5
#define GPIO_PIN_CONFIGRATION_MODE      CONFIG_ENABLE
#define GPIO_PORT_CONFIGRATION_MODE     CONFIG_ENABLE


/* Section : Macro Functions Declaration */
#define HWREG8(_x)                      (*(volatile uint8 *)(_x))
#define SET_BIT(REG ,BIT_POS)           (REG |=  (BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG ,BIT_POS)         (REG &= ~(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG ,BIT_POS)        (REG ^=  (BIT_MASK << BIT_POS))
#define READ_BIT(REG ,BIT_POS)          (REG  &  (BIT_MASK << BIT_POS))


/* Section : Data Types Declaration */
typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
}pin_index_t;

typedef enum
{
    GPIO_LOGIC_LOW = 0,
    GPIO_LOGIC_HIGH,
}logic_t;

typedef enum
{
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT,
}direction_t;

typedef enum 
{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}port_index_t;

typedef struct
{
    uint8 port : 3;         /* @ref port_index_t */ 
    uint8 pin : 3;          /* @ref pin_index_t */
    uint8 logic : 1;        /* @ref logic_t */
    uint8 direction : 1;    /* @ref direction_t */
}pin_config_t;

volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_registers[]  = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/* Section : Function Declaration */
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config , direction_t *dirc_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config , logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config , logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);

Std_ReturnType gpio_port_direction_initialize(port_index_t port , uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port , uint8 *direction);
Std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);




#endif	/* HAL_GPIO_H */

