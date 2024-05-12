#include <stdio.h>

int main() {
    int input, i, j, count = 1;
int lineloop=0;
    printf("Enter the number: ");
    scanf("%d", &input);

    for (i = 1; count <= input; i++) {
        for (j = 1; j <= i && count <= input; j++) {
            printf("%d ", count++);
        }
        printf("\n");
        lineloop++;
    }
printf("%d",lineloop);
    return 0;
}
