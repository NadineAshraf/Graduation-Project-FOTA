/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 22, 2022                               */
/* 								Module	 : NVIC                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

/*Enables An External Interrupt Connected to NVIC*/
void NVIC_VidEnablePeripheralInterrupt(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		NVIC_ISER0= (1 << Copy_u8InterruptId);
	}
	else if(Copy_u8InterruptId < 60)
	{
		Copy_u8InterruptId -= 32 ;
		NVIC_ISER1 = (1 << Copy_u8InterruptId);
	}
	else
	{
		/*Return Error*/
	}

}
/*Disables An External Interrupt Connected to NVIC*/
void NVIC_VidDisablePeripheralInterrupt(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptId);
	}
	else if(Copy_u8InterruptId < 60)
	{
		Copy_u8InterruptId -= 32 ;
		NVIC_ICER1 = (1 << Copy_u8InterruptId);
	}
	else
	{
		/*Return Error*/
	}
}
/*Sets A Pending Flag of An External Interrupt Connected to NVIC*/
void NVIC_VidSetPendingFlag(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptId);
	}
	else if(Copy_u8InterruptId < 60)
	{
		Copy_u8InterruptId -= 32 ;
		NVIC_ISPR1 = (1 << Copy_u8InterruptId);
	}
	else
	{
		/*Return Error*/
	}
}
/*Clears A Pending Flag of An External Interrupt Connected to NVIC*/
void NVIC_VidClearPendingFlag(u8 Copy_u8InterruptId)
{
	if(Copy_u8InterruptId < 32)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptId);
	}
	else if(Copy_u8InterruptId < 60)
	{
		Copy_u8InterruptId -= 32 ;
		NVIC_ICPR1 = (1 << Copy_u8InterruptId);
	}
	else
	{
		/*Return Error*/
	}
}
/*Sets the Software Priority of An External Interrupt Connected to NVIC*/
void NVIC_VidSetInterruptPriority(s8 Copy_u8InterruptId , u8 Copy_Priority)
{
	if(Copy_u8InterruptId >= 0)
	{
		NVIC_IPR[Copy_u8InterruptId] = (Copy_Priority << 4);
	}
}
/*Gets the Active Flag Value of An External Interrupt Connected to NVIC*/
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptId)
{
	u8 local_u8ActiveFlag = 0 ;

	if(Copy_u8InterruptId < 32)
	{
		local_u8ActiveFlag = GET_BIT(NVIC_IABR0,Copy_u8InterruptId);
	}
	else if(Copy_u8InterruptId < 60)
	{
		Copy_u8InterruptId -= 32 ;
		local_u8ActiveFlag = GET_BIT(NVIC_IABR1,Copy_u8InterruptId);
	}
	else
	{
		/*Return Error*/
	}
	return local_u8ActiveFlag ;
}
