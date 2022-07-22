/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Mar 4, 2022                                */
/* 								Module	 : STK                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef STK_CONFIG_H_
#define STK_CONFIG_H_


/*
 * Choose clock source for the SYSTICK timer:
 *
 * Options	: STK_AHB_DIV_EIGHT
 * 			  STK_AHB
 *
 */
#define STK_CLK_SRC  STK_AHB_DIV_EIGHT  /* Default clock source for the timer */

#endif /* STK_CONFIG_H_ */
