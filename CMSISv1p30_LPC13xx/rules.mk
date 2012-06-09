LOCAL_DIR := $(GET_PARENT)

INCLUDES += -I$(LOCAL_DIR)/inc/

OBJS += \
	$(LOCAL_DIR)/src/core_cm3.o \
	$(LOCAL_DIR)/src/system_LPC13xx.o 
