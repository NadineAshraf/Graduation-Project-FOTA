/*
 * HexDataProcessor_prog.c
 *
 *  Created on: Oct 5, 2019
 *      Author: sondo
 */

#include "stdio.h"
#include "util.h"
#include "STD_Types.h"
#include "FLASH_int.h"
#include "HexDataProcessor_int.h"
#include "HexDataProcessor_priv.h"



/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Log the Driver Version													*/
/* Input      : Void																	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void HexDataProcessor_vidGetVersionInfo(void)
{

}




/****************************************************************************************/
/* Description: Store Hex Data in the Flash												*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The Array containing the Hex Line to extract the data from	*/
/* Output     : Error_Status                                                            */
/*				Description: Status of the operation									*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
Error_Status HexDataProcessor_u32StoreHexInFlash(u8* au8HexLineArray)
{
	Line_State enuCurrentState = CheckValidation;
	Error_Status enuError = OK;
	HexData strHexExtractedData;	/* Structure to store the hex data format in */
	u8 u8CharacterCount = 0;		/* Counter to count number of the characters in the hex line */


	for ( ; enuCurrentState < Done; )
	{
		switch (enuCurrentState)
		{
		case CheckValidation:
			enuError = enuCheckLineValidation(au8HexLineArray);
			if (enuError == OK)
			{
				/* Increment the array pointer to decline the first character of the array in the next steps */
				au8HexLineArray++;
				enuCurrentState = ConvertToHex;
			}
			else
			{
				enuCurrentState = Error;
			}
			break;

		case ConvertToHex:
			enuError = enuConvertLineToHex(au8HexLineArray, &u8CharacterCount);
			if (enuError == OK)
			{
				enuCurrentState = ParseLine;
			}
			else
			{
				enuCurrentState = Error;
			}
			break;

		case ParseLine:
			enuError = enuParseLine(au8HexLineArray, u8CharacterCount, &strHexExtractedData);
			if (enuError == OK)
			{
				enuCurrentState = StoreInFlash;
			}
			else
			{
				enuCurrentState = Error;
			}
			break;

		case StoreInFlash:
			enuError = enuWriteDataInFlash(&strHexExtractedData);
			if (enuError == OK)
			{
				enuCurrentState = Done;
				if (strHexExtractedData.enuDataRecord == EndOfLine)
				{
					enuError = limitReached;
				}
			}
			else
			{
				enuCurrentState = Error;
			}
			break;
		default:
			break;
		}
	}
	return enuError;
}



/*****************************************/
/***********Private Functions*************/
/*****************************************/


/****************************************************************************************/
/* Description: Check if the line is a valid hex line									*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The array of the line to check the validation for			*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the file 										*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuCheckLineValidation(u8* au8HexLineArray)
{
	Error_Status enuError = OK;
	u16 u16Counter = 0;
	/* Check for null pointer */
	if (au8HexLineArray == NULL)
	{
		enuError = nullPointer;
	}
	else if (au8HexLineArray[DEF_u8ZERO] != ':')
	{
		enuError = NOK;
	}
	else
	{
		/* Count the number of characters in the array to check it is even */
		for (u16Counter = 0; ( (au8HexLineArray[u16Counter] != u8ENDOFLINECHARACTER) && (u16Counter < u16MAXFRAMESIZE) ); u16Counter++);
		if (u16Counter > u16MAXFRAMESIZE )
		{
			enuError = NOK;
		}
		else if ( (u16Counter % DEF_u8TWO) != DEF_u8ONE)
		{
			enuError = NOK;
		}
		else
		{

		}
	}
	return enuError;
}




/****************************************************************************************/
/* Description: Convert the line from Hex Characters to hex numbers 	 				*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The array of the line to convert							*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the conversion 									*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuConvertLineToHex(u8* au8HexLineArray, u8* pu8CharacterCount)
{
	Error_Status enuError = OK;
	u8 u8CharCount = 0;
	u8 u8Counter = 0;

	/* Convert the line from hex characters to hex numbers, example from 'A' to 0x0A */
	for (u8Counter = 0; au8HexLineArray[u8Counter] != u8ENDOFLINECHARACTER; u8Counter++)
	{
		au8HexLineArray[u8Counter] = u8CharacterToHex(au8HexLineArray[u8Counter]);
		if (au8HexLineArray[u8Counter] == DEF_u8OXFF)
		{
			enuError = NOK;
		}
	}

	/* Convert from the ascii-hex format to hex format. EX from 0A0A to AA*/
	for (u8CharCount = 0; u8CharCount != (u8Counter / DEF_u8TWO) ; u8CharCount++)
	{
		au8HexLineArray[u8CharCount] = (au8HexLineArray[(u8CharCount * DEF_u8TWO)] << u8HALFBYTEOFFSET) \
				| (au8HexLineArray[ (u8CharCount * DEF_u8TWO) + 1] & u8HALFBYTEMASK) ;
	}
	/* Change the last element to be terminating character to mark the end of the array */
	*pu8CharacterCount = u8CharCount;

	/* Check Checksum */
	return enuError;
}



/****************************************************************************************/
/* Description: Parse the data to its corresponding fields in the structure		 		*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The array of the line to convert							*/
/*				u8 u8CharacterCount														*/
/*				Description: number of characters in the array							*/
/*				HexData* pstrHexData													*/
/*				Description: the structure to extract the data into						*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the parsing 										*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuParseLine(u8* au8HexLineArray, u8 u8CharacterCount, HexData* pstrHexData)
{
	Error_Status enuError = OK;
	u8 u8Counter = 0;

	pstrHexData->u8DataLength = au8HexLineArray[BYTECOUNTSTARTINDEX];
	pstrHexData->enuDataRecord = (RecordType)au8HexLineArray[RECORDTYPESTARTINDEX];
	pstrHexData->u16DataAddress = (u16)((((u16)(au8HexLineArray[ADDRESSSTARTINDEX] << BYTEOFFSET))) | (u16)(au8HexLineArray[ADDRESSSTARTINDEX + 1]));
	pstrHexData->u8CheckSum = 0;

	/* Check the checksum of the line */
	for (u8Counter = 0; u8Counter < (u8CharacterCount - DEF_u8ONE); u8Counter++)
	{
		pstrHexData->u8CheckSum += au8HexLineArray[u8Counter];
	}
	pstrHexData->u8CheckSum = (DEF_u8OXFF - pstrHexData->u8CheckSum) + DEF_u8ONE;
	if ( pstrHexData->u8CheckSum != au8HexLineArray[u8CharacterCount - DEF_u8ONE])
	{
		enuError = NOK;
	}

	/* Parse the data field */
	if (pstrHexData->enuDataRecord == Data)
	{
		/* If the record type is data, extract the data with flipping it */
		for (u8Counter = 0; u8Counter < u8CharacterCount ; u8Counter++)
		{
			/* Take every 4 bytes and put them in the form of u32 in the data array of the structure */
			pstrHexData->au32Data[u8Counter] = (u32) ( (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR)] ) \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8ONE] << u8SECONDBYTEOFFSET) \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8TWO] << u8THIRDBYTEOFFSET)  \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8THREE]) << u8FOURTHBYTEOFFSET);
		}

		/* If the data length isn't a multiple of u32, add 0xFF in the remaining data */
		if (pstrHexData->u8DataLength % DEF_u8FOUR != 0)
		{
			/* Shift the data to the most significant bits to add FF in the rest of them */
			//wrong according to flasher sequence, just add FF in the MSBs without shifting
			for (u8Counter = (pstrHexData->u8DataLength % DEF_u8FOUR) ; u8Counter < DEF_u8FOUR; u8Counter++)
			{
				pstrHexData->au32Data[(pstrHexData->u8DataLength / DEF_u8FOUR)] |= (DEF_u8OXFF << ( u8Counter * BYTEOFFSET) );
			}
			/* Add the number of bytes added to the data length */
			pstrHexData->u8DataLength += (DEF_u8FOUR - (pstrHexData->u8DataLength % DEF_u8FOUR));
		}
		else
		{
			/* Do Nothing */
		}
		/* Convert the length to be in u32 */
		pstrHexData->u8DataLength = pstrHexData->u8DataLength / DEF_u8FOUR;
	}
	else
	{
		/* If the Record type isn't data, put the data without flipping */
		for (u8Counter = 0; u8Counter < u8CharacterCount ; u8Counter++)
		{
			/* Take every 4 bytes and put them in the form of u32 in the data array of the structure */
			pstrHexData->au32Data[u8Counter] = (u32) ( (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR)] ) << u8FOURTHBYTEOFFSET) \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8ONE] << u8THIRDBYTEOFFSET) \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8TWO] << u8SECONDBYTEOFFSET)  \
					| (au8HexLineArray[DATASTARTINDEX + (u8Counter * DEF_u8FOUR) + DEF_u8THREE]);
		}
	}
	return enuError;
}


/****************************************************************************************/
/* Description: Structure of the data to be stored in flash						 		*/
/* Input      : HexData* pstrHexData													*/
/*				Description: the structure to store data from							*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the parsing 										*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuWriteDataInFlash(const HexData* pstrHexData)
{
	Error_Status enuError = OK;
	static u16 u16AddressOffset = 0;
	u32 u32TempAddress = 0;

	switch (pstrHexData->enuDataRecord)
	{
	case Data:
		/* Check the offset Address was already initialized by an Extended Linear Address */
		if (u16AddressOffset != DEF_u8ZERO)
		{
			/* Add the address of the data to the data address offset */
			u32TempAddress = ((u32)(u16AddressOffset << u8HALFWORDOFFSET)) | (pstrHexData->u16DataAddress);

			/* Write the Data in Flash */
			FLASH_vidWriteArray((u32*)u32TempAddress, pstrHexData->au32Data, pstrHexData->u8DataLength);
		}
		else
		{
			/* Do Nothing */
		}
		break;

	case EndOfLine:
		break;

	case ExtendedSegmentAddress:
		break;

	case StartSegmentAddress:
		break;

	case ExtendedLinearAddress:
		/*  Check the address is zero and the data length is 2 */
		if (pstrHexData->u8DataLength != DEF_u8TWO)
		{
			enuError = NOK;
		}
		else if (pstrHexData->u16DataAddress != DEF_u8ZERO)
		{
			enuError = NOK;
		}
		else
		{
			/* Put the address offset in the static variable */
			u16AddressOffset = ( (pstrHexData->au32Data[DEF_u8ZERO] >> u8HALFWORDOFFSET) & u32HALFWORDMASK );
		}
		break;

	case StartLinearAddress:
		/*  Check the address is zero and the data length is 1 */
		if (pstrHexData->u8DataLength != DEF_u8ONE)
		{
			enuError = NOK;
		}
		else if (pstrHexData->u16DataAddress != DEF_u8ZERO)
		{
			enuError = NOK;
		}
		else
		{
			/* Put the address in the return variable */
			//			u32ReturnAddress = pstrHexData->au32Data[DEF_u8ZERO];
			//			u32ReturnAddress = (u32ReturnAddress << u8FOURTHBYTEOFFSET) \
			//					| (u32ReturnAddress >> u8FOURTHBYTEOFFSET) \
			//					| (((u32ReturnAddress >> u8THIRDBYTEOFFSET) & u32BYTEMASK) << u8SECONDBYTEOFFSET) \
			//					| (((u32ReturnAddress >> u8SECONDBYTEOFFSET) & u32BYTEMASK) << u8THIRDBYTEOFFSET);
		}
		break;

	default:
		break;
	}
	return enuError;
}


/****************************************************************************************/
/* Description: Convert Character form to Hex Form. EX. from 'A' to 0x0A				*/
/* Input      : u8 u8Character															*/
/*				Description: Character to be converted									*/
/* Output     : u8	                                                                 	*/
/*				Description: The Character after conversion to hex						*/
/*							 It returns 0xFF if the character is an invalid hex format	*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
u8 u8CharacterToHex(u8 u8Character)
{
	u8 u8Return = DEF_u8OXFF;
	if ( (u8Character >= '0') && (u8Character <= '9') )
	{
		u8Return = u8Character - '0';
	}
	else if ( (u8Character >= 'A') && (u8Character <= 'F') )
	{
		u8Return = u8Character - 'A' + 0x0A;
	}
	else
	{

	}
	return u8Return;
}
