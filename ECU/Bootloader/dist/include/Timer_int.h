/*
 * Timer_int.h
 *
 *  Created on: May 6, 2020
 *      Author: Salma ahmed
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_



/*****************************************************************************/
/* Description 	: Initialization of timer 1									        */
/* input 		:void																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/
void Timer1_UEV_Interrupt(void);


/****************************************************************************/
/* Description 	: Generating PWM signal by using timer 1					*/
/* input 		:void														*/
/*output		:void														*/
/*scope			:															*/
/****************************************************************************/
void Timer1_Genetare_PWM(void);


/****************************************************************************/
/* Description 	: Start Timer Counting										*/
/* input 		:void														*/
/*output		:void														*/
/*scope			:															*/
/****************************************************************************/
void Timer1_vidStartCount(void);


#endif /* TIMER_INT_H_ */
