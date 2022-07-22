/*
 * BOOTLOADER_prog.c
 *
 *  Created on: Jul 28, 2020
 *      Author: lenovo
 */


#include "STD_Types.h"
#include "util.h"
#include "RCC_int.h"
#include "DIO_int.h"
#include "NVIC_int.h"
#include "AFIO_init.h"
#include "AFIO_config.h"
#include "CAN.h"

#include "Timer_int.h"

#include "CANHANDLER_int.h"
#include "CANHANDLER_cfg.h"
#include "FLASH_int.h"
#include "SCB_int.h"
#include "HexDataProcessor_int.h"
#include "BOOTLOADER_int.h"

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
void BOOTLOADER_vidStart(u8 u8ProgrammingBank, u8 u8OptionDataBytes)
{
	u8 au8DTCs[]={20,30};
	u8 HexArrayLine[261] = {0};
	u8 u8Counter  = 0;
	Error_Status enuError = OK;
	u16 u16LineCounter = 0;
	u8 u8RxCount = 0;
	u8 u8UsedBank = 0;
	u32* pu32BaseAddress = 0;
	u8 au8version[3] = {0};

	filter_type filters[] =
	{
		{CANHANDLER_u8HEXFILEID,DATA_FRAME, STANDARD_FORMAT},
		{CANHANDLER_u8ECUSWVERSION, REMOTE_FRAME,STANDARD_FORMAT},
		{CANHANDLER_u8GETFLASHBANK, REMOTE_FRAME,STANDARD_FORMAT},
		{CANHANDLER_u8ECUDTCs, REMOTE_FRAME,STANDARD_FORMAT},

	};

	/* RCC Peripherals Initializations */
	RCC_vidEnablePeripheral(RCC_u8GPIOCCLK);
	RCC_vidEnablePeripheral(RCC_u8CANCLK);
	RCC_vidEnablePeripheral(RCC_u8AFIOCLK);		// enable clock for Alternate Function
	RCC_vidEnablePeripheral(RCC_u8GPIOBCLK);			 // enable clock for GPIO B


	RCC_vidEnablePeripheral(RCC_u8TIM1CLK);
	NVIC_vidEnableInterrupt(NVIC_u8TIM1_UP);
	Timer1_UEV_Interrupt();

	/* AFIO and DIO Initializations */
	AFIO_vidinit();
	DIO_vidInit();

	/* Interrupt Initializations */
	NVIC_vidInit();
	NVIC_vidEnableInterrupt(NVIC_u8USB_HP_CAN_TX);			// enable interrupt
	NVIC_vidEnableInterrupt(NVIC_u8USB_LP_CAN_RX0);			// enable interrupt

	/* CAN Initialization */
	CAN_setup ();                                   // setup CAN interface
	CAN_vid_filter_list(filters,CANHANDLER_u8MAXFILTERNUMBERS);
	CAN_testmode(0);      // Normal, By Salma
	CAN_start ();                                   // leave init mode
	CAN_waitReady ();                               // wait til mbx is empty

	/* Used Bank Initialization, Setting Data in programming bank to Invalid */
	switch (u8ProgrammingBank)
	{
	case BOOTLOADER_u8BANK0:
		u8UsedBank = BOOTLOADER_u8BANK1;
		pu32BaseAddress = (u32*)BOOTLOADER_pu32BANK0BASEADRESS;

		/* Set The data in the bank as Invalid */
		CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8VALIDBANK0);
		u8OptionDataBytes |= (BOOTLOADER_u8BANKUNVALID << BOOTLOADER_u8VALIDBANK0);
		FLASH_vidWriteOptionByteData(FLASH_u8OPTDATA0 , u8OptionDataBytes);

		break;
	case BOOTLOADER_u8BANK1:
		u8UsedBank = BOOTLOADER_u8BANK0;
		pu32BaseAddress = (u32*)BOOTLOADER_pu32BANK1BASEADRESS;

		/* Set The data in the bank as Invalid */
		CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8VALIDBANK1);
		u8OptionDataBytes |= (BOOTLOADER_u8BANKUNVALID << BOOTLOADER_u8VALIDBANK1);
		FLASH_vidWriteOptionByteData(FLASH_u8OPTDATA0 , u8OptionDataBytes);

		break;
	default:
		break;
	}


	/* Erase the flashing bank */
	for ( u8Counter = 0; u8Counter < 59; u8Counter++)
	{
		FLASH_vidErasePage(u8Counter + 10 + 59*u8ProgrammingBank);
	}

	while (1)
	{
		// Add your code here.
		do
		{
			do
			{
				while (CAN_RxRdy == 0);
				if (CAN_RxRdy)
				{
					CAN_RxRdy = 0;
					if (CAN_RxMsg[u8RxCount].u8ActiveFlag == 1)
					{
						switch (CAN_RxMsg[u8RxCount].id)
						{
						case CANHANDLER_u8HEXFILEID:
							for (u8Counter = 0; u8Counter < CAN_RxMsg[u8RxCount].len ; u8Counter++ )
							{
								HexArrayLine[u16LineCounter] = CAN_RxMsg[u8RxCount].data[u8Counter];
								u16LineCounter++;
							}
							CANHANDLER_vidSend(CANHANDLER_u8NEXTMSGREQUEST,CAN_u8REMOTEFRAME,(void*)0,0);

							break;
						case CANHANDLER_u8ECUSWVERSION:
							CANHANDLER_vidSend(CANHANDLER_u8ECUSWVERSION,CAN_u8DATAFRAME,au8version,3);
							break;

						case CANHANDLER_u8GETFLASHBANK:
							CANHANDLER_vidSend(CANHANDLER_u8GETFLASHBANK,CAN_u8DATAFRAME,&u8UsedBank,1);
							break;
						case CANHANDLER_u8ECUDTCs:
							CANHANDLER_vidSend(CANHANDLER_u8ECUDTCs,CAN_u8DATAFRAME,au8DTCs,1);
							break;

						}
						CAN_RxMsg[u8RxCount].u8ActiveFlag = 0;
						u8RxCount++;
						if (u8RxCount == 3)
						{
							u8RxCount = 0;
						}
					}
				}
			}while ( HexArrayLine[u16LineCounter-1] != '\r');
			u16LineCounter = 0;
			Timer1_vidStartCount();
			enuError = HexDataProcessor_u32StoreHexInFlash(HexArrayLine);
		} while (enuError != limitReached);

		switch (u8ProgrammingBank)
		{
		case BOOTLOADER_u8BANK0:
			/* Set The data in the bank as Valud and set bank to bank 0 */
			CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8VALIDBANK0);
			CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8USEDBANK);
			u8OptionDataBytes |= ((BOOTLOADER_u8VALIDBANK0 << BOOTLOADER_u8VALIDBANK0) | (BOOTLOADER_u8BANK0 << BOOTLOADER_u8USEDBANK) | (BOOTLOADER_u8OPTIONBYTESVALID << BOOTLOADER_u8VALIDOPTIONBYTES));
			FLASH_vidWriteOptionByteData(FLASH_u8OPTDATA0 , u8OptionDataBytes);

			break;
		case BOOTLOADER_u8BANK1:
			/* Set The data in the bank as Valud and set bank to bank 0 */
			CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8VALIDBANK1);
			CLR_BIT(u8OptionDataBytes, BOOTLOADER_u8USEDBANK);
			u8OptionDataBytes |= ((BOOTLOADER_u8VALIDBANK1 << BOOTLOADER_u8VALIDBANK1) | (BOOTLOADER_u8BANK1 << BOOTLOADER_u8USEDBANK) | (BOOTLOADER_u8OPTIONBYTESVALID << BOOTLOADER_u8VALIDOPTIONBYTES));
			FLASH_vidWriteOptionByteData(FLASH_u8OPTDATA0 , u8OptionDataBytes);

			break;
		default:
			break;
		}

		BOOTLOADER_vidJumpToApplication(pu32BaseAddress);

	}

}




/****************************************************************************************/
/* Description: Jump to Application														*/
/* Input      : u32* pu32BaseAddress					                                */
/*				Description: Base address of application to jump to						*/
/* Output     : Void		                                                            */
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void BOOTLOADER_vidJumpToApplication(u32* pu32BaseAddress)
{
	void (*pfunc)(void) = 0;

	/* Get  Application Reset Vector Address */
	pfunc = *(u32*)(pu32BaseAddress + 1);
	/* Jump to Application Reset Vector */
	pfunc();
}
