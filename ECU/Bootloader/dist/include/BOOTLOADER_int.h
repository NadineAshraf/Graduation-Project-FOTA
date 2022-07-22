/*
 * BL_int.h
 *
 *  Created on: Jul 28, 2020
 *      Author: lenovo
 */

#ifndef BOOTLOADER_INT_H_
#define BOOTLOADER_INT_H_




/*****************************************/
/*********Public Definitions*************/
/*****************************************/

/* Option Bytes Data0 Definitons */
#define BOOTLOADER_u8VALIDOPTIONBYTES	0
#define BOOTLOADER_u8USEDBANK			1
#define BOOTLOADER_u8VALIDBANK0			2
#define BOOTLOADER_u8VALIDBANK1			3

/* Option Bytes Data0 Masks */
#define BOOTLOADER_u8VALIDOPTIONBYTESMASK	0x01
#define BOOTLOADER_u8USEDBANKMASK			0x02
#define BOOTLOADER_u8VALIDBANK0MASK			0x04
#define BOOTLOADER_u8VALIDBANK1MASK			0x08


/* Option Bytes Data0 Valid and Not Valid Flags */
#define BOOTLOADER_u8OPTIONBYTESVALID		0
#define BOOTLOADER_u8OPTIONBYTESNOTVALID	1

/* Used Banks Definitions */
#define BOOTLOADER_u8BANK0					0
#define BOOTLOADER_u8BANK1					1

/* Valid or Unvalid Banks Definitions */
#define BOOTLOADER_u8BANKVALID				0
#define BOOTLOADER_u8BANKUNVALID			1

/* Soft Reset Flag Definitions */
#define BOOTLOADER_u8NOSOFTRESET			0					1
#define BOOTLOADER_u8SOFTRESET				1


/* Banks Start Addresses */
#define BOOTLOADER_pu32BANK0BASEADRESS	0x08002800
#define BOOTLOADER_pu32BANK1BASEADRESS	0x08014000

/*****************************************/
/***********Public Functions**************/
/*****************************************/

/****************************************************************************************/
/* Description: Start Bootloader														*/
/* Input      : u8 u8ProgrammingBank						                            */
/*				Description: Bank to flash software in 									*/
/*				Range: BOOTLOADER_u8BANK0, BOOTLOADER_u8BANK1							*/
/*				u8 u8OptionDataBytes													*/
/*				Description: Current Option Bytes Data0 								*/
/*				Range: 0x00 ~ 0xFF														*/
/* Output     : Void		                                                            */
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void BOOTLOADER_vidStart(u8 u8ProgrammingBank, u8 u8OptionDataBytes);


/****************************************************************************************/
/* Description: Jump to Application														*/
/* Input      : u32* pu32BaseAddress					                                */
/*				Description: Base address of application to jump to						*/
/* Output     : Void		                                                            */
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void BOOTLOADER_vidJumpToApplication(u32* pu32BaseAddress);

#endif /* BOOTLOADER_INT_H_ */
