/*
 * 阶梯电价计算练习。
 * 输入起始与结束电表读数，按各用电区间对应的阶梯费率计算本段费用。
 * 费率：0–2760 为 0.52，2760–4800 为 0.57，超过 4800 为 0.82。
 * 读数非法或用电量非正时输出 ERROR。
 */
#include<stdio.h>

int main(){
    /* u、v 分别是本次用电的起始和结束读数；d_2 是用电量。 */
    int u,v,d_2 ,type = 0;

    /* 两个阶梯分界点和各档单价。 */
    const int latter_1 = 2760;

    const int latter_2 = 4800;

    const double price_in_latter_1 = 0.52;

    const double price_in_latter_2 = 0.57;

    const double price_in_latter_3 = 0.82;

    double price = 0.0;

    scanf("%d %d",&u ,&v);

    d_2 = v - u  ;

    /* 结束读数必须大于起始读数。 */
    if (d_2<=0){
        printf("ERROR");
        return 0;
    }
    /* 根据起始读数确定本段用电从哪一档开始计费。 */
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
    /* 若本段跨过档位边界，将每一档的用电量分别计价后相加。 */
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
