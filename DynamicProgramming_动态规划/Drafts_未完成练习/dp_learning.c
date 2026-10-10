/*
 * 动态规划练习：定义三个整数中的最大值和最小值辅助函数，
 * 并预留数组来记录状态。main 中的状态转移循环尚未完成。
 */
#include<stdio.h>

/* 返回 a、b、c 三个整数中的最大值。 */
long max(int a,int b,int c){

    int n[3]={a,b,c};

    int max =a;

    for(int i=1;i<=2;i++){
        if (n[i]>max){
            max =n[i];
        }
    }
    return max;
}

/* 返回 a、b、c 三个整数中的最小值。 */
long min(int a,int b,int c){

    int n[3]={a,b,c};

    int min =a;

    for(int i=1;i<=2;i++){
        if (n[i]<min){
            min =n[i];
        }
    }
    return min;
}
int main(){

    /* num 保存输入序列；dp_max 和 dp_min 预备用于记录动态规划状态。 */
    int n;
    int num_max;
    int i=0,j=0;
    int num[1005];
    int dp_max[1005]={0};
    int dp_min[1005]={0};

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    /* 用第一个数初始化状态；后续状态转移逻辑仍待补充。 */
    num_max=dp_max[0]=dp_min[0]=num[0];
    for (i=1;i<n;i++){

    }
    printf("%d",num_max);

}
