#ifndef O_COMMON_H
#define O_COMMON_H
#include <inttypes.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include "config.h"

#ifdef TEST_BUILD
#define STATIC 
#define INLINE 
#else
#define STATIC static
#define INLINE inline
#endif /*TEST_BUILD*/
#define API extern
#define UNUSED(val) ((void)val)

struct Obuf
{
    size_t size;
    unsigned char *buf;
};



#endif /*O_COMMON_H*/