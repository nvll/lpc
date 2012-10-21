#ifndef __LPC13XX_GPIO_H
#define __LPC13XX_GPIO_H

#include <LPC13xx.h>

#define GPIO(port, pin)	(port << 16 | pin)
#define GPIO_PORT(gpio) (gpio >> 16)
#define GPIO_PIN(gpio)	(gpio & 0xFFFF)
#define GPIO_INPUT      0x0
#define GPIO_OUTPUT     0x1

#define GPIO_LOW        0x0
#define GPIO_HIGH       0x1


#define GPIO_PIN_0		(0x1)
#define GPIO_PIN_1		(0x1 << 1)
#define GPIO_PIN_2		(0x1 << 2)
#define GPIO_PIN_3		(0x1 << 3)
#define GPIO_PIN_4		(0x1 << 4)
#define GPIO_PIN_5		(0x1 << 5)
#define GPIO_PIN_6		(0x1 << 6)
#define GPIO_PIN_7		(0x1 << 7)
#define GPIO_PIN_8		(0x1 << 8)
#define GPIO_PIN_9		(0x1 << 9)
#define GPIO_PIN_10		(0x1 << 10)
#define GPIO_PIN_11		(0x1 << 11)

#define LED_0	GPIO(3, GPIO_PIN_0)
#define LED_1	GPIO(3, GPIO_PIN_1)
#define LED_2	GPIO(3, GPIO_PIN_2)
#define LED_3	GPIO(3, GPIO_PIN_3)
#define LED_4	GPIO(2, GPIO_PIN_4)
#define LED_5	GPIO(2, GPIO_PIN_5)
#define LED_6	GPIO(2, GPIO_PIN_6)
#define LED_7	GPIO(2, GPIO_PIN_7)

LPC_GPIO_TypeDef *gpio_get_base(int);
void gpio_config(unsigned int, int);
void gpio_set(unsigned int, unsigned int);
unsigned int gpio_get(unsigned int);
void gpio_toggle(unsigned int);
void led_set_binary(unsigned int);

#endif
