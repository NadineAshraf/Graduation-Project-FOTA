#ifndef NVIC_PRIV_H
#define NVIC_PRIV_H

#define NVIC_ISER		((volatile u32*)0xE000E100)
#define NVIC_ICER		((volatile u32*)0xE000E180)
#define NVIC_ISPR		((volatile u32*)0xE000E200)
#define NVIC_ICPR		((volatile u32*)0xE000E280)
#define NVIC_IABR		((volatile u32*)0xE000E300)
#define NVIC_IPR		((volatile u8*) 0xE000E400)

#endif
