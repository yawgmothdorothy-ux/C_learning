#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

int maxdp(int a ,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }

}
int main(){
    int count;
    scanf("%d",&count);
    int *arr = create_int_array(count);

    int *dp = create_int_array(count);

    if(arr == NULL){
        printf("Error");
        return 1;
    }
    for(int i=0;i<count;i++){
        scanf("%d",&arr[i]);
    }
    int themax = dp[0] = arr[0];
    for(int i=1;i<count;i++){
        dp[i] = maxdp(arr[i],dp[i-1]+arr[i]);
        themax = maxdp(themax,dp[i]);
    }
    printf("%d\n",themax);
    return 0;
}