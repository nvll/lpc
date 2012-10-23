LOCAL_DIR := $(GET_PARENT)

INCLUDES += -I$(LOCAL_DIR)/include

OBJS += \
	$(LOCAL_DIR)/string.o \
	$(LOCAL_DIR)/ctype.o
