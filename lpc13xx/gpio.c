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

inline void gpio_config (int port, int pin, int dir)
{
    LPC_GPIO_TypeDef *gpio = gpio_get_base(port);
    gpio->DIR = (gpio->DIR & ~(1 << pin)) | (dir << pin);
}

void gpio_set (int port, int pin, unsigned int value)
{
    LPC_GPIO_TypeDef *gpio = gpio_get_base(port);
    gpio->DATA = (gpio->DATA & ~(1 << pin)) | (value << pin);
}


