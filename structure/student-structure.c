#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int age;
    float mark;
} std[2];

int main() {
    for (int i = 0; i < 2; i++) {
        printf("\nEnter student %d name: ", i + 1);
        scanf("%s", std[i].name);
        printf("\nEnter student %d age: ", i + 1);
        scanf("%d", &std[i].age);  
        printf("\nEnter student %d mark: ", i + 1);
        scanf("%f", &std[i].mark);  
    }

    for (int i = 0; i < 2; i++) {
        printf("\nSTUDENT %d\n", i + 1);
        printf("Name: %s\n", std[i].name);
        printf("Age: %d\n", std[i].age);
        printf("Mark: %f\n", std[i].mark);
    }
printf("\nAverage make:%f",(std[0].mark+std[1].mark)/2)
    return 0;
}
