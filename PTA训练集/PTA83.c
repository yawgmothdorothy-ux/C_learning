#include<stdio.h>
int main(){
    int n;

    scanf("%d",&n);

int count =0;
    for(int i = 1;i<=30;i++){
         int remaining = 150;
        for(int j = 1;j<=143;j++){
            int remaining =150;
            remaining -= j + 5*i;
            if (remaining%2 == 0 && count < n && remaining/2>0 && j+i+remaining/2 == 100){
                printf("%d %d %d\n",i,remaining/2,j);
                count ++;
            }
        }
    }  
}