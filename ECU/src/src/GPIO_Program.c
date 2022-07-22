/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 17, 2022                               */
/* 								Module	 : GPIO                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

/****************************************** Pin Level ******************************************/

/*Configures GPIO PIN Mode of Operation*/
void GPIO_vidSetPinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
	case GPIO_A:
		if(Copy_u8Pin < 8)
		{
			/*Clear the four bits concerned with the pin in GPIOA_CRL register*/
			GPIOA_CRL &= ~((0b1111) << (4*Copy_u8Pin));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOA_CRL register*/
			GPIOA_CRL |= ((Copy_u8Mode) << (4*Copy_u8Pin));
		}
		else if(Copy_u8Pin < 16)
		{
			/*Clear the four bits concerned with the pin in GPIOA_CRH register*/
			GPIOA_CRH &= ~((0b1111) << (4*(Copy_u8Pin-8)));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOA_CRH register*/
			GPIOA_CRH |= ((Copy_u8Mode) << (4*(Copy_u8Pin-8)));
		}
		else
		{
			/*Return error*/
		}
		break;
	case GPIO_B:
		if(Copy_u8Pin < 8)
		{
			/*Clear the four bits concerned with the pin in GPIOB_CRL register*/
			GPIOB_CRL &= ~((0b1111) << (4*Copy_u8Pin));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOB_CRL register*/
			GPIOB_CRL |= ((Copy_u8Mode) << (4*Copy_u8Pin));
		}
		else if(Copy_u8Pin < 16)
		{
			/*Clear the four bits concerned with the pin in GPIOB_CRH register*/
			GPIOB_CRH &= ~((0b1111) << (4*(Copy_u8Pin-8)));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOB_CRH register*/
			GPIOB_CRH |= ((Copy_u8Mode) << (4*(Copy_u8Pin-8)));
		}
		else
		{
			/*Return error*/
		}
		break;
	case GPIO_C:
		if(Copy_u8Pin < 8)
		{
			/*Clear the four bits concerned with the pin in GPIOC_CRL register*/
			GPIOC_CRL &= ~((0b1111) << (4*Copy_u8Pin));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOC_CRL register*/
			GPIOC_CRL |= ((Copy_u8Mode) << (4*Copy_u8Pin));
		}
		else if(Copy_u8Pin < 16)
		{
			/*Clear the four bits concerned with the pin in GPIOC_CRH register*/
			GPIOC_CRH &= ~((0b1111) << (4*(Copy_u8Pin-8)));
			/*Set the pin mode through configuring the four bits concerned with the pin in GPIOC_CRH register*/
			GPIOC_CRH |= ((Copy_u8Mode) << (4*(Copy_u8Pin-8)));
		}
		else
		{
			/*Return error*/
		}
		break;
//	default:
//		/*Return Error*/
	}
}
/*Sets A Value [(LOW or OD_LOW) or (HIGH or OD_HIGH)] to A Pin*/
void GPIO_vidSetPinVal(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	if(Copy_u8Pin < 16)
	{
		switch(Copy_u8Port)
		{
		case GPIO_A:
			if(Copy_u8Value == GPIO_HIGH || Copy_u8Value == GPIO_OD_HIGH)
			{
				/*Set the pin to HIGH or OD_HIGH by setting the pin to 1 in GPIOA_BSRR*/
				GPIOA_BSRR = (1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW || Copy_u8Value == GPIO_OD_LOW)
			{
				/*Set the pin to LOW or OD_LOW by setting the pin to 1 in GPIOA_BRR*/
				GPIOA_BRR = (1 << Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_B:
			if(Copy_u8Value == GPIO_HIGH || Copy_u8Value == GPIO_OD_HIGH)
			{
				/*Set the pin to HIGH or OD_HIGH by setting the pin to 1 in GPIOB_BSRR*/
				GPIOB_BSRR = (1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW || Copy_u8Value == GPIO_OD_LOW)
			{
				/*Set the pin to LOW or OD_LOW by setting the pin to 1 in GPIOB_BRR*/
				GPIOB_BRR = (1 << Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_C:
			if(Copy_u8Value == GPIO_HIGH || Copy_u8Value == GPIO_OD_HIGH)
			{
				/*Set the pin to HIGH or OD_HIGH by setting the pin to 1 in GPIOC_BSRR*/
				GPIOC_BSRR = (1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW || Copy_u8Value == GPIO_OD_LOW)
			{
				/*Set the pin to LOW or OD_LOW by setting the pin to 1 in GPIOC_BRR*/
				GPIOC_BRR = (1 << Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
//		default:
//			/*Return Error*/
		}
	}
	else
	{
		/*Return Error*/
	}

}
/*Connects An Internal Pull_up or Pull_down Resistor to A Pin*/
void GPIO_vidSetPinPullUpOrDown(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	if(Copy_u8Pin < 16)
	{
		switch(Copy_u8Port)
		{
		case GPIO_A:
			if(Copy_u8Value == GPIO_PULLUP)
			{
				/*Connect the pin to an internal pull-up resistor by setting the pin to 1 in GPIOA_ODR*/
				SET_BIT(GPIOA_ODR , Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_PULLDOWN)
			{
				/*Connect the pin to an internal pull-down resistor by setting the pin to 0 in GPIOA_ODR*/
				CLR_BIT(GPIOA_ODR , Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_B:
			if(Copy_u8Value == GPIO_PULLUP)
			{
				/*Connect the pin to an internal pull-up resistor by setting the pin to 1 GPIOB_ODR*/
				SET_BIT(GPIOB_ODR , Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_PULLDOWN)
			{
				/*Connect the pin to an internal pull-down resistor by setting the pin to 0 GPIOB_ODR*/
				CLR_BIT(GPIOB_ODR , Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_C:
			if(Copy_u8Value == GPIO_PULLUP)
			{
				/*Connect the pin to an internal pull-up resistor by setting the pin to 1 GPIOC_ODR*/
				SET_BIT(GPIOC_ODR , Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_PULLDOWN)
			{
				/*Connect the pin to an internal pull-down resistor by setting the pin to 0 GPIOC_ODR*/
				CLR_BIT(GPIOC_ODR , Copy_u8Pin);
			}
			else
			{
				/*Return Error*/
			}
			break;
//		default:
//			/*Return Error*/
		}
	}
	else
	{
		/*Return Error*/
	}

}
///*Locks the Configuration Mode on A Pin*/
//void GPIO_vidLCKPin(u8 Copy_u8Port , u8 Copy_u8Pin)
//{
//
//}
/*Gets the Value on the Pin*/
u8 GPIO_vidGetPinVal(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 local_u8PinVal = 0 ;
	if(Copy_u8Pin < 16)
	{
		switch(Copy_u8Port)
		{
		case GPIO_A:
			/*Get the value on the pin from GPIOA_IDR*/
			local_u8PinVal = GET_BIT(GPIOA_IDR , Copy_u8Pin);
			break;
		case GPIO_B:
			/*Get the value on the pin from GPIOB_IDR*/
			local_u8PinVal = GET_BIT(GPIOB_IDR , Copy_u8Pin);
			break;
		case GPIO_C:
			/*Get the value on the pin from GPIOC_IDR*/
			local_u8PinVal = GET_BIT(GPIOC_IDR , Copy_u8Pin);
			break;
//		default:
//			/*Return Error*/
		}
	}
	else
	{
		/*Return Error*/
	}
	return local_u8PinVal;
}

/****************************************** Port Level ******************************************/

/*Configures GPIO PORT Mode of Operation*/
void GPIO_vidSetPortMode(u8 Copy_u8Port , u8 Copy_u8Position , u32 Copy_u8Mode)
{
	switch(Copy_u8Port)
		{
		case GPIO_A:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				GPIOA_CRL = Copy_u8Mode;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				GPIOA_CRH = Copy_u8Mode;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_B:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				GPIOB_CRL = Copy_u8Mode;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				GPIOB_CRH = Copy_u8Mode;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_C:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				GPIOC_CRL = Copy_u8Mode;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				GPIOC_CRH = Copy_u8Mode;
			}
			else
			{
				/*Return Error*/
			}
			break;
//		default:
//			/*Return Error*/
		}
}
/*Sets A Value to A Port*/
void GPIO_vidSetPortVal(u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value)
{
	switch(Copy_u8Port)
		{
		case GPIO_A:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Set the first eight pins of port A to a value*/
				GPIOA_ODR = (GPIOA_ODR & 0xFF00) | (Copy_u8Value & 0x00FF) ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Set the last eight pins of port A to a value*/
				GPIOA_ODR = (GPIOA_ODR & 0x00FF) | (Copy_u8Value & 0xFF00) ;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_B:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Set the first eight pins of port B to a value*/
				GPIOB_ODR = (GPIOB_ODR & 0xFF00) | (Copy_u8Value & 0x00FF) ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Set the last eight pins of port B to a value*/
				GPIOB_ODR = (GPIOB_ODR & 0x00FF) | (Copy_u8Value & 0xFF00) ;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_C:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Set the first eight pins of port C to a value*/
				GPIOC_ODR = (GPIOC_ODR & 0xFF00) | (Copy_u8Value & 0x00FF) ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Set the last eight pins of port C to a value*/
				GPIOC_ODR = (GPIOC_ODR & 0x00FF) | (Copy_u8Value & 0xFF00) ;
			}
			else
			{
				/*Return Error*/
			}
			break;
//		default:
//			/*Return Error*/
		}

}
/*Gets the Value on the Port*/
u16 GPIO_u16GetPortValue(u8 Copy_u8Port , u8 Copy_u8Position)
{
	u16 local_u16PortVal = 0;
	switch(Copy_u8Port)
		{
		case GPIO_A:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Get the value on first eight pins of port A*/
				local_u16PortVal = GPIOA_IDR & 0x00FF ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Get the value on last eight pins of port A*/
				local_u16PortVal = GPIOA_IDR & 0xFF00 ;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_B:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Get the value on first eight pins of port B*/
				local_u16PortVal = GPIOB_IDR & 0x00FF ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Get the value on last eight pins of port B*/
				local_u16PortVal = GPIOB_IDR & 0xFF00 ;
			}
			else
			{
				/*Return Error*/
			}
			break;
		case GPIO_C:
			if(Copy_u8Position == GPIO_PORT_LOW)
			{
				/*Get the value on first eight pins of port C*/
				local_u16PortVal = GPIOC_IDR & 0x00FF ;
			}
			else if(Copy_u8Position == GPIO_PORT_HIGH)
			{
				/*Get the value on last eight pins of port C*/
				local_u16PortVal = GPIOC_IDR & 0xFF00 ;
			}
			else
			{
				/*Return Error*/
			}
			break;
//		default:
//			/*Return Error*/
		}
	return local_u16PortVal;
}


