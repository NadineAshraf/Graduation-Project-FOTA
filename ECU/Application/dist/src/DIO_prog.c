/*
 * DIO_prog->c
 *
 *  Created on: Aug 13, 2019
 *      Author: sondo
 */


#include "util.h"
#include "STD_Types.h"
#include "DIO_cfg.h"
#include "DIO_int.h"
#include "DIO_priv.h"



/******** GPIO Registers Structure Initialization ************/
GPIO* DIO_PORTAREG = PORTA_BASEADDRESS;
GPIO* DIO_PORTBREG = PORTB_BASEADDRESS;
GPIO* DIO_PORTCREG = PORTC_BASEADDRESS;

GPIO* DIO_apgpioRegisters[3] = { PORTA_BASEADDRESS, PORTB_BASEADDRESS, PORTC_BASEADDRESS };




/****************************************************************************************/
/* Description: Initialize DIO Peripheral-> 											 	*/
/* Input      : Void                                                                   	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void DIO_vidInit(void)
{
	u8 u8counter = 0;
	u8 u8counter2 = 0;
	u8 u8temp = 0;
	/* Array containing Pins configurations for the uC */
	u8 au8PinsCfg[]=
	{
			/* Port A */
			DIO_u8PINA0CFG,
			DIO_u8PINA1CFG,
			DIO_u8PINA2CFG,
			DIO_u8PINA3CFG,
			DIO_u8PINA4CFG,
			DIO_u8PINA5CFG,
			DIO_u8PINA6CFG,
			DIO_u8PINA7CFG,
			DIO_u8PINA8CFG,
			DIO_u8PINA9CFG,
			DIO_u8PINA10CFG,
			DIO_u8PINA11CFG,
			DIO_u8PINA12CFG,
			DIO_u8PINA13CFG,
			DIO_u8PINA14CFG,
			DIO_u8PINA15CFG,
			/* Port B */
			DIO_u8PINB0CFG,
			DIO_u8PINB1CFG,
			DIO_u8PINB2CFG,
			DIO_u8PINB3CFG,
			DIO_u8PINB4CFG,
			DIO_u8PINB5CFG,
			DIO_u8PINB6CFG,
			DIO_u8PINB7CFG,
			DIO_u8PINB8CFG,
			DIO_u8PINB9CFG,
			DIO_u8PINB10CFG,
			DIO_u8PINB11CFG,
			DIO_u8PINB12CFG,
			DIO_u8PINB13CFG,
			DIO_u8PINB14CFG,
			DIO_u8PINB15CFG,
			/* Port C */
			DIO_u8PINC13CFG,
			DIO_u8PINC14CFG,
			DIO_u8PINC15CFG,
	};

	/* Clear Previous Data in the Registers */
	for (u8counter = 0; u8counter < 3; u8counter++)
	{
		DIO_apgpioRegisters[u8counter]->GPIO_CRL &= 0x00000000;
		DIO_apgpioRegisters[u8counter]->GPIO_CRH &= 0x00000000;
		DIO_apgpioRegisters[u8counter]->GPIO_ODR &= 0x00000000;
		DIO_apgpioRegisters[u8counter]->GPIO_IDR &= 0x00000000;
	}

	/* Setting Configurations for PortA */
	for (u8counter = 0; u8counter <= 7; u8counter++)
	{
		for (u8counter2 = 0; u8counter2 < 3; u8counter2++)
			/* For PortA and PortB */
		{
			/* Set Mode, CNF and Port Configurations for Low Pins */
			//Mode Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_CRL |= ( ((au8PinsCfg[u8counter + 16*u8counter2] >> 3) & 0x03) << (u8counter*4) );
			//CNF Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_CRL |= ( (au8PinsCfg[u8counter + 16*u8counter2] & 0x03) << ((u8counter*4) + 2) );
			//ODR Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_ODR |=  ( ((au8PinsCfg[u8counter + 16*u8counter2] >> 2) & 0x01) << u8counter );

			/* Set Mode, CNF and Port Configurations for High Pins */
			//Mode Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_CRH |= ( ((au8PinsCfg[u8counter + 8 + 16*u8counter2] >> 3) & 0x03) << (u8counter*4) );
			//CNF Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_CRH |= ( (au8PinsCfg[u8counter + 8 + 16*u8counter2] & 0x03) << ((u8counter*4) + 2) );
			//ODR Configuration
			DIO_apgpioRegisters[u8counter2]->GPIO_ODR |=  ( ((au8PinsCfg[u8counter + 8 + 16*u8counter2] >> 2) & 0x01) << (u8counter + 8) );
		}
	}

	/* PortC Configurations */
	for ( u8counter = DIO_u8PORTCSTART; u8counter <= DIO_u8PORTCEND; u8counter++)
	{
		u8temp = u8counter - DIO_u8PORTCSTART;
		u8temp += 5;
		/* Set Mode, CNF and Port Configurations */
		//Mode Configuration
		DIO_PORTCREG->GPIO_CRH |= ( ((au8PinsCfg[u8counter] >> 3) & 0x03) << (u8temp*4) );
		//CNF Configuration
		DIO_PORTCREG->GPIO_CRH |= ( (au8PinsCfg[u8counter] & 0x03) << ((u8temp*4) + 2) );
		//ODR Configuration
		DIO_PORTCREG->GPIO_ODR |=  ( ((au8PinsCfg[u8counter] >> 2) & 0x01) << (u8temp + 8) );
	}

	/* Lock Port configurations */
//	for ( u8counter = 0; u8counter < 3; u8counter++)
//	{
//		DIO_apgpioRegisters[u8counter]->GPIO_LCKR |= 0x00FF;
//		DIO_apgpioRegisters[u8counter]->GPIO_LCKR |= 0x00FF;
//		DIO_apgpioRegisters[u8counter]->GPIO_LCKR |= 0x00FF;
//
//		SET_BIT(DIO_apgpioRegisters[u8counter]->GPIO_LCKR, 16);
//		CLR_BIT(DIO_apgpioRegisters[u8counter]->GPIO_LCKR, 16);
//		SET_BIT(DIO_apgpioRegisters[u8counter]->GPIO_LCKR, 16);
//		if ( GET_BIT(DIO_apgpioRegisters[u8counter]->GPIO_LCKR, 16) == 0 )
//		{
//
//		}
//	}
}




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
void DIO_vidSetPinValue(u8 u8PortIndex, u8 u8PinIndex, u8 u8Value)
{
	if ( (u8PortIndex >= DIO_u8PORTA) && (u8PortIndex <= DIO_u8PORTC) )
	{
		if ( (u8PinIndex >= DIO_u8PIN0) && (u8PinIndex <= DIO_u8PIN15) )
		{
			switch (u8Value)
			{
			case DIO_u8HIGH:
				SET_BIT(DIO_apgpioRegisters[u8PortIndex]->GPIO_ODR, u8PinIndex);
				break;
			case DIO_u8LOW:
				CLR_BIT(DIO_apgpioRegisters[u8PortIndex]->GPIO_ODR, u8PinIndex);
				break;
			default:
				break;
			}
		}
		else
		{

		}
	}
	else
	{

	}
}



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
u8 DIO_u8GetPinValue(u8 u8PortIndex, u8 u8PinIndex)
{
	u8 u8temp = 0;
	if ( (u8PortIndex >= DIO_u8PORTA) && (u8PortIndex <= DIO_u8PORTC) )
	{
		if ( (u8PinIndex >= DIO_u8PIN0) && (u8PinIndex <= DIO_u8PIN15) )
		{
			u8temp = GET_BIT(DIO_apgpioRegisters[u8PortIndex]->GPIO_IDR, u8PinIndex);
		}
		else
		{

		}
	}
	else
	{

	}
	return u8temp;
}





