/*
 * Timer_cfg.h
 *
 *  Created on: May 6, 2020
 *      Author: Salma ahmed
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


/*******************************CR1 register bits*****************************/

#define CEN			TIMER_u8COUNTEREENABLE
#define UDIS		TIMER_u8UEVENABLE
#define DIR			TIMER_u8UPCOUNT
#define ARPE		TIMER_u8PRELOADENABLE


/*******************************DIER register bits*****************************/
#define BIE		    TIMER_u8BIEENABLE
#define TIE		    TIMER_u8TIEENABLE
#define UIE		    TIMER_u8UIEENABLE

/*******************************PSC register bits*****************************/
#define PSCVALUE		    71

/*******************************ARR register bits*****************************/
#define ARRVALUE		    1000

/*******************************CCR1 register bits*****************************/
#define CCR1VALUE		    800

/*******************************CCMR1 register bits*****************************/
#define OC1M		        PWM_MODE1_UP
#define OC1PE		        PRELOAD_ENABLED
#define CC1S				CHANNEL1OUTPUT

/*******************************EGR register bits*****************************/
#define UG		             INITIALIZE

/*******************************CCER register bits*****************************/
#define CC1E		         OC1_ACTIVE

/*******************************BDTR register bits*****************************/
#define MOE		              OC_ENABLE

#endif /* TIMER_CFG_H_ */
