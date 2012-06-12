#ifndef __UART_H
#define __UART_H


#define LPC13XX_UART_AHB_CLK_ENABLE     (1 << 12)
// Line Control Register
#define LPC13XX_UART_LCR_8BIT   0x3

// FIFO Control Register
#define LPC13XX_UART_FIFO_ENABLE    0x1
#define LPC13XX_UART_RX_RST     (1 << 1)
#define LPC13XX_UART_TX_RST     (1 << 2)

// Line Status Register
#define LPC13XX_UART_THRE       (1 << 5)
#define LPC13XX_UART_TEMT       (1 << 6)

void uart_init();
void uart_putc(char buf);

#endif
