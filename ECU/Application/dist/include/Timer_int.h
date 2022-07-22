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


/*****************************************************************************/
/* Description 	: Timer 1_PWM Configuration								*/
/* input 		:void																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/
void Timer1_Genetare_PWM_config(void);


/*****************************************************************************/
/* Description 	:choose duty cycle of PWM signal channel 1								*/
/* input 		:u32																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/
void Timer1_Channel1_Genetare_PWM(u32 CCR1);




/*****************************************************************************/
/* Description 	:choose duty cycle of PWM signal channel 2									*/
/* input 		:u32																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/
void Timer1_Channel2_Genetare_PWM(u32 CCR2);



#endif /* TIMER_INT_H_ */
