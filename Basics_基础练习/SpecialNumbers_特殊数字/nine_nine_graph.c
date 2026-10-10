/*
 * 练习：判断输入整数是否满足题目条件。
 * 满足条件的情况是：数字能被 62 整除，或十进制表示中含有相邻的“62”。
 * 输入：一个整数 n；输出：Yes 或 No。
 */
#include<stdio.h>

int main(){
    long long n;
    scanf("%lld",&n);

    /* 能被 62 整除时无需再检查数位。 */
    if (n%62 == 0){
    printf("Yes");
    return 0;
    }
    /* 先统计位数，以便创建保存各数位的变长数组。 */
    int i =0;
    long long demo =n;
  
    while(n !=0){
        n /= 10;
        i++;
    }

    int digit[i];

    int j =0;

    /* 从个位开始逆序保存每一位，便于检查相邻数位。 */
    while(demo !=0){
        digit[j]=demo%10;//逆序存放进最低位
        demo /= 10;
        j++;
    }
    /* 数组按低位到高位排列；相邻的 2、6 对应原数中的“62”。 */
    for (int k=0;k <i -1;k++){
        if (digit[k] ==2 && digit[k+1]==6){

            printf("Yes");
            return 0;
        }
   
}
 printf("No");
    return 0;
}
