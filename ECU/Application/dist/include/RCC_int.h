/*
 * RCC_int.h
 *
 *  Created on: Aug 6, 2019
 *      Author: sondo
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_

/*****************************************/
/*********Public Definitions*************/
/*****************************************/

/* APB2 Clock Peripherals */
#define	RCC_u8AFIOCLK		 0
#define	RCC_u8GPIOACLK		 2
#define	RCC_u8GPIOBCLK		 3
#define	RCC_u8GPIOCCLK		 4
#define	RCC_u8GPIODCLK		 5
#define	RCC_u8ADC1CLK		 9
#define	RCC_u8ADC2CLK		 10
#define	RCC_u8TIM1CLK		 11
#define	RCC_u8SPI1CLK		 12
#define	RCC_u8TIM8CLK		 13
#define	RCC_u8USART1CLK		 14
#define	RCC_u8ADC3CLK		 15
#define	RCC_u8TIM9CLK		 19
#define	RCC_u8TIM10CLK		 20
#define	RCC_u8TIM11CLK		 21

/* APB1 Clock Peripherals */
#define	RCC_u8TIM2CLK		 32
#define	RCC_u8TIM3CLK		 33
#define	RCC_u8TIM4CLK		 34
#define	RCC_u8TIM5CLK		 35
#define	RCC_u8TIM6CLK		 36
#define	RCC_u8TIM7CLK		 37
#define	RCC_u8TIM12CLK		 38
#define	RCC_u8TIM13CLK		 39
#define	RCC_u8TIM14CLK		 40
#define	RCC_u8WWDGCLK		 43
#define	RCC_u8SPI2CLK		 46
#define	RCC_u8SPI3CLK		 47
#define	RCC_u8USART2CLK		 49
#define	RCC_u8USART3CLK		 50
#define	RCC_u8USART4CLK		 51
#define	RCC_u8USART5CLK		 52
#define RCC_u8I2C1CLK		 53
#define RCC_u8I2C2CLK		 54
#define RCC_u8USBCLK		 55
#define RCC_u8CANCLK		 57
#define RCC_u8BKPCLK		 59
#define RCC_u8PWRCLK		 60
#define RCC_u8DACCLK		 61


/* AHB Clock Definitions */
#define RCC_u8DMA1CLK		 64
#define RCC_u8DMA2CLK		 65
#define RCC_u8FLITFCLK		 66
#define RCC_u8CRCCLK		 68
#define RCC_u8FSMCCLK		 70
#define RCC_u8SDIOCLK		 72



/* Reset Reasons */
#define RCC_u8PINRESET			0
#define RCC_u8PORRESET			1
#define RCC_u8SOFTRESET			2
#define RCC_u8IWDGRESET			3
#define RCC_u8WWDGRESET			4
#define RCC_u8LOWPOWERRESET		5
#define RCC_u8POWERRESET		6



/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Initialize RCC Peripheral. This must be the first line of the program 	*/
/* Input      : Void                                                                   	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidInit(void);


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
void RCC_vidEnablePeripheral(u8 u8PeripheralIndex);


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
void RCC_vidDisablePeripheral(u8 u8PeripheralIndex);



/****************************************************************************************/
/* Description: Reset the reset Flags													*/
/* Input      : Void					                               	               	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void RCC_vidResetResetFlags(void);


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
u8 RCC_u8GetResetFlag(u8 u8ResetFlag);


#endif /* RCC_INT_H_ */
