/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 17, 2022                               */
/* 								Module	 : GPIO                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/***********************************************************************************************************/
/* 	Note	: In STM32F103C8T6 there are only three GPIO ports and number of pins in each GPIO port is     */
/*			  as follows:                                                                                  */
/* 																								   		   */
/* 	- GPIO A (Port A) --> 16 pins (From PIN_0 to PIN_15)                                                   */
/* 	- GPIO B (Port B) --> 16 pins (From PIN_0 to PIN_15)                                                   */
/* 	- GPIO C (Port C) --> 3 pins  (From PIN_13 to PIN_15)                                                  */
/*                                                                                                         */
/* 	Note	: The number of ports and pins in each port varies depending on STM version used    		   */
/*                                                                                                         */
/***********************************************************************************************************/

							  	 /* Interface Macros */

/*Available Ports*/
#define GPIO_A 0
#define GPIO_B 1
#define GPIO_C 2

/*Available Pins*/
#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7
#define PIN_8  8
#define PIN_9  9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15

/*GPIO Modes of Operation*/

							/*GPIO Input Modes*/

/*******************************Pin Level*******************************/
#define GPIO_INPUT_ANALOG          						0b0000
#define GPIO_INPUT_FLOATING        						0b0100
#define GPIO_INPUT_PULLDOWN_PULLUP 						0b1000

/*******************************Port Level*******************************/
#define GPIO_PORT_INPUT_ANALOG          				(0x11111111 * GPIO_INPUT_ANALOG         )
#define GPIO_PORT_INPUT_FLOATING        				(0x11111111 * GPIO_INPUT_FLOATING       )
#define GPIO_PORT_INPUT_PULLDOWN_PULLUP 				(0x11111111 * GPIO_INPUT_PULLDOWN_PULLUP)

					/*GPIO Output Modes at 10 MHz Speed*/

/*******************************Pin Level*******************************/
#define GPIO_OUTPUT_SPEED_10MHZ_PUSHPULL				0b0001
#define GPIO_OUTPUT_SPEED_10MHZ_OPENDRAIN				0b0101
#define GPIO_OUTPUT_SPEED_10MHZ_AF_PUSHPULL     		0b1001
#define GPIO_OUTPUT_SPEED_10MHZ_AF_OPENDRAIN			0b1101

/*******************************Port Level*******************************/
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_PUSHPULL			(0x11111111 * GPIO_OUTPUT_SPEED_10MHZ_PUSHPULL	  )
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_OPENDRAIN			(0x11111111 * GPIO_OUTPUT_SPEED_10MHZ_OPENDRAIN	  )
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_AF_PUSHPULL     	(0x11111111 * GPIO_OUTPUT_SPEED_10MHZ_AF_PUSHPULL )
#define GPIO_PORT_OUTPUT_SPEED_10MHZ_AF_OPENDRAIN		(0x11111111 * GPIO_OUTPUT_SPEED_10MHZ_AF_OPENDRAIN)

					/*GPIO Output Modes at 2 MHz Speed*/

/*******************************Pin Level*******************************/
#define GPIO_OUTPUT_SPEED_2MHZ_PUSHPULL					0b0010
#define GPIO_OUTPUT_SPEED_2MHZ_OPENDRAIN       			0b0110
#define GPIO_OUTPUT_SPEED_2MHZ_AF_PUSHPULL      		0b1010
#define GPIO_OUTPUT_SPEED_2MHZ_AF_OPENDRAIN     		0b1110

/*******************************Port Level*******************************/
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_PUSHPULL			(0x11111111 * GPIO_OUTPUT_SPEED_2MHZ_PUSHPULL	 )
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_OPENDRAIN        	(0x11111111 * GPIO_OUTPUT_SPEED_2MHZ_OPENDRAIN   )
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_AF_PUSHPULL      	(0x11111111 * GPIO_OUTPUT_SPEED_2MHZ_AF_PUSHPULL )
#define GPIO_PORT_OUTPUT_SPEED_2MHZ_AF_OPENDRAIN     	(0x11111111 * GPIO_OUTPUT_SPEED_2MHZ_AF_OPENDRAIN)

					/*GPIO Output Modes at 50 MHz Speed*/

/*******************************Pin Level*******************************/
#define GPIO_OUTPUT_SPEED_50MHZ_PUSHPULL        		0b0011
#define GPIO_OUTPUT_SPEED_50MHZ_OPENDRAIN       		0b0111
#define GPIO_OUTPUT_SPEED_50MHZ_AF_PUSHPULL     		0b1011
#define GPIO_OUTPUT_SPEED_50MHZ_AF_OPENDRAIN    		0b1111

/*******************************Port Level*******************************/
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_PUSHPULL        	(0x11111111 * GPIO_OUTPUT_SPEED_50MHZ_PUSHPULL    )
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_OPENDRAIN       	(0x11111111 * GPIO_OUTPUT_SPEED_50MHZ_OPENDRAIN   )
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_AF_PUSHPULL     	(0x11111111 * GPIO_OUTPUT_SPEED_50MHZ_AF_PUSHPULL )
#define GPIO_PORT_OUTPUT_SPEED_50MHZ_AF_OPENDRAIN       (0x11111111 * GPIO_OUTPUT_SPEED_50MHZ_AF_OPENDRAIN)

/*Possible Pin Values in Output Modes of Various Speeds (Frequencies)*/

					/*Push-Pull Mode*/

#define GPIO_HIGH		1	/*Set MC VCC on the Pin*/
#define GPIO_LOW		0	/*Set 0V on the Pin*/

					/*Open-Drain Mode*/

#define GPIO_OD_HIGH	1	/*Make the MC Pin Floating*/
#define GPIO_OD_LOW		0	/*Set 0V on the Pin*/

/*Possible Pin Values in PULL_UP or PULL_DOWN Input Mode (PULL_UP Resistor or PULL_DOWN Resistor)*/
#define GPIO_PULLUP		1
#define GPIO_PULLDOWN	0

/*Common Port Values (FULL_HIGH or FULL_LOW) in PUSHULL Output Modes of Various Speeds (Frequencies)*/
#define GPIO_FULL_HIGH	0xFFFF
#define GPIO_FULL_LOW	0x0000

/*Positions of Pins in Port*/
#define GPIO_PORT_HIGH  1
#define GPIO_PORT_LOW   0

								 /* Functions Prototypes */

/*Pin Level*/
void GPIO_vidSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);
void GPIO_vidSetPinVal(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
void GPIO_vidSetPinPullUpOrDown(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);
//void GPIO_vidLCKPin(u8 Copy_u8Port , u8 Copy_u8Pin);
u8 GPIO_vidGetPinVal(u8 Copy_u8Port , u8 Copy_u8Pin);

/*Port Level*/
void GPIO_vidSetPortMode(u8 Copy_u8Port , u8 Copy_u8Position , u32 Copy_u8Mode);
void GPIO_vidSetPortVal(u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value);
u16  GPIO_u16GetPortValue(u8 Copy_u8Port , u8 Copy_u8Position);

#endif /* GPIO_INTERFACE_H_ */
