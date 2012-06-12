#ifndef __GPIO_H
#define __GPIO_H

#include <LPC13xx.h>

#define GPIO_INPUT      0x0
#define GPIO_OUTPUT     0x1

#define GPIO_LOW        0x0
#define GPIO_HIGH       0x1

#define led_on(port, pin) gpio_set(port, pin, GPIO_LOW)
#define led_off(port, pin) gpio_set(port, pin, GPIO_HIGH)

LPC_GPIO_TypeDef *gpio_get_base (int port);
void gpio_config (int port, int pin, int dir);
void gpio_set (int port, int pin, unsigned int value);

#endif
