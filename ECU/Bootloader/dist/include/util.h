#ifndef _UTIL_H

#define _UTIL_H

#define SET_BIT(Reg,BitNo)           Reg|=(1<<(BitNo))
#define CLR_BIT(Reg,BitNo)           Reg&=~(1<<(BitNo))
#define GET_BIT(Reg,BitNo)           ((Reg&(1<<(BitNo)))>>(BitNo))
#define TOGGLE_BIT(Reg,BitNo)        Reg=(Reg ^ (1<<(BitNo)))
#define ASSIGN_BIT(Reg, BitNo,Value) \
	do \
	{ \
		Reg &= ~(1 << BitNo); \
		Reg |= ((Value & 0x01) << BitNo); \
	} while(0)

#define SET_REG(Reg)                 Reg=0xFF
#define CLR_REG(Reg)                 Reg=0x00
#define GET_REG(Reg)                 (Reg)
#define TOGGLE_REG(Reg)              Reg^=0xFF
#define ASSIGN_REG(Reg,Value)        Reg=Value

#define GET_LOW_NIB(Reg)             (Reg&0x0F)
#define SET_LOW_NIB(Reg)             Reg|=0x0F
#define CLR_LOW_NIB(Reg)             Reg&=~(0x0F)
#define ASSIGN_LOW_NIB(Reg,Value)    \
	do \
	{ \
		Reg &= ~(0x0F); \
		Reg |= (Value & 0x0F); \
	} while(0)

#define GET_HIGH_NIB(Reg)            (Reg&0xF0)
#define SET_HIGH_NIB(Reg)            Reg|=0xF0
#define CLR_HIGH_NIB(Reg)            Reg&=~(0xF0)
#define ASSIGN_HIGH_NIB(Reg,Value)   \
	do \
	{ \
		Reg &= ~(0xF0); \
		Reg |= ( (Value & 0x0F) << 4); \
	} while(0)
#endif
