/* 最大子段和函数的声明，供 main.c 等调用方使用。 */
#ifndef MAX_SUBARRAY_H
#define MAX_SUBARRAY_H


typedef struct {
    long long sum;
    int start;
    int end;
}MaxSubarrayResult;

/*
 * 计算 arr[0..n-1] 的最大连续子数组和。
 * 成功返回 1 并将结果写入 *out_sum；参数无效或分配失败时返回 0。
 */
int max_subarray(const int *arr, int n, MaxSubarrayResult *out_sum);



#endif
