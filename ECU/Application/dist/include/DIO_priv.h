/*
 * DIO_priv.h
 *
 *  Created on: Aug 13, 2019
 *      Author: sondo
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


/***************************************/
/******** Private Definitions **********/
/***************************************/

/******** GPIO Pin States ************/
/*		MSB			6			5			4			3			2			1			LSB		*/
/*		x(0)		x(0)		x(0)		MODE1		MODE0		PxODR		CNF1		CNF0	*/
/* Input Modes: Mode -> 00 (from 0~7) */
#define DIO_u8INPUTANALOG						0
#define DIO_u8INPUTFLOATING						1
#define DIO_u8INPUTPULLUP						6
#define DIO_u8INPUTPULLDOWN						2
/* Output Modes */
#define DIO_u8DIGITALOUTPUTPUSHPULL_10MHZ		8
#define DIO_u8DIGITALOUTPUTOPENDRAIN_10MHZ		9
#define DIO_u8AFOUTPUTPUSHPULL_10MHZ			10
#define DIO_u8AFOUTPUTOPENDRAIN_10MHZ			11
#define DIO_u8DIGITALOUTPUTPUSHPULL_2MHZ		16
#define DIO_u8DIGITALOUTPUTOPENDRAIN_2MHZ		17
#define DIO_u8AFOUTPUTPUSHPULL_2MHZ				18
#define DIO_u8AFOUTPUTOPENDRAIN_2MHZ			19
#define DIO_u8DIGITALOUTPUTPUSHPULL_50MHZ		24
#define DIO_u8DIGITALOUTPUTOPENDRAIN_50MHZ		25
#define DIO_u8AFOUTPUTPUSHPULL_50MHZ			26
#define DIO_u8AFOUTPUTOPENDRAIN_50MHZ			27


/******** GPIO Registers Structure ************/
typedef struct
{
	u32 GPIO_CRL;
	u32 GPIO_CRH;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_BRR;
	u32 GPIO_LCKR;
}GPIO;


/******** Register Base Addresses ************/
#define PORTA_BASEADDRESS	(( GPIO*)  0x40010800)
#define PORTB_BASEADDRESS	(( GPIO*)  0x40010C00)
#define PORTC_BASEADDRESS	(( GPIO*)  0x40011000)






/******** DIO Start and Stop Positions in the Configuration Array ************/
#define DIO_u8PORTALSTART		0
#define DIO_u8PORTALEND			7
#define DIO_u8PORTAHSTART		8
#define DIO_u8PORTAHEND			15
#define DIO_u8PORTBLSTART		16
#define DIO_u8PORTBLEND			23
#define DIO_u8PORTBHSTART		24
#define DIO_u8PORTBHEND			31
#define DIO_u8PORTCSTART		32
#define DIO_u8PORTCEND			34


#endif /* DIO_PRIV_H_ */
