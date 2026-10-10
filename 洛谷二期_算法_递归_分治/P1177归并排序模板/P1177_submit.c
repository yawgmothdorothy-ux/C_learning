#include<stdio.h>
#include<stdlib.h>

void merge_sort(int arr[],int temp[],int left,int right){


    if(left>=right){
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(arr,temp,left,mid);

    merge_sort(arr,temp,mid+1,right);

    int i = left;
    int j = mid +1;
    int k = left;


    while(i <= mid && j<= right){

        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
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
