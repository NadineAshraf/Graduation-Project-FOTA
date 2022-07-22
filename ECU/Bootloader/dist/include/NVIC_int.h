#ifndef NVIC_INT_H
#define NVIC_INT_H


/*****************************************/
/***********Public Definitions************/
/*****************************************/
#define NVIC_u8WWDG						0			//Window Watchdog Interrupt
#define NVIC_u8PVD						1			//PVD Through EXTI Line Detection Interrupt
#define NVIC_u8TAMPER					2			//Tamper Interrupt
#define NVIC_u8RTC						3			//RTC
#define NVIC_u8FLASH					4			//Flash
#define NVIC_u8RCC						5			//RCC
#define NVIC_u8EXTI0					6			//EXTI0
#define NVIC_u8EXTI1					7			//EXTI1
#define NVIC_u8EXTI2					8			//EXTI2
#define NVIC_u8EXTI3					9			//EXTI3
#define NVIC_u8EXTI4					10			//EXTI4
#define NVIC_u8DMA1_CHANNEL1			11			//DMA Channel1
#define NVIC_u8DMA1_CHANNEL2			12			//DMA Channel2
#define NVIC_u8DMA1_CHANNEL3			13			//DMA Channel3
#define NVIC_u8DMA1_CHANNEL4			14			//DMA Channel4
#define NVIC_u8DMA1_CHANNEL5			15			//DMA Channel5
#define NVIC_u8DMA1_CHANNEL6			16			//DMA Channel6
#define NVIC_u8DMA1_CHANNEL7			17			//DMA Channel7
#define NVIC_u8ADC1_2					18			//ADC1 and ADC2
#define NVIC_u8USB_HP_CAN_TX			19			//USB High Priority or CAN TX interrupt
#define NVIC_u8USB_LP_CAN_RX0			20			//USB Low Priority or CAN RX0 interrupt
#define NVIC_u8CAN_RX1					21			//CAN RX1
#define NVIC_u8CAN_SCE					22			//CAN SCE
#define NVIC_u8EXTI9_5					23			//EXTI5 to EXTI9
#define NVIC_u8TIM1_BRK					24			//Timer1 Break Interrupt
#define NVIC_u8TIM1_UP					25			//Timer1 Update Interrupt
#define NVIC_u8TIM1_TRG_COM				26			//Timer1 Trigger and Communication Interrupts
#define NVIC_u8TIM1_CC					27			//Timer1 Capture Compare Interrupt
#define NVIC_u8TIM2						28			//Timer2
#define NVIC_u8TIM3						29			//Timer3
#define NVIC_u8TIM4						30			//Timer4
#define NVIC_u8I2C1_EV					31			//I2C1 Event Interrupt
#define NVIC_u8I2C1_ER					32			//I2C1 Error Interrupt
#define NVIC_u8I2C2_EV					33			//I2C2 Event Interrupt
#define NVIC_u8I2C2_ER					34			//I2C2 Error Interrupt
#define NVIC_u8SPI1						35			//SPI1
#define NVIC_u8SPI2						36			//SPI2
#define NVIC_u8USART1					37			//USART1
#define NVIC_u8USART2					38			//USART2
#define NVIC_u8USART3					39			//USART3
#define NVIC_u8EXTI15_10				40			//EXTI15 to EXTI10
#define NVIC_u8RTCALARM					41			//RTC Alarm through EXTI line interrupt
#define NVIC_u8USBWAKEUP				42			//USB wakeup from suspend through EXTI line interrupt
#define NVIC_u8TIM8_BRK					43			//Timer8 Break interrupt
#define NVIC_u8TIM8_UP					44			//Timer8 Update interrupt
#define NVIC_u8TIM8_TRG_COM				45			//Timer8 Trigger and Communication Interrupts
#define NVIC_u8TIM8_CC					46			//Timer8 Capture Compare Interrupt
#define NVIC_u8ADC3						47			//ADC3
#define NVIC_u8FSMC						48			//FSMC
#define NVIC_u8SDIO						49			//SDIO
#define NVIC_u8TIM5						50			//Timer5
#define NVIC_u8SPI3						51			//SPI3
#define NVIC_u8UART4					52			//UART4
#define NVIC_u8UART5					53			//UART5
#define NVIC_u8TIM6						54			//Timer6
#define NVIC_u8TIM7						55			//Timer7
#define NVIC_u8DMA2_CHANNEL1			56			//DMA2 Channel1
#define NVIC_u8DMA2_CHANNEL2			57			//DMA2 Channel2
#define NVIC_u8DMA2_CHANNEL3			58			//DMA2 Channel3
#define NVIC_u8DMA2_CHANNEL4_5			59			//DMA2 Channel4 and Channel5



/*****************************************/
/***********Public Functions**************/
/*****************************************/

/************************************************************************************************/
/* Description: Enable NVIC input for the corresponding peripheral								*/
/* Input      : Void					                               	               			*/
/* Output     : Void                                                                  		 	*/
/* Scope      : Public                                                                 			*/
/************************************************************************************************/
void NVIC_vidInit(void);


/************************************************************************************************/
/* Description: Enable NVIC input for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to enable the NVIC for                         			*/
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
void NVIC_vidEnableInterrupt(u8 u8InterruptIndex);



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
void NVIC_vidDisableInterrupt(u8 u8InterruptIndex);



/************************************************************************************************/
/* Description: Set Pending Flag for the corresponding peripheral								*/
/* Input      : u8 u8PeripheralIndex                                	               			*/
/*              Description: Peripheral to set pending flag for                         		*/
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
void NVIC_vidSetPendingFlag(u8 u8InterruptIndex);



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
void NVIC_vidClearPendingFlag(u8 u8InterruptIndex);



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
u8 NVIC_u8GetActiveFlag(u8 u8InterruptIndex);



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
void NVIC_vidSetPriority(u8 u8InterruptIndex, u8 u8Priority);


#endif
