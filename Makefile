MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
GET_PARENT = $(dir $(lastword $(MAKEFILE_LIST)))

CC = arm-eabi-gcc
LD = arm-eabi-ld
OBJDUMP = arm-eabi-objdump
OBJCOPY = arm-eabi-objcopy
OBJS = 
OUTPUT := main
OBJDIR := build
CFLAGS = -std=c99 -mcpu=cortex-m3 -mthumb -O2 -Wall -W -nostartfiles -nostdlib -fno-builtin -fdata-sections -ffunction-sections
LDFLAGS = -gc-sections -T cortex-m3.ld 
DEFINES = -D STACK_SIZE=2048
INCLUDES := -Iinclude  
ECHO = @ 

include lpc13xx/CMSISv1p30_LPC13xx/rules.mk
$(warning $(OBJS))
include lpc13xx/rules.mk
$(warning $(OBJS))
include cortex-m3/rules.mk
$(warning $(OBJS))

OBJS += \
	main.o \


OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

all: $(OBJS)
	$(ECHO) echo "linking $(OUTPUT)"
	$(ECHO) $(LD) $(LDFLAGS) $^ -o $(OUTPUT)
	$(ECHO) $(OBJDUMP) -Dlx $(OUTPUT) > $(OUTPUT).dump 
	$(ECHO) $(OBJCOPY) -O binary $(OUTPUT) $(OUTPUT).bin

$(OBJDIR)/%.o: %.c
	@$(MKDIR)
	$(ECHO) echo "compiling $< from $@"
	$(ECHO) $(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $< -c -o $@
	

clean:
	rm -rf $(OBJDIR) $(OUTPUT) $(OUTPUT).bin $(OUTPUT).dump

