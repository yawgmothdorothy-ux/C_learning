#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    if (n-m<0){
        return 0;
    }

    double sum = 0.0;

    for(int i=m;i<=n;i++){

        sum += i*i + 1.0/i;
        
    }
    printf("sum = %.6lf",sum);
}