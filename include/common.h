#ifndef O_COMMON_H
#define O_COMMON_H
#include "config.h"

#ifdef TEST_BUILD
#define STATIC 
#define INLINE 
#else
#define STATIC static
#define INLINE inline
#endif /*TEST_BUILD*/



#endif /*O_COMMON_H*/