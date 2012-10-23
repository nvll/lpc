#ifndef __LPC13XX_IOCON_H
#define __LPC13XX_IOCON_H

#define IOCON_FUNC_1		0x1
#define IOCON_FUNC_2		0x2
#define IOCON_MODE_PULLDOWN		(0x1 << 3)
#define IOCON_MODE_PULLUP		(0x2 << 3)
#define IOCON_MODE_REPEAT		(0x3 << 3)
#define IOCON_HYS_ENABLE		(0x1 << 5)
#define IOCON_OD_ENABLE			(0x1 << 10)

#endif
