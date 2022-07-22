#ifndef STD_TYPES_H
#define STD_TYPES_H




typedef unsigned char		u8;
typedef unsigned short int	u16;
typedef unsigned long int	u32;
typedef signed char			s8;
typedef signed short int	s16;
typedef signed long int		s32;
typedef float  				f32;
typedef double 				f64;

#define ENABLE				1
#define DISABLE				0

#define TRUE 				0b1
#define FALSE 				0b0

typedef enum {
	OK,
	NOK,
	indexOutOfRange,
	nullPointer,
	numberOutOfRange,
	elementNotFound,
	limitReached
} Error_Status;

#endif
