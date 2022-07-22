/************************************************************************/
/* Author  : Sondos Aly	                                                */
/* Date    : 9/12/2019                                                  */
/* Version : V03	                                                    */
/************************************************************************/
/* Modification Log                                                     */
/* -----------------                                                    */
/*     Name     |    Version    |                 Changes               */
/*  Sondos 		        V01                      First Creation         */
/*	Sondos				V02				Removed interface: 				*/
/* 										HexDataProcessor_vidGetHexData	*/
/*										Edited and optimised interface: */
/* 									HexDataProcessor_u32StoreHexInFlash	*/
/* 	Sondos				V03			Optimization using state flow		*/
/************************************************************************/
/*
 * HexDataProcessor_int.h
 *
 *  Created on: Oct 5, 2019
 *      Author: sondo
 */

#ifndef HEXDATAPROCESSOR_INT_H_
#define HEXDATAPROCESSOR_INT_H_



/*****************************************/
/***********Public Definitions************/
/*****************************************/

/* Max Data Length per line in the Hex File in u32 format*/
/* Equals 256(max. number in u8 format) divides 4 */
#define u8MAXDATALENGTH	64


/* Record Type enum */
typedef enum
{
	Data = 0,
	EndOfLine,
	ExtendedSegmentAddress,
	StartSegmentAddress,
	ExtendedLinearAddress,
	StartLinearAddress
} RecordType;


/* Hex Data Structure */
typedef struct
{
	u8 u8DataLength;
	u8 u8CheckSum;
	RecordType	enuDataRecord;
	u16 u16DataAddress;
	u32 au32Data[u8MAXDATALENGTH];
} HexData;


/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Log the Driver Version													*/
/* Input      : Void																	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void HexDataProcessor_vidGetVersionInfo(void);



/****************************************************************************************/
/* Description: Get the Hex Data from the hex line and return it in the form of hex data*/
/* 				structure																*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The Array containing the Hex Line to extract the data from	*/
/*				HexData *pstrHexExtractedData											*/
/*				Description: Structure to put the extracted data in						*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
//void HexDataProcessor_vidGetHexData(u8* au8HexLineArray, HexData *pstrHexExtractedData);




/****************************************************************************************/
/* Description: Store Hex Data in the Flash												*/
/* Input      : HexData *astrHexDataArray												*/
/*				Description: Array of hex data structures to be stored in the flash		*/
/*				u16 u16HexSize															*/
/*				Description: Structure Array length										*/
/* Output     : u32                                                                  	*/
/*				Description: Address of the startup code of the hex file				*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
//u32 HexDataProcessor_u32StoreHexInFlash(HexData *astrHexDataArray, u16 u16HexSize);

/****************************************************************************************/
/* Description: Store Hex Data in the Flash												*/
/* Input      : u8* u8HexLineArray														*/
/*				Description: The Array containing the Hex Line to extract the data from	*/
/* Output     : Error_Status                                                            */
/*				Description: Status of the operation									*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
Error_Status HexDataProcessor_u32StoreHexInFlash(u8* au8HexLineArray);

#endif /* HEXDATAPROCESSOR_INT_H_ */
