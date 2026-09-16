#include<stdio.h>
int main(){
    long long n;
    scanf("%lld",&n);
    if (n%62 == 0){
    printf("Yes");
    return 0;
    }
    int i =0;
    long long demo =n;
  
    while(n !=0){
        n /= 10;
        i++;
    }

    int digit[i];

    int j =0;

    while(demo !=0){
        digit[j]=demo%10;//逆序存放进最低位
        demo /= 10;
        j++;
    }
    for (int k=0;k <i -1;k++){
        if (digit[k] ==2 && digit[k+1]==6){

            printf("Yes");
            return 0;
        }
   
}
 printf("No");
    return 0;
}
