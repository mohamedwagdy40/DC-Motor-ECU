/*
 * pwm.c
 *
 *  Created on: Sep 22, 2020
 *      Author: Mohamed Wagdy
 */

#include "pwm.h"

void PWM_timer0_init(uint8 clock){
	TCNT0 = 0;
	SET_BIT(DDRB,PB3);
	TCCR0 = 0;
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#ifdef NON_INVERTING_MODE
	SET_BIT(TCCR0,COM01);
#else
	SETBIT(TCCR0,COM00);
	SETBIT(TCCR0,COM01);
#endif
	TCCR0 |= (TCCR0 & (0xF8))|(clock  & (0x07)) ;       //pre-scaler insert in LS 3 bits in TCCR0 register
}

void PWM_timer0_setDutyCycle(uint8 dutyCycle){
	OCR0 = dutyCycle;
}

void PWM_timer0_deinit(void){
	TCNT0 = 0;
	TCCR0 = 0;
	CLEAR_BIT(DDRB,PB3);
}
