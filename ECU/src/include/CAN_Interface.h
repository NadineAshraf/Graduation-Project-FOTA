/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : May 12, 2022                               */
/* 								Module	 : CAN                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef CAN_INTERFACE_H_
#define CAN_INTERFACE_H_
									/* New Data-types Definitions */
/* CAN Message */
typedef struct  {
  u32   id;               // ( 11 + 18 ) bits identifier => ( 11 bits for standard id) or ( [11 + 18] bits for extended id)
  u8  data[8];            // Data field
  u8  len;                // Length of data field in bytes
  u8  format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  u8  type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
  u8 u8ActiveFlag;	      // Active flag
} CAN_Msg;
/* CAN Filter */
typedef struct
{
	u8 Id;
	u8 Frame;
	u8 Type;
}Filter_Type;
									/* Interface Macros */
/* CAN Frame Types */
#define CAN_DATA_FRAME      0
#define CAN_REMOTE_FRAME    1

/* CAN FIFO Mailbox Indexes */
#define CAN_FIFO_MB_0       0
#define CAN_FIFO_MB_1       1

/* CAN Message Id Formats */
#define CAN_STANDARD_ID     0
#define CAN_EXTENDED_ID     1

/* CAN Test Modes */
#define CAN_NO_TST	        0
#define CAN_SILENT	        1
#define CAN_LBK             2
#define CAN_SILENT_LBK      3

									/* Function Prototypes */
void CAN_vidInit();
void CAN_vidStart();
void CAN_vidSendMsg(u32 Copy_u8MsgId , u8* MsgData , u8 Copy_u8MsgDataLength , u8 Copy_u8MsgIdFormat , u8 Copy_u8MsgType);
void CAN_vidSetTestMode(u8 Copy_u32TestMode);
void CAN_vidTransmitMsg(CAN_Msg* msg , u8 Copy_u8MailBoxIndex);
void CAN_vidReadMsg(CAN_Msg* msg , u8 Copy_u8FIFOMailBoxIndex);
void CAN_vidWaitReady();
void CAN_vidReleaseMessage(u8 Copy_u8FIFOMailBoxIndex);
u8 CAN_u8GetNumberOfPendingMessage(u8 Copy_u8FIFOMailBoxIndex);
void CAN_vidWriteFilter(Filter_Type *pstrfilter);
void CAN_vidFilterList(Filter_Type *pstrfilter,u8 Copy_u8NumOfFilters);
u8 CAN_u8GetFilterMatchIndex();
//void CAN_vidSetMode(u32 Copy_u32Mode);
/***********************************************************************************************************/
/* Some extern variables */
extern CAN_Msg CAN_TxMsg[3];      // CAN messge for sending
extern CAN_Msg CAN_RxMsg[3];      // CAN message for receiving
extern u8  CAN_TxRdy[3];          // CAN HW ready to transmit a message
extern u8  CAN_RxRdy;             // CAN HW received a message

#endif /* CAN_INTERFACE_H_ */
