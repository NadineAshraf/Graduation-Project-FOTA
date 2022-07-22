/*
 * RCC_cfg.h
 *
 *  Created on: Aug 6, 2019
 *      Author: sondo
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/* Description:	PLL Clock Output. Direct Input to USB Prescaler				*/
/*				MAKE SURE RESULT DOESN'T EXCEED 72MHZ						*/
/*				Must be configured when using the USB or using the PLLCLK	*/
/* 				as a source in SYSCLK or using it on MCO Pin, Ignore 		*/
/* 				otherwise													*/
/* Range:		RCC_u8PPLLINTERNAL8MHZ,	RCC_u8PLLINTERNAL12MHZ				*/
/*				RCC_u8PLLINTERNAL16MHZ,	RCC_u8PLLINTERNAL20MHZ				*/
/*				RCC_u8PLLINTERNAL24MHZ,	RCC_u8PLLINTERNAL24MHZ				*/
/*				RCC_u8PLLINTERNAL28MHZ,	RCC_u8PLLINTERNAL32MHZ				*/
/*				RCC_u8PLLINTERNAL36MHZ,	RCC_u8PLLINTERNAL40HZ				*/
/*				RCC_u8PLLINTERNAL44MHZ,	RCC_u8PLLINTERNAL48MHZ				*/
/*				RCC_u8PLLINTERNAL52MHZ,	RCC_u8PLLINTERNAL54MHZ				*/
/*				RCC_u8PLLINTERNAL58MHZ,	RCC_u8PLLINTERNAL64MHZ				*/
/*				RCC_u8PLLHSEX2,		RCC_u8PLLHSEX3,		RCC_u8PLLHSEX4		*/
/*				RCC_u8PLLHSEX5,		RCC_u8PLLHSEX6,		RCC_u8PLLHSEX7		*/
/*				RCC_u8PLLHSEX8,		RCC_u8PLLHSEX9,		RCC_u8PLLHSEX10		*/
/*				RCC_u8PLLHSEX11,	RCC_u8PLLHSEX12,	RCC_u8PLLHSEX13		*/
/*				RCC_u8PLLHSEX14,	RCC_u8PLLHSEX15,	RCC_u8PLLHSEX16		*/
/*				RCC_u8PLLHSE,		RCC_u8PLLHALFHSEX3,	RCC_u8PLLHALFHSEX5	*/
/*				RCC_u8PLLHALFHSEX7,	RCC_u8PLLHALFHSEX9,	RCC_u8PLLHALFHSEX11	*/
/*				RCC_u8PLLHALFHSEX13,	RCC_u8PLLHALFHSEX15					*/
#define RCC_u8PLLCLK	RCC_u8PLLHSEX9


/* Description:	HSE Clock Bypassing Enable or Disable						*/
/*				Must be configured if HSE Clock is used						*/
/* Range:		RCC_u8HSEBYPOFF,	RCC_u8SHSEBYPON							*/
#define RCC_u8HSEBYP	RCC_u8HSEBYPOFF



/* Description:	LSE Clock Bypassing Enable or Disable						*/
/*				Must be configured if LSE Clock is used						*/
/* Range:		RCC_u8LSEBYPOFF,	RCC_u8SLSEBYPON							*/
#define RCC_u8LSEBYP	RCC_u8LSEBYPOFF



/* Description:	System Clock. Direct clock to I2S2 and I2S3.				*/
/*				Must be configured 											*/
/* Range:		RCC_u8SYSCLKINTERNAL8MHZ,	RCC_u8SYSCLKHSE,				*/
/* 				RCC_u8SYSCLKPLL												*/
#define RCC_u8SYSCLK	RCC_u8SYSCLKPLL



/* Description:	AHB Bus Clock Prescaler. It is a prescaler of SYSCLK 		*/
/*				Must be configured 											*/
/* Range:		RCC_u8AHBNOPRESCALER,	RCC_u8AHBPRESCALER2,				*/
/* 				RCC_u8AHBPRESCALER4,	RCC_u8AHBPRESCALER8,				*/
/* 				RCC_u8AHBPRESCALER16,	RCC_u8AHBPRESCALER64,				*/
/* 				RCC_u8AHBPRESCALER128,	RCC_u8AHBPRESCALER256				*/
/* 				RCC_u8AHBPRESCALER512										*/
#define RCC_u8AHBPRESCALER	RCC_u8AHBNOPRESCALER



/* Description:	APB2 Bus Clock Prescaler. It is a prescaler of APB2 Clock	*/
/*				Must be configured 											*/
/* Range:		RCC_u8APB2NOPRESCALER,	RCC_u8APB2PRESCALER2,				*/
/* 				RCC_u8APB2PRESCALER4,	RCC_u8APB2PRESCALER8,				*/
/* 				RCC_u8APB2PRESCALER16										*/
#define RCC_u8APB2PRESCALER	RCC_u8APB2NOPRESCALER



/* Description:	APB1 Bus Clock Prescaler. It is a prescaler of APB1 Clock	*/
/*				MAKE SURE RESULT DOESN'T EXCEED 36MHZ						*/
/*				Must be configured 											*/
/* Range:		RCC_u8APB1NOPRESCALER,	RCC_u8APB1PRESCALER2,				*/
/* 				RCC_u8APB1PRESCALER4,	RCC_u8APB1PRESCALER8,				*/
/* 				RCC_u8APB1PRESCALER16										*/
#define RCC_u8APB1PRESCALER	RCC_u8APB1PRESCALER2



/* Description:	USB Clock Prescaler. It is a prescaler of PLL Clock			*/
/*				Used to Generate 48 MHz 									*/
/*				Must be configured 											*/
/* Range:		RCC_u8USBNOPRESCALER,	RCC_u8USBPRESCALERONEANDHALF		*/
/*				RCC_u8USBOFF												*/
#define RCC_u8USBPRESCALER	RCC_u8USBOFF



/* Description:	ADC Clock Prescaler. It is a prescaler of APB2 Clock		*/
/*				MAKE SURE RESULT DOESN'T EXCEED 14MHZ						*/
/*				Must be configured 											*/
/* Range:		RCC_u8ADCNOPRESCALER,	RCC_u8ADCPRESCALER2					*/
/*				RCC_u8ADCNOPRESCALER4,	RCC_u8ADCPRESCALER8	,RCC_u8ADCOFF	*/
#define RCC_u8ADCPRESCALER	RCC_u8ADCOFF



/* Description:	MCO Pin Output Source										*/
/*				MAKE SURE CLOCK DOESN'T EXCEED 50MHZ						*/
/*				Must be configured 											*/
/* Range:		RCC_u8MCOOFF,		RCC_u8MCOSYSCLK,	RCC_u8MCOHSICLK		*/
/*				RCC_u8MCOHSECLK,	RCC_u8MCOPLLPRESCALER2	 				*/
#define RCC_u8MCOSRC		RCC_u8MCOOFF



/* Description:	RTC Clock Source. 											*/
/*				Must be configured 											*/
/* Range:		RCC_u8RTCOFF,	RCC_u8RTCLSE,	RCC_u8RTCLSI				*/
/* 				RCC_u8RTCHSEPRESCALER128									*/
#define RCC_u8RTCCLK	RCC_u8RTCOFF



/* Description:	Clock Security System Enable or Diasble. 					*/
/*				Must be configured 											*/
/* Range:		RCC_u8CSSON, RCC_u8CSSOFF									*/
#define RCC_u8CSSONOFF	RCC_u8CSSOFF



#endif /* RCC_CFG_H_ */
