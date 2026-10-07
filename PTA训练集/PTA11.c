#include<stdio.h>

int main(){
    int n;
    int an=1;
    double sum = 0.0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){

        if (i%2 == 0){
            an = -(1+3*(i-1));
        }else{
            an = 1+3*(i-1);
        }
        sum += 1.0/an;
    }    
    printf("sum = %.3lf\n",sum);

}