#include<stdio.h>
long max(int a,int b,int c){

    int n[3]={a,b,c};

    int max =a;

    for(int i=1;i<=2;i++){
        if (n[i]>max){
            max =n[i];
        }
    }
    return max;
}
long min(int a,int b,int c){

    int n[3]={a,b,c};

    int min =a;

    for(int i=1;i<=2;i++){
        if (n[i]<min){
            min =n[i];
        }
    }
    return min;
}
int main(){

    int n;
    int num_max;
    int i=0,j=0;
    int num[1005];
    int dp_max[1005]={0};
    int dp_min[1005]={0};

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    num_max=dp_max[0]=dp_min[0]=num[0];
    for (i=1;i<n;i++){

    }
    printf("%d",num_max);

}