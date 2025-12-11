#ifndef O_PRIVATE_MEM_H
#define O_PRIVATE_MEM_H
#include "mem/mem.h"

struct Omem
{
    size_t size;
    unsigned char data[1];
};

#define offsetof(type, member) \
    ((size_t)(&((type *)0)->member))

// 通过成员指针获取结构体基地址
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#endif