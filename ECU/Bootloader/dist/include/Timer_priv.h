/*
 * Timer_priv.h
 *
 *  Created on: May 6, 2020
 *      Author: Salma ahmed
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_



/***************Registers for timer 1 *************************/

#define TIM1_CR1		(*((volatile u32*)0x40012C00))
#define TIM1_CR2		(*((volatile u32*)0x40012C04))
#define TIM1_SMCR		(*((volatile u32*)0x40012C08))
#define TIM1_DIER		(*((volatile u32*)0x40012C0C))
#define TIM1_SR			(*((volatile u32*)0x40012C10))
#define TIM1_EGR		(*((volatile u32*)0x40012C14))
#define TIM1_CCMR1		(*((volatile u32*)0x40012C18))
#define TIM1_CCMR2		(*((volatile u32*)0x40012C1C))
#define TIM1_CCER		(*((volatile u32*)0x40012C20))
#define TIM1_CNT		(*((volatile u32*)0x40012C24))
#define TIM1_PSC		(*((volatile u32*)0x40012C28))
#define TIM1_ARR		(*((volatile u32*)0x40012C2C))
#define TIM1_RCR		(*((volatile u32*)0x40012C30))
#define TIM1_CCR1		(*((volatile u32*)0x40012C34))
#define TIM1_CCR2		(*((volatile u32*)0x40012C38))
#define TIM1_CCR3		(*((volatile u32*)0x40012C3C))
#define TIM1_CCR4		(*((volatile u32*)0x40012C40))
#define TIM1_BDTR		(*((volatile u32*)0x40012C44))
#define TIM1_DCR		(*((volatile u32*)0x40012C48))
#define TIM1_DMAR		(*((volatile u32*)0x40012C4C))


/***************Registers for timer 8 *************************/

#define TIM8_CR1		(*((volatile u32*)0x40013400))
#define TIM8_CR2		(*((volatile u32*)0x40013404))
#define TIM8_SMCR		(*((volatile u32*)0x40013408))
#define TIM8_DIER		(*((volatile u32*)0x4001340C))
#define TIM8_SR			(*((volatile u32*)0x40013410))
#define TIM8_EGR		(*((volatile u32*)0x40013414))
#define TIM8_CCMR1		(*((volatile u32*)0x40013418))
#define TIM8_CCMR2		(*((volatile u32*)0x4001341C))
#define TIM8_CCER		(*((volatile u32*)0x40013420))
#define TIM8_CNT		(*((volatile u32*)0x40013424))
#define TIM8_PSC		(*((volatile u32*)0x40013428))
#define TIM8_ARR		(*((volatile u32*)0x4001342C))
#define TIM8_RCR		(*((volatile u32*)0x40013430))
#define TIM8_CCR1		(*((volatile u32*)0x40013434))
#define TIM8_CCR2		(*((volatile u32*)0x40013438))
#define TIM8_CCR3		(*((volatile u32*)0x4001343C))
#define TIM8_CCR4		(*((volatile u32*)0x40013440))
#define TIM8_BDTR		(*((volatile u32*)0x40013444))
#define TIM8_DCR		(*((volatile u32*)0x40013448))
#define TIM8_DMAR		(*((volatile u32*)0x4001344C))


/**************************bits of CR1 register*************************/



#define TIMER_u8COUNTEREENABLE		0x00000001
#define TIMER_u8COUNTEREDISABLE 	0x00000000

#define TIMER_u8UEVENABLE			0x00000000
#define TIMER_u8UEVDISABLE			0x00000002

#define TIMER_u8UPCOUNT				0x00000010
#define TIMER_u8DOWNCOUNT			0x00000010

#define TIMER_u8PRELOADENABLE		0x00000080
#define TIMER_u8PRELOADDISABLE		0x00000000

#define TIMER_u8BIEENABLE		    0x00000080
#define TIMER_u8BIEDISABLE		    0x00000000
#define TIMER_u8TIEENABLE		    0x00000040
#define TIMER_u8TIEDISABLE		    0x00000000
#define TIMER_u8UIEENABLE		    0x00000001
#define TIMER_u8UIEDISABLE		    0x00000000


/*******************************CCMR1 register bits*****************************/
/******* OC1M *******/
#define FROZEN		        0X00000000
#define CH1_ACTIVE		    0X00000010
#define CH1_INACTIVE		0X00000020
#define TOGGLE		        0X00000030
#define FORCE_INACTIVE		0X00000040
#define FORCE_ACTIVE		0X00000050
#define PWM_MODE1_UP	    0X00000060
#define PWM_MODE2_UP	    0X00000070
/******* OC1PE *******/
#define PRELOAD_DISABLED	0X00000000
#define PRELOAD_ENABLED		0X00000008

/*******************************EGR register bits*****************************/
/******* UG *******/
#define NO_ACTION		0X00000000
#define INITIALIZE		0X00000001

/*******************************CCER register bits*****************************/
/******* CC1E *******/
#define OC1_ACTIVE		0X00000001
#define OC1_INTACTIVE	0X00000000

/*******************************BDTR register bits*****************************/
/******* MOE *******/
#define OC_ENABLE		0X00008000
#define OC_DISABLE  	0X00000000

/*******************************CCMR1 register bits*****************************/
#define CHANNEL1OUTPUT		0x00000003



#endif /* TIMER_PRIV_H_ */
