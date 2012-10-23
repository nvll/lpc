#ifndef __CORTEX_M3_H
#define __CORTEX_M3_H

#define __WEAK			__attribute__((weak))
#define __SECTION(x)	__attribute__((section(x)))
#define DEFINE_HANDLER(x) \
void __WEAK x##_handler(void) \
{ \
}

inline void spin(int ms)
{
    for (int x = ms * 10000; x > 0; x--)
        __asm__ ("nop");
}

#define HANDLER(x) &x##_handler
#endif
