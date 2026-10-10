#include<stdio.h>
int main(){
    int end;

    int count = 0;

    scanf("%d",&end);
    if (end<=2000 || end >3000){
        printf("Invalid year!");
        return 0;
    }
    for (int i=2001;i<=end ;i++){

        if ((i%4 == 0 && i%100 != 0) || (i%400 == 0)){

            count ++;
            printf("%d\n",i);

        }

    }
    if (count==0){
        printf("None");
    }
}
