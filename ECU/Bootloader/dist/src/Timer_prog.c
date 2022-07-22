/*
 * Timer_prog.c

 *
 *  Created on: May 6, 2020
 *      Author: Salma ahmed
 */
#include "STD_Types.h"
#include "RCC_int.h"
#include"AFIO_register.h"
#include "Timer_priv.h"
#include "Timer_int.h"
#include "Timer_cfg.h"


u32 x = 0;

/****************************************************************************/
/* Description 	: Initialization of timer 1									*/
/* input 		:void														*/
/*output		:void														*/
/*scope			:															*/
/****************************************************************************/
void Timer1_UEV_Interrupt (void)

{
	//TIM1_CR1 |= (CEN | UDIS | DIR | ARPE );			// counter enable /UEV enable/ direction / preload or not
	TIM1_CR1 &= ~(DIR);
	TIM1_PSC = (u32)0;
	TIM1_ARR = (u32)72000;
	TIM1_DIER |= UIE;
}


/****************************************************************************/
/* Description 	: Generating PWM signal by using timer 1					*/
/* input 		:void														*/
/*output		:void														*/
/*scope			:															*/
/****************************************************************************/
void Timer1_Genetare_PWM(void)
{

	RCC_vidEnablePeripheral(RCC_u8TIM1CLK);
	TIM1_CR1 &= ~(DIR);
	TIM1_CR1 |= ARPE;

	TIM1_PSC = PSCVALUE;

	/* SET THE PERIOD OF THE PWM*/
	TIM1_ARR = ARRVALUE;

	/* SET THE VALUE OF THE DUTY CYCLE THE PWM*/
	TIM1_CCR1 = CCR1VALUE;

	/* SET PWM MODE (CHOOSE PWM MODE 1)*/
	TIM1_CCMR1 |= OC1M;

	/*ENABLE OUTPUT COMPARE1 PRELOAD */
	TIM1_CCMR1 |= OC1PE;

	/* INITIALIAZE ALL THE REGISTERS */
	TIM1_EGR |= UG;

	/* ENABLE COMPARE1 OUTPUT*/
	TIM1_CCER |= CC1E;

	/* MAIN OUTPUT ENABLE*/
	TIM1_BDTR |= MOE;

	/* CONFIGURE CHANNEL 1 OUTPUT */
	TIM1_CCMR1 &= ~(CHANNEL1OUTPUT);

	TIM1_CR1 |= CEN;
}


/****************************************************************************/
/* Description 	: Start Timer Counting										*/
/* input 		:void														*/
/*output		:void														*/
/*scope			:															*/
/****************************************************************************/
void Timer1_vidStartCount(void)
{
	TIM1_CR1 |= CEN;
}


void TIM1_UP_IRQHandler(void)
{
	TIM1_SR &= 0xFFFFFFFE;
	x++;
}
