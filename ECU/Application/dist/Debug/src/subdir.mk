################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADC_prog.c \
../src/AFIO_program.c \
../src/CAN.c \
../src/CANHANDLER_prog.c \
../src/DIO_prog.c \
../src/DMA_program.c \
../src/FLASH_prog.c \
../src/HexDataProcessor_prog.c \
../src/NVIC_prog.c \
../src/RCC_prog.c \
../src/SCB_prog.c \
../src/Timer_prog.c \
../src/_write.c \
../src/main.c 

OBJS += \
./src/ADC_prog.o \
./src/AFIO_program.o \
./src/CAN.o \
./src/CANHANDLER_prog.o \
./src/DIO_prog.o \
./src/DMA_program.o \
./src/FLASH_prog.o \
./src/HexDataProcessor_prog.o \
./src/NVIC_prog.o \
./src/RCC_prog.o \
./src/SCB_prog.o \
./src/Timer_prog.o \
./src/_write.o \
./src/main.o 

C_DEPS += \
./src/ADC_prog.d \
./src/AFIO_program.d \
./src/CAN.d \
./src/CANHANDLER_prog.d \
./src/DIO_prog.d \
./src/DMA_program.d \
./src/FLASH_prog.d \
./src/HexDataProcessor_prog.d \
./src/NVIC_prog.d \
./src/RCC_prog.d \
./src/SCB_prog.d \
./src/Timer_prog.d \
./src/_write.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


