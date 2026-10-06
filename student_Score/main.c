#include<stdio.h>
#include<stdlib.h>

int main(void){

    typedef struct{
        long long total;
        int highest;
        int highest_index;
    } StudentScore;

    int count;
    scanf("%d",&count);

    int *scores = malloc(count*sizeof(int));

    for(int i=0;i<count;i++){
       if( scanf("%d",&scores[i]) != 1){
            printf("第%d个元素输入错误\n", i + 1);
            free(scores);
            return 1;
        }
    }

    StudentScore result = {0};

    result.highest = scores[0];
    result.highest_index = 1;
    result.total = scores[0];



    for(int i=1;i<count;i++){
        result.total += scores[i];
        if(scores[i] > result.highest){
            result.highest = scores[i];
            result.highest_index = i+1;
        }
    }

    printf("总分：%lld\n",result.total);
    printf("最高分：%d\n",result.highest);
    printf("第一个最高分的学生编号：%d\n",result.highest_index);
    
    free(scores);
    return 0;
}