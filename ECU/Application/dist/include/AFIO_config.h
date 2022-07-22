#ifndef _AFIO_CONFIG_H
#define _AFIO_CONFIG_H

/****************** AFIO_REMAP **********************/

#define    AFIO_SPI1CFG                         SPI1_NoRemap
#define    AFIO_I2C1CFG                         I2C1_NoRemap
#define    AFIO_USART1CFG                       USART1_NoRemap 
#define    AFIO_USART2CFG                       USART2_NoRemap
#define    AFIO_USART3CFG                       USART3_NoRemap
#define    AFIO_TIM1CFG                         TIM1_PartialRemap
#define    AFIO_TIM2CFG                         TIM2_NoRemap
#define    AFIO_TIM3CFG                         TIM3_NoRemap
#define    AFIO_TIM4CFG                         TIM4_NoRemap
#define    AFIO_CANCFG                          CAN_TX_B9_RX_B8
#define    AFIO_PD01CFG                         PD01_REMAP
#define    AFIO_TIM5CFG                         TIM5_CH4_PA3
#define    AFIO_ADC1CFG                         ADC1_EXTI15
#define    AFIO_ADC1_RegularCFG                 ADC1_EXTI11
#define    AFIO_ADC2CFG                         ADC2_EXTI15
#define    AFIO_ADC2_RegularCFG                 ADC2_EXTI11
#define    AFIO_SWJ_CFG                         Full_SWJ


/****************** EXTI ***********************/

#define  AFIO_EXTI0CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI1CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI2CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI3CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI4CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI5CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI6CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI7CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI8CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI9CFG                           AFIO_EXTI_PORTA 
#define  AFIO_EXTI10CFG                         AFIO_EXTI_PORTA 
#define  AFIO_EXTI11CFG                         AFIO_EXTI_PORTA 
#define  AFIO_EXTI12CFG                         AFIO_EXTI_PORTA 
#define  AFIO_EXTI13CFG                         AFIO_EXTI_PORTA
#define  AFIO_EXTI14CFG                         AFIO_EXTI_PORTA 
#define  AFIO_EXTI15CFG                         AFIO_EXTI_PORTA 

/****************** AFIO_REMAP2 **********************/
 
#define    AFIO_TIM9CFG                              TIM9_NoRemap
#define    AFIO_TIM10CFG                            TIM10_NoRemap
#define    AFIO_TIM11CFG                            TIM11_NoRemap
#define    AFIO_TIM13CFG                            TIM13_NoRemap
#define    AFIO_TIM14CFG                            TIM14_NoRemap
#define    AFIO_NADVCFG                             NADV_CONNECT

#endif
