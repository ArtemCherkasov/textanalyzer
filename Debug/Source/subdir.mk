################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/ContextMenu.cpp \
../Source/ContextMenuItemList.cpp \
../Source/FileSystem.cpp \
../Source/FullDictionary.cpp \
../Source/LexiconHandle.cpp \
../Source/Point.cpp \
../Source/ScrollBar.cpp \
../Source/TextField.cpp \
../Source/TextLoader.cpp \
../Source/Word.cpp \
../Source/WordBlock.cpp 

OBJS += \
./Source/ContextMenu.o \
./Source/ContextMenuItemList.o \
./Source/FileSystem.o \
./Source/FullDictionary.o \
./Source/LexiconHandle.o \
./Source/Point.o \
./Source/ScrollBar.o \
./Source/TextField.o \
./Source/TextLoader.o \
./Source/Word.o \
./Source/WordBlock.o 

CPP_DEPS += \
./Source/ContextMenu.d \
./Source/ContextMenuItemList.d \
./Source/FileSystem.d \
./Source/FullDictionary.d \
./Source/LexiconHandle.d \
./Source/Point.d \
./Source/ScrollBar.d \
./Source/TextField.d \
./Source/TextLoader.d \
./Source/Word.d \
./Source/WordBlock.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


