/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Mar 4, 2022                                */
/* 								Module	 : STK                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/**********************************************************************************************************/
/*									Important Notes	on SYSTICK									    	  */
/*																								 	  	  */
/* Note(1)	: The number of ticks (RELOAD) value can be any value in the range 0x00000001-0x00FFFFFF 	  */
/*																								     	  */
/* Note(2)	: The RELOAD value is calculated according to its use:										  */
/*			  1) To generate a multi-shot timer with a period of N processor clock cycles, use a RELOAD   */
/*  		  value of N-1. For example, if the SysTick interrupt is required every 100 clock pulses, set */
/* 	    	  RELOAD to 99.                                                                               */
/* 	          2) To deliver a single SysTick interrupt after a delay of N processor clock cycles, use a   */
/*  		  RELOAD of value N. For example, if a SysTick interrupt is required after 400 clock		  */
/*  		  pulses, set RELOAD to 400.																  */
/*																								 	  	  */
/**********************************************************************************************************/

								/* Function Prototypes */
void STK_vidSTKInit();
void STK_vidSetBusyWait(u32 Copy_u32Ticks);
void STK_vidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_vidPtr)(void));
void STK_vidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_vidPtr)(void));
void STK_vidStopTimer();
u32  STK_u32GetElapsedTime();
u32  STK_u32GetRemainingTime();

#endif /* STK_INTERFACE_H_ */
