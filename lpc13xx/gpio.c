#include <gpio.h>

// Some of this could be done by indexing right off GPIOBASE0
LPC_GPIO_TypeDef *gpio_get_base (int port)
{   
    if (port == 0)
        return LPC_GPIO0;
    else if (port == 1)
        return LPC_GPIO1;
    else if (port == 2)
        return LPC_GPIO2;
    else if (port == 3)
        return LPC_GPIO3;

    return 0;
}

void gpio_config(unsigned int gpio, int dir)
{
	unsigned int port = GPIO_PORT(gpio), pin = GPIO_PIN(gpio);
    LPC_GPIO_TypeDef *gpio_base = gpio_get_base(port);
	if (dir) {
		gpio_base->DIR |= pin;
	} else {
		gpio_base->DIR &= ~pin;
	}
}

/*	For gpio access the LPC13xx chips have a bank of memory that
 *	can be indexed into with an offset based on which pin you want.
 *	This means we can use an address to get exactly the data we want
 *	without needing to mask
 */

void gpio_set(unsigned int gpio, unsigned int value)
{
	unsigned int port = GPIO_PORT(gpio), pin = GPIO_PIN(gpio);
    LPC_GPIO_TypeDef *gpio_base = gpio_get_base(port);
	gpio_base->MASKED_ACCESS[pin] = (value) ? 0xFFFF : 0x0;
}

unsigned int gpio_get(unsigned int gpio)
{
	unsigned int port = GPIO_PORT(gpio), pin = GPIO_PIN(gpio);
    LPC_GPIO_TypeDef *gpio_base = gpio_get_base(port);
	return gpio_base->MASKED_ACCESS[pin];
}

void gpio_toggle(unsigned int gpio)
{
	unsigned int value = gpio_get(gpio);
	gpio_set(gpio, !value);
}

void led_set_binary(unsigned int val)
{
	gpio_set(LED_0, (val & (1 << 0)) ? 0 : 1);
	gpio_set(LED_1, (val & (1 << 1)) ? 0 : 1);
	gpio_set(LED_2, (val & (1 << 2)) ? 0 : 1);
	gpio_set(LED_3, (val & (1 << 3)) ? 0 : 1);
	gpio_set(LED_4, (val & (1 << 4)) ? 0 : 1);
	gpio_set(LED_5, (val & (1 << 5)) ? 0 : 1);
	gpio_set(LED_6, (val & (1 << 6)) ? 0 : 1);
	gpio_set(LED_7, (val & (1 << 7)) ? 0 : 1);
}

