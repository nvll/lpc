#ifndef __CORTEX_M3_H
#define __CORTEX_M3_H

#define __WEAK			__attribute__((weak))
#define __SECTION(x)	__attribute__((section(x)))
#define HANDLER(x) &x##_handler
#define DEFINE_HANDLER(x) \
void __WEAK x##_handler(void) \
{ \
	puts(__PRETTY_FUNCTION__); \
	while(1) \
		;; \
}

inline void spin(int ms)
{
    for (int x = ms * 10000; x > 0; x--)
        __asm__ ("nop");
}

#endif
