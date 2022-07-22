/*
 * CANHANDLER_int.h
 *
 *  Created on: Feb 5, 2020
 *      Author: sondo
 */

#ifndef CANHANDLER_INT_H_
#define CANHANDLER_INT_H_


/*****************************************/
/***********Public Definitions************/
/*****************************************/
/* Can Frame Types Definitions */
#define CAN_u8REMOTEFRAME	1
#define CAN_u8DATAFRAME		0


/*****************************************/
/***********Public Functions**************/
/*****************************************/
/****************************************************************************************/
/* Description: Send Can Message 							 							*/
/* Input      : u8 u8MessageID		                                                	*/
/*              Description: ID of the message to send over CAN			                */
/* 				Range: 	u8																*/
/*				u8 u8Frame																*/
/*              Description: Type of Frame								                */
/* 				Range: 	CAN_u8REMOTEFRAME, CAN_u8DATAFRAME										*/
/*				u8* pu8Data																*/
/*              Description: Array containing data to send over CAN, NULL if Remote Fram*/
/* 				Range: 	u8*																*/
/*				u8 u8DataLength															*/
/*              Description: Length of Data to be sent in bytes							*/
/* 				Range: 	0 ~ 8															*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void CANHANDLER_vidSend(u8 u8MessageID, u8 u8Frame,u8* pu8Data, u8 u8DataLength);



#endif /* CANHANDLER_INT_H_ */
