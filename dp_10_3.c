#include<stdio.h>

int maxdp(int a, int b){
    return a>b?a:b;
}

int main() {
    int n;
    int num[1000]={0};
    int dp[1000]={0};
    scanf("%d", &n);

    if (n>995 || n<1){
        printf("ERROR");
        return 0;
    }
    for (int i=0;i<n;i++){
        scanf("%d", &num[i]);
    }
    int dpmax=dp[0]=num[0];
    for (int i=1;i<n;i++){
        dp[i]=maxdp(dp[i-1]+num[i], num[i]);
        dpmax =maxdp(dpmax,dp[i]);
    }
    printf("%d", dpmax);  
}