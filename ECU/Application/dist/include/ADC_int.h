/*
 * ADC_int.h
 *
 *  Created on: May 11, 2020
 *      Author: Salma ahmed
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_



void ADC_Init();
//void Reading_Channels(u32 * ptr);
void Reading_Channels(f32*ptr);
void WaitingStartConversion (void);
void WaitingEndofConversion (void);
void EndofConversionReset(void);
void SequenceRegistersInit(void);
#endif /* ADC_INT_H_ */
