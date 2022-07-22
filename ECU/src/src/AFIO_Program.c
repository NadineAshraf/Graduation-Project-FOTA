/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 26, 2022                               */
/* 								Module	 : AFIO                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_Interface.h"
#include "AFIO_Private.h"
#include "AFIO_Config.h"

/* Configure EXTI Line and Port To Which EXTI Line is Mapped */
void AFIO_vidSetEXTIConfiguration(u8 Copy_u8EXTILine , u8 Copy_u8PortMap)
{
	if(Copy_u8EXTILine < 4)
	{
		AFIO_EXTICR1 &= ~((0b1111) << 4*Copy_u8EXTILine);
		AFIO_EXTICR1 &= ~((Copy_u8PortMap) << 4*Copy_u8EXTILine);
	}
	else if(Copy_u8EXTILine < 8)
	{
		Copy_u8EXTILine -= 4 ;
		AFIO_EXTICR2 &= ~((0b1111) << 4*Copy_u8EXTILine);
		AFIO_EXTICR2 &= ~((Copy_u8PortMap) << 4*Copy_u8EXTILine);
	}
	else if(Copy_u8EXTILine < 12)
	{
		Copy_u8EXTILine -= 8 ;
		AFIO_EXTICR2 &= ~((0b1111) << 4*Copy_u8EXTILine);
		AFIO_EXTICR2 &= ~((Copy_u8PortMap) << 4*Copy_u8EXTILine);
	}
	else if(Copy_u8EXTILine < 16)
	{
		Copy_u8EXTILine -= 12 ;
		AFIO_EXTICR2 &= ~((0b1111) << 4*Copy_u8EXTILine);
		AFIO_EXTICR2 &= ~((Copy_u8PortMap) << 4*Copy_u8EXTILine);
	}
	else
	{
		/* Return Error */
	}
}
/* Remap STMF103 Pins To Act For Specific Alternative Functions Rather Than I/O (Not finished yet) */
void AFIO_vidAlternativeFunctionRemap(u8 Copy_u8FunctionRemapType,u32 Copy_u32FunctionRemapVal)
{
	/* Check Remap Type */
	switch(Copy_u8FunctionRemapType)
	{
	case AFIO_CAN_REMAP:
		/* Reset CAN Remap */
		AFIO_MAPR &= AFIO_CAN_REMAP_RESET;
		/* Set Specified CAN Remap Value */
		AFIO_MAPR |= Copy_u32FunctionRemapVal;
		break;
	}
	/* Rest Of Cases To Be Handled Later */
}

