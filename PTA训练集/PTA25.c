#include<stdio.h>
int main(){
    int n;
    typedef struct 
    {
        int a;
        int b;
        int c;
        int d;
        int e;
    }scores;

    scores num = {0};

    scanf("%d",&n);
    int score[n];
    for(int i=0;i<n;i++){
        scanf("%d",&score[i]);
            if (score[i]>=90){
               num.a++;
            }else if (score[i]>=80){
               num.b++;
            }else if (score[i]>=70){
               num.c++;
            }else if (score[i]>=60){
               num.d++;
            }else{
               num.e++;
            }
    }
    printf("%d %d %d %d %d",num.a,num.b,num.c,num.d,num.e);

    
}