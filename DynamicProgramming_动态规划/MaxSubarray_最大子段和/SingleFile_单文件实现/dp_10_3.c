/*
 * 最大子段和练习：使用动态规划求连续子数组的最大和。
 * 输入：元素个数 n 和 n 个整数；输出：最大子段和。
 */
#include<stdio.h>

/* 返回两个整数中的较大值。 */
int maxdp(int a, int b){
    return a>b?a:b;
}

int main() {
    /* num 保存输入序列，dp[i] 表示以 num[i] 结尾的最大子段和。 */
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
    /* 单个元素作为子段初始化；整体答案从首个状态开始更新。 */
    int dpmax=dp[0]=num[0];
    for (int i=1;i<n;i++){
        /* 在“延长前一段”和“从当前元素重新开始”之间取较大值。 */
        dp[i]=maxdp(dp[i-1]+num[i], num[i]);
        dpmax =maxdp(dpmax,dp[i]);
    }
    printf("%d", dpmax);  
}
