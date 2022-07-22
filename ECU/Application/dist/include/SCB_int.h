/*
 * SCB_int.h
 *
 *  Created on: Jan 30, 2020
 *      Author: sondo
 */
/************************************************************************/
/* Author  : Sondos Aly	                                                */
/* Date    : 30/1/2020                                                  */
/* Version : V01	                                                    */
/************************************************************************/
/* Modification Log                                                     */
/* -----------------                                                    */
/*     Name     |    Version    |                 Changes               */
/*  Sondos 		        V01                      First Creation         */
/************************************************************************/

#ifndef SCB_INT_H_
#define SCB_INT_H_

/*****************************************/
/***********Public Definitions************/
/*****************************************/


/*****************************************/
/***********Public Functions**************/
/*****************************************/
/****************************************************************************************/
/* Description: Setting Interrupt Vector Table Base address	 							*/
/* Input      : u32 u32VTORBaseAddress                                                 	*/
/*              Description: Address to set the VTOR to			                        */
/* 				Range: 	u32																*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void SCB_vidSetInterruptVectorTable(u32 u32VTORBaseAddress);


/****************************************************************************************/
/* Description: Perform Soft Reset							 							*/
/* Input      : Void				                                                 	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void SCB_vidPerformSoftReset(void);

#endif /* SCB_INT_H_ */
