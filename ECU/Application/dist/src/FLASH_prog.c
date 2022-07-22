/*
 * FLASH_prog.c
 *
 *  Created on: Sep 26, 2019
 *      Author: sondo
 */

#include "util.h"
#include "STD_Types.h"
//#include "DEBUG_int.h"
#include "FLASH_priv.h"
#include "FLASH_cfg.h"
#include "FLASH_int.h"


/*****************************************/
/***********Public Variables**************/
/*****************************************/
const u8 u8Version[]= "V01";


/*****************************************/
/***********Public Functions**************/
/*****************************************/


/****************************************************************************************/
/* Description: Log the Driver Version													*/
/* Input      : Void																	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
//void Flash_vidGetVersionInfo(void)
//{
//	Debug_LogVersion(u8Version);
//}


/****************************************************************************************/
/* Description: Write one word in the Flash Memory										*/
/* Input      : u32* pu32address		                                	            */
/*              Description: Address to write in the flash		                        */
/*				u32 u32value															*/
/*              Description: Word to write in flash			                 		    */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteWord(u32* pu32address, u32 u32value)
{
	u16* address = (u16*)pu32address;
	/* Perform Unlock Sequence */
	if (GET_BIT(FLASH_CR,LOCK) == FLASH_u8LOCKED)
	{
		FLASH_KEYR = FLASH_u32KEY1;
		FLASH_KEYR = FLASH_u32KEY2;
	}
	/* Set Programming Bit */
	SET_BIT(FLASH_CR, PG);
	/* Put first half-word int he address */
	*address = (u16)(u32value & HALFWORDMASK);
	/* Wait for the busy flag */
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
	/* Write second half-word in the address */
	*(address+1) = (u16)(u32value >> HALFWORDOFFSET);
	/* Wait for busy bit */
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
	/* Reset programming Bit */
	CLR_BIT(FLASH_CR,PG);
}

/****************************************************************************************/
/* Description: Write an array in the Flash memory										*/
/* Input      : u32* pu32address		                                	            */
/*              Description: address to write in the flash		                        */
/*				u32* pu32array															*/
/*              Description:array address to write in flash			                    */
/*				u8 u8arraysize															*/
/*              Description: Size of the array to write in the flash		            */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteArray(u32* pu32address, u32* pu32array, u8 u8arraysize)
{
	u8 u8counter = 0;
	u16* address = (u16*)pu32address;
	/* Perform Unlock Sequence */
	if (GET_BIT(FLASH_CR,LOCK) == FLASH_u8LOCKED)
	{
		FLASH_KEYR = FLASH_u32KEY1;
		FLASH_KEYR = FLASH_u32KEY2;
	}
	/* Set Programming Bit */
	SET_BIT(FLASH_CR, PG);

	for (u8counter = 0 ; u8counter < u8arraysize; u8counter++)
	{
		/* Put first half-word in the address */
		*(address+(u8counter*2)) = (u16)(pu32array[u8counter] & HALFWORDMASK);
		/* Wait for the busy flag */
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
		/* Write second half-word in the address */
		*(address+1+(u8counter*2)) = (u16)(pu32array[u8counter] >> HALFWORDOFFSET);
		/* Wait for busy bit */
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
	}
	/* Reset programming Bit */
	CLR_BIT(FLASH_CR,PG);
}


/****************************************************************************************/
/* Description: Erase Page in Flash Memory												*/
/* Input      : u8 u8PageNumber		                                	               	*/
/*              Description: Page to erase in the Flash			                        */
/*				Range: 0 ~ 127															*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidErasePage(u8 u8PageNumber)
{
	u32 u32FlashBaseAddress = FLASH_u32BASEADDRESS;
	/* Perform Unlock Sequence */
	if (GET_BIT(FLASH_CR,LOCK) == FLASH_u8LOCKED)
	{
		FLASH_KEYR = FLASH_u32KEY1;
		FLASH_KEYR = FLASH_u32KEY2;
	}
	/* Set Erase Bit */
	SET_BIT(FLASH_CR, PER);
	/* Wait for busy bit */
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
	/* Write page address in the Address Register*/
	FLASH_AR = u32FlashBaseAddress + (u32)(FLASH_u16PAGESIZE * (u16)u8PageNumber);
	/* Set Start Bit */
	SET_BIT(FLASH_CR, STRT);
	/* Wait for Busy Flag */
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
	/* Reset Erase Bit */
	CLR_BIT(FLASH_CR, PER);

}


/****************************************************************************************/
/* Description: Read one word from the Flash Memory										*/
/* Input      : u32* pu32address		                                	            */
/*              Description: Address to read in the flash		                        */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u32 FLASH_u32ReadWord(u32* pu32address)
{
	return *(pu32address);
}


/****************************************************************************************/
/* Description: Read an array from the Flash memory										*/
/* Input      : u32* pu32address		                                	            */
/*              Description: address to read from the flash		                        */
/*				u32* pu32array															*/
/*              Description:array address to put in data from flash			            */
/*				u8 u8arraysize															*/
/*              Description: Size of the array to read from the flash		            */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidReadArray(u32* pu32address, u32* pu32array, u8 u8arraysize)
{
	u8 u8counter = 0;
	for (u8counter = 0; u8counter < u8arraysize; u8counter++)
	{
		pu32array[u8counter] = *(pu32address + u8counter);
	}
}



/****************************************************************************************/
/* Description: Write Option Byte														*/
/* Input      : u8 u8DataByte			                                	        	*/
/*              Description: Data Byte to be programmed				                    */
/*				Range: FLASH_u8OPTDATA0, FLASH_u8OPTDATA1								*/
/*				u8 u8Value																*/
/*              Description: Value to write in the option Byte			                */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteOptionByteData(u8 u8DataByte, u8 u8Value)
{
	u8 u8ReadProtection = FLASH_u8READUNPROTECTED;
	u8 au8Data[2] = {0};
	/* Check data byte is valid */
	if (u8DataByte > FLASH_u8OPTDATA1)
	{
		return;
	}

	/* Store current status */
	u8ReadProtection = GET_BIT(FLASH_OBR,RDPRT);
	au8Data[0] = (u8) (FLASH_OPTDATA0ADDR & BYTEMASK);
	au8Data[1] = (u8) (FLASH_OPTDATA1ADDR & BYTEMASK);

	/* Perform Flash Unlock Sequence */
	if (GET_BIT(FLASH_CR,LOCK) == FLASH_u8LOCKED)
	{
		FLASH_KEYR = FLASH_u32KEY1;
		FLASH_KEYR = FLASH_u32KEY2;
	}

	/* Unlock Option Byte Programming */
	FLASH_OPTKEYR = FLASH_u32KEY1;
	FLASH_OPTKEYR = FLASH_u32KEY2;

	/* Perform Erase Sequence */
	SET_BIT(FLASH_CR,OPTWRE);
	SET_BIT(FLASH_CR,OPTER);
	SET_BIT(FLASH_CR,STRT);

	/* Wait for Erase to be performed */
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);

	/* Clear OPTER Bit */
	CLR_BIT(FLASH_CR,OPTER);

	/* Start Option Byte Programming */
	SET_BIT(FLASH_CR, OPTPG);

	/* Re-set read protection */
	if (u8ReadProtection == FLASH_u8READUNPROTECTED)
	{
		FLASH_OPTRDPADRR = FLASH_u16READPROTECTKEY;
	}
	while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);

	/* Write Data in the specified address */
	switch (u8DataByte)
	{
	case FLASH_u8OPTDATA0:
		FLASH_OPTDATA0ADDR = u8Value;
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
		FLASH_OPTDATA1ADDR = au8Data[1];
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
		break;

	case FLASH_u8OPTDATA1:
		FLASH_OPTDATA0ADDR = au8Data[0];
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
		FLASH_OPTDATA1ADDR = u8Value;
		while (GET_BIT(FLASH_SR,BSY) == FLASH_u8BSY);
		break;

	default:
		break;
	}

	/* Clear Option Byte Programming bit and write protection */
	CLR_BIT(FLASH_CR, OPTPG);
	CLR_BIT(FLASH_CR, OPTWRE);

}


/****************************************************************************************/
/* Description: Get Option Byte Data													*/
/* Input      : u8 u8DataByte			                                	        	*/
/*              Description: Data Byte to get the value of			                    */
/*				Range: FLASH_u8OPTDATA0, FLASH_u8OPTDATA1								*/
/* Output     : Value of Chosen data byte                                               */
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u8 FLASH_u8GetOptionByteData(u8 u8DataByte)
{
	u8 u8Data = 0;
	switch (u8DataByte)
	{
	case FLASH_u8OPTDATA0:
		u8Data = (u8) (FLASH_OPTDATA0ADDR & BYTEMASK);
		break;

	case FLASH_u8OPTDATA1:
		u8Data = (u8) (FLASH_OPTDATA1ADDR & BYTEMASK);
		break;

	default :
		break;
	}
	return u8Data;
}


