/*
 * 最大子段和算法实现。
 * max_subarray 使用动态规划计算整数数组的最大连续子数组和，
 * 通过 out_sum 返回结果，以返回值表示成功或失败。
 */
#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "Max_subarray.h"

/* 返回两个候选子段和中的较大值。 */
static long long maxdp(long long a, long long b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }

}
int max_subarray(const int *arr, int n, MaxSubarrayResult *out_sum){

    /* 检查数组、输出位置和元素个数，避免无效输入。 */
    if (arr == NULL || out_sum == NULL || n <= 0) {
        return 0;  // 失败
    }



    /* dp[i] 表示以 arr[i] 结尾的最大连续子数组和。 */
    int count = n;
    long long *dp = create_long_long_array(count);

    if(dp == NULL){
        printf("Error");
        return 0;
    }
    /* 以首元素初始化，然后逐项决定延长旧子段或从当前元素重启。 */
       dp[0] = arr[0];

       int current_start = 0;

         out_sum->sum = arr[0];
         out_sum->start = 0;
         out_sum->end = 0;

    for(int i=1;i<count;i++){

        if (dp[i-1] < 0){
            dp[i] = arr[i];
            current_start = i;
        }
        else{
            dp[i] = dp[i-1]+arr[i];

        }
       if (dp[i] > out_sum->sum){
            out_sum->sum = dp[i];
            out_sum->start = current_start;
            out_sum->end = i;
        }
    }
    free(dp);
    return 1;
}
