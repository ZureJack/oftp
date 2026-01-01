#include "mem.h"
#include <stdlib.h>
#include <string.h>



void *omem_alloc(size_t size)
{
    size_t n = size + sizeof(Omem);
    Omem * ptr = (Omem *)malloc(n);
    memset(ptr, 0, n);
    ptr->size = size;
    return (void *)ptr->data;
}
void omem_free(void *ptr)
{
    if (NULL == ptr)
    {
        return ;
    }
    free(container_of(ptr, Omem, data));
}