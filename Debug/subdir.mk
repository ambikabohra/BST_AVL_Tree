################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AvlTree.cpp \
../BSTApp.cpp \
../BinaryNode.cpp \
../BinarySearchTree.cpp \
../BinaryTreeChecker.cpp \
../BinaryTreePrinter.cpp 

OBJS += \
./AvlTree.o \
./BSTApp.o \
./BinaryNode.o \
./BinarySearchTree.o \
./BinaryTreeChecker.o \
./BinaryTreePrinter.o 

CPP_DEPS += \
./AvlTree.d \
./BSTApp.d \
./BinaryNode.d \
./BinarySearchTree.d \
./BinaryTreeChecker.d \
./BinaryTreePrinter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


