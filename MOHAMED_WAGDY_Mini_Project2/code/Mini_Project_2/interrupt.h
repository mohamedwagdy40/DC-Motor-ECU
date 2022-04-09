/*
 * interrupt.h
 *
 *  Created on: Sep 23, 2020
 *      Author: medo_
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

/**********************************************user defined variables*********************************************************/
typedef enum{
	INT_1,INT_0,INT_2
}INTNumber;

typedef enum{
	falling=2,rising=3
}Int_edge;

/*********************************************prototypes for Interrupt 0*****************************************************************/
void Interrupt_init(INTNumber number);
void INT0_setEdge(Int_edge edge);
void INT1_setEdge(Int_edge edge);
void INT2_setEdge(Int_edge edge);
void INT0_setCallBack(void(*a_ptr)(void));
void INT0_deinit(void);


#endif /* INTERRUPT_H_ */
