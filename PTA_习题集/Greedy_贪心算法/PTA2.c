#include<stdio.h>
int main(){
   
    int type_moon;

    int market;

    double price;

    int i=0;

    int j=0;

    double double_temp;

    double sale=0.0;

    scanf("%d %d",&type_moon,&market);

    double prices_of_moon[type_moon];

    double existing_num[type_moon];

    for(i=0;i<type_moon;i++){
        scanf("%lf",&existing_num[i]);
    }


    for(i=0;i<type_moon;i++){
        scanf("%lf",&price);
        prices_of_moon[i] = price / existing_num[i];
    }

    for(i=0;i<type_moon-1;i++){
        for(j=0;j<type_moon-1-i;j++){
            if(prices_of_moon[j]<prices_of_moon[j+1]){
                double_temp = prices_of_moon[j];
                prices_of_moon[j]=prices_of_moon[j+1];
                prices_of_moon[j+1]=double_temp;

                double_temp = existing_num[j];
                existing_num[j] = existing_num[j+1];
                existing_num[j+1] = double_temp;
            }
        }
    }

    for(i=0;i<type_moon;i++){
        if(market - existing_num[i] > 0){
            market -= existing_num[i];
            sale += existing_num[i]*prices_of_moon[i];
        }else{
            sale += market*prices_of_moon[i];
            break;
        }
    }

    printf("%.2lf",sale);
    
}