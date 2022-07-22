/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Mar 4, 2022                                */
/* 								Module	 : STK                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

/* Global Variables Definitions */
void(*Callback_Func)(void);
u8 Global_u8IntervalMode;

/*
 * 1- Selects the Clock Source from Configuration File
 * 2- Disables SYSTICK Timer
 * 3- Disables SYSTICK Interrupt
 */
void STK_vidSTKInit()
{
	/* Disable SYSTICK Timer and SYSTICK Interrupt */
	STK_CTRL = 0x00000000;
#if   STK_CLK_SRC == STK_AHB_DIV_EIGHT
	/* Select AHB/8 as Clock Source of SYSTICK Timer */
	CLR_BIT(STK_CTRL,2);
#elif STK_CLK_SRC == STK_AHB
	/* Select AHB as Clock Source of SYSTICK Timer */
	SET_BIT(STK_CTRL,2);
#else
#error " Wrong Clock Source Configuration "
#endif
}
/*Delays or Locks the Processor for N Clock Cycles Based on the Number of Ticks Passed (Synchronous)*/
void STK_vidSetBusyWait(u32 Copy_u32Ticks)
{
	if(Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
	{
		/* Set the Number of ticks (Reload or Start) Value in STK_LOAD Register */
		STK_LOAD = Copy_u32Ticks;
		/* Start (Enable) SYSTICK Timer */
		SET_BIT(STK_CTRL,0);
		/* Lock the processor until SYSTICK timer reaches 0 */
		while (GET_BIT(STK_CTRL,16) != 1){};
		/* Stop (Disable) SYSTICK Timer */
		CLR_BIT(STK_CTRL, 0);
		/* Clear SYSTICK Timer and Flag */
		STK_LOAD = 0;
		STK_VAL = 0;
	}
	else
	{
		/* Return Error */
	}
}
/*Sets A Count-Down Timer that Generates An Interrupt When it Reaches 0 After N Clock Cycles Based on the Number of Ticks Passed (Asynchronous)*/
void STK_vidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_vidPtr)(void))
{
	if(Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
	{
		/* Assign the passed function as a callback function to be called in ISR when triggered */
		Callback_Func = Copy_vidPtr;
		/* Set the interval mode */
		Global_u8IntervalMode = STK_INTERVAL_SINGLE;
		/* Set the Number of ticks (Reload or Start) Value in STK_LOAD Register */
		STK_LOAD = Copy_u32Ticks;
		/* Enable SYSTICK Interrupt */
		SET_BIT(STK_CTRL,1);
		/* Start (Enable) SYSTICK Timer */
		SET_BIT(STK_CTRL,0);
	}
	else
	{
		/* Return Error */
	}
}
/*Sets A Count-Down Timer that Generates An Interrupt When it Reaches 0 Every N Clock Cycles Based on the Number of Ticks Passed (Asynchronous)*/
void STK_vidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_vidPtr)(void))
{
	if(Copy_u32Ticks >= 0x00000001 && Copy_u32Ticks <= 0x00FFFFFF)
	{
		/* Assign the passed function as a callback function to be called in ISR when triggered */
		Callback_Func = Copy_vidPtr;
		/* Set the interval mode */
		Global_u8IntervalMode = STK_INTERVAL_PERIODIC;
		/* Set the Number of ticks (Reload or Start) Value in STK_LOAD Register */
		STK_LOAD = Copy_u32Ticks;
		/* Enable SYSTICK Interrupt */
		SET_BIT(STK_CTRL,1);
		/* Start (Enable) SYSTICK Timer */
		SET_BIT(STK_CTRL,0);
	}
	else
	{
		/* Return Error */
	}
}
/*Stops the SYSTICK Timer*/
void STK_vidStopTimer()
{
	/* Disable SYSTICK Interrupt */
	CLR_BIT(STK_CTRL,1);
	/* Stop (Disable) SYSTICK Timer */
	CLR_BIT(STK_CTRL,0);
	/* Clear SYSTICK Timer and Flag */
	STK_LOAD = 0;
	STK_VAL = 0;
}
/*Calculates The Elapsed Time of SYSTICK Timer*/
u32 STK_u32GetElapsedTime()
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK_LOAD - STK_VAL;
	return Local_u32ElapsedTime;
}
/*Calculates The Remaining Time of SYSTICK Timer*/
u32 STK_u32GetRemainingTime()
{
	u32 Local_u32RemainingTime;
	Local_u32RemainingTime = STK_VAL;
	return Local_u32RemainingTime;
}
/*SYSTICK Exception Handler*/
void SysTick_Handler(void)
{
	if(Global_u8IntervalMode == STK_INTERVAL_SINGLE)
	{
		/* Disable SYSTICK Interrupt */
		CLR_BIT(STK_CTRL,1);
		/* Stop (Disable) SYSTICK Timer */
		CLR_BIT(STK_CTRL,0);
		/* Clear SYSTICK Timer */
		STK_LOAD = 0;
	}
		/* Clear SYSTICK Flag */
		STK_VAL = 0;
		Callback_Func();

}
