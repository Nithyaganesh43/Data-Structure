#include<stdio.h>

void remdup(int *arr, int *arrnd, int n,int *nnd) {
    int indx = 0;
    *nnd=0;
    for (int i = 0; i < n; i++) {
        
        if (i == 0 || arr[i] != arr[i - 1]) {
            arrnd[indx++] = arr[i];
            (*nnd)++;
        }}
        
        }
int main(){
    int n,nnd,total=0;
    printf("enter the no of array:");
    scanf("%d",&n);
    int arr[n],arrnd[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
remdup(arr,arrnd,n,&nnd);
int val[nnd];
for(int i=0;i<nnd;i++){
    val[i]=0;
}
for(int i=0;i<nnd;i++){
    for(int j=0;j<n;j++){
        if(arr[j]==arrnd[i]){
            val[i]++;
        }
    }
}
for(int i=0;i<nnd;i++){
    if(val[i]>1){
total++;
    }
}
        printf("number of numbers having duplicates %d",total);
    }
