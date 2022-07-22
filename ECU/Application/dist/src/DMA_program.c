#include <STD_TYPES.h>
#include <BIT_MATH.h>

#include <DMA_priv.h>
#include <DMA_int.h>

void (*DMA_CallbackFunction[6])(void);	// Not stored in memory at startup

static void DMA_Stub (void) {
	__asm__("NOP");
}

/**
  * @brief  Initiates the DMA and sets channel configuration
  * @param	newDMA: The channel configuration of type DMA_Config
  * @retval Error_Status
  */
Error_Status DMA_enumInit(DMA_Config newDMA) {
	Error_Status returnVal = OK;

	if (newDMA.Channel >= 1 && newDMA.Channel < 7) {
		u32* currentChannel = ((u32*) (&DMA->CCR1 + (u32) (newDMA.Channel - 1) * 5));
		*currentChannel = 0;
		*currentChannel |= newDMA.MEM2MEM 	<< 	14;
		*currentChannel |= newDMA.Priority 	<< 	12;
		*currentChannel |= newDMA.SrcSIZE 	<< 	10;
		*currentChannel |= newDMA.DstSIZE 	<< 	8;
		*currentChannel |= newDMA.SrcINC 	<< 	7;
		*currentChannel |= newDMA.DstINC 	<< 	6;
		*currentChannel |= newDMA.CIRC 		<< 	5;
		*currentChannel |= newDMA.DIR 		<< 	4;
		*currentChannel |= newDMA.TEIE 		<< 	3;
		*currentChannel |= newDMA.HTIE 		<< 	2;
		*currentChannel |= newDMA.TCIE 		<< 	1;
		DMA_CallbackFunction[newDMA.Channel] = &DMA_Stub;
	} else {
		returnVal = indexOutOfRange;
	}

	return returnVal;
}

/**
  * @brief  Starts and transfer
  * @param	Channel:	The DMA channel number.
  * 					Can be DMA_CHANNEL_x where x is from 1 to 6
  * @param	MEM_ADDRESS:	Pointer to the Memory address
  * @param	PER_ADDRESS:	Pointer to the Peripheral address
  * @param 	Count:			Number of (units) to transfer
  * @retval void
  */
void DMA_Transfer(volatile u8 Channel, volatile u32* MEM_ADDRESS, volatile u32* PER_ADDRESS, volatile u32 Count) {
	if (Channel >= 1 && Channel < 7) {
		*((u32*) (&DMA->CNDTR1	+ (u32) (Channel - 1) * 5)) 	= 		Count;
		*((u32*) (&DMA->CMAR1 	+ (u32) (Channel - 1) * 5)) 	= (u32) MEM_ADDRESS;
		*((u32*) (&DMA->CPAR1	+ (u32) (Channel - 1) * 5)) 	= (u32) PER_ADDRESS;
		*((u32*) (&DMA->CCR1	+ (u32) (Channel - 1) * 5))	   |= 		0b1;
	}
}

/**
  * @brief  Disables the DMA channel
  * @param	Channel: The DMA channel number
  * @retval void
  */
void DMA_voidDisable(u8 Channel) {
	if (Channel >= 1 && Channel < 7) {
		// Disable DMA to clear buffer
		*((u32*) (&DMA->CCR1	+ (u32) (Channel - 1) * 5)) &= 0b0;
	}
}

/**
  * @brief  Set a callback function to call in the handler
  * @param	Channel:	The DMA channel number.
  * 					Can be DMA_CHANNEL_x where x is from 1 to 6
  * @param 	void (*x)(void): 	Pointer to the callback function
  * @retval void
  */
Error_Status DMA_enumSetCallback(u8 Channel, void (*fun)(void)) {
	Error_Status returnVal = OK;

	if (Channel >= 1 && Channel < 7) {
		DMA_CallbackFunction[Channel - 1] = fun;
	} else {
		returnVal = indexOutOfRange;
	}

	return returnVal;
}


void DMA1_Channel1_IRQHandler(void) {
	if (GET_BIT(DMA->ISR, 0)) {
		SET_BIT(DMA->IFCR, 0);		// Clear Global INT for DMA1

		if (GET_BIT(DMA->ISR, 2)) {							// Half Transfer Complete
			SET_BIT(DMA->IFCR, 2);		// Clear Half transfer flag
			asm("NOP");
		} else if (GET_BIT(DMA->ISR, 1)) {					// Transfer Complete
			SET_BIT(DMA->IFCR, 1);		// Clear Transfer Complete flag
			asm("NOP");
		} else if (GET_BIT(DMA->ISR, 3)) {					// Error Happened
			SET_BIT(DMA->IFCR, 3);		// Clear Error flag
			asm("NOP");
		}
	}
}

void DMA1_Channel5_IRQHandler(void) {
	// Channel 5 global interrupt flag
	if (GET_BIT(DMA->ISR, 16)) {

		if (GET_BIT(DMA->ISR, 17)) {									// Transfer Complete
			DMA_CallbackFunction[4]();
			SET_BIT(DMA->IFCR, 17);		// Clear Transfer Complete flag
		} else if ( GET_BIT(DMA->ISR, 18) ) {							// Half Transfer Complete
			DMA_CallbackFunction[4]();
			SET_BIT(DMA->IFCR, 18);		// Clear Half transfer flag
		} else if (GET_BIT(DMA->ISR, 19)) {								// Error Happened
			SET_BIT(DMA->IFCR, 19);		// Clear Error flag
		}

		SET_BIT(DMA->IFCR, 16);		// Clear Global INT for DMA1 Channel 5
	}
}
