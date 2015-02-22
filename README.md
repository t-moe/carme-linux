BFH carme-m4 linuxsupport
============================

## Synopsis

The following project consists of a minimal setup for the carme-m4 STM32F407 board. The makefile should be easily adaptable to your needs. 

## Motivation

We'd like to enable linux enthusiastic students of the bern university of applied sciences to work with their beloved operating system without setting up a virtual machine just to run *atollic true studio*. ;)

## Installation and required packages

You'll need the following packages installed on your system: 

        arm-none-eabi-binutils
        arm-none-eabi-gcc
        arm-none-eabi-gdb
        arm-none-eabi-newlib
        stlink
        make

The package names are taken from the arch linux community repository, hence they may differ on your linux distribution.

## Instructions

####first steps
   
- Clone the repository.
- Install the required software packages.
- Plug in your carme-m4.
- Don't forget to add yourself to the group 'dialout' by invoking "gpasswd -a ${USER} dialout"
    
#### using make

- Build software: make all
- Debug software: make debug
- flash software: make flash

## Contributors

- t-moe
- id101010

## Links

- https://carme.bfh.ch

## Additional Tags

stm32, stm32f407, bfh ti, berner fachhochschule für technik und informatik, carme-m4, atollic true studio, linux
