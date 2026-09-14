#include<stdio.h>
int main(){
    int u,v,d_2 ,type = 0;

    const int latter_1 = 2760;

    const int latter_2 = 4800;

    const double price_in_latter_1 = 0.52;

    const double price_in_latter_2 = 0.57;

    const double price_in_latter_3 = 0.82;

    double price = 0.0;

    scanf("%d %d",&u ,&v);

    d_2 = v - u  ;

    if (d_2<=0){
        printf("ERROR");
        return 0;
    }
    if (0 <= u && u<=latter_1){
        type = 0;
    }else if (u > latter_1 && u <= latter_2){
        type = 1;
    }else if (u > latter_2){
        type = 2;
    }else{
        printf("ERROR");
        return 0;
    }
    switch(type){
        case 0:
        if (0 < v && v <= latter_1){
            price =  d_2 * price_in_latter_1;
            printf("%.2lf",price);
        }else if (latter_1 < v  && v <= latter_2){
            price = (latter_1 - u )*price_in_latter_1 + ( v - latter_1)*price_in_latter_2;
            printf("%.2lf",price);
        }else if (latter_2 < v){
            price = (latter_1 - u )*price_in_latter_1 + (latter_2 - latter_1)*price_in_latter_2 + (v -latter_2)*price_in_latter_3;
            printf("%.2lf",price);
        }else{
            printf("ERROR");
        }
        break;

        case 1:
        if (v <= latter_2){
            price = d_2 * price_in_latter_2;
            printf("%.2lf",price);
        }else if (v > latter_2){
            price = (latter_2 - u )*price_in_latter_2 + (v - latter_2)* price_in_latter_3;
            printf("%.2lf",price);
        }else {
            printf("ERROR");
        }
        break;

        case 2:
        price = d_2 * price_in_latter_3;
        printf("%.2lf",price);

    }

return 0;
}
