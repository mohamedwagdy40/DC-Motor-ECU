/*
 * mini_project.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Mohamed Wagdy
 */


#include "lcd.h"
#include "adc.h"
#include "pwm.h"
#include "interrupt.h"

void convert_motorRound(void){
	/*Toggle pin PB0*/
	TOGGLE_BIT(PORTB,PB0);
	/*toggle pin PB1*/
	TOGGLE_BIT(PORTB,PB1);

}

int main()
{
	/*res_value variable to hold digital converted value*/
	uint16 res_value;
	/*initialize LCD*/
	LCD_init();
	/*structure holds configuration for ADC*/
	ADC_configType adc_config={Intenal256v,FCPU_16};
	/*initialize ADC*/
	ADC_init(&adc_config);
	LCD_clearScreen(); /* clear LCD at the beginning */
	/* display this string "ADC Value = " only once at LCD */
	LCD_displayString("ADC Value = ");
	/*initialize PWM with frequency FCPU/1024*/
	PWM_timer0_init(FCPU1024);
	/*make PB0 and PB1 output pins*/
	SET_BIT(DDRB,PB0);
	SET_BIT(DDRB,PB1);
	/*logic HIGH on pin PB0*/
	SET_BIT(PORTB,PB0);
	/*logic LOW on pin PB1*/
	CLEAR_BIT(PORTB,PB1);
	/*initialize Interrupt 0 */
	Interrupt_init(INT_0);
	/*set interrupt 0 in rising edge mode*/
	INT0_setEdge(rising);
	/*set call back for interrupt0*/
	INT0_setCallBack(convert_motorRound);

	while(1)
	{
		LCD_goToRowColumn(0,12); /* display the number every time at this position */
		res_value = ADC_readChannel(PA_0); /* read channel zero where the potentiometer is connect */
		LCD_intgerToString(res_value); /* display the ADC value on LCD screen */
		/*send the digital value converted by ADC from potentiometer to PWM DutyCylce to control the motor from the potentiometer*/
		PWM_timer0_setDutyCycle(res_value/4);
	}
}
