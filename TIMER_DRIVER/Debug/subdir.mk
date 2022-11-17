################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TIMER_DRIVER_program.c 

OBJS += \
./TIMER_DRIVER_program.o 

C_DEPS += \
./TIMER_DRIVER_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\courses\eclipse drivers\global_interrupt_driver" -I"D:\courses\eclipse drivers\MCAL\DIO_Driver" -I"D:\courses\eclipse drivers\MCAL\INTERRUPT_DRIVER" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


