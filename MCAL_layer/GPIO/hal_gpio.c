/* 
 * File:   hal_gpio.c
 * Author: Mr_Alsaied
 *
 * Created on November 15, 2023, 11:10 PM
 */
#include "hal_gpio.h"


/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_NOT_OK;
    if(_pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(_pin_config);
        gpio_pin_write_logic(_pin_config ,GPIO_LOGIC_LOW);
        ret = E_NOT_OK;
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_OK;
    if(_pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT :
                CLEAR_BIT(*(tris_registers[_pin_config->port]) ,_pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                SET_BIT(*(tris_registers[_pin_config->port]) ,_pin_config->pin);
                break;
            default : 
                ret = E_NOT_OK;
        }
        ret = E_OK;
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config , direction_t *dirc_status)
{
    Std_ReturnType ret = E_OK;
    if(_pin_config == NULL || dirc_status == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dirc_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
        ret = E_OK;
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config , logic_t logic)
{
    Std_ReturnType ret = E_OK;
    if(_pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(logic)
        {
            case GPIO_LOGIC_LOW:
                CLEAR_BIT(*lat_registers[_pin_config->port] ,_pin_config->pin);
                break;
            case GPIO_LOGIC_HIGH:
                SET_BIT(*lat_registers[_pin_config->port] ,_pin_config->pin);
                break;
            default:    
                ret = E_NOT_OK;
        }   
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config , logic_t *logic)
{
    Std_ReturnType ret = E_OK;
    if(_pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1 || logic == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
        ret = E_OK;
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PIN_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_OK;
    if(_pin_config == NULL || _pin_config->pin > PORT_PIN_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {   
        TOGGLE_BIT(*lat_registers[_pin_config->port] , _pin_config->pin);
        ret = E_OK;
    }
    return ret;
    
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t port , uint8 direction)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *tris_registers[port] = direction;
        ret = E_OK;
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port , uint8 *direction)
{
    Std_ReturnType ret = E_OK;
    if(direction == NULL || port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction = *tris_registers[port];
    }
    return ret;
    
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port , uint8 logic)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_registers[port] = logic;
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port , uint8 *logic)
{
    Std_ReturnType ret = E_OK;
    if(logic == NULL || port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *lat_registers[port];
    }
    
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATION_MODE==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_registers[port] ^= PORTC_MASK;
    }
    
    return ret;
}
#endif