#include<stdio.h>
#include<math.h>
long fact(int n){
    long result = 1;
    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    if (m>n){
        return 0;
    }
    printf("result = %ld\n",fact(n)/(fact(m)*fact(n-m)));

}
