/*
 * RCC_priv.h
 *
 *  Created on: Aug 6, 2019
 *      Author: sondo
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/***************************************/
/******** Private Definitions **********/
/***************************************/

/******** Register Declarations ************/
#define RCC_CR			(*((volatile u32*)  0x40021000))
#define RCC_CFGR		(*((volatile u32*)  0x40021004))
#define RCC_CIR			(*((volatile u32*)  0x40021008))
#define RCC_APB2RSTR	(*((volatile u32*)  0x4002100C))
#define RCC_APB1RSTR	(*((volatile u32*)  0x40021010))
#define RCC_AHBENR		(*((volatile u32*)  0x40021014))
#define RCC_APB2ENR		(*((volatile u32*)  0x40021018))
#define RCC_APB1ENR		(*((volatile u32*)  0x4002101C))
#define RCC_BDCR		(*((volatile u32*)  0x40021020))
#define RCC_CSR			(*((volatile u32*)  0x40021024))


/*********** RCC_CR Register Bits *******************/
#define HSION			0
#define HSIRDY			1
#define HSITRIM			3
#define HSITRIM0		3
#define HSITRIM1		4
#define HSITRIM2		5
#define HSITRIM3		6
#define HSITRIM4		7
#define HSICAL			8
#define HSICAL0			8
#define HSICAL1			9
#define HSICAL2			10
#define HSICAL3			11
#define HSICAL4			12
#define HSICAL5			13
#define HSICAL6			14
#define HSICAL7			15
#define HSEON			16
#define HSERDY			17
#define HSEBYP			18
#define CSSON			19
#define	PLLON			24
#define PLLRDY			25


/*********** RCC_CFGR Register Bits *******************/
#define SW				0
#define SW0				0
#define SW1				1
#define SWS				2
#define SWS0			2
#define SWS1			3
#define HPRE			4
#define HPRE0			4
#define HPRE1			5
#define HPRE2			6
#define HPRE3			7
#define PPRE1			8
#define PPRE10			8
#define PPRE11			9
#define PPRE12			10
#define PPRE2			11
#define PPRE20			11
#define PPRE21			12
#define PPRE22			13
#define ADCPRE			14
#define ADCPRE0			14
#define ADCPRE1			15
#define PLLSRC			16
#define PLLXTPRE		17
#define PLLMUL			18
#define	PLLMUL0			18
#define PLLMUL1			19
#define	PLLMUL2			20
#define PLLMUL3			21
#define USBPRE			22
#define MCO				24
#define MCO0			24
#define MCO1			25
#define MCO2			26


/*********** RCC_CIR Register Bits *******************/
#define LSIRDYF			0
#define LSERDYF			1
#define HSIRDYF			2
#define HSERDYF			3
#define PLLRDYF			4
#define CSSF			7
#define LSIRDYIE		8
#define LSERDYIE		9
#define HSIRDYIE		10
#define HSERDYIE		11
#define PLLRDYIE		12
#define LSIRDYC			16
#define LSERDYC			17
#define HSIRDYC			18
#define HSERDYC			19
#define PLLRDYC			20
#define CSSC			23


/*********** RCC_BDCR Register Bits *******************/
#define LSEON			0
#define LSERDY			1
#define LSEBYP			2
#define RTCSEL			8
#define RTCSEL0			8
#define RTCSEL1			9
#define RTCEN			15
#define BDRST			16


/*********** RCC_CSR Register Bits *******************/
#define LSION			0
#define LSIRDY			1
#define RMVF			24
#define PINRSTF			26
#define PORRSTF			27
#define SFTRSTF			28
#define IWDGRSTF		29
#define WWDGRSTF		30
#define LPWRSTF			31


/*********** AHB/APB1/APB2 Start and End Values *******************/
#define u8APB2_START	0
#define u8APB2_END		31

#define u8APB1_START	32
#define u8APB1_END		63

#define u8AHB_START		64
#define u8AHB_END		95


/*********** PLL Clock Output Values Definitions *******************/
/*	MSB			6			5			4			3			2			1			LSB			*/
/*	0			0			PLLXTPRE	PLLSRC		PLLMUL3		PLLMUL2		PLLMUL1		PLLMUL0		*/
// HSI/2 as PLL input, PLLXTPRE -> x(0) , PLLSRC -> 0
#define RCC_u8PPLLINTERNAL8MHZ		0
#define RCC_u8PLLINTERNAL12MHZ		1
#define RCC_u8PLLINTERNAL16MHZ		2
#define RCC_u8PLLINTERNAL20MHZ		3
#define RCC_u8PLLINTERNAL24MHZ		4
#define RCC_u8PLLINTERNAL28MHZ		5
#define RCC_u8PLLINTERNAL32MHZ		6
#define RCC_u8PLLINTERNAL36MHZ		7
#define RCC_u8PLLINTERNAL40HZ		8
#define RCC_u8PLLINTERNAL44MHZ		9
#define RCC_u8PLLINTERNAL48MHZ		10
#define RCC_u8PLLINTERNAL52MHZ		11
#define RCC_u8PLLINTERNAL54MHZ		12
#define RCC_u8PLLINTERNAL58MHZ		13
#define RCC_u8PLLINTERNAL64MHZ		14
//HSE as Clock Input, PLLXTPRE -> 0, PLLSRC -> 1
#define RCC_u8PLLHSEX2				16
#define RCC_u8PLLHSEX3				17
#define RCC_u8PLLHSEX4				18
#define RCC_u8PLLHSEX5				19
#define RCC_u8PLLHSEX6				20
#define RCC_u8PLLHSEX7				21
#define RCC_u8PLLHSEX8				22
#define RCC_u8PLLHSEX9				23
#define RCC_u8PLLHSEX10				24
#define RCC_u8PLLHSEX11				25
#define RCC_u8PLLHSEX12				26
#define RCC_u8PLLHSEX13				27
#define RCC_u8PLLHSEX14				28
#define RCC_u8PLLHSEX15				30
#define RCC_u8PLLHSEX16				31
// HSE/2 as Clock Input, PLLXTPRE -> 1, PLLSRC -> 1
#define RCC_u8PLLHSE				48
#define RCC_u8PLLHALFHSEX3			49
#define RCC_u8PLLHALFHSEX5			51
#define RCC_u8PLLHALFHSEX7			53
#define RCC_u8PLLHALFHSEX9			55
#define RCC_u8PLLHALFHSEX11			57
#define RCC_u8PLLHALFHSEX13			59
#define RCC_u8PLLHALFHSEX15			61


/*********** HSE Clock Bypassing Values Definitions *******************/
#define RCC_u8HSEBYPOFF				0
#define	RCC_u8HSEBYPON				1


/*********** LSE Clock Bypassing Values Definitions *******************/
#define RCC_u8LSEBYPOFF				0
#define	RCC_u8LSEBYPON				1



/*********** System Clock Values Definitions *******************/
#define RCC_u8SYSCLKINTERNAL8MHZ	0
#define	RCC_u8SYSCLKHSE				1
#define RCC_u8SYSCLKPLL				2


/*********** AHB Clock Prescaler Values Definitions *******************/
#define RCC_u8AHBNOPRESCALER		0
#define RCC_u8AHBPRESCALER2			8
#define RCC_u8AHBPRESCALER4			9
#define RCC_u8AHBPRESCALER8			10
#define RCC_u8AHBPRESCALER16		11
#define RCC_u8AHBPRESCALER64		12
#define RCC_u8AHBPRESCALER128		13
#define RCC_u8AHBPRESCALER256		14
#define RCC_u8AHBPRESCALER512		15


/*********** APB1 Clock Prescaler Values Definitions *******************/
#define RCC_u8APB1NOPRESCALER			0
#define RCC_u8APB1PRESCALER2			4
#define RCC_u8APB1PRESCALER4			5
#define RCC_u8APB1PRESCALER8			6
#define RCC_u8APB1PRESCALER16			7


/*********** APB2 Clock Prescaler Values Definitions *******************/
#define RCC_u8APB2NOPRESCALER			0
#define RCC_u8APB2PRESCALER2			4
#define RCC_u8APB2PRESCALER4			5
#define RCC_u8APB2PRESCALER8			6
#define RCC_u8APB2PRESCALER16			7



/*********** USB Clock Prescaler Values Definitions *******************/
#define RCC_u8USBNOPRESCALER			0
#define RCC_u8USBPRESCALERONEANDHALF	1
#define RCC_u8USBOFF					2



/*********** ADC Clock Prescaler Values Definitions *******************/
#define RCC_u8ADCNOPRESCALER			0
#define RCC_u8ADCPRESCALER2				1
#define RCC_u8ADCPRESCALER4				2
#define RCC_u8ADCPRESCALER8				3
#define RCC_u8ADCOFF					4


/*********** MCO Source Values Definitions *******************/
#define RCC_u8MCOOFF					0
#define RCC_u8MCOSYSCLK					4
#define RCC_u8MCOHSICLK					5
#define RCC_u8MCOHSECLK					6
#define RCC_u8MCOPLLPRESCALER2			7



/*********** RTC Clock Source Values Definitions *******************/
#define RCC_u8RTCOFF					0
#define RCC_u8RTCLSE					1
#define RCC_u8RTCLSI					2
#define RCC_u8RTCHSEPRESCALER128		3



/*********** CSS Enable/Disable Values Definitions *******************/
#define RCC_u8CSSOFF				0
#define RCC_u8CSSON					1

#endif /* RCC_PRIV_H_ */
