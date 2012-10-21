MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
GET_PARENT = $(patsubst %/, %, $(dir $(lastword $(MAKEFILE_LIST))))

CC = arm-eabi-gcc
LD = arm-eabi-ld
OBJDUMP = arm-eabi-objdump
OBJCOPY = arm-eabi-objcopy
OBJS := 
OUTPUT := main
BUILDDIR := build
CFLAGS = -std=c99 -mcpu=cortex-m3 -mthumb -O2 -Wall -W -nostartfiles -nostdlib -fno-builtin -fdata-sections -ffunction-sections
LDFLAGS = -gc-sections -T $(BUILDDIR)/cortex-m3.ld 
DEFINES = -D STACK_SIZE=2048
INCLUDES := -Iinclude  
ECHO = @ 

all: buildall
CM3_ROMBASE := 0x00000000
CM3_MEMBASE := 0x10000000
CM3_MEMSIZE := 0x00008000
include cortex-m3/rules.mk
include lpc13xx/CMSISv1p30_LPC13xx/rules.mk
include lpc13xx/rules.mk

OBJS += \
	main.o \


OBJS := $(addprefix $(BUILDDIR)/, $(OBJS))

buildall: $(OBJS)
	$(ECHO) echo "linking $(OUTPUT)"
	$(ECHO) $(LD) $(LDFLAGS) $^ -o $(OUTPUT)
	$(ECHO) $(OBJDUMP) -Dlx $(OUTPUT) > $(OUTPUT).dump 
	$(ECHO) $(OBJCOPY) -O binary $(OUTPUT) $(OUTPUT).bin

$(BUILDDIR)/%.o: %.c
	@$(MKDIR)
	$(ECHO) echo "compiling $<"
	$(ECHO) $(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $< -c -o $@
	

clean:
	rm -rf $(BUILDDIR) $(OUTPUT) $(OUTPUT).bin $(OUTPUT).dump

.PHONY: all buildall
