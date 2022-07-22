/**************************************************************************************/
/* 						Author   	 : Mark Ehab                                      */
/* 						Date     	 : Sep 17, 2021                                   */
/* 						Description	 : BitMath Functions                              */
/**************************************************************************************/

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/*Function-like Macros for set, clear, toggle and get bit*/

#define SET_BIT(Copy_u8Reg,Copy_u8Pin) 		Copy_u8Reg |= (1<<(Copy_u8Pin))
#define CLR_BIT(Copy_u8Reg,Copy_u8Pin) 		Copy_u8Reg &= ~(1<<(Copy_u8Pin))
#define GET_BIT(Copy_u8Reg,Copy_u8Pin)	    ((Copy_u8Reg)>>(Copy_u8Pin)) & (1)
#define TOGGLE_BIT(Copy_u8Reg,Copy_u8Pin)	Copy_u8Reg ^= (1<<(Copy_u8Pin))

#endif /* LIB_BIT_MATH_H_ */
