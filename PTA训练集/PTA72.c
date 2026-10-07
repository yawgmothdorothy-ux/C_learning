#include<stdio.h>
int main(){
    int n;
    int found=0;
    scanf("%d",&n);
    for(int x = 1; 2 * x * x <= n; x++){
        int value = n - x * x;
        for(int y = x; y * y <= value; y++){
            if (y * y == value){
                printf("%d %d\n", x, y);

                found =1;

            }
        }
    }
    if (!found){
        printf("No Solution\n");
    }
    return 0;
}
