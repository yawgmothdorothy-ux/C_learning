/* 原来的冒泡排序代码保留在这里，注释内的代码不参与编译。
#include<stdio.h>
int main(){
    int n;
  
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
*/

#include <stdio.h>
#include <stdlib.h>

// 对 arr[left..right] 进行归并排序，左右边界都包含在内。
// temp 是临时数组，所有递归调用共用它，避免反复申请内存。
void merge_sort(int arr[], int temp[], int left, int right) {
    // 递归结束条件：区间只有一个元素或没有元素时，已经有序。
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // 分治：先分别排好左半部分和右半部分。
    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    // 合并：i、j 分别指向两部分尚未取出的第一个元素。
    // k 指向临时数组中下一个要写入的位置。
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        // 每次取较小的元素，保证合并结果从小到大排列。
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 一边取完后，将另一边剩余的元素依次复制过去。
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将当前区间的合并结果写回原数组，供上一层递归使用。
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // 在堆上申请数组，大量数据时避免局部数组占用过多栈空间。
    int *arr = malloc((size_t)n * sizeof *arr);
    int *temp = malloc((size_t)n * sizeof *temp);
    if (arr == NULL || temp == NULL) {
        free(arr);
        free(temp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(temp);
            return 1;
        }
    }

    // 数组下标从 0 开始，最后一个元素的下标是 n - 1。
    // 时间复杂度 O(n log n)，额外空间复杂度 O(n)。
    merge_sort(arr, temp, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
    }

    // 释放动态申请的内存。
    free(arr);
    free(temp);
    return 0;
}
