/*
 * interrupt.c
 *
 *  Created on: Sep 23, 2020
 *      Author: medo_
 */


#include "interrupt.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(INT0_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}

}

void Interrupt_init(INTNumber number){
	SET_BIT(SREG,7);                                          /* set the global interrupt bit by 1*/
	GICR = (GICR & (0x2F))|( (number << 6) & (0xE0)) ;      /*insert the volt value in MS 3 bits in GICR register*/
	CLEAR_BIT(DDRD,PD2);                                     /*set PD2 as input pin*/
}

void INT0_setEdge(Int_edge edge){
	MCUCR = (MCUCR & (0xFC))|(edge  & (0x03)) ;       /*edge insert in LS 2 bits in MCUCR register*/
}

void INT1_setEdge(Int_edge edge){
	MCUCR |= (MCUCR & (0xFC))|( (edge<<2)  & (0x03)) ;       /*edge insert in bit2,3 in MCUCR register*/
}


void INT2_setEdge(Int_edge edge){
	MCUCSR |= (MCUCSR & (0xBF))|( (edge-2)<<6  & (0x40)) ;       /*edge insert in bit6 in MCUCSR register*/
}


void INT0_setCallBack(void(*a_ptr)(void)){
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}
