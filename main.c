#include <system_LPC13xx.h>
#include <LPC13xx.h>
#include <gpio.h>
#include <uart.h>
#include <string.h>

void spin(int ms)
{
    for (int x = ms * 10000; x > 0; x--)
        __asm__ ("nop");
}

int main(void)
{
	SystemInit();
	
    uart_init();
    
    gpio_config(3, 0, GPIO_OUTPUT);
    gpio_config(3, 1, GPIO_OUTPUT);
    gpio_config(3, 2, GPIO_OUTPUT);
    gpio_config(3, 3, GPIO_OUTPUT);
    
    SysTick->CTRL = (1 << 0) | (1 << 1) | (1 << 2);
    SysTick->LOAD = 5;
    SysTick->VAL = 5;
    int value = 0;
    while (1) {
        for (int x = 0; x < 4; x++) {
            spin(1000);
            gpio_set(3, x, value);

        }
        value = !value;
    }
}
