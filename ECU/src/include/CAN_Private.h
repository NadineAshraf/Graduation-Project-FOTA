/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : May 12, 2022                               */
/* 								Module	 : CAN                                        */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef CAN_PRIVATE_H_
#define CAN_PRIVATE_H_

/*
 * bxCAN1 Peripheral Base Address :
 *
 * bxCAN1	: 0x40006400
 */

/* Definition of Registers Addresses of CAN */

typedef struct
{
  volatile u32 TIR;    							  // CAN TX mailbox identifier register
  volatile u32 TDTR;   							  // CAN mailbox data length control and time stamp register
  volatile u32 TDLR;   							  // CAN mailbox data low register
  volatile u32 TDHR;   							  // CAN mailbox data high register
} CAN_TxMailBox_TypeDef;


typedef struct
{
  volatile u32 RIR;   							  // CAN receive FIFO mailbox identifier register
  volatile u32 RDTR; 							  // CAN receive FIFO mailbox data length control and time stamp register
  volatile u32 RDLR; 							  // CAN receive FIFO mailbox data low register
  volatile u32 RDHR; 							  // CAN receive FIFO mailbox data high register
} CAN_RxFIFOMailBox_TypeDef;


typedef struct
{
  volatile u32 FR1; 							  // CAN Filter Bank Register 1
  volatile u32 FR2;							   	  // CAN Filter Bank Register 2
} CAN_FilterRegister_TypeDef;

typedef struct
{
  volatile u32 MCR;                               // CAN master control register
  volatile u32 MSR;                               // CAN master status register
  volatile u32 TSR;                               // CAN transmit status register
  volatile u32 RF0R;                              // CAN receive FIFO 0 register
  volatile u32 RF1R;                              // CAN receive FIFO 1 register
  volatile u32 IER;                               // CAN interrupt enable register
  volatile u32 ESR;                               // CAN error status register
  volatile u32 BTR;                               // CAN bit timing register
  u32 RESERVED0[88];							  // Reserved Bits
  CAN_TxMailBox_TypeDef sTxMailBox[3];            // The 3 Transmit MailBoxes of CAN
  CAN_RxFIFOMailBox_TypeDef sFIFOMailBox[2];      // The 2 Receive FIFO MailBoxes of CAN
  u32 RESERVED1[12];						      // Reserved Bits
  volatile u32 FMR;                               // CAN filter master register
  volatile u32 FM1R;                              // CAN filter mode register
  u32 RESERVED2;                                  // Reserved Bits
  volatile u32 FS1R;                              // CAN filter scale register
  u32 RESERVED3;                                  // Reserved Bits
  volatile u32 FFA1R;                             // CAN filter FIFO assignment register
  u32 RESERVED4;                                  // Reserved Bits
  volatile u32 FA1R;                              // CAN filter activation register
  u32 RESERVED5[8];                               // Reserved Bits
#ifndef STM32F10X_CL
  CAN_FilterRegister_TypeDef sFilterRegister[14]; // 14 CAN filter banks in case of low, medium and high density STM32F103xx
#else
  CAN_FilterRegister_TypeDef sFilterRegister[28]; // 28 CAN filter banks in case of connectivity line STM32F103xx
#endif /* STM32F10X_CL */
} CAN_TypeDef;

#define CAN1 ((CAN_TypeDef *) 0x40006400)

/* CAN Modes */
#define CAN_INIT_MODE   		 0x00000001
#define CAN_SLEEP_MODE 			 0x00000002

/* CAN Test Modes */
#define CAN_SILENT_TST_MODE  	 0x80000000
#define CAN_LBK_TST_MODE         0x40000000
#define CAN_SILENT_LBK_TST_MODE  0xC0000000
#define CAN_NO_TST_MODE 		 0x3FFFFFFF

/* CAN Transmission Available Priorities */
#define CAN_MSG_ID_PRORITY       0x00000000
#define CAN_MSG_FIFO_PRIORTY     0x00000004

/* CAN Acknowledge Signals */
#define CAN_INIT_ACK             0x00000001
#define CAN_SLEEP_ACK            0x00000002

/* CAN Transmission Signals */
#define CAN_RQCP0                0x00000001
#define CAN_RQCP1                0x00000100
#define CAN_RQCP2                0x00010000
#define CAN_TME0                 0x04000000
#define CAN_TME1                 0x08000000
#define CAN_TME2                 0x10000000

/* CAN Reception Signals */
#define CAN_FMP0        		 0x00000003
#define CAN_RFOM0        		 0x00000020
#define CAN_FMP1          		 0x00000003
#define CAN_RFOM1         		 0x00000020

/* CAN TX mailbox identifier register (CAN_TIxR) available configurations */
#define CAN_TXRQ                 0x00000001
#define CAN_ID_STD			     0x00000000
#define CAN_ID_EXT			     0x00000004
#define CAN_RTR_DATA		     0x00000000
#define CAN_RTR_REMOTE		     0x00000002

/* Signals of CAN interrupt enable register (CAN_IER) */
#define CAN_TMEIE                0x00000001
#define CAN_FMPIE0               0x00000002
#define CAN_FMPIE1               0x00000010

/* Filter Initialization Mode */
#define CAN_FINIT                0x00000001

#endif /* CAN_PRIVATE_H_ */
