#include<stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    float salary;
} employees[3];

int main() {
    float max_salary = 0;
    int max_salary_index = 0;

    for (int i = 0; i < 3; i++) {
        printf("\nEnter Employee %d ID: ", i + 1);
        scanf("%d", &employees[i].emp_id);
        printf("Enter Employee %d Name: ", i + 1);
        scanf("%s", employees[i].name);
        printf("Enter Employee %d Salary: ", i + 1);
        scanf("%f", &employees[i].salary);

        if (employees[i].salary > max_salary) {
            max_salary = employees[i].salary;
            max_salary_index = i;
        }
    }

    printf("\nEmployee with highest salary:\n");
    printf("ID: %d\n", employees[max_salary_index].emp_id);
    printf("Name: %s\n", employees[max_salary_index].name);
    printf("Salary: %.2f\n", employees[max_salary_index].salary);

    return 0;
}
