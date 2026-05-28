
COMMON_DIR = ~/projects/stm32-bare-metal/src/common
BUILD_DIR = ~/projects/stm32-bare-metal/src/build/

# Define the linker script location and chip architecture.
LD_SCRIPT = $(COMMON_DIR)/stm32l476xx.ld
MCU_SPEC  = cortex-m4

# Toolchain definitions (ARM bare metal defaults)
TOOLCHAIN = /opt/homebrew
CC = $(TOOLCHAIN)/bin/arm-none-eabi-gcc
AS = $(TOOLCHAIN)/bin/arm-none-eabi-as
LD = $(TOOLCHAIN)/bin/arm-none-eabi-ld
OC = $(TOOLCHAIN)/bin/arm-none-eabi-objcopy
OD = $(TOOLCHAIN)/bin/arm-none-eabi-objdump
OS = $(TOOLCHAIN)/bin/arm-none-eabi-size

# C compilation directives
CFLAGS += -mcpu=$(MCU_SPEC)
CFLAGS += -mthumb
CFLAGS += -mfloat-abi=hard
CFLAGS += -mfpu=fpv4-sp-d16
CFLAGS += -Wall
CFLAGS += -g
# (Set error messages to appear on a single line.)
CFLAGS += -fmessage-length=0
# (Set system to ignore semihosted junk)
CFLAGS += --specs=nosys.specs


LFLAGS += -mcpu=$(MCU_SPEC)
LFLAGS += -mthumb
LFLAGS += -mfloat-abi=hard
LFLAGS += -mfpu=fpv4-sp-d16
LFLAGS += -Wall
LFLAGS += --specs=nosys.specs
LFLAGS += -nostdlib
LFLAGS += -lgcc
LFLAGS += -T $(LD_SCRIPT)

C_SRC    = main.c $(COMMON_DIR)/stm32l476xx_startup.c

OBJS = $(C_SRC:.c=.o)

.PHONY: all
all: $(TARGET).bin

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(TARGET).elf: $( notdir $(OBJS))
	$(CC) $^ $(LFLAGS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OC) -S -O binary $< $@
	$(OS) $<

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET).elf
	rm -f $(TARGET).bin