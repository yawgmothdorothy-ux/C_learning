#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "Max_subarray.h"

static int maxdp(int a ,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }

}
int max_subarray(const int *arr, int n, long long *out_sum){

    if (arr == NULL || out_sum == NULL || n <= 0) {
        return 0;  // 失败
    }

    int count = n;
    int *dp = create_int_array(count);

    if(dp == NULL){
        printf("Error");
        return 0;
    }
    int themax = dp[0] = arr[0];
    for(int i=1;i<count;i++){
        dp[i] = maxdp(arr[i],dp[i-1]+arr[i]);
        themax = maxdp(themax,dp[i]);
    }
    *out_sum = themax;
    free(dp);
    return 1;
}