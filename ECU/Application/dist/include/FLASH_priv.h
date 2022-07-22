/*
 * FLASH_priv.h
 *
 *  Created on: Sep 25, 2019
 *      Author: sondo
 */

#ifndef FLASH_PRIV_H_
#define FLASH_PRIV_H_


/* Register Description */
#define FLASH_ACR		(*((volatile u32*)  0x40022000))
#define FLASH_KEYR		(*((volatile u32*)  0x40022004))
#define FLASH_OPTKEYR	(*((volatile u32*)  0x40022008))
#define FLASH_SR		(*((volatile u32*)  0x4002200C))
#define FLASH_CR		(*((volatile u32*)  0x40022010))
#define FLASH_AR		(*((volatile u32*)  0x40022014))
#define FLASH_OBR		(*((volatile u32*)  0x4002201C))
#define FLASH_WRPR		(*((volatile u32*)  0x40022020))


/* Option Bytes Description */
#define FLASH_OPTRDPADRR			(*((volatile u16*)  0x1FFFF800))
#define FLASH_OPTUSERADDR			(*((volatile u16*)  0x1FFFF802))
#define FLASH_OPTDATA0ADDR			(*((volatile u16*)  0x1FFFF804))
#define FLASH_OPTDATA1ADDR			(*((volatile u16*)  0x1FFFF806))
#define FLASH_OPTWRP0ADDR			(*((volatile u16*)  0x1FFFF808))
#define FLASH_OPTWRP1ADDR			(*((volatile u16*)  0x1FFFF80A))
#define FLASH_OPTWRP2ADDR			(*((volatile u16*)  0x1FFFF80C))
#define FLASH_OPTWRP3ADDR			(*((volatile u16*)  0x1FFFF80E))

/* ACR Register Bits */
#define LATENCY		0
#define HLFCYA		3
#define PRFTBE		4
#define PRFTBS		5


/* SR Register Bits*/
#define BSY			0
#define ERLYBSY		1
#define PGERR		2
#define WRPRTERR	4
#define EOP			5


/* CR Register Bits */
#define PG			0
#define PER			1
#define MER			2
#define OPTPG		4
#define OPTER		5
#define STRT        6
#define LOCK        7
#define OPTWRE		9
#define ERRIE		10
#define EOPIE		12



/* OBR Register Bits */
#define OPTERR		0
#define RDPRT		1
#define WDG_SW		2
#define NRST_STOP	3
#define NRST_STDBY	4
#define DATA0		10
#define DATA1		18


/* Bits Status Definitions */
#define FLASH_u8LOCKED		1
#define FLASH_u8BSY			1



/* Flash Base Address */
#define FLASH_u32BASEADDRESS		0x08000000
#define FLASH_u16PAGESIZE			0x0400


/* Flash Unlock Key Definitions */
#define FLASH_u32KEY1				0x45670123
#define FLASH_u32KEY2				0xCDEF89AB


/* Half Word Definitions */
#define HALFWORDMASK				0x0000FFFF
#define HALFWORDOFFSET				16
#define	BYTEMASK						0x000000FF
/* Flash Read Protection */
#define FLASH_u8READUNPROTECTED		0
#define FLASH_u8READPROTECTED		1
#define FLASH_u16READPROTECTKEY		0x00A5
#endif /* FLASH_PRIV_H_ */
