/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 15, 2022                               */
/* 								Module	 : RCC                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

/*Initializes the processor (system) clock and selects its type based on user configuration*/
void RCC_vidClkInit()
{
	#if   RCC_CLK_TYPE == RCC_HSI
		RCC_CR 	 = 0x00000081 ;					/* Enable HSI Clock with Trimming = 0 */
		RCC_CFGR = 0x00000000 ;					/* HSI is selected as system clock */
	#elif RCC_CLK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR 	 = 0x00090080 ;					/* Enable HSE Crystal Clock with No Bypass and CSS Enabled */
		RCC_CFGR = 0x00000001 ;					/* HSE is selected as system clock */
	#elif RCC_CLK_TYPE == RCC_HSE_RC
		RCC_CR 	 = 0x000D0080 ;					/* Enable HSE RC Clock with Bypass and CSS Enabled */
		RCC_CFGR = 0x00000001 ;					/* HSE is selected as system clock */
	#elif RCC_CLK_TYPE == RCC_PLL
		RCC_CFGR = 0x00000002 ;					/* HSE is selected as system clock */

		#if (RCC_PLL_MUL_FACTOR_VAL>RCC_PLL_NO_CLK_FACTOR && RCC_PLL_MUL_FACTOR_VAL<=RCC_PLL_CLK_MULTIPLE_BY_16)
			RCC_CFGR &= 0xFFC3FFFF;				/*Clear PLL Multiplication Value*/
			RCC_CFGR |= RCC_PLL_MUL_FACTOR_VAL; /*Set New PLL Multiplication Value*/
		#endif

		#if   RCC_PLL_INPUT == RCC_PLL_HSI_DIV_2
			RCC_CFGR &= 0xFFFFFFFF ;			/*HSI clock / 2 selected as PLL input clock*/
			RCC_CR 	 = 0x00000081 ;				/* Enable HSI Clock with Trimming = 0 */
		#elif RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2
			RCC_CFGR |= 0x00030000 ;			/*HSE clock / 2 selected as PLL input clock*/
			#if   RCC_PLL_HSE_TYPE == RCC_PLL_HSE_CRYSTAL
				RCC_CR = 0x00010080 ;			/* Enable HSE Crystal Clock with No Bypass*/
			#elif RCC_PLL_HSE_TYPE == RCC_PLL_HSE_RC
				RCC_CR = 0x00050080 ;		  	/* Enable HSE RC Clock with Bypass*/
			#endif
		#elif RCC_PLL_INPUT == RCC_PLL_HSE
			RCC_CFGR |= 0x00010000 ;			/*HSE clock selected as PLL input clock*/
			#if   RCC_PLL_HSE_TYPE == RCC_PLL_HSE_CRYSTAL
				RCC_CR = 0x00010080 ;			/* Enable HSE Crystal Clock with No Bypass*/
			#elif RCC_PLL_HSE_TYPE == RCC_PLL_HSE_RC
				RCC_CR = 0x00050080 ;		  	/* Enable HSE RC Clock with Bypass*/
			#endif
		#endif

		RCC_CR |= 0x01000000 ;					/* Enable PLL Clock */
	#else
		#error " Wrong Clock Type Configuration "
	#endif
}
/*Enables the clock source for a peripheral*/
void RCC_vidEnablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB :
			SET_BIT(RCC_AHBENR,Copy_u8PeripheralId);  /*Enables the clock source for a peripheral connected to AHB BUS*/
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR,Copy_u8PeripheralId); /*Enables the clock source for a peripheral connected to APB1 BUS*/
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR,Copy_u8PeripheralId); /*Enables the clock source for a peripheral connected to AP2 BUS*/
			break;
//		default:
//			/* Return Error */
		}
	}
	else
	{
		/* Return Error */
	}
}
/*Disables the clock source for a peripheral*/
void RCC_vidDisablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB :
			CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId);  /*Disables the clock source for a peripheral connected to AHB BUS*/
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralId); /*Disables the clock source for a peripheral connected to APB1 BUS*/
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralId); /*Disables the clock source for a peripheral connected to AP2 BUS*/
			break;
//		default:
//			/* Return Error */
		}
	}
	else
	{
		/* Return Error */
	}
}

