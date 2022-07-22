/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Mar 4, 2022                                */
/* 								Module	 : STK                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

/*
 * SYSTICK Peripheral Base Address :
 *
 * SYSTICK	: 0xE000E010
 */

/*Definitions of Registers Addresses for STK*/
#define STK_CTRL   *((volatile u32*) 0xE000E010)
#define STK_LOAD   *((volatile u32*) 0xE000E014)
#define STK_VAL    *((volatile u32*) 0xE000E018)
#define STK_CALIB  *((volatile u32*) 0xE000E01C)

/*SYSTICK Clock Source*/
#define STK_AHB_DIV_EIGHT  0
#define STK_AHB  		   1

/*SYSTICK INTERVAL MODE*/
#define STK_INTERVAL_SINGLE    0
#define STK_INTERVAL_PERIODIC  1

#endif /* STK_PRIVATE_H_ */
