/*
 * 最大子段和程序入口。
 * 从标准输入读取数组长度和数组元素，调用 max_subarray 计算结果，
 * 输出最大连续子数组和，并释放申请的内存。
 */
#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "Max_subarray.h"



int main(){


    int count;
    /* 限制输入规模，保证后续数组申请符合本练习的范围。 */
    if (scanf("%d", &count) != 1 ||
        count < 1 || count > 10000) {
        printf("数量输入错误\n");
        return 1;
    }

    /* 动态申请数组空间，避免将较大的输入数组放在栈上。 */
    int *arr = create_int_array(count);

        if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    for(int i=0;i<count;i++){

        if (scanf("%d", &arr[i]) != 1) {
            printf("第%d个元素输入错误\n", i + 1);
            free(arr);
            return 1;
        }
    
    }

    /* out_sum 接收算法计算出的最大子段和。 */
    MaxSubarrayResult out_sum;

    if (max_subarray(arr, count, &out_sum) == 0) {
        printf("计算失败\n");
        free(arr);
        return 1;
    }

    printf("最大和：%lld\n", out_sum.sum);
    printf("起点下标：%d\n", out_sum.start);
    printf("终点下标：%d\n", out_sum.end);

   
    free(arr);
    return 0;

}
