#2015 by tmoe, (and the internet :) )


#Name of the binary/project
TARGET = hello


#Known issues:
#obj dir is not actually used, obj's are placed under source


#Tools
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
MKDIR = mkdir -p



#Directories
SOURCE_DIR = ./src
OBJ_DIR = ./obj # not used yet
BUILD_DIR = ./build
LIB_DIR = ./libs


#Architecture flags
FP_FLAGS ?= -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
ARCH_FLAGS = -mthumb -mcpu=cortex-m4 $(FP_FLAGS)

#Compiler, Linker Options
CPPFLAGS = -I$(LIB_DIR)/BSP -I$(LIB_DIR)/sGUI
CFLAGS = $(ARCH_FLAGS) -O0 -ffunction-sections -fdata-sections -g
LDFLAGS =  -Wl,--start-group -lm -Wl,--end-group -static -Wl,-cref,-u,Reset_Handler 
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(TARGET).map 
LDFLAGS += -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x1000


#Finding Input files
CFILES		= 	$(shell find $(SOURCE_DIR) -name '*.c')
#CFILES  	=	$(notdir $(wildcard $(SOURCE_DIR)/*.c))
SFILES  	=	$(SOURCE_DIR)/startup.s

#Generate corresponding obj names
SOBJS   =	$(SFILES:.s=.o)
COBJS   =	$(CFILES:.c=.o)
OBJS    =	$(SOBJS) $(COBJS)

#Keep the objects files
.SECONDARY: $(OBJS)

#Mark targets which are not "file-targets"
.PHONY: all debug flash clean


# List of all binaries to build
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin

#objects to elf
%.elf : $(OBJS)
	@echo Linking...
	$(MKDIR) $(BUILD_DIR)
	$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -T./utils/stm32f4_flash.ld $^

#elf to binary
%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

#Asm files to objects
%.o: %.s
	@echo Assembling $<...
	$(CC) -x assembler-with-cpp $(CFLAGS) $(CPPFLAGS) -c $< -o $@

#C files to objects
%.o: %.c
	@echo Compiling $<...
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<


#Clean Obj files and builded stuff
clean:
	rm -rf $(BUILD_DIR) $(OBJ_DIR)
	rm -f $(SOURCE_DIR)/*.o

#Debug target: starts gdb and leaves it open
debug: all
	arm-none-eabi-gdb $(BUILD_DIR)/$(TARGET).elf -x ./utils/gdb.script

#Flash target: flashes the elf with gdb and exits afterwards
flash: all
	arm-none-eabi-gdb $(BUILD_DIR)/$(TARGET).elf -x ./utils/gdb.script -batch


