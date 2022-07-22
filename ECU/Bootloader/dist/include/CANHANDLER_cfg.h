/*
 * CANHANDLER_cfg.h
 *
 *  Created on: Feb 5, 2020
 *      Author: sondo
 */

#ifndef CANHANDLER_CFG_H_
#define CANHANDLER_CFG_H_

/* Description:	Maximum Number of Filters ion filters array					*/
/* Range:		1 ~ 13														*/
#define CANHANDLER_u8MAXFILTERNUMBERS		3


/* Description:	Tx Message IDs												*/
/* Range:		u8															*/
#define CANHANDLER_u8UPDATEREQUESTID		40
#define CANHANDLER_u8HEXFILEID				45
#define CANHANDLER_u8NEXTMSGREQUEST			60
#define CANHANDLER_u8ECUSWVERSION			80
#define CANHANDLER_u8GETFLASHBANK			90
#define CANHANDLER_u8ECUDTCs				25

/* Description:	Rx Message IDs												*/
/* Range:		u8															*/


#endif /* CANHANDLER_CFG_H_ */
