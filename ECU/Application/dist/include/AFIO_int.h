#ifndef _AFIO_INIT_H
#define _AFIO_INIT_H


/****************** AFIO_REMAP **********************/

///////////******************SPI**********************///////////////

#define   SPI1_NoRemap         0x00000000	//(NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)
#define   SPI1_Remap           0x00000001	//(NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)

///////////******************I2C**********************///////////////

#define   I2C1_NoRemap				0x00000000		//(SCL/PB6, SDA/PB7)
#define   I2C1_Remap				0x00000001		//(SCL/PB8, SDA/PB9)

///////////******************USART1**********************///////////////

#define   USART1_NoRemap			0x00000000		//(TX/PA9, RX/PA10)
#define   USART1_Remap				0x00000001		//(TX/PB6, RX/PB7)

///////////******************USART2**********************///////////////
#define   USART2_NoRemap			0x00000000		//(CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
#define   USART2_Remap				0x00000001		//(CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)

///////////******************USART3**********************///////////////
#define   USART3_NoRemap			0x00000000		//(TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
#define   USART3_PartialRemap		0x00000001		//(TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
#define   USART3_FullRemap			0x00000003		//(TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12)

///////////******************TIM1**********************///////////////

#define   TIM1_NoRemap                    0x00000000		//(ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12,
															//CH1N/PB13, CH2N/PB14, CH3N/PB15)
#define   TIM1_PartialRemap               0x00000001		//(ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6,
															//CH1N/PA7, CH2N/PB0, CH3N/PB1)
#define   TIM1_FullRemap                  0x00000003		//(ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15,
															//CH1N/PE8, CH2N/PE10, CH3N/PE12)

///////////******************TIM2**********************///////////////

#define   TIM2_NoRemap					0x00000000		//(CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
#define   TIM2_PartialRemap_1			0x00000001		//(CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
#define   TIM2_PartialRemap_2			0x00000002		//(CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
#define   TIM2_FullRemap				0x00000003		//(CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)

///////////******************TIM3**********************///////////////

#define   TIM3_NoRemap					0x00000000		//(CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
#define   TIM3_PartialRemap				0x00000001		//(CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
#define   TIM3_FullRemap				0x00000003		//(CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)

///////////******************TIM4**********************///////////////

#define   TIM4_NoRemap					0x00000000		//(TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
#define   TIM4_FullRemap				0x00000001 		//(TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)

///////////******************CAN1**********************///////////////

#define   CAN_TX_A12_RX_A11            0x00000000			//CAN1_RX mapped to PA11, CAN1_TX mapped to PA12
#define   CAN_TX_B9_RX_B8              0x00000002 		//CAN1_RX mapped to PB8, CAN1_TX mapped to PB9
#define   CAN_TX_D1_RX_D0              0x00000003  		//CAN1_RX mapped to PD0, CAN1_TX mapped to PD1


////Port D0/Port D1 mapping on OSC_IN/OSC_OUT
#define   PD01_REMAP                                              0x00000000
#define   PD0_OSC_IN_PD1_OSC_OUT                       0x00000001

////TIM5 channel4 internal remap
#define   TIM5_CH4_PA3                                              0x00000000
#define   TIM5_CH4_LSI                                               0x00000001

////ADC 1 External trigger injected conversion remapping
#define   ADC1_EXTI15                                              0x00000000
#define   ADC1_TIM8_CH4                                          0x00000001

////ADC 1 external trigger regular conversion remapping
#define   ADC1_EXTI11                                              0x00000000
#define   ADC1_TIM8_TRG0                                        0x00000001

////ADC 2 external trigger injected conversion remapping
#define   ADC2_EXTI15                                              0x00000000
#define   ADC2_TIM8_CH4                                          0x00000001

////ADC 2 external trigger regular conversion remapping
#define   ADC2_EXTI11                                              0x00000000
#define   ADC2_TIM8_TRG0                                        0x00000001

////Serial wire JTAG configuration
#define   Full_SWJ								0x00000000		//(JTAG-DP + SW-DP): Reset State
#define   Full_SWJ_No_NJTRST					0x00000001		//(JTAG-DP + SW-DP) but without NJTRST
//#define   SW-DP_N0_JTAG-DP							0x00000002		//JTAG-DP Disabled and SW-DP Enabled
//#define   JTAG-DP_N0_SW-DP							0x00000004		//JTAG-DP Disabled and SW-DP Disabled





/****************** EXTI ***********************/

#define AFIO_EXTI_PORTA             0b0000
#define AFIO_EXTI_PORTB             0b0001
#define AFIO_EXTI_PORTC             0b0010
//#define AFIO_EXTI_NOTHING         F


/****************** AFIO_REMAP2 **********************/


///////////******************TIM9**********************///////////////

#define TIM9_NoRemap		0x00000000		//(TIM9_CH1 on PA2 and TIM9_CH2 on PA3)
#define TIM9_Remap			0x00000001		//(TIM9_CH1 on PE5 and TIM9_CH2 on PE6)

///////////******************TIM10**********************///////////////

#define TIM10_NoRemap		0x00000000		//(PB8)
#define TIM10_Remap			0x00000001		//(PF6)

///////////******************TIM11**********************///////////////

#define TIM11_NoRemap		0x00000000		//(PB9)
#define TIM11_Remap			0x00000001		//(PF7)

///////////******************TIM13**********************///////////////

#define TIM13_NoRemap		0x00000000		//(PA6)
#define TIM13_Remap			0x00000001		//(PF8)

///////////******************TIM14**********************///////////////

#define TIM14_NoRemap		0x00000000		//(PA7)
#define TIM14_Remap			0x00000001		//(PF9)


///////////******************NADV connect/disconnect**********************///////////////


#define   NADV_CONNECT                   0x00000000
#define   NADV_DISCONNECT              0x00000001


 void  AFIO_voidinit(void);


#endif
