#include <system_LPC13xx.h>
#include <LPC13xx.h>
#include <gpio.h>
#include <uart.h>
#include <string.h>
#include <stdint.h>

void spin(int ms)
{
    for (int x = ms * 10000; x > 0; x--)
        __asm__ ("nop");
}

int main(void)
{
	SystemInit();
    uart_init();
	puts("kernel alive");
    
    gpio_config(GPIO(2, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7), GPIO_OUTPUT);
    gpio_config(GPIO(3, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), GPIO_OUTPUT);
    
    uint32_t value = 0;
    while (1) {
		spin(1000);
		led_set_binary(value++);
    }
}
