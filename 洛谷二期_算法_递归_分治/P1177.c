#include<stdio.h>
#include<stdlib.h>

void merge_sort(int arr[],int temp[],int left,int right){
//传入原始数组arr,临时分配数组temp
    
    if(left>=right){
        return;//数组分治结束
    }

    int mid = left + (right - left) / 2;
    //找到分治的中间点
    merge_sort(arr,temp,left,mid);
    //分治的左半边
    merge_sort(arr,temp,mid+1,right);
    //分治的右半边
    int i = left;//总数组的元素标志
    int j = mid +1;
    int k = left;//左边数组的元素标志
    //归并的前置工作

    while(i <= mid && j<= right){//确定边界条件，防止越位

        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];//当左边的数组元素比右边小的时候，把这个元素存储回临时数组
        }else{
            temp[k++] = arr[j++];//当右边更小时存入右边的元素,存储元素并且递增递归
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(int p=left;p<=right;p++){
        arr[p]=temp[p];
    }
}
int main(void){
    int n;
    if (scanf("%d",&n) != 1 || n <= 0) {
        return 0;
    }

    int *arr = malloc((size_t)n * sizeof*arr);
    int *temp = malloc((size_t)n * sizeof*temp);
    if (arr == NULL || temp == NULL){
        free(arr);
        free(temp);
        return 1;
    }

    for(int i=0;i<n;i++){
        if (scanf("%d",&arr[i]) != 1){
            free(arr);
            free(temp);
            return 1;
        }
    }

    merge_sort(arr,temp,0,n-1);

    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    free(arr);
    free(temp);
    return 0;
}

