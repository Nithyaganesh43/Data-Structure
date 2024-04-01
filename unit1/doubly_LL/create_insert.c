#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

void create(struct node **q, int d) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    nn->prev = NULL;
    *q = nn;
}

void insert_beg(struct node **q, int d) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = *q;
    nn->prev = NULL;
    if (*q != NULL) {
        (*q)->prev = nn;
    }
    *q = nn;
}

void insert_last(struct node **q, int d) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    if (*q == NULL) {
        nn->prev = NULL;
        *q = nn;
        return;
    }
    struct node *temp = *q;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
    nn->prev = temp;
}

void insert_position(struct node **q, int d, int p) {
    if (p <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (p == 1) {
        insert_beg(q, d);
        return;
    }
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    struct node *temp = *q;
    int pos = 1;
    while (temp != NULL && pos < p - 1) {
        temp = temp->next;
        pos++;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the list. Inserting at the end.\n");
        insert_last(q, d);
    } else {
        nn->next = temp->next;
        nn->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = nn;
        }
        temp->next = nn;
    }
}

void display(struct node *head) {
    printf("Current elements: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int data, choice, position;

    while (1) {
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at last\n4. Insert at position\nEnter your choice (1/2/3/4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to create: ");
                scanf("%d", &data);
                create(&head, data);
                display(head);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insert_beg(&head, data);
                display(head);
                break;
            case 3:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insert_last(&head, data);
                display(head);
                break;
            case 4:
                printf("Enter data to insert at position: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_position(&head, data, position);
                display(head);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
