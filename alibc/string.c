#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>

extern void _putc(const char c);
void putc(const char c)
{
	_putc(c);
}

/* puts with no \n */
void _puts(const char *s)
{
	int x = 0;
	while (s[x] != '\0')
		putc(s[x++]);
}

void puts(const char *s)
{
	_puts(s);
	putc('\n');
}

int strlen(const char *s)
{
	int cnt = 0;
	while (s[cnt++] != '\0')
		;;

	return cnt-1;
}

static char hex_tbl[] = "0123456789abcdef";
void _printf_hex(unsigned int val, int caps)
{
	while (val) {
		uint8_t masked = (val >> 28);
		if(masked) {
			int hex = hex_tbl[masked];
			putc((caps) ? toupper(hex) : hex);
		}
		val <<= 4;
	}
}

int printf(const char * restrict format, ...)
{
	va_list ap;
	char c;

	va_start(ap, format);
	while((c = *format++)) {
		int arg = 0;

		if (c != '%') {
			putc(c);
			continue;
		}

		switch((c = *format++)) {
		case 's':
			_puts(va_arg(ap, char *));
			break;
		case 'X':
			arg = 1;
		case 'x':
			_printf_hex(va_arg(ap, uint32_t), arg);
			break;
		default:
			putc(c);
		}
	}
	va_end(ap);
	return 0;
}
