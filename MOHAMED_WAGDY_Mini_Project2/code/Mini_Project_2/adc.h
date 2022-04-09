/*
 * adc.h
 *
 *  Created on: Sep 20, 2020
 *      Author: Mohamed Wagdy
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/**********************************************user defined variables*********************************************************/
typedef enum {
	Aref,Avcc,Intenal256v=4
}ADC_Ref;

typedef enum{

	PA_0,PA_1,PA_2,PA_3,PA_4,PA_5,PA_6,PA_7
}ADC_Pin;

typedef enum{
	FCPU_2=1,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Clock;

typedef struct{
	ADC_Ref volt;
	ADC_Clock clock;
}ADC_configType;


/**********************************************prototypes*********************************************************/

void ADC_init(ADC_configType* ptr_configType);
uint16 ADC_readChannel(ADC_Pin pin);
void ADC_deinit(void);

#endif /* ADC_H_ */
