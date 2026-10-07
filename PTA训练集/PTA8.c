#include<stdio.h>

int main(){

    int lower ;
    int upper ;

    double c = 0.0;
    scanf("%d %d",&lower,&upper);

    if (lower>upper || lower<0 || upper>100){
        printf("Invalid.\n");
        return 0;
    }

    printf("fahr celsius\n");

    for(int i = lower;i<= upper ;i += 2){

        c = 5*(i-32)/9.0;

        printf("%d%6.1lf\n",i,c);

    }
    return 0;

}
