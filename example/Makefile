#2015 by tmoe, id10101 (and the internet :) )

#Name of the binary/project
TARGET=hello

#Tools
CROSS_COMPILE=arm-none-eabi-
CC=$(CROSS_COMPILE)gcc
OBJCOPY=$(CROSS_COMPILE)objcopy
GDB=$(CROSS_COMPILE)gdb

MKDIR=mkdir -p
RM=rm -f
RMDIR=rm -rf
STUTIL=utils/st-util-daemon.sh

#Directories
SRC_DIR=./src
OBJ_DIR=./obj
BUILD_DIR=./build
LIB_DIR=./libs

#Architecture flags
FP_FLAGS?=-mfpu=fpv4-sp-d16 -mfloat-abi=softfp
ARCH_FLAGS=-mthumb -mcpu=cortex-m4 $(FP_FLAGS)

#Compiler, Linker Options
CPPFLAGS=-I$(LIB_DIR)/BSP -I$(LIB_DIR)/sGUI
CFLAGS=$(ARCH_FLAGS) -O0 -ffunction-sections -fdata-sections -g
LDFLAGS=-Wl,--start-group -lm -Wl,--end-group -static -Wl,-cref,-u,Reset_Handler 
LDFLAGS+=-Wl,-Map=$(BUILD_DIR)/$(TARGET).map 
LDFLAGS+=-Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x1000

#Finding Input files
CFILES=$(shell find $(SRC_DIR) -name '*.c')
SFILES=$(SRC_DIR)/startup.s

#Generate corresponding obj names
SOBJS=$(SFILES:.s=.o)
COBJS=$(CFILES:.c=.o)
OBJS=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOBJS) $(COBJS))

#Keep the objects files
.SECONDARY: $(OBJS)

#Mark targets which are not "file-targets"
.PHONY: all debug flash clean

# List of all binaries to build
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin

start:
	$(STUTIL) start

stop:
	$(STUTIL) stop

#objects to elf
%.elf : $(OBJS)
	@echo Linking...
	$(MKDIR) $(BUILD_DIR)
	$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -T./utils/stm32f4_flash.ld $^

#elf to binary
%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

#Asm files to objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@echo Assembling $<...
	$(MKDIR) $(OBJ_DIR)
	$(CC) -x assembler-with-cpp $(CFLAGS) $(CPPFLAGS) -c $< -o $@

#C files to objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<...
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

#Clean Obj files and builded stuff
clean:
	$(RMDIR) $(BUILD_DIR) $(OBJ_DIR)

#Debug target: starts the st-util server and gdb and leaves it open
debug: start all
	$(GDB) $(BUILD_DIR)/$(TARGET).elf -x ./utils/gdb.script

#Flash target: starts the st-util server flashes the elf with gdb and exits afterwards
flash: start all
	$(GDB) $(BUILD_DIR)/$(TARGET).elf -x ./utils/gdb.script -batch
