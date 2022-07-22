/*
 * DIO_int.h
 *
 *  Created on: Aug 13, 2019
 *      Author: sondo
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


//extern AFIO* AFIO_REG;
#define AFIO_BASEADDRESS    (( strAFIO*)  0x40010000)


/******** AFIO Registers Structure ************/
typedef struct
{
  u32 EVCR;
  u32 MAPR;
  u32 EXTICR[4];
  u32 RESERVED0;
  u32 MAPR2;
} strAFIO;


/*****************************************/
/*********Public Definitions*************/
/*****************************************/


/* DIO Ports Definitions */
#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2


/* DIO Pins Definitions */
#define DIO_u8PIN0		0
#define DIO_u8PIN1		1
#define DIO_u8PIN2		2
#define DIO_u8PIN3		3
#define DIO_u8PIN4		4
#define DIO_u8PIN5		5
#define DIO_u8PIN6		6
#define DIO_u8PIN7		7
#define DIO_u8PIN8		8
#define DIO_u8PIN9		9
#define DIO_u8PIN10		10
#define DIO_u8PIN11		11
#define DIO_u8PIN12		12
#define DIO_u8PIN13		13
#define DIO_u8PIN14		14
#define DIO_u8PIN15		15


/* DIO Values */
#define DIO_u8LOW		0
#define DIO_u8HIGH		1


/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Initialize DIO Peripheral. 											 	*/
/* Input      : Void                                                                   	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void DIO_vidInit(void);



/****************************************************************************************/
/* Description: Set Pin Value 														 	*/
/* Input      : u8 u8PortIndex                                                         	*/
/*              Description: Port containing the Pin			                        */
/* 				Range: 	DIO_u8PORTA,	DIO_u8PORTB, DIO_u8PORTC						*/
/*				u8 u8PinIndex															*/
/*              Description: Pin to Set the Value to				                    */
/* 				Range: 	DIO_u8PIN0 ~ DIO_u8PIN15										*/
/*				u8 u8Value																*/
/*              Description: Value to Set the Pin					                    */
/* 				Range: 	DIO_u8HIGH , DIO_u8LOW											*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void DIO_vidSetPinValue(u8 u8PortIndex, u8 u8PinIndex, u8 u8Value);



/****************************************************************************************/
/* Description: Get Pin Value 														 	*/
/* Input      : u8 u8PortIndex                                                         	*/
/*              Description: Port containing the Pin			                        */
/* 				Range: 	DIO_u8PORTA,	DIO_u8PORTB, DIO_u8PORTC						*/
/*				u8 u8PinIndex															*/
/*              Description: Pin to Get the Value of				                    */
/* 				Range: 	DIO_u8PIN0 ~ DIO_u8PIN15										*/
/* Output     : u8                                                                   	*/
/*				Description: Value of the Pin											*/
/*				Range: DIO_u8HIGH, DIO_u8LOW											*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u8 DIO_u8GetPinValue(u8 u8PortIndex, u8 u8PinIndex);

#endif /* DIO_INT_H_ */
