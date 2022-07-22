#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define GET_BIT(Reg,Bit) ( Reg >> Bit) & (0x01)
#define SET_BIT(Byte, Pos) 		Byte |= (1 << Pos)
#define CLEAR_BIT(Byte, Pos) 	Byte &= ~(1 << Pos)
#define TOGGLE_BIT(Byte, Pos) 	Byte ^= (1 << Pos)

#define SET_BYTE(Byte) 			Byte |= (0xFF)
#define CLEAR_BYTE(Byte) 		Byte &=(0x00)

#define CONC_BIT(bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0) 	CONC_HELP(bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0)
#define CONC_HELP(bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0) 	0x##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0

#define CONCC_BIT(bit15,bit14,bit13,bit12,bit11,bit10,bit9,bit8,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)   CONCC_HELP(bit15,bit14,bit13,bit12,bit11,bit10,bit9,bit8,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)
#define CONCC_HELP(bit15,bit14,bit13,bit12,bit11,bit10,bit9,bit8,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)  0b##bit15##bit14##bit13##bit12##bit11##bit10##bit9##bit8##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0

#endif
