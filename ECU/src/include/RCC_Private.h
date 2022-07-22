/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 15, 2022                               */
/* 								Module	 : RCC                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*
 * RCC Peripheral Base Address :
 *
 * RCC	:	0x40021000
 *
 * /

/* Definitions of Registers Addresses for RCC */
#define RCC_CR       *((volatile u32*)  0x40021000)
#define RCC_CFGR     *((volatile u32*)  0x40021004)
#define RCC_CIR      *((volatile u32*)  0x40021008)
#define RCC_APB2RSTR *((volatile u32*)  0x4002100C)
#define RCC_APB1RSTR *((volatile u32*)  0x40021010)
#define RCC_AHBENR   *((volatile u32*)  0x40021014)
#define RCC_APB2ENR  *((volatile u32*)  0x40021018)
#define RCC_APB1ENR  *((volatile u32*)  0x4002101C)
#define RCC_BDCR     *((volatile u32*)  0x40021020)
#define RCC_CSR      *((volatile u32*)  0x40021024)

/*Clock Types*/
#define RCC_HSI			 	0
#define RCC_HSE_RC		 	1
#define RCC_HSE_CRYSTAL	 	2
#define RCC_PLL			 	3

/*PLL Options*/
#define RCC_PLL_HSI_DIV_2   0
#define RCC_PLL_HSE_DIV_2   1
#define RCC_PLL_HSE         2

/*PLL HSE Types*/
#define RCC_PLL_HSE_CRYSTAL 0
#define RCC_PLL_HSE_RC		1

/*PLL Multiplication Factor Values*/
#define RCC_PLL_NO_CLK_FACTOR        0x00000000
#define RCC_PLL_CLK_MULTIPLE_BY_2    0x00000000
#define RCC_PLL_CLK_MULTIPLE_BY_3    0x00040000
#define RCC_PLL_CLK_MULTIPLE_BY_4    0x00080000
#define RCC_PLL_CLK_MULTIPLE_BY_5    0x000C0000
#define RCC_PLL_CLK_MULTIPLE_BY_6    0x00100000
#define RCC_PLL_CLK_MULTIPLE_BY_7    0x00140000
#define RCC_PLL_CLK_MULTIPLE_BY_8    0x00180000
#define RCC_PLL_CLK_MULTIPLE_BY_9    0x001C0000
#define RCC_PLL_CLK_MULTIPLE_BY_10   0x00200000
#define RCC_PLL_CLK_MULTIPLE_BY_11   0x00240000
#define RCC_PLL_CLK_MULTIPLE_BY_12   0x00280000
#define RCC_PLL_CLK_MULTIPLE_BY_13   0x002C0000
#define RCC_PLL_CLK_MULTIPLE_BY_14   0x00300000
#define RCC_PLL_CLK_MULTIPLE_BY_15   0x00340000
#define RCC_PLL_CLK_MULTIPLE_BY_16   0x00380000

#endif /* RCC_PRIVATE_H_ */
