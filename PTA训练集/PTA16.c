#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);

    double sum =0.0;

    for(int i=1;i<=n;i++){
        sum += sqrt(i);
    }

    printf("sum = %.2lf\n",sum);

}