#include <ctype.h>

int tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 31);
	return c;
}

int toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 31);
	return c;
}
