#include<stdio.h>
int main(void){
    int i =0;
    int arr[100];

    while(1){
        scanf("%d",&arr[i]);
        if(arr[i] == 0){
            break;
        }else{
            i++;
        }
    }

    for(int j = 1;j<=i;j++){
        printf("%d ",arr[i-j]);
    }
}