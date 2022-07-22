/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include"STD_Types.h"
#include"util.h"
#include"RCC_int.h"
#include"DIO_int.h"
#include "DMA_int.h"
#include "DMA_priv.h"

#include"NVIC_int.h"
#include"AFIO_int.h"

#include"ADC_int.h"
#include"ADC_priv.h"
#include "Timer_int.h"
#include "SCB_int.h"
#include "FLASH_int.h"
#include "CAN.h"
#include "CANHANDLER_int.h"
#include "CANHANDLER_cfg.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F1 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

#define updated 		1
#define not_updated 	0

#define temp_sensor_state 	updated
#define light_sensor_state 	updated
#define IR_sensor_state 	updated

#define Error_TempSensor	0X50

volatile u8 v=0;
void check (void);

int
main(int argc, char* argv[])
{
	volatile f32 channel_reading[2]={0};
	u8 Error_array[10]={0};
	volatile u8 IR=0;

	u8 rxcount = 0;
	u8 au8version[3] = {0};
	u8 u8UsedBank = 0;
	filter_type filters[] =
	{
			{CANHANDLER_u8UPDATEREQUESTID,REMOTE_FRAME, STANDARD_FORMAT},
			{CANHANDLER_u8ECUSWVERSION,REMOTE_FRAME, STANDARD_FORMAT},
			{CANHANDLER_u8GETFLASHBANK, REMOTE_FRAME, STANDARD_FORMAT},
			{CANHANDLER_u8ECUDTCs, REMOTE_FRAME, STANDARD_FORMAT}
	};

	// Infinite loop
	RCC_vidInit();
	RCC_vidEnablePeripheral(RCC_u8GPIOACLK);
	RCC_vidEnablePeripheral(RCC_u8AFIOCLK);

	RCC_vidEnablePeripheral(RCC_u8GPIOCCLK);
	RCC_vidEnablePeripheral(RCC_u8ADC1CLK);
	RCC_vidEnablePeripheral(RCC_u8DMA1CLK);
	RCC_vidEnablePeripheral(RCC_u8TIM1CLK);

	DIO_vidInit();
	NVIC_vidInit();
	NVIC_vidEnableInterrupt(NVIC_u8ADC1_2);

	AFIO_voidinit();


	CAN_setup ();                                   // setup CAN interface
	CAN_vid_filter_list(filters,CANHANDLER_u8MAXFILTERNUMBERS);
	CAN_testmode(0);      // Normal, By Salma
	CAN_start ();                                   // leave init mode
	CAN_waitReady ();                               // wait til mbx is empty


	ADC_Init();

	while (1)
	{


		Reading_Channels(channel_reading);


#if temp_sensor_state == not_updated
		Error_array[0]=Error_TempSensor;

#elif temp_sensor_state == updated

		if (channel_reading[0]>0.0 && channel_reading[0]<30.0)
		{
			DIO_vidSetPinValue(DIO_u8PORTA,4,DIO_u8LOW);		// for motor
		}
		if (channel_reading[0]>=30.0 && channel_reading[0]<60.0)
		{
			DIO_vidSetPinValue(DIO_u8PORTA,4,DIO_u8HIGH);		// for motor
		}
		else
		{
			DIO_vidSetPinValue(DIO_u8PORTA,4,DIO_u8HIGH);		// for motor
			Error_array[0]=Error_TempSensor;
		}

#endif
#if IR_sensor_state == updated

		IR=DIO_u8GetPinValue(DIO_u8PORTA,2);
		if(IR==1)
		{
			DIO_vidSetPinValue(DIO_u8PORTA,3,DIO_u8LOW);		// for buzzer
		}
		else if(IR==0)
		{
			DIO_vidSetPinValue(DIO_u8PORTA,3,DIO_u8HIGH);		//for buzzer
		}

#elif IR_sensor_state == not_updated
		asm("NOP");

#endif

		if (CAN_RxRdy)
		{
			CAN_RxRdy = 0;
			if (CAN_RxMsg[rxcount].u8ActiveFlag == 1)
				switch (CAN_RxMsg[rxcount].id)
				{
				case CANHANDLER_u8UPDATEREQUESTID:
					RCC_vidResetResetFlags();
					SCB_vidPerformSoftReset();
					break;
				case CANHANDLER_u8ECUSWVERSION:
					CANHANDLER_vidSend(CANHANDLER_u8ECUSWVERSION,CAN_u8DATAFRAME,au8version,3);
					break;
				case CANHANDLER_u8GETFLASHBANK:
 					u8UsedBank = FLASH_u8GetOptionByteData(FLASH_u8OPTDATA0);
 					CANHANDLER_vidSend(CANHANDLER_u8GETFLASHBANK,CAN_u8DATAFRAME,&u8UsedBank,1);
					break;
				case CANHANDLER_u8ECUDTCs:
					CANHANDLER_vidSend(CANHANDLER_u8ECUDTCs,CAN_u8DATAFRAME,Error_array,1);
					break;
				}
			CAN_RxMsg[rxcount].u8ActiveFlag = 0;
			rxcount++;
			if (rxcount == 3)
			{
				rxcount = 0;
			}
		}
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
