/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 15, 2022                               */
/* 								Module	 : RCC                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

								/* Interface Macros */

/* Buses options to enable or disable clock on peripherals using RCC*/
#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

							 	/* Functions Prototypes */

void RCC_vidClkInit();
void RCC_vidEnablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeripheralId);
void RCC_vidDisablePeripheralClk(u8 Copy_u8BusId , u8 Copy_u8PeripheralId);


#endif /* RCC_INTERFACE_H_ */
