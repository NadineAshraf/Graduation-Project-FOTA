/*
 * SCB_priv.h
 *
 *  Created on: Jan 30, 2020
 *      Author: sondo
 */

#ifndef SCB_PRIV_H_
#define SCB_PRIV_H_


/******** AIRCR Register Bits Definitions ************/
#define VECTRESET			0
#define VECTCLRACTIVE		1
#define SYSRESETREQ			2
#define PRIGROUP			8
#define ENDIANESS			15
#define VECTKEY				16




/******** SCB Register Structure ************/
typedef struct
{
	u32 SCB_CPUID;
	u32 SCB_ICSR;
	u32 SCB_VTOR;
	u32 SCB_AIRCR;
	u32 SCB_SCR;
	u32 SCB_CCR;
	u32 SCB_SHPR1;
	u32 SCB_SHPR2;
	u32 SCB_SHPR3;
	u32 SCB_SHCRS;
	u32 SCB_CFSR;
	u32 SCB_HFSR;
	u32 SCB_MMAR;
	u32 SCB_BFAR;
}SCB;


/******** Register Base Addresses ************/
#define SCB_BASEADDRESS	((SCB*)  0xE000ED00)


#endif /* SCB_PRIV_H_ */
