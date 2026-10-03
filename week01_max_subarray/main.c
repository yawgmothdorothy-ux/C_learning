#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "Max_subarray.h"

int main(){
    int count;
    scanf("%d",&count);
    int *arr = create_int_array(count);

    long long out_sum;
    max_subarray(arr, count, &out_sum);
    printf("%lld\n", out_sum);
    return 0;
}