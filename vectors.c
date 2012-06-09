#include <stdint.h>

static uint8_t stack[2048];
typedef void * irq_handler_t;

extern void _start(void);

void nmi_handler(void) {
}

void memmange_handler(void) {
}

void busfault_handler(void) {
}

void usagefault_handler(void) {
}

void svc_handler(void) {
}

void pendsv_handler(void) {
}

void systick_handler(void) {
}

void debug_monitor(void) {
}

const irq_handler_t __attribute__((section(".text.vector_table"))) vector_table[] = {
	stack + sizeof(stack),
	_start,
	memmange_handler,
	busfault_handler,
	usagefault_handler,
	0,
	0,
	0,
	0,
	svc_handler,
	debug_monitor,
	0,
	pendsv_handler,
	systick_handler,
};
