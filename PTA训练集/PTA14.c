#include<stdio.h>
int main(){
    int n;
    double cost =0.0;
    scanf("%d",&n);
    if (n<0){
        printf("Invalid Value!\n");
        return 0;
    }else if(n<50){
        cost = n * 0.53;
        printf("cost = %.2lf\n",cost);
    }else{
        cost = (n-50)*0.58+50*0.53;
        printf("cost = %.2lf\n",cost);
    }
    return 0;
    
}
