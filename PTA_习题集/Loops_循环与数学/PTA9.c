#include<stdio.h>
int main(){

    int n;
    double sum = 0.0;
    double n0 = 1.0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        sum += 1.0/n0;
        n0 += 2.0;
    }
    printf("sum = %.6lf\n",sum);
    return 0;

}
