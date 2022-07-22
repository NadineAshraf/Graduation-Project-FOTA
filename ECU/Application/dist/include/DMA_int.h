/*
 * DMA_int.h
 *
 *  Created on: 26 Aug 2019
 *      Author: Mario
 */
#ifndef _DMA_INT_H
#define _DMA_INT_H

typedef struct {
	u8 Channel;			// Channel number: CHANNEL_1, CHANNEL_2, ...
	u8 MEM2MEM;			// Memory to Memory: TRUE, FALSE
	u8 Priority;		// LOW, MEDIUM, HIGH, VERY_HIGH
	u8 SrcSIZE;			// Specifies Source data size alignment (byte, half word, word).
	u8 DstSIZE;			// Specifies Source data size alignment (byte, half word, word).
	u8 SrcINC;			// Specifies if Source address is incremented or not
	u8 DstINC;			// Specifies Destination address is incremented or not.
	u8 CIRC;			// Specifies the normal or circular operation mode: TRUE, FALSE
	u8 DIR;				// If the data will be transferred from memory to peripheral: FROM_MEM, FROM_PERIPHRAL
	u8 TEIE;			// Transfer error interrupt enable
	u8 HTIE;			// Half transfer interrupt enable
	u8 TCIE;			// Transfer complete interrupt enable
} DMA_Config;

/**
  * @brief  Initiates the DMA and sets channel configuration
  * @param	newDMA: The channel configuration of type DMA_Config
  * @retval Error_Status
  */
Error_Status DMA_enumInit(DMA_Config);

/**
  * @brief  Starts and transfer
  * @param	Channel:	The DMA channel number.
  * 					Can be DMA_CHANNEL_x where x is from 1 to 6
  * @param	MEM_ADDRESS:	Pointer to the Memory address
  * @param	PER_ADDRESS:	Pointer to the Peripheral address
  * @param 	Count:			Number of (units) to transfer
  * @retval void
  */
void DMA_Transfer(volatile u8, volatile u32*, volatile u32*, volatile u32);


/**
  * @brief  Disables the DMA channel
  * @param	u8: DMA channel number
  * @retval void
  */
void DMA_voidDisable(u8);

/**
  * @brief  Set a callback function to call in the handler
  * @param	Channel:	The DMA channel number.
  * 					Can be DMA_CHANNEL_x where x is from 1 to 6
  * @param 	void (*x)(void): 	Pointer to the callback function
  * @retval void
  */
Error_Status DMA_enumSetCallback(u8, void (*x)(void));

/*
 * Channel names
 */
#define DMA_CHANNEL_1 		1
#define DMA_CHANNEL_2 		2
#define DMA_CHANNEL_3 		3
#define DMA_CHANNEL_4 		4
#define DMA_CHANNEL_5 		5
#define DMA_CHANNEL_6 		6


/*
 * Channel Priorities
 * LOW, Medium, high, very high
 */
#define LOW 			0b00
#define MEDIUM 			0b01
#define HIGH			0b10
#define VERY_HIGH		0b11

/*
 * STD sizes
 * 8, 16, 32
 */
#define BITS_8 			0b00
#define BITS_16 		0b01
#define BITS_32			0b10

/*
 * Read direction
 */
#define FROM_PERIPHRAL 	0
#define FROM_MEM		1

#endif	/* _DMA_INT_H */
