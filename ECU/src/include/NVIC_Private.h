/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 22, 2022                               */
/* 								Module	 : NVIC                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*************************************************************************************************************/
/* NVIC Peripheral Base Address :                                                                            */
/*                                                                                                           */
/* NVIC	 :	0xE000E100                                                                             		     */
/*                                                                          					  		  	 */
/* Note	 : NVIC in general supports 255 interrupts divided into 15 internal interrupts and 240 external      */
/* 		   interrupts but in our STM32F103C8T6 controller there are only 60 external interrupts connected to */
/* 		   60 pins of 240 external interrupt pins supported by NVIC                                          */
/*                                                                                                		  	 */
/*************************************************************************************************************/

/*Definitions of Registers Addresses for NVIC*/

	/* Registers Used to Enable The First 64 External Interrupts Connected to NVIC */
#define NVIC_ISER0  *((volatile u32 *)  0xE000E100)
#define NVIC_ISER1  *((volatile u32 *)  0xE000E104)
	/* Registers Used to Disable the First 64 External Interrupts Connected to NVIC */
#define NVIC_ICER0  *((volatile u32 *)  0xE000E180)
#define NVIC_ICER1  *((volatile u32 *)  0xE000E184)
	/* Registers Used to Set Pending Flag of the First 64 External Interrupts Connected to NVIC */
#define NVIC_ISPR0  *((volatile u32 *)  0xE000E200)
#define NVIC_ISPR1  *((volatile u32 *)  0xE000E204)
	/* Registers Used to Clear Pending Flag of the First 64 External Interrupts Connected to NVIC */
#define NVIC_ICPR0  *((volatile u32 *)  0xE000E280)
#define NVIC_ICPR1  *((volatile u32 *)  0xE000E284)
	/* Registers Used to Get Active Flag of the First 64 External Interrupts Connected to NVIC */
#define NVIC_IABR0  *((volatile u32 *)  0xE000E300)
#define NVIC_IABR1  *((volatile u32 *)  0xE000E304)
	/* Registers Used to Set Software Priority of the First 64 External Interrupts Connected to NVIC */
#define NVIC_IPR     ((volatile u8 *)   0xE000E400) /* NVIC_IPRx Registers are Byte Addressable */

#endif /* NVIC_PRIVATE_H_ */
