#include <system_LPC13xx.h>
#include <LPC13xx.h>

// LEDs 0-3 are PIO3_0 through PIO3_3, in GPIO block 3
void _start (void)
{
	SystemInit();

    LPC_GPIO3->DIR = 0xFF; 
    LPC_GPIO3->DATA = 0xFF;

	return;
}
