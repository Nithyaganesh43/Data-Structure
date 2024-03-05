#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a;
    int n;    int d;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
            int val=0;
        scanf("%d",&val);
        for(int j=n-1;j>0;j--){
            *(a+j)=*(a+j-1);
        }
        *a=val;

    }
    printf("Elements entered:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", *(a + i));
    }
    printf("\nenter the no. elements you need to delete for frist:");
    scanf("%d",&d);
    for(int i=0;i<d;i++){
     for(int j=0;j<n;j++){
            *(a+j-1)=*(a+j);

             }}
             printf("Elements after delete:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", *(a + i));
    }
    free(a);
    return 0;
}
