/*
 * 动态整数数组分配接口。
 * create_int_array 接受元素个数，成功时返回数组指针，失败时返回 NULL。
 */
#ifndef MEMORY_H
#define MEMORY_H

/* 申请 count 个 long long 大小的连续空间；调用方负责使用 free 释放。 */
long long *create_long_long_array(int count);

int *create_int_array(int count);



#endif
