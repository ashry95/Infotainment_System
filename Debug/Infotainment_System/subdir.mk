################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Infotainment_System/DIO.c \
../Infotainment_System/KPAD.c \
../Infotainment_System/Sos.c \
../Infotainment_System/TIM0.c \
../Infotainment_System/lcd_drive.c \
../Infotainment_System/main.c 

OBJS += \
./Infotainment_System/DIO.o \
./Infotainment_System/KPAD.o \
./Infotainment_System/Sos.o \
./Infotainment_System/TIM0.o \
./Infotainment_System/lcd_drive.o \
./Infotainment_System/main.o 

C_DEPS += \
./Infotainment_System/DIO.d \
./Infotainment_System/KPAD.d \
./Infotainment_System/Sos.d \
./Infotainment_System/TIM0.d \
./Infotainment_System/lcd_drive.d \
./Infotainment_System/main.d 


# Each subdirectory must supply rules for building sources it contributes
Infotainment_System/%.o: ../Infotainment_System/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


