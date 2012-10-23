LOCAL_DIR := $(GET_PARENT)

INCLUDES += -I$(LOCAL_DIR)/include/

OBJS += \
	$(LOCAL_DIR)/lpc13xx.o \
	$(LOCAL_DIR)/gpio.o \
	$(LOCAL_DIR)/uart.o
