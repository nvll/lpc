MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
GET_PARENT = $(dir $(lastword $(MAKEFILE_LIST)))

CC = arm-elf-gcc
LD = arm-elf-ld
OBJDUMP = arm-elf-objdump
OBJCOPY = arm-elf-objcopy
OUTPUT := main
OBJDIR := build
CFLAGS = -std=c99 -mcpu=cortex-m3 -mthumb -O2 -Wall -W -nostartfiles -nostdlib -fdata-sections -ffunction-sections
LDFLAGS = -gc-sections -T link.ld 
DEFINES = 
INCLUDES := -Iinclude
ECHO = @ 

include CMSISv1p30_LPC13xx/rules.mk

OBJS += \
		vectors.o \
		main.o \


OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

.PHONY: all

all: $(OBJS)
	$(ECHO) echo "linking $(OUTPUT)"
	$(ECHO) $(LD) $(LDFLAGS) $^ -o $(OUTPUT)
	$(ECHO) $(OBJDUMP) -S $(OUTPUT) > $(OUTPUT).sym 
	$(ECHO) $(OBJCOPY) -O binary $(OUTPUT) $(OUTPUT).bin

$(OBJDIR)/%.o: %.c
	@$(MKDIR)
	$(ECHO) echo "compiling $<"
	$(ECHO) $(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $< -c -o $@
	

clean:
	rm -rf $(OBJDIR) $(OUTPUT) $(OUTPUT).bin $(OUTPUT).sym

