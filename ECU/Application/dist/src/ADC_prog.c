/*
 * ADC_prog.c

 *
 *  Created on: May 11, 2020
 *      Author: Salma ahmed
 */

#include"STD_Types.h"
#include"BIT_MATH.H"
#include "ADC_priv.h"
#include "ADC_int.h"
#include "ADC_cfg.h"



void ADC_Enable (void)
{
	u32 i;
	ADC1_CR2 |= 0x00000001;		//ADC enable
	for (i = 0; i < 10000; i++)
	{

	}
	ADC1_CR2 |= 0x00000001;
}

void WaitingStartConversion (void)
{
	while (((ADC1_SR & 0x00000010) >>4)	== 0);
}
void WaitingEndofConversion (void)
{
	while (((ADC1_SR & 0x00000002) >>1)	== 0);
}

void EndofConversionReset (void)
{
	ADC1_SR &= ~(0x00000002);			//reset EOC after reading from DR
	while (((ADC1_SR & 0x00000002) >>1)	== 1);		//waiting for EOC reset flag
}

void SequenceRegistersInit(void)
{
	//ADC1_CR2 |= 0x00000100;		//DMA
	//ADC1_CR1 |= 0x00000100;		//SCAN
	//ADC1_CR1 |= 0x00002000;
	ADC1_SQR1 |= ((NOOFCHANNELS-1)<<20);
	ADC1_SQR3 |= ( (SQ6<<25)|(SQ5<<20)|(SQ4<<15)|(SQ3<<10)|(SQ2<<5)|(SQ1)    );
	ADC1_SQR2 |= ( (SQ12<<25)|(SQ11<<20)|(SQ10<<15)|(SQ9<<10)|(SQ8<<5)|(SQ7) );
	ADC1_SQR1 |= ( (SQ16<<15)|(SQ15<<10)|(SQ14<<5)|(SQ13)					 );

}




void ADC_Init()
{

//ADC1_CR2 |= CONT;

ADC1_CR2 |= EXTERNALTRIGGERENABLE ;		//external trigger enable

ADC_Enable();

ADC1_CR1 |= ENABLEDISCONTINOUS;		//discontinous mode

SequenceRegistersInit();			//to select the used channels

ADC1_CR2|= SOCTRIGGER;				//choose SWSTART as start of conversion trigger



//ADC1_CR1 |= EOCINTERRUPTENABLE;				//EOC interrupt enable

}

void Reading_Channels(f32*ptr)
{
	int j;
	for (j= 2 ; j>0;j--)
	{

	ADC1_CR2 |= SWSTART ;		//start conversion

	WaitingStartConversion ();		//waiting for start conversion flag

	WaitingEndofConversion ();	//waiting for EOC
	EndofConversionReset();
	ptr[2-j] = ADC1_DR*0.080586;

	}

}


///*
// * ADC_prog.c
//
// *
// *  Created on: May 11, 2020
// *      Author: Salma ahmed
// */
//
//#include"STD_Types.h"
//#include"BIT_MATH.H"
//#include "ADC_priv.h"
//#include "ADC_int.h"
//#include "ADC_cfg.h"
//#include "DMA_int.h"
//#include "DMA_priv.h"
//
//
//
//void ADC_Enable (void)
//{
//	u32 i;
//	ADC1_CR2 |= 0x00000001;		//ADC enable
//	for (i = 0; i < 10000; i++)
//	{
//asm("NOP");
//	}
//	ADC1_CR2 |= 0x00000001;
//}
//
//void WaitingStartConversion (void)
//{
//	while (((ADC1_SR & 0x00000010) >>4)	== 0);
//}
//void WaitingEndofConversion (void)
//{
//	while (((ADC1_SR & 0x00000002) >>1)	== 0);
//}
//
//void EndofConversionReset (void)
//{
//	ADC1_SR &= ~(0x00000002);			//reset EOC after reading from DR
//	while (((ADC1_SR & 0x00000002) >>1)	== 1);		//waiting for EOC reset flag
//}
//
//void SequenceRegistersInit(void)
//{
//
//	ADC1_SQR1 |= ((NOOFCHANNELS-1)<<20);
//	ADC1_SQR3 |= ( (SQ6<<25)|(SQ5<<20)|(SQ4<<15)|(SQ3<<10)|(SQ2<<5)|(SQ1)    );
//	ADC1_SQR2 |= ( (SQ12<<25)|(SQ11<<20)|(SQ10<<15)|(SQ9<<10)|(SQ8<<5)|(SQ7) );
//	ADC1_SQR1 |= ( (SQ16<<15)|(SQ15<<10)|(SQ14<<5)|(SQ13)					 );
//
//}
//
//
//
//
//void ADC_Init()
//{
//
////ADC1_CR2 |= CONT;
////ADC1_SMPR2 |= 0X00000004;   // 41.5 cycles
//
//ADC1_CR2 |= EXTERNALTRIGGERENABLE ;		//external trigger enable
////ADC1_CR2 |= 0x00000100 ;		//DMA
//
//ADC_Enable();
///*ADC1_CR2 |= 0x00000008 ;		//intiliaze calibration
//ADC1_CR2 |= 0x00000004 ;		//intiliaze calibration*/
//
////ADC1_CR1 |= ENABLEDISCONTINOUS;		//discontinous mode
//ADC1_CR2 |= DMA_ENABLE;		//DMA
//ADC1_CR1 |= SCAN;		//SCAN
//SequenceRegistersInit();			//to select the used channels
//
//ADC1_CR2|= SOCTRIGGER;				//choose SWSTART as start of conversion trigger
//
//
//
//
////ADC1_CR1 |= EOCINTERRUPTENABLE;				//EOC interrupt enable
//
//
//}
//
//void Reading_Channels(u32*ptr)
//{
//	//int j;
//	//for (j= 2 ; j>0;j--)
//	//{
//	//volatile u32 arr[2];
//	//for(u8 i=0;i<NOOFCHANNELS;i++)
//	//{
//   ADC1_CR2 |= SWSTART ;		//start conversion
//
//	//ADC_Enable();
//
//	DMA_Transfer(DMA_CHANNEL_1,ptr, & ADC1_DR,2);
//	DMA->CCR1 |=0X00000002;
//
//	 //EndofConversionReset ();
////	WaitingStartConversion ();		//waiting for start conversion flag
//
//	//WaitingEndofConversion ();	//waiting for EOC
//	//ptr[0]= arr[0]*(0.00080586);
//	//}
//	//}
//
//}
//
