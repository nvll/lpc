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
	char c;
	do {
		c = hex_tbl[val >> 28];
		putc((caps) ? toupper(c) : c);
		val <<= 4;
	} while (val);
}

void _printf_int(int val)
{
	char buf[11];
	int digit, n = val, pos = 0, len = 0;

	do {
		len++;
	} while ((n /= 10));

	if(val < 0) {
		putc('-');
		val *= -1;
	}

	pos = len - 1;
	
	do {
		digit = val % 10;
		buf[pos--] = '0' + digit;
	} while ((val /= 10));
	
	buf[len] = '\0';
	_puts(buf);
}

// TODO: find a way to merge this with _printf_int
void _printf_uint(uint32_t val)
{
	char buf[10];
	int digit, n = val, pos = 0, len = 0;

	do {
		len++;
	} while ((n /= 10));

	pos = len - 1;
	
	do {
		digit = val % 10;
		buf[pos--] = '0' + digit;
	} while ((val /= 10));
	
	buf[len] = '\0';
	_puts(buf);
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
			case 'd':
				_printf_int(va_arg(ap, int));
				break;
			case 'u':
				_printf_uint(va_arg(ap, unsigned int));
				break;
			default:
				putc(c);
		}
		
	}
	va_end(ap);
	return 0;
}
