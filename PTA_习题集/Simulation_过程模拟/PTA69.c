#include<stdio.h>
int main(){
    int n,u,d;
    scanf("%d %d %d",&n ,&u,&d);

    int height=0;
    int time =0;

    while(1){

        height += u;
        time ++;
        if (height>=n){
            break;
        }

        height -= d;
        time ++;

    }

printf("%d",time);
}