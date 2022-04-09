/*
 * adc.c
 *
 *  Created on: Sep 20, 2020
 *      Author: Mohamed Wagdy
 */

#include "adc.h"



void ADC_init(ADC_configType* ptr_configType)
{
	ADMUX = 0;                                                             //reset the ADMUX register
	ADMUX |= (ADMUX & (0x3F))|( (ptr_configType->volt<<6) & (0xC0)) ;      //insert the volt value in MS 2 bits in ADMUX register
	//note: ADMUX = make the rest of bits are zeros

	ADCSRA = (1<<ADEN);                                                   //enable ADC

	ADCSRA |= (ADCSRA & (0xF8))|( ptr_configType->clock & (0x07)) ;       //pre-scaler insert in LS 3 bits in ADCSRA register
}

uint16 ADC_readChannel(ADC_Pin pin)
{
	CLEAR_BIT(DDRA,pin);                                                 //make the passed pin as input pin
	ADMUX |= (ADMUX & (0xE0))|( pin & (0xF1)) ;                           //insert LS 5 bits in ADMUX register

	SET_BIT(ADCSRA,ADSC);                                               //start conversion

	while(BIT_IS_CLEAR(ADCSRA,ADIF));                                  //polling until conversion is done

	SET_BIT(ADCSRA,ADIF);                                             //clear the flag by write 1 on it

	return ADC;
}

void ADC_deinit(void){
	ADMUX = 0;
	ADCSRA = 0;
	ADC = 0;
}
