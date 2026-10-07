#include<stdio.h>

int deliver(int n){
    int sum=0;
    while(n != 0 ){

        sum +=  n%10;

        n /= 10;

    }
    return sum;
}

int main(){

    int n;
    scanf("%d",&n);
    int i =1;
    while(1){
        int next = 3*deliver(n)+1;
        printf("%d:%d\n",i,next);

        if (next == n){
            break;

        }
        n = next;
        i++;
    }
}
