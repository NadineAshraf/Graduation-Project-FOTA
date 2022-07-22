
#include "STD_Types.h"
#include "util.h"
#include "NVIC_priv.h"
#include "NVIC_int.h"



/*****************************************/
/***********Public Functions**************/
/*****************************************/


/************************************************************************************************/
/* Description: Enable NVIC input for the corresponding peripheral								*/
/* Input      : Void					                               	               			*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidInit(void)
{
#define SCB_AIRCR	(*(volatile u32*)0xE000ED0C)
	SCB_AIRCR = 0x05FA0500;
}

/************************************************************************************************/
/* Description: Enable NVIC input for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to enable the NVIC for                         			*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,			NVIC_u8TAMPER				*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidEnableInterrupt(u8 u8InterruptIndex)
{
	if (u8InterruptIndex <= 31)
	{
		NVIC_ISER[0] = 0x01 << u8InterruptIndex;
	}
	if (u8InterruptIndex <= 63)
	{
		u8InterruptIndex -= 32;
		NVIC_ISER[1] = 0x01 << u8InterruptIndex;
	}
}



/************************************************************************************************/
/* Description: Disable NVIC input for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to disable the NVIC for                        			*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,				NVIC_u8TAMPER			*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidDisableInterrupt(u8 u8InterruptIndex)
{
	if (u8InterruptIndex <= 31)
	{
		NVIC_ICER[0] = 0x01 << u8InterruptIndex;
	}
	if (u8InterruptIndex <= 63)
	{
		u8InterruptIndex -= 32;
		NVIC_ICER[1] = 0x01 << u8InterruptIndex;
	}
}



/************************************************************************************************/
/* Description: Set Pending Flag for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to set pending flag for                         		*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,			NVIC_u8TAMPER				*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidSetPendingFlag(u8 u8InterruptIndex)
{
	if (u8InterruptIndex <= 31)
	{
		NVIC_ISPR[0] = 0x01 << u8InterruptIndex;
	}
	if (u8InterruptIndex <= 63)
	{
		u8InterruptIndex -= 32;
		NVIC_ISPR[1] = 0x01 << u8InterruptIndex;
	}
}


/************************************************************************************************/
/* Description: Clear Pending Flag for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to clear pending flag for                         		*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,			NVIC_u8TAMPER				*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidClearPendingFlag(u8 u8InterruptIndex)
{
	if (u8InterruptIndex <= 31)
	{
		NVIC_ICPR[0] = 0x01 << u8InterruptIndex;
	}
	if (u8InterruptIndex <= 63)
	{
		u8InterruptIndex -= 32;
		NVIC_ICPR[1] = 0x01 << u8InterruptIndex;
	}
}



/************************************************************************************************/
/* Description: Get Active Flag for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to get active flag for              	           		*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,				NVIC_u8TAMPER			*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/* Output     : u8                                                      		             	*/
/*				Description: Active flag Status													*/
/*				Range: 0, 1																		*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
u8 NVIC_u8GetActiveFlag(u8 u8InterruptIndex)
{
	u8 u8value = 0;
	if (u8InterruptIndex <= 31)
	{
		u8value = GET_BIT(NVIC_IABR[0], u8InterruptIndex);
	}
	if (u8InterruptIndex <= 63)
	{
		u8InterruptIndex -= 32;
		u8value = GET_BIT(NVIC_IABR[1], u8InterruptIndex);
	}
	return u8value;
}




/************************************************************************************************/
/* Description: Set Priority of the corresponding interrupt										*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to disable the NVIC for                        			*/
/* 				Range: 	NVIC_u8WWDG,			NVIC_u8PVD,				NVIC_u8TAMPER			*/
/*						NVIC_u8RTC,				NVIC_u8FLASH,			NVIC_u8RCC				*/
/*						NVIC_u8EXTI0,			NVIC_u8EXTI1,			NVIC_u8EXTI2			*/
/*						NVIC_u8EXTI3,			NVIC_u8EXTI4,			NVIC_u8DMA1_CHANNEL1	*/
/*						NVIC_u8DMA1_CHANNEL2,	NVIC_u8DMA1_CHANNEL3,	NVIC_u8DMA1_CHANNEL4	*/
/*						NVIC_u8DMA1_CHANNEL5,	NVIC_u8DMA1_CHANNEL6,	NVIC_u8DMA1_CHANNEL7	*/
/*						NVIC_u8ADC1_2,			NVIC_u8USB_HP_CAN_TX,	NVIC_u8USB_LP_CAN_RX0	*/
/*						NVIC_u8CAN_RX1,			NVIC_u8CAN_SCE,			NVIC_u8EXTI9_5			*/
/*						NVIC_u8TIM1_BRK,		NVIC_u8TIM1_UP,			NVIC_u8TIM1_TRG_COM		*/
/*						NVIC_u8TIM1_CC,			NVIC_u8TIM2,			NVIC_u8TIM3				*/
/*						NVIC_u8TIM4,			NVIC_u8I2C1_EV,			NVIC_u8I2C1_ER			*/
/*						NVIC_u8I2C2_EV,			NVIC_u8I2C2_ER,			NVIC_u8SPI1				*/
/*						NVIC_u8SPI2,			NVIC_u8USART1,			NVIC_u8USART2			*/
/*						NVIC_u8USART3,			NVIC_u8EXTI15_10,		NVIC_u8RTCALARM			*/
/*						NVIC_u8USBWAKEUP,		NVIC_u8TIM8_BRK,		NVIC_u8TIM8_UP			*/
/*						NVIC_u8TIM8_TRG_COM,	NVIC_u8TIM8_CC,			NVIC_u8ADC3				*/
/*						NVIC_u8FSMC,			NVIC_u8SDIO,			NVIC_u8TIM5				*/
/*						NVIC_u8SPI3,			NVIC_u8UART4,			NVIC_u8UART5			*/
/*						NVIC_u8TIM6,			NVIC_u8TIM7,			NVIC_u8DMA2_CHANNEL1	*/
/*						NVIC_u8DMA2_CHANNEL2,	NVIC_u8DMA2_CHANNEL3,	NVIC_u8DMA2_CHANNEL4_5	*/
/*				u8 u8Priority                                	               					*/
/*              Description: Peripheral to disable the NVIC for                        			*/
/* 				Range: 0 ~ 255																	*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidSetPriority(u8 u8InterruptIndex, u8 u8Priority)
{
	NVIC_IPR[u8InterruptIndex] = u8Priority<<4;
}

