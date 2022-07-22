/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 15, 2022                               */
/* 								Module	 : RCC                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
 * Choose clock type for the system:
 *
 * Options	: RCC_HSI
 * 			  RCC_HSE_RC
 * 			  RCC_HSE_CRYSTAL
 * 			  RCC_PLL
 */
#define RCC_CLK_TYPE  RCC_HSE_CRYSTAL   		/* Default --> High Speed External Crystal Clock */

/*
 * In case RCC_PLL is chosen, you need to specify PLL's input clock:
 *
 * Options	: RCC_PLL_HSI_DIV_2
 * 			  RCC_PLL_HSE_DIV_2
 * 			  RCC_PLL_HSE
 * If either RCC_PLL_HSE_DIV_2 or RCC_PLL_HSE are chosen, you need to specify PLL's HSE input type
 *
 * Options  : RCC_PLL_HSE_CRYSTAL
 * 			  RCC_PLL_HSE_RC
 */
#if RCC_CLK_TYPE == RCC_PLL

#define RCC_PLL_INPUT  RCC_PLL_HSE_DIV_2 		/* Default --> High Speed External Clock Divided by 2*/

#if (RCC_PLL_INPUT == RCC_PLL_HSE_DIV_2 || RCC_PLL_INPUT == RCC_PLL_HSE)
#define RCC_PLL_HSE_TYPE  RCC_PLL_HSE_CRYSTAL	/* Default --> High Speed External Crystal Clock as PLL Input*/
#endif

#endif

/*
 * In case RCC_PLL is chosen, PLL multiplication factor values can be
 *
 * Options : RCC_PLL_NO_CLK_FACTOR
 * 			 RCC_PLL_CLK_MULTIPLE_BY_2
 * 			 RCC_PLL_CLK_MULTIPLE_BY_3
 * 			 RCC_PLL_CLK_MULTIPLE_BY_4
 * 			 RCC_PLL_CLK_MULTIPLE_BY_5
 * 			 RCC_PLL_CLK_MULTIPLE_BY_6
 * 			 RCC_PLL_CLK_MULTIPLE_BY_7
 * 			 RCC_PLL_CLK_MULTIPLE_BY_8
 * 			 RCC_PLL_CLK_MULTIPLE_BY_9
 * 			 RCC_PLL_CLK_MULTIPLE_BY_10
 * 			 RCC_PLL_CLK_MULTIPLE_BY_11
 * 			 RCC_PLL_CLK_MULTIPLE_BY_12
 * 			 RCC_PLL_CLK_MULTIPLE_BY_13
 * 			 RCC_PLL_CLK_MULTIPLE_BY_14
 * 			 RCC_PLL_CLK_MULTIPLE_BY_15
 * 			 RCC_PLL_CLK_MULTIPLE_BY_16
 *
 * Caution :The PLL output frequency must not exceed 72 MHz
 */
#if RCC_CLK_TYPE == RCC_PLL
#define RCC_PLL_MUL_FACTOR_VAL RCC_PLL_NO_CLK_FACTOR 		/* Default --> No Factor Multiplied By The PLL Clock*/
#endif
#endif /* RCC_CONFIG_H_ */
