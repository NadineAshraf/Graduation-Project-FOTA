/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 22, 2022                               */
/* 								Module	 : NVIC                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**************************************************************************************************************/
/* Notes to Consider about NVIC :                                                                   		  */
/*                                                                          					  			  */
/* 1) NVIC is a core peripheral (Standard) ==> (Low Interrupt Latency)                   		  			  */
/* 2) NVIC in general supports 255 interrupts divided into 15 internal interrupts and 240 external interrupts */
/* 3) NVIC is a vector table based system                                                		  			  */
/* 4) NVIC supports independent enable pin for each external interrupt even if it's a NMI                     */
/* 5) NVIC supports nesting especially Normal Nesting and don't support Self Nesting                          */
/* 6) NVIC supports independent set and clear pending flag for each external interrupt for debugging purposes */
/* 7) NVIC supports software and hardware priorities                                                          */
/*                                                                                               			  */
/* Important Note : NVIC manages all interrupts but controls only external ones which means that internal     */
/*        			interrupts caused by core peripherals can only by controlled through their drivers' 	  */
/* 					registers 																				  */
/*                                                                                               			  */
/*                                                                                               			  */
/**************************************************************************************************************/

								/* Interface Macros */

/*Available External Interrupts' IDs Connected to NVIC's 240 External Interrupt Pins*/
#define NVIC_INT_WWDG            0
#define NVIC_INT_PVD             1
#define NVIC_INT_TAMPER          2
#define NVIC_INT_RTC             3
#define NVIC_INT_FLASH           4
#define NVIC_INT_RCC             5
#define NVIC_INT_EXTI0           6
#define NVIC_INT_EXTI1           7
#define NVIC_INT_EXTI2           8
#define NVIC_INT_EXTI3           9
#define NVIC_INT_EXTI4           10
#define NVIC_INT_DMA1_Channel1   11
#define NVIC_INT_DMA1_Channel2   12
#define NVIC_INT_DMA1_Channel3   13
#define NVIC_INT_DMA1_Channel4   14
#define NVIC_INT_DMA1_Channel5   15
#define NVIC_INT_DMA1_Channel6   16
#define NVIC_INT_DMA1_Channel7   17
#define NVIC_INT_ADC1_2          18
#define NVIC_INT_USB_HP_CAN_TX   19
#define NVIC_INT_USB_LP_CAN_RX0  20
#define NVIC_INT_CAN_RX1         21
#define NVIC_INT_CAN_SCE         22
#define NVIC_INT_EXTI9_5         23
#define NVIC_INT_TIM1_BRK        24
#define NVIC_INT_TIM1_UP         25
#define NVIC_INT_TIM1_TRG_COM    26
#define NVIC_INT_TIM1_CC         27
#define NVIC_INT_TIM2            28
#define NVIC_INT_TIM3            29
#define NVIC_INT_TIM4            30
#define NVIC_INT_I2C1_EV         31
#define NVIC_INT_I2C1_ER         32
#define NVIC_INT_I2C2_EV         33
#define NVIC_INT_I2C2_ER         34
#define NVIC_INT_SPI1            35
#define NVIC_INT_SPI2            36
#define NVIC_INT_USART1          37
#define NVIC_INT_USART2          38
#define NVIC_INT_USART3          39
#define NVIC_INT_EXTI15_10       40
#define NVIC_INT_RTCAlarm        41
#define NVIC_INT_USBWakeup       42
#define NVIC_INT_TIM8_BRK        43
#define NVIC_INT_TIM8_UP         44
#define NVIC_INT_TIM8_TRG_COM    45
#define NVIC_INT_TIM8_CC         46
#define NVIC_INT_ADC3            47
#define NVIC_INT_FSMC            48
#define NVIC_INT_SDIO            49
#define NVIC_INT_TIM5            50
#define NVIC_INT_SPI3            51
#define NVIC_INT_UART4           52
#define NVIC_INT_UART5           53
#define NVIC_INT_TIM6            54
#define NVIC_INT_TIM7            55
#define NVIC_INT_DMA2_Channel1   56
#define NVIC_INT_DMA2_Channel2   57
#define NVIC_INT_DMA2_Channel3   58
#define NVIC_INT_DMA2_Channel4_5 59

								/* Functions Prototypes */

void NVIC_VidEnablePeripheralInterrupt(u8 Copy_u8InterruptId);
void NVIC_VidDisablePeripheralInterrupt(u8 Copy_u8InterruptId);
void NVIC_VidSetPendingFlag(u8 Copy_u8InterruptId);
void NVIC_VidClearPendingFlag(u8 Copy_u8InterruptId);
void NVIC_VidSetInterruptPriority(s8 Copy_u8InterruptId , u8 Copy_Priority);
u8   NVIC_u8GetActiveFlag(u8 Copy_u8InterruptId);

#endif /* NVIC_INTERFACE_H_ */
