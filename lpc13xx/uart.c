#include <LPC13xx.h>
#include <cortex-m3.h>
#include <uart.h>
#include <iocon.h>

/*
    LPC13xx uses
    RTS - PIO1_5 - direction control pin
    RXD - PIO1_6 - serial input
    TXD - PIO1_7 - serial output
    DTR - PIO2_0 - data terminal ready
    DSR - PIO2_1 - data set ready
    DCD - PIO2_2 - data carrier detect
    CTS - PIO0_7 - clear to send
*/

void uart_init()
{
	// ioconfig setup
	LPC_IOCON->PIO1_6 = IOCON_FUNC_1; // function RXD
	LPC_IOCON->PIO1_7 = IOCON_FUNC_1; // function TXD

	// enable uart
	LPC_SYSCON->SYSAHBCLKCTRL |= LPC13XX_UART_AHB_CLK_ENABLE;

	// 115200
	LPC_SYSCON->UARTCLKDIV = 0x128;

	LPC_UART->LCR = LPC13XX_UART_LCR_8BIT;
	LPC_UART->FCR = LPC13XX_UART_FIFO_ENABLE | LPC13XX_UART_RX_RST | LPC13XX_UART_TX_RST;

	spin(1); // without this the uart eats the first character we print on setup. Race?

}

void _putc(char c)
{
	if (c == '\n')
		_putc('\r');

	while (!(LPC_UART->LSR & LPC13XX_UART_THRE))
		;;


	LPC_UART->THR = c;
}
