LOCAL_DIR := $(GET_PARENT)

INCLUDES += -I$(LOCAL_DIR)
LDFLAGS += -T $(BUILDDIR)/cortex-m3.ld 
DEFINES += -D CM3_STACKSIZE=${CM3_STACKSIZE}

OBJS += \
	$(LOCAL_DIR)/cortex-m3.o \
	cortex-m3.ld

$(BUILDDIR)/cortex-m3.ld: $(LOCAL_DIR)/cortex-m3.ld Makefile
	@$(MKDIR)
	@echo generating linker script using:
	@echo CM3_ROMBASE=$(CM3_ROMBASE)
	@echo CM3_MEMBASE=$(CM3_MEMBASE)
	@echo CM3_MEMSIZE=$(CM3_MEMSIZE)
	@echo CM3_STACKSIZE=$(CM3_STACKSIZE)
	@sed "s/%CM3_ROMBASE%/$(CM3_ROMBASE)/;s/%CM3_MEMBASE%/$(CM3_MEMBASE)/;s/%CM3_MEMSIZE%/$(CM3_MEMSIZE)/" < $< > $@
