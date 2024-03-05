#include<stdio.h>

struct Car {
    char car_id[50];
    char model[20];
    float rent;
} car[3];

int main() {
    int num_days;
    float total_cost = 0;

    for (int i = 0; i < 3; i++) {
        printf("\nEnter car %d ID: ", i + 1);
        scanf("%s", car[i].car_id);
        printf("\nEnter car %d model: ", i + 1);
        scanf("%s", car[i].model);
        printf("\nEnter car %d rent per day: ", i + 1);
        scanf("%f", &car[i].rent);
    }

    printf("\nEnter the number of days: ");
    scanf("%d", &num_days);

    for (int i = 0; i < 3; i++) {
        total_cost += car[i].rent * num_days;
    }

    printf("\nTotal rental cost for %d days: %.2f\n", num_days, total_cost);

    return 0;
}
