/*----------------------------------------------------------------------------
 * Name:    CAN.h
 * Purpose: CAN interface for STM32
 * Version: V1.00
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * Copyright (c) 2005-2007 Keil Software. All rights reserved.
 *----------------------------------------------------------------------------*/

#ifndef _CAN_H_
#define _CAN_H_

#define STANDARD_FORMAT  0
#define EXTENDED_FORMAT  1

#define DATA_FRAME       0
#define REMOTE_FRAME     1

typedef struct  {
  u32   id;                 // 29 bit identifier
  u8  data[8];            // Data field
  u8  len;                // Length of data field in bytes
  u8  format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER
  u8  type;               // 0 - DATA FRAME, 1 - REMOTE FRAME
  u8 u8ActiveFlag;			//active flag by sondos
} CAN_msg;



typedef struct
{
	u8 u8Id;
	u8 u8Frame;
	u8 u8Type;
}filter_type;
/* Functions defined in module CAN.c */
void CAN_setup         (void);
void CAN_init          (void);
void CAN_start         (void);
void CAN_waitReady     (void);
void CAN_wrMsg      (CAN_msg *msg, u8 u8MailBox);
void CAN_rdMsg_0        (CAN_msg *msg);
void CAN_rdMsg_1        (CAN_msg *msg);
void CAN_wrFilter      (filter_type *pstrfilter);

void CAN_testmode      (u32 testmode);

void CAN_vidReleaseMessage(void);
u8 CAN_u8GetNumberOfPendingMessage(void);
void CAN_vid_filter_list(filter_type *pstrfilter,u8 no_of_filters);

extern CAN_msg       CAN_TxMsg[3];      // CAN messge for sending
extern CAN_msg       CAN_RxMsg[3];      // CAN message for receiving
extern u8  CAN_TxRdy[3];      // CAN HW ready to transmit a message
extern u8  CAN_RxRdy;      // CAN HW received a message

extern u8 u8MailBox0Flag;
extern u8 u8MailBox1Flag;
extern u8 u8MailBox2Flag;


#endif // _CAN_H_


