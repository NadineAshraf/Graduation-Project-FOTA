/*
 * SCB_prog.c
 *
 *  Created on: Jan 30, 2020
 *      Author: sondo
 */

#include "STD_Types.h"
#include "util.h"
#include "SCB_priv.h"
#include "SCB_int.h"

/******** SCB Registers Structure Initialization ************/
SCB* SCB_REG = SCB_BASEADDRESS;


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
void SCB_vidSetInterruptVectorTable(u32 u32VTORBaseAddress)
{
	SCB_REG->SCB_VTOR = u32VTORBaseAddress;
}


/****************************************************************************************/
/* Description: Perform Soft Reset							 							*/
/* Input      : Void				                                                 	*/
/* Output     : Void                                                                   	*/
/* Scope      : Public                                                                 	*/
/****************************************************************************************/
void SCB_vidPerformSoftReset(void)
{
	SCB_REG->SCB_AIRCR = (0x05FA << VECTKEY) | (1 << SYSRESETREQ);
	while(1);
}





