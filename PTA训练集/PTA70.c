#include<stdio.h>
int main(){
    int n;
    int found =0;
    scanf("%d",&n);
    for(int i=0;i<100;i++){
        int value = 98*i - n;

        if (value >=0 && value%199 == 0){
             int y = value / 199;
             printf("%d.%d\n", y, i);
             found = 1;
             break;
        }
    }
    if (!found){
        printf("No Solution");
    }
}