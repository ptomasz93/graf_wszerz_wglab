################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../prj/generator.cpp \
../prj/graf.cpp \
../prj/komiwojazer.cpp \
../prj/main.cpp \
../prj/menu.cpp \
../prj/wierzcholek.cpp 

OBJS += \
./prj/generator.o \
./prj/graf.o \
./prj/komiwojazer.o \
./prj/main.o \
./prj/menu.o \
./prj/wierzcholek.o 

CPP_DEPS += \
./prj/generator.d \
./prj/graf.d \
./prj/komiwojazer.d \
./prj/main.d \
./prj/menu.d \
./prj/wierzcholek.d 


# Each subdirectory must supply rules for building sources it contributes
prj/%.o: ../prj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


