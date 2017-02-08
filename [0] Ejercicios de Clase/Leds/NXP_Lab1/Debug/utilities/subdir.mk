################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_debug_console.c \
../utilities/fsl_notifier.c \
../utilities/fsl_sbrk.c \
../utilities/fsl_shell.c 

OBJS += \
./utilities/fsl_debug_console.o \
./utilities/fsl_notifier.o \
./utilities/fsl_sbrk.o \
./utilities/fsl_shell.o 

C_DEPS += \
./utilities/fsl_debug_console.d \
./utilities/fsl_notifier.d \
./utilities/fsl_sbrk.d \
./utilities/fsl_shell.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -flto  -g3 -D"CPU_MKL27Z64VDA4" -DFSL_RTOS_BM -I../CMSIS -I../board -I../drivers -I../startup -I../utilities -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


