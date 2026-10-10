#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include <stdio.h>

int all_digits_same(int number)
{
    char str[32];

    // 把数字转换成字符串，存入 str
    snprintf(str, sizeof(str), "%d", number);

    // 从第二个字符开始，逐个与第一个字符比较
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] != str[0]) {
            return 0;
        }
    }

    return 1;
}

int main(){
    typedef struct{
        int k_63;
        int k_sprt;
        int k_same;
    }k_num;

    typedef struct{
        int answer_1;
        int answer_2;
        int answer_3;
    }answers;

    answers the_answers = {0,0,0};

    k_num the_k = {0,0,0};

    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);

    for(int i=a;i<=b;i++){

        if(i%63 == 0){

            the_k.k_63++;

            if(the_k.k_63 == k){

                the_answers.answer_1 = i;
                break;
            }
        }        
    }



    for(int i=a;i<=b;i++){

        double sprt_num = sqrt(i);

        if(sprt_num - (int)sprt_num == 0.0){

            the_k.k_sprt++;

        }
        if (the_k.k_sprt == k){

            the_answers.answer_2 = i;
            
            break;
        }
    }

    for(int i=a;i<=b;i++){
        if(all_digits_same(i)){

            the_k.k_same++;

        }
        if (the_k.k_same == k){

            the_answers.answer_3 = i;
            break;
        }
    }
    printf("%d %d %d\n",the_answers.answer_1,the_answers.answer_2,the_answers.answer_3);

}