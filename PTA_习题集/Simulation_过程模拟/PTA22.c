#include<stdio.h>
int main(){
    typedef struct 
    {
        double apple;
        double pear;
        double orange;
        double grape;
    }fruit;

    int choice;

    int count =0;

    fruit price ={3.00,2.50,4.10,10.20};

    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");  

    while (scanf("%d",&choice) == 1 ){
        if (choice == 0 || count >= 5){
            break;
        }else if (choice == 1){
            printf("price = %.2lf\n", price.apple);
            count ++;
        }else if (choice == 2) {

            printf("price = %.2lf\n", price.pear);
            count ++;         


        }else if (choice == 3){

            printf("price = %.2lf\n", price.orange);
            count ++;
            

        }else if (choice == 4){

            printf("price = %.2lf\n", price.grape);
            count ++;
        }else{
            printf("price = 0.00\n");
            count ++;
        }
    }

}
