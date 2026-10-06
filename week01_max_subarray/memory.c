/* 动态整数数组分配函数的实现。 */
#include <stdlib.h>
#include "memory.h"

long long *create_long_long_array(int count)
{
    /* 拒绝不合理的长度，避免无效或超出练习限制的内存申请。 */
    if (count <= 0 || count > 10000) {
        return NULL;
    }

    /* malloc 返回的空间未初始化；调用方需检查 NULL 并负责释放。 */
    return malloc((size_t)count * sizeof(long long));
}


int *create_int_array(int count)
{
    /* 拒绝不合理的长度，避免无效或超出练习限制的内存申请。 */
    if (count <= 0 || count > 10000) {
        return NULL;
    }

    /* malloc 返回的空间未初始化；调用方需检查 NULL 并负责释放。 */
    return malloc((size_t)count * sizeof(int));
}
