TARGET = firmware

# Define the chip architecture.
MCU = cortex-m4
FPU = fpv4-sp-d16

# Toolchain definitions (ARM bare metal defaults)
TOOLCHAIN = /opt/homebrew
CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-as
LD = $(TOOLCHAIN)/bin/arm-none-eabi-ld
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size

# Define linker and startup scripts location
LINKERSCRIPT = ../../STM32L476RG/STM32L476RG.ld
STARTUPSCRIPT = ../../STM32L476RG/stm32l476rg_startup.c

# Define included header files 
INCLUDE = -I../../Drivers/CMSIS/Core/Include
INCLUDE += -I../../Drivers/CMSIS/Device/Include
INCLUDE += -I./include

# Define compilation flags
CFLAGS = -Wall -T $(LINKERSCRIPT)
CFLAGS += -mthumb -mcpu=$(MCU) -mfloat-abi=hard -mfpu=$(FPU)
CFLAGS += -nostdlib -specs=nosys.specs
CFLAGS += $(INCLUDE)

# Build sources
SRCS = main.c gpio_handler.c led.c button.c
SRCS += $(STARTUPSCRIPT)

.PHONY: all
all: $(TARGET).elf $(TARGET).bin

$(TARGET).elf:
	$(CC) $(CFLAGS) $(SRCS) -o ./build/$(TARGET).elf

$(TARGET).bin:
	$(OC) -O binary ./build/$(TARGET).elf ./build/$(TARGET).bin

.PHONY: flash
flash:
	st-flash --reset write ./build/$(TARGET).bin 0x08000000

.PHONY: flash-clean
flash-clean:
	st-flash erase

.PHONY: clean
clean:
	rm -rf ./build/$(TARGET).elf
	rm -rf ./build/$(TARGET).bin
