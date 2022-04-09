/*
 * pwm.h
 *
 *  Created on: Sep 22, 2020
 *      Author: Mohamed Wagdy
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"


#define NON_INVERTING_MODE


typedef enum{
	NOCLOCK,NOPRESCALING,FCPU8,FCPU64,FCPU256,FCPU1024,EXTERNALCLOCKFALINGEDGE,EXTERNALCLOCKRISINGEDGE
}PWM_Clock;
/*********************************************prototypes for timer 0*****************************************************************/
void PWM_timer0_init(uint8 clock);
void PWM_timer0_setDutyCycle(uint8 dutyCycle);
void PWM_timer0_deinit(void);



#endif /* PWM_H_ */
