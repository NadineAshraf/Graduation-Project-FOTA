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
/*****************************************************************************/
/* Description 	: Initialization of timer 1									*/
/* input 		:void																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/
void Timer1_UEV_Interrupt (void)

{
	RCC_vidEnablePeripheral(RCC_u8TIM1CLK);
	//TIM1_CR1 |= (CEN | UDIS | DIR | ARPE );			// counter enable /UEV enable/ direction / preload or not
	TIM1_CR1 &= ~(DIR);
	TIM1_PSC = 35999;
	TIM1_ARR = 2000;
	TIM1_DIER |= UIE;
	TIM1_CR1 |= CEN;

}
/*****************************************************************************/
/* Description 	: Timer 1_PWM Configuration								*/
/* input 		:void																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/

void Timer1_Genetare_PWM_config(void)
{

	TIM1_CR1 |= DIR;
	TIM1_CR1 |= ARPE;

	TIM1_PSC = PSCVALUE;
	/* SET THE PERIOD OF THE PWM*/
	TIM1_ARR = ARRVALUE;

	/* SET THE VALUE OF THE DUTY CYCLE THE PWM*/
	//TIM1_CCR1 = CCR1VALUE;

	/* SET PWM MODE (CHOOSE PWM MODE 1)*/
	TIM1_CCMR1 |= (OC1M | OC2M) ;

	/*ENABLE OUTPUT COMPARE1 PRELOAD */
	TIM1_CCMR1 |= (OC1PE |OC2PE);

	/* INITIALIAZE ALL THE REGISTERS */
	TIM1_EGR |= UG;

	/* ENABLE COMPARE1 OUTPUT*/
	TIM1_CCER |= (CC1E | CC2E );

    /* MAIN OUTPUT ENABLE*/
	TIM1_BDTR |= MOE;

	TIM1_CR1 |= CEN;
}

/*****************************************************************************/
/* Description 	:choose duty cycle of PWM signal									*/
/* input 		:u32																*/
/*output		:void																*/
/*scope			:																	*/
/*****************************************************************************/

void Timer1_Channel1_Genetare_PWM(u32 CCR1)
{
	TIM1_CCR1 = CCR1;
}

void Timer1_Channel2_Genetare_PWM(u32 CCR2)
{
	TIM1_CCR2 = CCR2;


}
