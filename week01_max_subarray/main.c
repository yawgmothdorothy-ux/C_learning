#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "Max_subarray.h"

int main(){
    int count;
    if (scanf("%d", &count) != 1 ||
        count < 1 || count > 10000) {
        printf("数量输入错误\n");
        return 1;
    }

    int *arr = create_int_array(count);

        if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    for(int i=0;i<count;i++){
        scanf("%d",&arr[i]);
    }

    long long out_sum;

    if (max_subarray(arr, count, &out_sum) == 0) {
        printf("计算失败\n");
        free(arr);
        return 1;
    }

    printf("%lld\n", out_sum);
    free(arr);
    return 0;

}