#include <stdint.h>
#include <cortex-m3.h>

static uint8_t cortex_m3_stack[CM3_STACKSIZE];
typedef void * irq_handler_t;
extern void main();

void cortex_m3_start(void)
{
	main();
}

// 
void __WEAK puts(const char *s)
{
}

DEFINE_HANDLER(nmi);
DEFINE_HANDLER(hardfault);
DEFINE_HANDLER(memmanage);
DEFINE_HANDLER(busfault);
DEFINE_HANDLER(usagefault);
DEFINE_HANDLER(svc);
DEFINE_HANDLER(debug);
DEFINE_HANDLER(pendsv);
DEFINE_HANDLER(systick);


const irq_handler_t __SECTION(".text.vector_table") vector_table[] = {
	cortex_m3_stack + sizeof(cortex_m3_stack), // ARM stack grows downward
	cortex_m3_start,
	HANDLER(nmi),
	HANDLER(hardfault),
	HANDLER(memmanage),
	HANDLER(busfault),
	HANDLER(usagefault),
	0, // Reserved
	0, // Reserved
	0, // Reserved
	0, // Reserved
	HANDLER(svc),
	HANDLER(debug),
	0, // Reserved
	HANDLER(pendsv),
	HANDLER(systick),
};
