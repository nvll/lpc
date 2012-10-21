LOCAL_DIR := $(GET_PARENT)

INCLUDES += -I$(LOCAL_DIR)

OBJS += \
	$(LOCAL_DIR)/cortex-m3.o \
	cortex-m3.ld

$(BUILDDIR)/cortex-m3.ld: $(LOCAL_DIR)/cortex-m3.ld Makefile
	@$(MKDIR)
	@echo generating linker script using CM3_ROMBASE=$(CM3_ROMBASE), CM3_MEMBASE=$(CM3_MEMBASE), CM3_MEMSIZE=$(CM3_MEMSIZE)
	@sed "s/%CM3_ROMBASE%/$(CM3_ROMBASE)/;s/%CM3_MEMBASE%/$(CM3_MEMBASE)/;s/%CM3_MEMSIZE%/$(CM3_MEMSIZE)/" < $< > $@
