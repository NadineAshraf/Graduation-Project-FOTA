/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : May 12, 2022                               */
/* 								Module	 : CAN                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CAN_Interface.h"
#include "CAN_Private.h"
#include "CAN_Config.h"

/* Some Variables Declarations */
CAN_Msg CAN_TxMsg[3];                          // CAN message for sending
CAN_Msg CAN_RxMsg[3];                          // CAN message for receiving
u8 CAN_TxRdy[3] = {0};                         // CAN HW ready to transmit a message
u8 CAN_RxRdy = 0;                              // CAN HW received a message
u32 filt_counter;

/* CAN Setup and Initialization */
void CAN_vidInit()
{
	/* APB1 clock = 36MHz (MAX Clock for APB1)*/
	u32 brp =  36000000;

//	/* Disable Debug Freeze Mode */
//	CAN1->MCR |= 0x00010000;

	/* Setup CAN To Enter Initialization Mode With Automatic Retransmission Enabled */
	CAN1->MCR = CAN_INIT_MODE;

	/* Setup CAN Transmission To Be Driven By FIFO Priority (Priority driven by the request order and not message ID priority) */
	CAN1->MCR |= CAN_MSG_FIFO_PRIORTY;

	/* Enable Transmit mailbox empty,FIFO0 message pending and FIFO1 message pending Interrupts */
	CAN1->IER |= (CAN_TMEIE | CAN_FMPIE0 | CAN_FMPIE1);
	/*
	 * Setup Bit Timing For CAN Frame
	 * Note: These calculations fit for PCLK1 = 36MHz
	 */
	brp  = (brp / 18) / 500000;                     // BaudRate is set to 500k bit/s

	/* Set BTR register so that sample point is at about 72% bit time from bit start */
	/* TSEG1 = 12, TSEG2 = 5, SJW = 4 => 1 CAN bit = 18 TQ, sample at 72% */
	CAN1->BTR &= ~(((        0x03) << 24) | ((        0x07) << 20) | ((         0x0F) << 16) | (          0x1FF));
	CAN1->BTR |=  ((((4-1) & 0x03) << 24) | (((5-1) & 0x07) << 20) | (((12-1) & 0x0F) << 16) | ((brp-1) & 0x1FF));

}
/* Get CAN Into Operational Mode of Transmitting and Receiving (Leave initialization mode to normal mode) */
void CAN_vidStart()
{
	/* Setup CAN To Enter Operating Normal Mode */
	CAN1->MCR &= ~(CAN_INIT_MODE) ;
	/* Wait Until Normal Mode Is Confirmed By the Hardware By Clearing the INAK Bit in the CAN_MSR Register */
	while (CAN1->MSR & CAN_INIT_ACK);
}
/* Check If TxMailboxes are Empty */
void CAN_vidWaitReady()
{
	/* Check If Transmit MailBox 0 is Empty */
	while ((CAN1->TSR & CAN_TME0) == 0);
	/* Check If Transmit MailBox 1 is Empty */
	while ((CAN1->TSR & CAN_TME1) == 0);
	/* Check If Transmit MailBox 0 is Empty */
	while ((CAN1->TSR & CAN_TME2) == 0);
	/* Confirming That TxMailboxes are Empty */
	CAN_TxRdy[0] = 1;
	CAN_TxRdy[1] = 1;
	CAN_TxRdy[2] = 1;
}
/* Write CAN Frame Contents and Features To Be Send in a Free TxMailbox If any */
void CAN_vidSendMsg(u32 Copy_u8MsgId , u8* MsgData , u8 Copy_u8MsgDataLength , u8 Copy_u8MsgIdFormat , u8 Copy_u8MsgType)
{
	u8 local_u8MailboxIndex;      // Index of current TxMailbox
	u8 local_u8DataBytesCounter;  // A counter for bytes of CAN message data

	/* Check Which TxMailbox is Empty */
	for (local_u8MailboxIndex = 0 ; local_u8MailboxIndex < 3 ; local_u8MailboxIndex++)
	{
		if(CAN_TxRdy[local_u8MailboxIndex] == 1)
		{
			break;
		}
	}
	/* If no TxMailbox is empty ==> End the function and return the TxMailbox index to be 3 (Non is Empty) */
	if(local_u8MailboxIndex == 3)
	{
		return ;
	}
	/* Writing of CAN message contents and features */
	/* Load Message Identifier */
	CAN_TxMsg[local_u8MailboxIndex].id = Copy_u8MsgId;
	/*
	 * Check the CAN frame type :
	 * In Case of CAN_DATA_FRAME   ==> There is data to be loaded
	 * In Case of CAN_REMOTE_FRAME ==> There is no data to be loaded
	 */
	if (Copy_u8MsgType == CAN_DATA_FRAME)
	{
		for(local_u8DataBytesCounter = 0 ; local_u8DataBytesCounter < Copy_u8MsgDataLength ; local_u8DataBytesCounter++)
		{
			/* Load Message Data */
			CAN_TxMsg[local_u8MailboxIndex].data[local_u8DataBytesCounter] = MsgData[local_u8DataBytesCounter];
		}
	}
	/* Load Message Data Length */
	CAN_TxMsg[local_u8MailboxIndex].len = Copy_u8MsgDataLength;
	/* Load Message Identifier Format */
	CAN_TxMsg[local_u8MailboxIndex].format = Copy_u8MsgIdFormat;
	/* Load Message Type */
	CAN_TxMsg[local_u8MailboxIndex].type = Copy_u8MsgType;
	/* Current TxMailBox is Not Empty*/
	CAN_TxRdy[local_u8MailboxIndex] = 0;
	/* Request To Transmit The Message */
	CAN_vidTransmitMsg(&(CAN_TxMsg[local_u8MailboxIndex]), local_u8MailboxIndex);
}
/* Set CAN Controller Test Mode */
void CAN_vidSetTestMode(u8 Copy_u32TestMode)
{
	/* Clear Silent and Loop Back bits in BTR Register */
	CAN1->BTR &= ~(CAN_SILENT_TST_MODE | CAN_LBK_TST_MODE);
	/* Check Which Test Mode To Be Applied */
	switch(Copy_u32TestMode)
	{
	case CAN_SILENT:     // Silent Mode
		CAN1->BTR |= CAN_SILENT_TST_MODE;
		break;
	case CAN_LBK:        // Loop Back Mode
		CAN1->BTR |= CAN_LBK_TST_MODE;
		break;
	case CAN_SILENT_LBK: // Silent Combined With Loop Back Mode
		CAN1->BTR |= CAN_SILENT_LBK_TST_MODE;
		break;
	}
}
/* Request For Transmitting A Message Through CAN Bus */
void CAN_vidTransmitMsg(CAN_Msg* msg , u8 Copy_u8MailBoxIndex)
{
	if(Copy_u8MailBoxIndex < 3)
	{
		/* Reset TIR Register */
		CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR = (u32)0 ;
		/* Check The Format of Message Identifier */
		if(msg->format == CAN_STANDARD_ID)
		{
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR |= (u32)(msg->id << 21) | (u32) (CAN_ID_STD);
		}
		else if(msg->format == CAN_EXTENDED_ID)
		{
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR |= (u32)(msg->id << 3) | (CAN_ID_EXT);
		}
		else
		{
			/* Return Error */
		}
		/* Check The Type of Message */
		if(msg->type == CAN_RTR_DATA)
		{
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR |= CAN_RTR_DATA;
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TDLR = (((u32)msg->data[3] << 24) |
					((u32)msg->data[2] << 16) |
					((u32)msg->data[1] <<  8) |
					((u32)msg->data[0]));
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TDHR = (((u32)msg->data[7] << 24) |
					((u32)msg->data[6] << 16) |
					((u32)msg->data[5] <<  8) |
					((u32)msg->data[4]));
		}
		else if(msg->type == CAN_RTR_REMOTE)
		{
			CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR |= CAN_RTR_REMOTE;
		}
		else
		{
			/* Return Error */
		}
		/* Reset TDTR Register */
		CAN1->sTxMailBox[Copy_u8MailBoxIndex].TDTR  = (u32)0 ;
		CAN1->sTxMailBox[Copy_u8MailBoxIndex].TDTR |= (u32)(msg[Copy_u8MailBoxIndex].len);
		/* Enable Transmit mailbox empty Interrupt */
		CAN1->IER |= CAN_TMEIE;
		/* Request For Transmission For The Corresponding mailbox */
		CAN1->sTxMailBox[Copy_u8MailBoxIndex].TIR |= CAN_TXRQ;
	}
	else
	{
		/* Return Error */
	}
}
/* Read Pending Received Message in One of RxFIFOMailboxes Then Release It */
void CAN_vidReadMsg(CAN_Msg* msg , u8 Copy_u8FIFOMailBoxIndex)
{
	if(Copy_u8FIFOMailBoxIndex == CAN_FIFO_MB_0)
	{
		/* Read Identifier Information */
		if ((CAN1->sFIFOMailBox[0].RIR & CAN_ID_EXT) == 0) { // Standard ID

			msg->format = CAN_STANDARD_ID;


			msg->id     = (u32)0x000007FF & (CAN1->sFIFOMailBox[0].RIR >> 21);
		}  else  {                                          // Extended ID
			msg->format = CAN_EXTENDED_ID;

			msg->id     = (u32)0x0003FFFF & (CAN1->sFIFOMailBox[0].RIR >> 3);
		}
		/* Read Type Information */
		if ((CAN1->sFIFOMailBox[0].RIR & CAN_RTR_REMOTE) == 0) {

			msg->type = CAN_DATA_FRAME;                     // DATA FRAME

		}  else  {
			msg->type = CAN_REMOTE_FRAME;                   // REMOTE FRAME
		}
		/* Read Length (Number of received bytes) */
		msg->len = (u8)0x0000000F & CAN1->sFIFOMailBox[0].RDTR;
		/* Read Data Bytes */
		msg->data[0] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR);
		msg->data[1] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 8);
		msg->data[2] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 16);
		msg->data[3] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDLR >> 24);

		msg->data[4] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR);
		msg->data[5] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 8);
		msg->data[6] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 16);
		msg->data[7] = (u32)0x000000FF & (CAN1->sFIFOMailBox[0].RDHR >> 24);
		CAN_vidReleaseMessage(CAN_FIFO_MB_0);
	}
	else if(Copy_u8FIFOMailBoxIndex == CAN_FIFO_MB_1)
	{
		/* Read Identifier Information */
		if ((CAN1->sFIFOMailBox[1].RIR & CAN_ID_EXT) == 0) { // Standard ID

			msg->format = CAN_STANDARD_ID;

			msg->id     = (u32)0x000007FF & (CAN1->sFIFOMailBox[1].RIR >> 21);
		}  else  {                                          // Extended ID
			msg->format = CAN_EXTENDED_ID;

			msg->id     = (u32)0x0003FFFF & (CAN1->sFIFOMailBox[1].RIR >> 3);
		}
		/* Read Type Information */
		if ((CAN1->sFIFOMailBox[1].RIR & CAN_RTR_REMOTE) == 0) {

			msg->type = CAN_DATA_FRAME;                     // DATA FRAME

		}  else  {
			msg->type = CAN_REMOTE_FRAME;                   // REMOTE FRAME
		}
		/* Read Length (Number of received bytes) */
		msg->len = (u8)0x0000000F & CAN1->sFIFOMailBox[1].RDTR;
		/* Read Data Bytes */
		msg->data[0] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDLR);
		msg->data[1] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDLR >> 8);
		msg->data[2] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDLR >> 16);
		msg->data[3] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDLR >> 24);

		msg->data[4] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDHR);
		msg->data[5] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDHR >> 8);
		msg->data[6] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDHR >> 16);
		msg->data[7] = (u32)0x000000FF & (CAN1->sFIFOMailBox[1].RDHR >> 24);
		CAN_vidReleaseMessage(CAN_FIFO_MB_1);
	}
	else
	{
		/* Return Error */
	}
}
/* Release RxFIFOMailbox */
void CAN_vidReleaseMessage(u8 Copy_u8FIFOMailBoxIndex)
{
	switch(Copy_u8FIFOMailBoxIndex)
	{
	case CAN_FIFO_MB_0:
		/* Release RxFIFOMailbox 0 */
		CAN1->RF0R |= CAN_RFOM0;
		break;
	case CAN_FIFO_MB_1:
		/* Release RxFIFOMailbox 1 */
		CAN1->RF1R |= CAN_RFOM1;
		break;
		//	default:
		//		/* Return Error */
	}
}
/* Get Number of Pending Messages of One of RxFIFOMailboxes */
u8 CAN_u8GetNumberOfPendingMessage(u8 Copy_u8FIFOMailBoxIndex)
{
	u8 local_u8Num = 0; // Number of pending messages
	if(Copy_u8FIFOMailBoxIndex ==  CAN_FIFO_MB_0)
	{
		local_u8Num = (u8)((CAN1->RF0R) & (CAN_FMP0));
	}
	else if(Copy_u8FIFOMailBoxIndex ==  CAN_FIFO_MB_1)
	{
		local_u8Num = (u8)((CAN1->RF1R) & (CAN_FMP1));
	}
	return local_u8Num;
}
/* Enable and Configure Mode and Scale of Specific Filter Bank To Be Ready For Message Reception */
void CAN_vidWriteFilter(Filter_Type *pstrfilter)
{
	static u16 CAN_filterIdx = 0;                              // Filter Bank Index
	u32   CAN_msgId     = 0;                                   // Message id to be compared with received message id
	/* Check If Filter Memory is Full */
	if (CAN_filterIdx > 13) {
		return;
	}
	/* Setup Identifier Information */
	if (pstrfilter->Type == CAN_STANDARD_ID)  {               // Standard ID
		CAN_msgId  |= (u32)(pstrfilter->Id << 21) | CAN_ID_STD;

	}  else  {                                                // Extended ID
		CAN_msgId  |= (u32)(pstrfilter->Id <<  3) | CAN_ID_EXT;
	}
	if (pstrfilter->Frame == CAN_REMOTE_FRAME)  {             // Remote Frame
		CAN_msgId  |= CAN_RTR_REMOTE;
	}
	else													  // Remote Frame
	{
		CAN_msgId  |= CAN_RTR_DATA;
	}
	/* Deactivate Filter */
	CAN1->FA1R &=  ~(u32)(1 << CAN_filterIdx);

	/* Initialize Filter Bank */
	/* Set 32-bit Scale Configuration */
	CAN1->FS1R |= (u32)(1 << CAN_filterIdx);
	/* Set Identifier List Mode Configuration ==> 2 32-bit Identifiers Registers (Filters)*/
	CAN1->FM1R |= (u32)(1 << CAN_filterIdx);
	/* 32-bit Identifier */
	CAN1->sFilterRegister[CAN_filterIdx].FR1 = CAN_msgId;
	CAN1->sFilterRegister[CAN_filterIdx].FR2 = CAN_msgId;
	/* Assign Filter Bank to FIFO 0 */
	CAN1->FFA1R &= ~(u32)(1 << CAN_filterIdx);
	/* Activate Filter Bank */
	CAN1->FA1R  |=  (u32)(1 << CAN_filterIdx);
	/* Increase Filter Bank Index */
	CAN_filterIdx += 1;
}
/* Setup List of Filters */
void CAN_vidFilterList(Filter_Type *pstrfilter,u8 Copy_u8NumOfFilters)
{
	/* Set Initialization Mode for Filter Banks */
	CAN1->FMR  |=  CAN_FINIT;
	for (filt_counter=0 ; filt_counter<Copy_u8NumOfFilters ; filt_counter++)
	{
		/* Enable Reception of Messages */
		CAN_vidWriteFilter(&(pstrfilter[filt_counter]));
	}
	/* Reset Initialization Mode for Filter Banks (Active Filter Mode) */
	CAN1->FMR &= ~(CAN_FINIT);
}
/* Get Filter Match Index Through it CAN Message Passed To RxFIFOMailBox0 */
u8 CAN_u8GetFilterMatchIndex()
{
	u8 local_u8Index ;
	local_u8Index = (u8)(((u32)0x000000FF) & (CAN1->sFIFOMailBox[0].RDTR >> 8));
	return local_u8Index;
}
/***************************************** CAN Interrupt Handlers********************************************/

/* CAN Transmit Interrupt Handler */
void USB_HP_CAN1_TX_IRQHandler (void)
{
	/* Check If the Transmission Request of TxMailbox0 is Completed */
	if (CAN1->TSR & (CAN_RQCP0))
	{
		/* Reset Transmission Request of TxMailbox0 */
		CAN1->TSR |= (CAN_RQCP0);
		/* Disable TME Interrupt */
		CAN1->IER &= ~(CAN_TMEIE);
		CAN_TxRdy[0] = 1;
	}
	/* Check If the Transmission Request of TxMailbox1 is Completed */
	else if (CAN1->TSR & (CAN_RQCP1))
	{
		/* Reset Transmission Request of TxMailbox1 */
		CAN1->TSR |= (CAN_RQCP1);
		/* Disable TME Interrupt */
		CAN1->IER &= ~(CAN_TMEIE);
		CAN_TxRdy[1] = 1;
	}
	/* Check If the Transmission Request of TxMailbox2 is Completed */
	else if (CAN1->TSR & (CAN_RQCP2))
	{
		/* Reset Transmission Request of TxMailbox2 */
		CAN1->TSR |= (CAN_RQCP2);
		/* Disable TME Interrupt */
		CAN1->IER &= ~(CAN_TMEIE);
		CAN_TxRdy[2] = 1;
	}
	else
	{
		/* Do Nothing */
	}
}
/* CAN Receive Interrupt Handler 0 */
void USB_LP_CAN1_RX0_IRQHandler (void) {
	static u8 u8RxMsgIndex = 0;
	if (CAN1->RF0R & CAN_FMP0)
	{			      // message pending ?
		if (CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag == 0)
		{
			CAN_vidReadMsg(&(CAN_RxMsg[u8RxMsgIndex]), CAN_FIFO_MB_0);  // Read the message
			CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag = 1;
			CAN_RxRdy = 1;                                              // Set receive flag
			u8RxMsgIndex++;
			if (u8RxMsgIndex == 3)
			{
				u8RxMsgIndex = 0;
			}
		}
	}
}
/* CAN Receive Interrupt Handler 1 */
void CAN_RX1_IRQHandler (void) {
	static u8 u8RxMsgIndex = 0;
	if (CAN1->RF0R & CAN_FMP1)
	{			      // message pending ?
		if (CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag == 0)
		{
			CAN_vidReadMsg(&(CAN_RxMsg[u8RxMsgIndex]), CAN_FIFO_MB_1);  // Read the message
			CAN_RxMsg[u8RxMsgIndex].u8ActiveFlag = 1;
			CAN_RxRdy = 1;                                              // Set receive flag
			u8RxMsgIndex++;
			if (u8RxMsgIndex == 3)
			{
				u8RxMsgIndex = 0;
			}
		}
	}
}
