#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int main(){
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }
    
    // 按草稿纸编号使用下标 1..n，第 0 行和第 0 列不用。
    int dp[n+1][n+1];
    int num[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&num[i][j]);
        }
    }
    // 下标统一从 1 开始：顶点的路径和就是顶点本身。
    dp[1][1]= num[1][1];
    // 包含最后一行；一行和两行的情况也由同一套逻辑处理。
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j == 1){
                dp[i][j] = num[i][1] + dp[i-1][1];
            }else if(j == i){
                dp[i][j] = num[i][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = num[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    // 必须走到底部，只从最后一行选答案。
    int maxdp = dp[n][1];
    for(int j=2;j<=n;j++){
        maxdp = max(maxdp,dp[n][j]);
    }
    printf("%d\n",maxdp);
    return 0;
}
