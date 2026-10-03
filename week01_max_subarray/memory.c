// memory.c
#include <stdlib.h>
#include "memory.h"

int *create_int_array(int count)
{
    if (count <= 0 || count > 10000) {
        return NULL;
    }

    return malloc((size_t)count * sizeof(int));
}