/*
 * ADC_priv.h
 *
 *  Created on: May 11, 2020
 *      Author: Salma ahmed
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


#define ADC1_SR			(*((volatile u32*)0x40012400))
#define ADC1_CR1		(*((volatile u32*)0x40012404))
#define ADC1_CR2		(*((volatile u32*)0x40012408))
#define ADC1_SMPR1		(*((volatile u32*)0x4001240C))
#define ADC1_SMPR2		(*((volatile u32*)0x40012410))
#define ADC1_JOFR1		(*((volatile u32*)0x40012414))
#define ADC1_JOFR2		(*((volatile u32*)0x40012418))
#define ADC1_JOFR3		(*((volatile u32*)0x4001241C))
#define ADC1_JOFR4		(*((volatile u32*)0x40012420))
#define ADC1_HTR		(*((volatile u32*)0x40012424))
#define ADC1_LTR		(*((volatile u32*)0x40012428))
#define ADC1_SQR1		(*((volatile u32*)0x4001242C))
#define ADC1_SQR2		(*((volatile u32*)0x40012430))
#define ADC1_SQR3		(*((volatile u32*)0x40012434))
#define ADC1_JSQR		(*((volatile u32*)0x40012438))
#define ADC1_JDR1		(*((volatile u32*)0x4001243C))
#define ADC1_JDR2		(*((volatile u32*)0x40012440))
#define ADC1_JDR3		(*((volatile u32*)0x40012444))
#define ADC1_JDR4		(*((volatile u32*)0x40012448))
#define ADC1_DR			(*((volatile u32*)0x4001244C))


/******************************CR2 register bits*****************************/

#define SWSTART					0x00400000
#define CONT					0x00000002
#define SWSTARTTRIGGER			0x000E0000
#define EXTERNALTRIGGERENABLE	0x00100000
#define SOCFLAG					0x00000010
#define EOCFLAG					0x00000002
#define DMA_ENABLE				0x00000100

/******************************CR1 register bits*****************************/
#define ENABLEDISCONTINOUS		0x00000800
#define EOCINTERRUPTENABLE		0x00000020
#define SCAN		            0x00000100


#define NOCHANNEL		0x00000000
#define CHANNEL0		0x00000000
#define CHANNEL1		0x00000001
#define CHANNEL2		0x00000002
#define CHANNEL3		0x00000003
#define CHANNEL4		0x00000004
#define CHANNEL5		0x00000005
#define CHANNEL6		0x00000006
#define CHANNEL7		0x00000007
#define CHANNEL8		0x00000008
#define CHANNEL9		0x00000009
#define CHANNEL10		0x0000000A
#define CHANNEL11		0x0000000B
#define CHANNEL12		0x0000000C
#define CHANNEL13		0x0000000D
#define CHANNEL14		0x0000000E
#define CHANNEL15		0x0000000F
#define CHANNEL16		0x00000010
#define CHANNEL17		0x00000011

#endif /* ADC_PRIV_H_ */
