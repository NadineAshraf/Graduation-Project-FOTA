/*
 * HexDataProcessor_priv.h
 *
 *  Created on: Oct 7, 2019
 *      Author: sondo
 */

#ifndef HEXDATAPROCESSOR_PRIV_H_
#define HEXDATAPROCESSOR_PRIV_H_


/* Maximum frame size in the hex line in u8 format */
#define u16MAXFRAMESIZE	265

/* Half u8 Definitions */
#define u8HALFBYTEOFFSET	4
#define u8HALFBYTEMASK	0x0F
#define u32BYTEMASK		0x000000FF
#define BYTEOFFSET		8


/*Half u32 Definitions*/
#define u8HALFWORDOFFSET	16
#define u32HALFWORDMASK		0x0000FFFF

/* u8 to u32 OFFSET Definitions */
#define u8FOURTHBYTEOFFSET		24
#define u8THIRDBYTEOFFSET		16
#define u8SECONDBYTEOFFSET		8

/* Fault Flag True/False Definitions */
#define FAULTFLAGTRUE	0
#define FAULTFLAGFALSE	1

/* Frame Start Indices */
#define BYTECOUNTSTARTINDEX		0
#define ADDRESSSTARTINDEX		1
#define RECORDTYPESTARTINDEX	3
#define DATASTARTINDEX			4


/* Frequently Used Numbers Defines */
#define DEF_u8ZERO		0
#define DEF_u8ONE		1
#define DEF_u8OXFF		0xFF
#define DEF_u8TWO		2
#define DEF_u8THREE		3
#define DEF_u8FOUR		4


/* File Parsing states */
typedef enum
{
	CheckValidation = 0,
	ConvertToHex,
	ParseLine,
	StoreInFlash,
	Done,
	Error
}Line_State;

#define u8ENDOFLINECHARACTER 	'\r'
#define u8TERMINATINGCHARACTER 	'\0'


/*****************************************/
/***********Private Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Check if the line is a valid hex line									*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The array of the line to check the validation for			*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the file 										*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuCheckLineValidation(u8* au8HexLineArray);



/****************************************************************************************/
/* Description: Convert the line from Hex Characters to hex numbers 	 				*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The array of the line to convert							*/
/*				u8* pu8CharacterCount													*/
/*				Description: pointer to return the number of elements on the array in	*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the conversion 									*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuConvertLineToHex(u8* au8HexLineArray, u8* pu8CharacterCount);


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
Error_Status enuParseLine(u8* au8HexLineArray, u8 u8CharacterCount, HexData* pstrHexData);


/****************************************************************************************/
/* Description: Structure of the data to be stored in flash						 		*/
/* Input      : HexData* pstrHexData													*/
/*				Description: the structure to store data from							*/
/* Output     : Error_Status	                                                        */
/*				Description: Status of the parsing 										*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
Error_Status enuWriteDataInFlash(const HexData* pstrHexData);



/****************************************************************************************/
/* Description: Convert Character form to Hex Form. EX. from 'A' to 0x0A				*/
/* Input      : u8 u8Character															*/
/*				Description: Character to be converted									*/
/* Output     : u8	                                                                 	*/
/*				Description: The Character after conversion to hex						*/
/*							 It returns 0xFF if the character is an invalid hex format	*/
/* Scope      : Private                                                                	*/
/****************************************************************************************/
u8 u8CharacterToHex(u8 u8Character);



#endif /* HEXDATAPROCESSOR_PRIV_H_ */
