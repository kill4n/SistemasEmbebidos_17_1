################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc16.c \
../drivers/fsl_clock.c \
../drivers/fsl_cmp.c \
../drivers/fsl_common.c \
../drivers/fsl_cop.c \
../drivers/fsl_crc.c \
../drivers/fsl_dma.c \
../drivers/fsl_dmamux.c \
../drivers/fsl_flash.c \
../drivers/fsl_flexio.c \
../drivers/fsl_flexio_i2c_master.c \
../drivers/fsl_flexio_i2s.c \
../drivers/fsl_flexio_i2s_dma.c \
../drivers/fsl_flexio_spi.c \
../drivers/fsl_flexio_spi_dma.c \
../drivers/fsl_flexio_uart.c \
../drivers/fsl_flexio_uart_dma.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_i2c_dma.c \
../drivers/fsl_llwu.c \
../drivers/fsl_lptmr.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_lpuart_dma.c \
../drivers/fsl_pit.c \
../drivers/fsl_pmc.c \
../drivers/fsl_rcm.c \
../drivers/fsl_rtc.c \
../drivers/fsl_sim.c \
../drivers/fsl_smc.c \
../drivers/fsl_spi.c \
../drivers/fsl_spi_dma.c \
../drivers/fsl_tpm.c \
../drivers/fsl_uart.c \
../drivers/fsl_uart_dma.c \
../drivers/fsl_vref.c 

OBJS += \
./drivers/fsl_adc16.o \
./drivers/fsl_clock.o \
./drivers/fsl_cmp.o \
./drivers/fsl_common.o \
./drivers/fsl_cop.o \
./drivers/fsl_crc.o \
./drivers/fsl_dma.o \
./drivers/fsl_dmamux.o \
./drivers/fsl_flash.o \
./drivers/fsl_flexio.o \
./drivers/fsl_flexio_i2c_master.o \
./drivers/fsl_flexio_i2s.o \
./drivers/fsl_flexio_i2s_dma.o \
./drivers/fsl_flexio_spi.o \
./drivers/fsl_flexio_spi_dma.o \
./drivers/fsl_flexio_uart.o \
./drivers/fsl_flexio_uart_dma.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_i2c_dma.o \
./drivers/fsl_llwu.o \
./drivers/fsl_lptmr.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_lpuart_dma.o \
./drivers/fsl_pit.o \
./drivers/fsl_pmc.o \
./drivers/fsl_rcm.o \
./drivers/fsl_rtc.o \
./drivers/fsl_sim.o \
./drivers/fsl_smc.o \
./drivers/fsl_spi.o \
./drivers/fsl_spi_dma.o \
./drivers/fsl_tpm.o \
./drivers/fsl_uart.o \
./drivers/fsl_uart_dma.o \
./drivers/fsl_vref.o 

C_DEPS += \
./drivers/fsl_adc16.d \
./drivers/fsl_clock.d \
./drivers/fsl_cmp.d \
./drivers/fsl_common.d \
./drivers/fsl_cop.d \
./drivers/fsl_crc.d \
./drivers/fsl_dma.d \
./drivers/fsl_dmamux.d \
./drivers/fsl_flash.d \
./drivers/fsl_flexio.d \
./drivers/fsl_flexio_i2c_master.d \
./drivers/fsl_flexio_i2s.d \
./drivers/fsl_flexio_i2s_dma.d \
./drivers/fsl_flexio_spi.d \
./drivers/fsl_flexio_spi_dma.d \
./drivers/fsl_flexio_uart.d \
./drivers/fsl_flexio_uart_dma.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_i2c_dma.d \
./drivers/fsl_llwu.d \
./drivers/fsl_lptmr.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_lpuart_dma.d \
./drivers/fsl_pit.d \
./drivers/fsl_pmc.d \
./drivers/fsl_rcm.d \
./drivers/fsl_rtc.d \
./drivers/fsl_sim.d \
./drivers/fsl_smc.d \
./drivers/fsl_spi.d \
./drivers/fsl_spi_dma.d \
./drivers/fsl_tpm.d \
./drivers/fsl_uart.d \
./drivers/fsl_uart_dma.d \
./drivers/fsl_vref.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -flto  -g3 -D"CPU_MKL27Z64VDA4" -DFSL_RTOS_BM -I../CMSIS -I../board -I../drivers -I../startup -I../utilities -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


