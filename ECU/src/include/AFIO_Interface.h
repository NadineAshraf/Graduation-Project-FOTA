/**************************************************************************************/
/* 								Author   : Mark Ehab                                  */
/* 								Date     : Feb 26, 2022                               */
/* 								Module	 : AFIO                                       */
/* 								Version  : V 1.0                                      */
/**************************************************************************************/

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

								/* Interface Macros (Not finished yet)*/
/* External Interrupt Lines */
#define EXTI_LINE_0    0
#define EXTI_LINE_1    1
#define EXTI_LINE_2    2
#define EXTI_LINE_3    3
#define EXTI_LINE_4    4
#define EXTI_LINE_5    5
#define EXTI_LINE_6    6
#define EXTI_LINE_7    7
#define EXTI_LINE_8    8
#define EXTI_LINE_9    9
#define EXTI_LINE_10   10
#define EXTI_LINE_11   11
#define EXTI_LINE_12   12
#define EXTI_LINE_12   12
#define EXTI_LINE_14   14
#define EXTI_LINE_15   15

/* Port Mappings on EXTI Lines */
#define AFIO_PORTA  0b0000
#define AFIO_PORTB  0b0001
#define AFIO_PORTC  0b0010

/* Alternative Functions Remap Types*/
#define AFIO_SPI1_REMAP            0
#define AFIO_I2C1_REMAP            1
#define AFIO_USART1_REMAP          2
#define AFIO_USART2_REMAP          3
#define AFIO_USART3_REMAP          4
#define AFIO_TIM1_REMAP            5
#define AFIO_TIM2_REMAP            6
#define AFIO_TIM3_REMAP            7
#define AFIO_TIM4_REMAP            8
#define AFIO_CAN_REMAP             9
#define AFIO_PD01_REMAP            10
#define AFIO_TIM5CH4_IREMAP        11
#define AFIO_ADC1_ETRGINJ_REMAP    12
#define AFIO_ADC1_ETRGREG_REMAP    13
#define AFIO_ADC2_ETRGINJ_REMAP    14
#define AFIO_ADC2_ETRGREG_REMAP    15

/* Alternative Functions Remap Values (Not finished yet)*/
/* CAN Remap Values */
#define AFIO_CAN_REMAP_RESET       0xFFFF9FFF
#define AFIO_CANRX_PA11_CANTX_PA12 0x00000000
#define AFIO_CANRX_PB8_CANTX_PB9   0x00004000
#define AFIO_CANRX_PD0_CANTX_PD0   0x00006000

								/* Functions Prototypes */

void AFIO_vidSetEXTIConfiguration(u8 Copy_u8EXTILine , u8 Copy_u8PortMap);
void AFIO_vidAlternativeFunctionRemap(u8 Copy_u8FunctionRemapType,u32 Copy_u32FunctionRemapVal);

#endif /* AFIO_INTERFACE_H_ */
