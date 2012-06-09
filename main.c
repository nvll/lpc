#include <system_LPC13xx.h>
#include <LPC13xx.h>

// LEDs 0-3 are PIO3_0 through PIO3_3, in GPIO block 3
void _start (void)
{
	SystemInit();

    LPC_IOCON->PIO3_3 = 0xFF;
    LPC_IOCON->PIO3_2 = 0xFF;
    LPC_IOCON->PIO3_1 = 0xFF;
    LPC_IOCON->PIO3_0 = 0xFF;
    LPC_IOCON->PIO2_4 = 0xFF;
    LPC_IOCON->PIO2_5 = 0xFF;
    LPC_IOCON->PIO2_6 = 0xFF;
    LPC_IOCON->PIO2_7 = 0xFF;
    LPC_GPIO1->DIR = 0xFF; 
    LPC_GPIO1->DIR = 0xFF; 
    LPC_GPIO2->DATA = 0xFF;
    LPC_GPIO2->DATA = 0xFF;
    LPC_GPIO3->DIR = 0xFF; 
    LPC_GPIO3->DATA = 0xFF;

	return;
}
