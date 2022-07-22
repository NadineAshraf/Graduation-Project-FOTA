/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 26, 2022                               */
/* 								Module	 : AFIO                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/*
 * AFIO Peripheral Base Address	:
 *
 * AFIO	:	0x40010000
 *
 */
/*Definitions of Registers Addresses for AFIO*/
#define AFIO_EVCR     *((volatile u32*) 0x40010000)
#define AFIO_MAPR  	  *((volatile u32*) 0x40010004)
#define AFIO_EXTICR1  *((volatile u32*) 0x40010008)
#define AFIO_EXTICR2  *((volatile u32*) 0x4001000C)
#define AFIO_EXTICR3  *((volatile u32*) 0x40010010)
#define AFIO_EXTICR4  *((volatile u32*) 0x40010014)
#define AFIO_MAPR2    *((volatile u32*) 0x4001001C)

#endif /* AFIO_PRIVATE_H_ */
