/* 
 * File:   application.h
 * Author: Mr_Alsaied
 *
 * Created on November 16, 2023, 12:24 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : includes  */
#include "ECU_layer/LED/ecu_led.h"
#include "ECU_layer/Button/Button.h"
#include "ECU_layer/Relay/Relay.h"
#include "ECU_layer/DC_motor/DC_motor.h"
#include "ECU_layer/7_segment/segment.h"
#include "ECU_layer/Keypad/keypad.h"

/* Section : Macro Declaration */
#define _LATC (HWREG8(0xF8B))
#define _TRISC (HWREG8(0xF94))
#define LATC_ADDR (0xF8B)


/* Section : Macro Functions Declaration */
#define HWREG8_ADDR(_x) ((volatile uint8_t *)(_x))
#define SET_BIT_BY_ADDR(REG ,POS) (*REG |= (1<<POS))
#define CLEAR_BIT_BY_ADDR(REG,POS) (*REG &= ~(1<<POS))
#define TOGGLE_BIT_BY_ADDR(REG,POS) (*REG ^= (1<<POS))

/* Section : Data Types Declaration */
extern keypad_t keypad1;

/* Section : Function Declaration */
void application_initialize();


#endif	/* APPLICATION_H */

