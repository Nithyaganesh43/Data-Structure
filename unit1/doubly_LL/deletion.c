#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

void create(struct node **q, int d) {
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = d;
    (*q) = nn;
}

void deletefirst(struct node **q) {
    if (*q == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *q;
    *q = (*q)->next;
    if (*q != NULL)
        (*q)->prev = NULL;
    printf("%d data is deleted\n", temp->data);
    free(temp);
}

void deleteAtlast(struct node **q) {
    if (*q == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *q;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev == NULL) {
        *q = NULL;
    } else {
        temp->prev->next = NULL;
    }
    printf("%d is deleted\n", temp->data);
    free(temp);
}

void deleteAtpos(struct node **q, int pos) {
    if (*q == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *q;
    struct node *prev = NULL;
    if (pos == 1) {
        deletefirst(q);
        return;
    }
    int count = 1;
    while (temp != NULL && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prev;
    }
    printf("%d is deleted\n", temp->data);
    free(temp);
}

void display(struct node *head) {
    int count=0;
    printf("\nCurrent elements: ");

    struct node *temp = head;
    if(temp == NULL)
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    count++;
    }
    if(temp == NULL)
    {
        count++;
    }
    printf("\ncount is :%d",count);
}

int main() {
    struct node *head = NULL;
    int data, position, choice;

    while (1) {
        printf("\n1. Create\n2. Delete at beginning\n3. Delete at end\n4. Delete at position\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to create: ");
                scanf("%d", &data);
                create(&head, data);
                display(head);
                break;
            case 2:
                deletefirst(&head);
                display(head);
                break;
            case 3:
                deleteAtlast(&head);
                display(head);
                break;
            case 4:
                printf("\nEnter position to delete: ");
                scanf("%d", &position);
                deleteAtpos(&head, position);
                display(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
