#ifndef __CORTEX_M3_H
#define __CORTEX_M3_H

#define __WEAK			__attribute__((weak))
#define __SECTION(x)	__attribute__((section(x)))
#define DEFINE_HANDLER(x) \
void __WEAK x##_handler(void) \
{ \
}

#define HANDLER(x) &x##_handler
#endif
