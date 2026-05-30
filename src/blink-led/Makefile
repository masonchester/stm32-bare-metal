TARGET = firmware

# Define the linker script location and chip architecture.
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

LINKERSCRIPT = ../../STM32L476RG/STM32L476RG.ld
STARTUPSCRIPT = ../../STM32L476RG/stm32l476rg_startup.c

CFLAGS = -Wall -T $(LINKERSCRIPT)
CFLAGS += -mthumb -mcpu=$(MCU) -mfloat-abi=hard -mfpu=$(FPU)
CFLAGS += -nostdlib -specs=nosys.specs

SRCS = main.c
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

.PHONY: clean
clean:
	rm -rf ./build/$(TARGET).elf
	rm -rf ./build/$(TARGET).bin