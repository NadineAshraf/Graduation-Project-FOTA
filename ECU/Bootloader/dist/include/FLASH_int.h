/************************************************************************/
/* Author  : Sondos Aly	                                                */
/* Date    : 13/3/2019                                                  */
/* Version : V01                                                        */
/************************************************************************/
/* Modification Log                                                     */
/* -----------------                                                    */
/*     Name     |    Version    |                 Changes               */
/*  Sondos 		        V01                      First Creation         */
/*  Sondos				V02						Added Read and Write 	*/
/*												Data Option Bytes		*/
/************************************************************************/


/*
 * FLASH_int.h
 *
 *  Created on: Sep 26, 2019
 *      Author: sondo
 */

#ifndef FLASH_INT_H_
#define FLASH_INT_H_

/*****************************************/
/***********Public Definitions************/
/*****************************************/

/* Option Data Bytes */
#define FLASH_u8OPTDATA0		0
#define FLASH_u8OPTDATA1		1

/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Log the Driver Version													*/
/* Input      : Void																	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
//void Flash_vidGetVersionInfo(void);


/****************************************************************************************/
/* Description: Write one word in the Flash Memory										*/
/* Input      : u32* pu32address		                                	               	*/
/*              Description: Address to write in the flash		                        */
/*				u32 u32value															*/
/*              Description: Word to write in flash			                 		    */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteWord(u32* pu32address, u32 u32value);

/****************************************************************************************/
/* Description: Write an array in the Flash memory										*/
/* Input      : u32* pu32address		                                	               	*/
/*              Description: address to write in the flash		                        */
/*				u32* pu32array															*/
/*              Description:array address to write in flash			                    */
/*				u8 u8arraysize															*/
/*              Description: Size of the array to write in the flash		            */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteArray(u32* pu32address, u32* pu32array, u8 u8arraysize);


/****************************************************************************************/
/* Description: Erase Page in Flash Memory												*/
/* Input      : u8 u8PageNumber		                                	               	*/
/*              Description: Page to erase in the Flash			                        */
/*				Range: 0 ~ 127															*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidErasePage(u8 u8PageNumber);


/****************************************************************************************/
/* Description: Read one word from the Flash Memory										*/
/* Input      : u32* pu32address		                                	               	*/
/*              Description: Address to read in the flash		                        */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u32 FLASH_u32ReadWord(u32* pu32address);


/****************************************************************************************/
/* Description: Read an array from the Flash memory										*/
/* Input      : u32* pu32address		                                	               	*/
/*              Description: address to read from the flash		                        */
/*				u32* pu32array															*/
/*              Description:array address to put in data from flash			            */
/*				u8 u8arraysize															*/
/*              Description: Size of the array to read from the flash		            */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidReadArray(u32* pu32address, u32* pu32array, u8 u8arraysize);


/****************************************************************************************/
/* Description: Write Option Byte														*/
/* Input      : u8 u8DataByte			                                	        	*/
/*              Description: Data Byte to be programmed				                    */
/*				Range: FLASH_u8OPTDATA0, FLASH_u8OPTDATA1									*/
/*				u8 u8Value																*/
/*              Description: Value to write in the option Byte			                */
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void FLASH_vidWriteOptionByteData(u8 u8DataByte, u8 u8Value);


/****************************************************************************************/
/* Description: Get Option Byte Data													*/
/* Input      : u8 u8DataByte			                                	        	*/
/*              Description: Data Byte to get the value of			                    */
/*				Range: FLASH_u8OPTDATA0, FLASH_u8OPTDATA1								*/
/* Output     : Value of Chosen data byte                                               */
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
u8 FLASH_u8GetOptionByteData(u8 u8DataByte);

#endif /* FLASH_INT_H_ */
