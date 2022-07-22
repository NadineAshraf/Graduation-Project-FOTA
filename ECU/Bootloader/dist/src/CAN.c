/*----------------------------------------------------------------------------
 * Name:    Can.c
 * Purpose: CAN interface for STM32
 * Version: V1.01
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * Copyright (c) 2005-2007 Keil Software. All rights reserved.
 *----------------------------------------------------------------------------*/

//#include <stm32f10x_lib.h>                        // STM32F10x Library Definitions

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "STD_Types.h"
#include "util.h"
#include "RCC_cfg.h"
#include "RCC_int.h"
#include "NVIC_int.h"
#include "CAN_priv.h"                              // STM32 CAN adaption layer
#include "CAN.h"



//#include "STM32_Reg.h"                            // STM32 register and bit Definitions
//#include "STM32_Init.h"                           // STM32 Initialization
//#include"stm32f10x_rcc.h"
//#include"stm32f10x_can.h"



CAN_msg       CAN_TxMsg[3];                          // CAN messge for sending
CAN_msg       CAN_RxMsg[3];                          // CAN message for receiving

u8  CAN_TxRdy[3] = {0};                      // CAN HW ready to transmit a message
u8  CAN_RxRdy = {0};                      // CAN HW received a message
u32  filt_counter;

u8 value_0[8];
u8 u8MailBox0Flag;
u8 value_1[8];
u8 u8MailBox1Flag;
u8 value_2[8];
u8 u8MailBox2Flag;




/*----------------------------------------------------------------------------
  setup CAN interface
 *----------------------------------------------------------------------------*/
void CAN_setup (void)  {
	u32 brp =  36000000;			//clock 36Mhz (salma)

	CAN1->MCR = (CAN_MCR_INRQ);       				// init mode, enable auto. retransmission                                         // Note: only FIFO 0, transmit mailbox 0 used
	CAN1->MCR |= (1<<CAN_MCR_TXFP); 					//Transmit priority by request order
	CAN1->IER = (CAN_IER_FMPIE0 | CAN_IER_TMEIE);    // FIFO 0 msg pending, Transmit mbx empty (enable interrupts)

	/* Note: this calculations fit for PCLK1 = 36MHz */
	brp  = (brp / 18) / 500000;                     // baudrate is set to 500k bit/s

	/* set BTR register so that sample point is at about 72% bit time from bit start */
	/* TSEG1 = 12, TSEG2 = 5, SJW = 4 => 1 CAN bit = 18 TQ, sample at 72%    */
	CAN1->BTR &= ~(((        0x03) << 24) | ((        0x07) << 20) | ((         0x0F) << 16) | (          0x1FF));
	CAN1->BTR |=  ((((4-1) & 0x03) << 24) | (((5-1) & 0x07) << 20) | (((12-1) & 0x0F) << 16) | ((brp-1) & 0x1FF));


}


/*----------------------------------------------------------------------------
  leave initialisation mode
 *----------------------------------------------------------------------------*/
void CAN_start (void)  {

	CAN1->MCR &= ~(CAN_MCR_INRQ);                      // normal operating mode, reset INRQ
	while (CAN1->MSR & CAN_MCR_INRQ);

}

/*----------------------------------------------------------------------------
  set the testmode
 *----------------------------------------------------------------------------*/
void CAN_testmode (u32 testmode) {

	CAN1->BTR &= ~(CAN_BTR_SILM | CAN_BTR_LBKM);     // set testmode

	CAN1->BTR |=  (testmode & (CAN_BTR_SILM | CAN_BTR_LBKM));

}

/*----------------------------------------------------------------------------
  check if transmit mailbox is empty
 *----------------------------------------------------------------------------*/
void CAN_waitReady (void)  {

	while ((CAN1->TSR & CAN_TSR_TME0) == 0);         // Transmit mailbox 0 is empty
	while ((CAN1->TSR & CAN_TSR_TME1) == 0);         // Transmit mailbox 1 is empty
	while ((CAN1->TSR & CAN_TSR_TME2) == 0);         // Transmit mailbox 2 is empty

	CAN_TxRdy[0] = 1;
	CAN_TxRdy[1] = 1;
	CAN_TxRdy[2] = 1;

}

/*----------------------------------------------------------------------------
  wite a message to CAN peripheral and transmit it
 *----------------------------------------------------------------------------*/
void CAN_wrMsg (CAN_msg *msg, u8 u8MailBox)  {

	CAN1->sTxMailBox[u8MailBox].TIR  = (u32)0;      // Reset TIR register
	// Setup identifier information
	if (msg->format == STANDARD_FORMAT)
	{
		CAN1->sTxMailBox[u8MailBox].TIR |= (u32)(msg->id << 21) | (CAN_ID_STD);
	}
	else
	{    // Extended ID

		CAN1->sTxMailBox[u8MailBox].TIR |= (u32)(msg->id <<  3) | (CAN_ID_EXT);
	}
	// Setup type information
	if (msg->type == DATA_FRAME)
	{                 // DATA FRAME
		CAN1->sTxMailBox[u8MailBox].TIR |= (CAN_RTR_DATA);
		CAN1->sTxMailBox[u8MailBox].TDLR = (((u32)msg->data[3] << 24) |
				((u32)msg->data[2] << 16) |
				((u32)msg->data[1] <<  8) |
				((u32)msg->data[0])        );
		CAN1->sTxMailBox[u8MailBox].TDHR = (((u32)msg->data[7] << 24) |
				((u32)msg->data[6] << 16) |
				((u32)msg->data[5] <<  8) |
				((u32)msg->data[4])        );
	}
	else
	{                  // REMOTE FRAME
		CAN1->sTxMailBox[u8MailBox].TIR |= (CAN_RTR_REMOTE);
	}
	// Setup length
	CAN1->sTxMailBox[u8MailBox].TDTR &= ~CAN_TDTxR_DLC;
	CAN1->sTxMailBox[u8MailBox].TDTR |=  (msg->len & CAN_TDTxR_DLC);

	CAN1->IER |= CAN_IER_TMEIE;                      // enable  TME interrupt                     // enable  TME interrupt
	CAN1->sTxMailBox[u8MailBox].TIR |=  CAN_TIxR_TXRQ;       // transmit message
}

//void CAN_wrMsg_1 (CAN_msg *msg)  {
//
//	//CAN1->sTxMailBox[1].TIR  = (u32)0;      // Reset TIR register
//	CAN1->sTxMailBox[1].TIR  = 0x00000000;
//	// Setup identifier information
//	if (msg->format == STANDARD_FORMAT)
//	{
//		CAN1->sTxMailBox[1].TIR |= (u32)(msg->id << 21) | (CAN_ID_STD);
//	}
//	else
//	{    // Extended ID
//
//		CAN1->sTxMailBox[1].TIR |= (u32)(msg->id <<  3) | (CAN_ID_EXT);
//	}
//	// Setup type information
//	if (msg->type == DATA_FRAME)
//	{                 // DATA FRAME
//		CAN1->sTxMailBox[1].TIR |= (CAN_RTR_DATA);
//	}
//	else
//	{                  // REMOTE FRAME
//		CAN1->sTxMailBox[1].TIR |= (CAN_RTR_REMOTE);
//	}
//	// Setup data bytes
//	CAN1->sTxMailBox[1].TDLR = (((u32)msg->data[3] << 24) |
//			((u32)msg->data[2] << 16) |
//			((u32)msg->data[1] <<  8) |
//			((u32)msg->data[0])        );
//	CAN1->sTxMailBox[1].TDHR = (((u32)msg->data[7] << 24) |
//			((u32)msg->data[6] << 16) |
//			((u32)msg->data[5] <<  8) |
//			((u32)msg->data[4])        );
//	// Setup length
//	CAN1->sTxMailBox[1].TDTR &= ~CAN_TDTxR_DLC;
//
//	CAN1->sTxMailBox[1].TDTR |=  (msg->len & CAN_TDTxR_DLC);
//
//	CAN1->IER |= CAN_IER_TMEIE;                      // enable  TME interrupt
//	CAN1->sTxMailBox[1].TIR |=  CAN_TIxR_TXRQ;       // transmit message
//}
//
//void CAN_wrMsg_2 (CAN_msg *msg)  {
//
//	//CAN1->sTxMailBox[2].TIR  = (u32)0;      // Reset TIR register
//	CAN1->sTxMailBox[2].TIR  = 0x00000000;
//	// Setup identifier information
//	if (msg->format == STANDARD_FORMAT)
//	{
//		CAN1->sTxMailBox[2].TIR |= (u32)(msg->id << 21) | (CAN_ID_STD);
//	}
//	else
//	{    // Extended ID
//
//		CAN1->sTxMailBox[2].TIR |= (u32)(msg->id <<  3) | (CAN_ID_EXT);
//	}
//	// Setup type information
//	if (msg->type == DATA_FRAME)
//	{                 // DATA FRAME
//		CAN1->sTxMailBox[2].TIR |= (CAN_RTR_DATA);
//	}
//	else
//	{                  // REMOTE FRAME
//		CAN1->sTxMailBox[2].TIR |= (CAN_RTR_REMOTE);
//	}
//	// Setup data bytes
//	CAN1->sTxMailBox[2].TDLR = (((u32)msg->data[3] << 24) |
//			((u32)msg->data[2] << 16) |
//			((u32)msg->data[1] <<  8) |
//			((u32)msg->data[0])        );
//	CAN1->sTxMailBox[2].TDHR = (((u32)msg->data[7] << 24) |
//			((u32)msg->data[6] << 16) |
//			((u32)msg->data[5] <<  8) |
//			((u32)msg->data[4])        );
//	// Setup length
//	CAN1->sTxMailBox[2].TDTR &= ~CAN_TDTxR_DLC;
//	CAN1->sTxMailBox[2].TDTR |=  (msg->len & CAN_TDTxR_DLC);
//	CAN1->IER |= CAN_IER_TMEIE;                      // enable  TME interrupt
//	CAN1->sTxMailBox[2].TIR |=  CAN_TIxR_TXRQ;       // transmit message
//}



/*----------------------------------------------------------------------------
  read a message from CAN peripheral and release it
 *----------------------------------------------------------------------------*/
void CAN_rdMsg_0 (CAN_msg *msg)  {
	// Read identifier information
	if ((CAN1->sFIFOMailBox[0].RIR & CAN_ID_EXT) == 0) { // Standard ID

		msg->format = STANDARD_FORMAT;


		msg->id     = (u32)0x000007FF & (CAN1->sFIFOMailBox[0].RIR >> 21);
	}  else  {                                          // Extended ID
		msg->format = EXTENDED_FORMAT;

		msg->id     = (u32)0x0003FFFF & (CAN1->sFIFOMailBox[0].RIR >> 3);
	}
	// Read type information
	if ((CAN1->sFIFOMailBox[0].RIR & CAN_RTR_REMOTE) == 0) {

		msg->type =   DATA_FRAME;                     // DATA   FRAME

	}  else  {
		msg->type = REMOTE_FRAME;                   // REMOTE FRAME
	}
	// Read length (number of received bytes)
	msg->len = (u8)0x0000000F & CAN1->sFIFOMailBox[0].RDTR;
	// Read data bytes
	msg->data[0] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR);
	msg->data[1] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 8);
	msg->data[2] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 16);
	msg->data[3] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 24);

	msg->data[4] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR);
	msg->data[5] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 8);
	msg->data[6] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 16);
	msg->data[7] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 24);
	CAN_vidReleaseMessage();
}

void CAN_wrFilter (filter_type *pstrfilter)  {
	static unsigned short CAN_filterIdx = 0;
	u32   CAN_msgId     = 0;

	if (CAN_filterIdx > 13) {                       // check if Filter Memory is full
		return;
	}
	// Setup identifier information
	if (pstrfilter->u8Type == STANDARD_FORMAT)  {               // Standard ID
		CAN_msgId  |= (u32)(pstrfilter->u8Id << 21) | CAN_ID_STD;

	}  else  {                                      // Extended ID
		CAN_msgId  |= (u32)(pstrfilter->u8Id <<  3) | CAN_ID_EXT;
	}
	if (pstrfilter->u8Frame == REMOTE_FRAME)  {               // Standard ID
		CAN_msgId  |= CAN_RTR_REMOTE;
	}
	else
	{

	}
	CAN1->FA1R &=  ~(u32)(1 << CAN_filterIdx); // deactivate filter

	// initialize filter
	CAN1->FS1R |= (u32)(1 << CAN_filterIdx);// set 32-bit scale configuration
	CAN1->FM1R |= (u32)(1 << CAN_filterIdx);// set 2 32-bit identifier list mode

	CAN1->sFilterRegister[CAN_filterIdx].FR1 = CAN_msgId; //  32-bit identifier
	CAN1->sFilterRegister[CAN_filterIdx].FR2 = CAN_msgId; //  32-bit identifier

	CAN1->FFA1R &= ~(u32)(1 << CAN_filterIdx);  // assign filter to FIFO 0
	CAN1->FA1R  |=  (u32)(1 << CAN_filterIdx);  // activate filter

	CAN_filterIdx += 1;                             // increase filter index
}




void CAN_vidReleaseMessage(void)
{
	CAN1->RF0R |= CAN_RF0R_RFOM0;
}

u8 CAN_u8GetNumberOfPendingMessage(void)
{
	return ((CAN1->RF0R) & (0x00000003));
}

void CAN_vid_filter_list(filter_type *pstrfilters,u8 no_of_filters)
{
	CAN1->FMR  |=  CAN_FMR_FINIT;						// set Initialisation mode for filter banks
	for (filt_counter=0 ; filt_counter<no_of_filters ; filt_counter++)
	{
		CAN_wrFilter (&(pstrfilters[filt_counter]));             // Enable reception of messages
	}
	CAN1->FMR &= ~(CAN_FMR_FINIT);						// reset Initialisation mode for filter banks
}

/*----------------------------------------------------------------------------
  CAN transmit interrupt handler
 *----------------------------------------------------------------------------*/
void USB_HP_CAN1_TX_IRQHandler (void) {

	if (CAN1->TSR & (CAN_TSR_RQCP0)) 						  // request completed mbx 0
	{
		CAN1->TSR |= (CAN_TSR_RQCP0);                    // reset request complete mbx 0
		CAN1->IER &= ~(CAN_IER_TMEIE);                   // disable  TME interrupt
		CAN_TxRdy[0] = 1;
	}
	if (CAN1->TSR & (CAN_TSR_RQCP1)) 						// request completed mbx 1
	{
		CAN1->TSR |= (CAN_TSR_RQCP1);                    // reset request complete mbx 1
		CAN1->IER &= ~(CAN_IER_TMEIE);                   // disable  TME interrupt
		CAN_TxRdy[1] = 1;

	}


	if (CAN1->TSR & (CAN_TSR_RQCP2)) 					 // request completed mbx 2
	{
		CAN1->TSR |= (CAN_TSR_RQCP2);                    // reset request complete mbx 2
		CAN1->IER &= ~(CAN_IER_TMEIE);                   // disable  TME interrupt
		CAN_TxRdy[2] = 1;
	}
}

/*----------------------------------------------------------------------------
  CAN receive interrupt handler
 *----------------------------------------------------------------------------*/
void USB_LP_CAN1_RX0_IRQHandler (void) {
	static u8 u8RxMsgIndex = 0;
	if (CAN1->RF0R & CAN__Msg_Pending)
	{			      // message pending ?
		if (CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag == 0)
		{
			CAN_rdMsg_0 (&(CAN_RxMsg[u8RxMsgIndex]));                     // read the message
			CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag = 1;
			CAN_RxRdy = 1;                                // set receive flag
			u8RxMsgIndex++;
			if (u8RxMsgIndex == 3)
			{
				u8RxMsgIndex = 0;
			}
		}
	}
}







