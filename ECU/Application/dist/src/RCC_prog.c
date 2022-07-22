/*
 * RCC_prog.c
 *
 *  Created on: Aug 6, 2019
 *      Author: sondo
 */

#include "STD_Types.h"
#include "util.h"
#include "RCC_priv.h"
#include "RCC_int.h"
#include "RCC_cfg.h"



/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Initialize RCC Peripheral. This must be the first line of the program 	*/
/* Input      : Void                                                                   	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidInit(void)
{
	RCC_CFGR &= 0X00000000;
	RCC_CR &= 0X00000000;
	RCC_CIR &= 0X00000000;
	RCC_APB2RSTR &= 0X00000000;
	RCC_APB1RSTR &= 0X00000000;
	RCC_AHBENR &= 0X00000000;
	RCC_APB2ENR	&= 0X00000000;
	RCC_APB1ENR	&= 0X00000000;
	RCC_BDCR	&= 0X00000000;
	RCC_CSR		&= 0X00000000;

	//Turn on HSI
	SET_BIT(RCC_CR, HSION);
	//Wait for HSI to be ON
	while (GET_BIT(RCC_CR, HSIRDY) != 1);

#if  ( (RCC_u8SYSCLK == RCC_u8SYSCLKHSE) 														\
		|| ( (RCC_u8SYSCLK == RCC_u8SYSCLKPLL) && (RCC_u8PLLCLK >= RCC_u8PLLHSEX2) ) 			\
		|| (RCC_u8MCOSRC == RCC_u8MCOHSECLK) 													\
		|| (RCC_u8RTCCLK == RCC_u8RTCHSEPRESCALER128) )
	/* If the Clock Source is from PLL using HSE or from HSE Directly or if MCO is using HSE OR RTC is using HSE Clock */

	//Choose HSE Bypassing
	RCC_CR|= ( (RCC_u8HSEBYP & 0x01) << HSEBYP);
	//Turn on HSE
	SET_BIT(RCC_CR, HSEON);
	//Wait for HSE to be Ready
	while (GET_BIT(RCC_CR, HSERDY) != 1);

#endif

#if  ( (RCC_u8SYSCLK == RCC_u8SYSCLKPLL) \
		|| (RCC_u8MCOSRC == RCC_u8MCOPLLPRESCALER2) \
		|| (RCC_u8USBPRESCALER < RCC_u8USBOFF) )
	/* If the PLL is the source for the System Clock or USB Peripheral is used or used on MCO Pin */

	/* After enabling HSE or HSI, set the multiplexers' values */
	//Assign PLLXTPRE Value
	RCC_CFGR |= (GET_BIT(RCC_u8PLLCLK, 5) << PLLXTPRE);
	//Assign PLLSRC Value
	RCC_CFGR |= (GET_BIT(RCC_u8PLLCLK, 4) << PLLSRC);
	//Assign PLLMUL Values
	RCC_CFGR |= (GET_LOW_NIB(RCC_u8PLLCLK) << PLLMUL);

	//Turn on PLL
	SET_BIT(RCC_CR, PLLON);
	//Wait for PLL to be Ready
	while (GET_BIT(RCC_CR, PLLRDY) != 1);

#endif

#if (RTC_u8RTCCLK > RTC_u8RTCOFF)
	/* If RTC is turned On */
#if ( RCC_u8RTCCLK == RCC_u8RTCLSE )

	//Choose LSE Bypassing
	RCC_BDCR |= (RCC_u8LSEBYP << LSEBYP);
	//Turn on LSE
	SET_BIT(RCC_BDCR, LSEON);
	//Wait for LSE to be Ready
	while (GET_BIT(RCC_BDCR, LSERDY) != 1);

#elif (RCC_u8RTCCLK == RCC_u8RTCLSI)

	//Turn on LSI
	SET_BIT(RCC_CSR, LSION);
	//Wait for LSI to be Ready
	while (GET_BIT(RCC_CSR, LSIRDY) != 1);

#endif

	/* Set RTC Clock Source */
	RCC_BDCR |= ((RCC_u8RTCCLK & 0x03) << RTCSEL));

	/* Enable RTC Peripheral */
	SET_BIT(RCC_BDCR, RTCEN);

#endif

	/* At this stage all the clocks we need are enabled and ready, We choose the System Clock */
	RCC_CFGR |= ((RCC_u8SYSCLK & 0x03) << SW);

	/* Set Prescalers for APB1, APB2 and AHB */
	//Set Prescaler for APB2
	RCC_CFGR |= ((RCC_u8APB2PRESCALER & 0x07) << PPRE2);
	//Set Prescaler for APB1
	RCC_CFGR |= ((RCC_u8APB1PRESCALER & 0x07) << PPRE1);
	//Set Prescaler for AHB
	RCC_CFGR |= ((RCC_u8APB2PRESCALER & 0x0F) << HPRE);
#if ( RCC_u8ADCPRESCALER < RCC_u8ADCOFF)
	//Set Prescaler for ADC Peripheral
	RCC_CFGR |= ((RCC_u8ADCPRESCALER & 0x03) << ADCPRE);
#endif

	/* Set MCO Pin Configuration */
	RCC_CFGR |= ((RCC_u8MCOSRC & 0x07) << MCO);

	/* Set CSS On or Off */
	RCC_CR |= (RCC_u8CSSONOFF << CSSON);
}




/****************************************************************************************/
/* Description: Enable CLock input for the corresponding peripheral						*/
/* Input      : u8 u8PeripheralIndex                                	               	*/
/*              Description: Peripheral to enable the clock for                         */
/* 				Range: 	RCC_u8AFIOCLK,		RCC_u8GPIOACLK,		RCC_u8GPIOBCLK,			*/
/* 						RCC_u8GPIOCCLK,		RCC_u8GPIODCLK,		RCC_u8ADC1CLK,			*/
/* 						RCC_u8ADC2CLK,		RCC_u8TIM1CLK,		RCC_u8SPI1CLK,			*/
/* 						RCC_u8TIM8CLK,		RCC_u8USART1CLK,	RCC_u8ADC3CLK,			*/
/* 						RCC_u8TIM9CLK,		RCC_u8TIM10CLK,		RCC_u8TIM11CLK,			*/
/*						RCC_u8TIM2CLK,		RCC_u8TIM3CLK,		RCC_u8TIM4CLK,			*/
/* 						RCC_u8TIM5CLK,		RCC_u8TIM6CLK,		RCC_u8TIM7CLK,			*/
/* 						RCC_u8TIM12CLK,		RCC_u8TIM12CLK,		RCC_u8TIM13CLK,			*/
/* 						RCC_u8TIM14CLK,		RCC_u8WWDGCLK,		RCC_u8SPI2CLK,			*/
/* 						RCC_u8SPI3CLK,		RCC_u8USART2CLK,	RCC_u8USART3CLK,		*/
/* 						RCC_u8USART4CLK,	RCC_u8USART5CLK,	RCC_u8I2C1CLK,			*/
/* 						RCC_u8I2C2CLK,		RCC_u8USBCLK,		RCC_u8CANCLK,			*/
/* 						RCC_u8BKPCLK,		RCC_u8PWRCLK,		RCC_u8DACCLK,			*/
/* 						RCC_u8DMA1CLK,		RCC_u8DMA2CLK,		RCC_u8FLITFCLK,			*/
/*						RCC_u8CRCCLK,		RCC_u8FSMCCLK,		RCC_u8SDIOCLK			*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidEnablePeripheral(u8 u8PeripheralIndex)
{
	if  (u8PeripheralIndex <= u8APB2_END)
	{
		SET_BIT(RCC_APB2ENR, u8PeripheralIndex);
	}
	else if  ( (u8PeripheralIndex >= u8APB1_START) && (u8PeripheralIndex <= u8APB1_END) )
	{
		u8PeripheralIndex -= u8APB1_START;
		SET_BIT(RCC_APB1ENR, u8PeripheralIndex);
	}
	else if  ( (u8PeripheralIndex >= u8AHB_START) && (u8PeripheralIndex <= u8AHB_END) )
	{
		u8PeripheralIndex -= u8AHB_START;
		SET_BIT(RCC_AHBENR, u8PeripheralIndex);
	}
	else
	{

	}
}






/****************************************************************************************/
/* Description: Disable CLock input for the corresponding peripheral					*/
/* Input      : u8 u8PeripheralIndex                                	               	*/
/*              Description: Peripheral to enable the clock for                         */
/* 				Range: 	RCC_u8AFIOCLK,		RCC_u8GPIOACLK,		RCC_u8GPIOBCLK,			*/
/* 						RCC_u8GPIOCCLK,		RCC_u8GPIODCLK,		RCC_u8ADC1CLK,			*/
/* 						RCC_u8ADC2CLK,		RCC_u8TIM1CLK,		RCC_u8SPI1CLK,			*/
/* 						RCC_u8TIM8CLK,		RCC_u8USART1CLK,	RCC_u8ADC3CLK,			*/
/* 						RCC_u8TIM9CLK,		RCC_u8TIM10CLK,		RCC_u8TIM11CLK,			*/
/*						RCC_u8TIM2CLK,		RCC_u8TIM3CLK,		RCC_u8TIM4CLK,			*/
/* 						RCC_u8TIM5CLK,		RCC_u8TIM6CLK,		RCC_u8TIM7CLK,			*/
/* 						RCC_u8TIM12CLK,		RCC_u8TIM12CLK,		RCC_u8TIM13CLK,			*/
/* 						RCC_u8TIM14CLK,		RCC_u8WWDGCLK,		RCC_u8SPI2CLK,			*/
/* 						RCC_u8SPI3CLK,		RCC_u8USART2CLK,	RCC_u8USART3CLK,		*/
/* 						RCC_u8USART4CLK,	RCC_u8USART5CLK,	RCC_u8I2C1CLK,			*/
/* 						RCC_u8I2C2CLK,		RCC_u8USBCLK,		RCC_u8CANCLK,			*/
/* 						RCC_u8BKPCLK,		RCC_u8PWRCLK,		RCC_u8DACCLK,			*/
/* 						RCC_u8DMA1CLK,		RCC_u8DMA2CLK,		RCC_u8FLITFCLK,			*/
/*						RCC_u8CRCCLK,		RCC_u8FSMCCLK,		RCC_u8SDIOCLK			*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidDisablePeripheral(u8 u8PeripheralIndex)
{
	if  (u8PeripheralIndex <= u8APB2_END)
	{
		CLR_BIT(RCC_APB2ENR, u8PeripheralIndex);
	}
	else if  ( (u8PeripheralIndex >= u8APB1_START) && (u8PeripheralIndex <= u8APB1_END) )
	{
		u8PeripheralIndex -= u8APB1_START;
		CLR_BIT(RCC_AHBENR, u8PeripheralIndex);
	}
	else if  ( (u8PeripheralIndex >= u8AHB_START) && (u8PeripheralIndex <= u8AHB_END) )
	{
		u8PeripheralIndex -= u8AHB_START;
		CLR_BIT(RCC_AHBENR, u8PeripheralIndex);
	}
	else
	{

	}
}



/****************************************************************************************/
/* Description: Reset the reset Flags													*/
/* Input      : Void					                               	               	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidResetResetFlags(void)
{
	RCC_CSR |= (1 << RMVF);
}


/****************************************************************************************/
/* Description: Returns the reason of the previous reset 								*/
/* Input      : u8 u8ResetFlag					                               	       	*/
/*              Description: Reset Reason to get the flag of	                        */
/* 				Range: 	RCC_u8PINRESET,		RCC_u8PORRESET,		RCC_u8SOFTRESET,		*/
/*						RCC_u8IWDGRESET,	RCC_u8WWDGRESET,	RCC_u8LOWPOWERRESET		*/
/*						RCC_u8POWERRESET												*/
/* Output     : u8                                                                   	*/
/*				Range: 0,1																*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u8 RCC_u8GetResetFlag(u8 u8ResetFlag)
{
	u8 u8Flags = ((RCC_CSR & (0xFFFF << PINRSTF)) >> PINRSTF);
	u8 u8ReturnValue = 0;
	if (u8ResetFlag == RCC_u8POWERRESET)
	{
		if (u8Flags == 3)
		{
			u8ReturnValue = 1;
		}
	}
	else if ( (u8Flags & (1<<u8ResetFlag) ) >>u8ResetFlag == 1)
	{
		u8ReturnValue = 1;
	}
	return u8ReturnValue;
}


