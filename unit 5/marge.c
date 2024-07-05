#include <stdio.h>

void merge(int arr[],int left,int mid,int right) {
    int n=right-left+1;
    int sortedArr[n];//temp array
//i for left array j for right array k for temp array
    int i=left,j=mid+1,k=0;
//abdul bari valga !
    while (i<=mid && j<=right) {
        if (arr[i]<=arr[j]) {
            sortedArr[k++]=arr[i++];
        } else {
            sortedArr[k++]=arr[j++];
        }
    }
    //ithula eatho onu matum run agaum ilana eathuvum run agamalum poirum
    while(i<=mid){
        sortedArr[k++]=arr[i++];
    }
    while(j <= right){
        sortedArr[k++]=arr[j++];
    }
    //copy ing temp to org array
    for (i=0;i<n;i++) {
        arr[left+i]=sortedArr[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, arrSize - 1);

    printf("Sorted array: \n");
    printArray(arr, arrSize);

    return 0;
}
