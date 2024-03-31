#include<stdio.h>
int main(){
    int n;
    printf("enter the no of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\nEnter the %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    int narr[n];
    for(int i=0;i<n;i++){
    narr[i]=arr[i];
    }printf("\n the elements new array:");
     for(int i=0;i<n;i++){
        printf("%d",narr[i]);
        return ;
    }
}  