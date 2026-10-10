#include<stdio.h>
long long fact(int n){
    long long result = 1;
    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int n;
    long long sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum += fact(i);
    }
    printf("%lld\n",sum);
    return 0;
}
