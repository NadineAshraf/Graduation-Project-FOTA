/*
 * DMA_priv.h
 *
 *  Created on: 26 Aug 2019
 *      Author: Mario
 */
#ifndef _DMA_PRIV_H
#define _DMA_PRIV_H

#define DMA_BASE_ADDRESS           0x40020000 // Base Address

typedef struct {
	u32  ISR;			// Interrupt status register
	u32  IFCR;   		// Interrupt flag clear register
	u32  CCR1;    		// Configuration register
	u32  CNDTR1;    	// Number of data register
	u32  CPAR1;    		// Peripheral address register
	u32  CMAR1;    		// Memory address register
	const u32 Reserved1;
	u32  CCR2;
	u32  CNDTR2;
	u32  CPAR2;
	u32  CMAR2;
	const u32 Reserved2;
	u32  CCR3;
	u32  CNDTR3;
	u32  CPAR3;
	u32  CMAR3;
	const u32 Reserved3;
	u32  CCR4;
	u32  CNDTR4;
	u32  CPAR4;
	u32  CMAR4;
	const u32 Reserved4;
	u32  CCR5;
	u32  CNDTR5;
	u32  CPAR5;
	u32  CMAR5;
	const u32 Reserved5;
	u32  CCR6;
	u32  CNDTR6;
	u32  CPAR6;
	u32  CMAR6;
	const u32 Reserved6;
	u32  CCR7;
	u32  CNDTR7;
	u32  CPAR7;
	u32  CMAR7;
} DMA_REG;

#define DMA ((DMA_REG *) DMA_BASE_ADDRESS)
//static volatile  DMA_REG * DMA = ( volatile DMA_REG * ) DMA_BASE_ADDRESS;

#endif	/* _DMA_PRIV_H */
