#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *create(int d) {
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = d;
    return nn;
}

void insert_beg(struct node **q, int d) {
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = d;
    if (*q == NULL) {
        (*q) = nn;
    } else {
        nn->next = *q;
        (*q)->prev = nn;
        *q = nn;
    }
}

void insert_last(struct node **q, int d) {
    struct node *nn, *temp = *q;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = d;
    if (*q == NULL) {
        (*q) = nn;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    nn->prev = temp;
    temp->next = nn;
}

void insert_position(struct node **q, int d, int p) {
    struct node *nn, *temp = *q;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    nn->prev = NULL;
    nn->data = d;
    if (*q == NULL) {
        (*q) = nn;
    }
    for (int i = 1; i < p - 1; i++) {
        temp = temp->next;
    }
    nn->next = temp->next;
    nn->prev = temp;
    temp->next = nn;
    temp->next->prev = nn;
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
    struct node* temp=*q;
    if(!temp){
        return;
    }pos-=2;
    while(temp!=NULL && pos--){

        temp=temp->next;
    }
    if(!temp){
        temp=*q;
        while(temp->next->next)temp=temp->next;
        temp->next=NULL;
        return;
    }
    temp->next->next->prev=temp;
    temp->next=temp->next->next;

}

void display(struct node *head) {
    int count=0;
    printf("\nCurrent elements: ");

    struct node *temp = head;
    if(temp == NULL)
        printf("List is empty");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nCount is: %d\n", count);
}

int main() {
    struct node *head = NULL;
    int data, position, choice;

    while (1) {
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at last\n4. Insert at position\n5. Delete at beginning\n6. Delete at end\n7. Delete at position\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to create: ");
                scanf("%d", &data);
                head=create(data);
                display(head);
                break;
            case 2:
                printf("\nEnter data to insert at beginning: ");
                scanf("%d", &data);
                insert_beg(&head, data);
                display(head);
                break;
            case 3:
                printf("\nEnter data to insert at last: ");
                scanf("%d", &data);
                insert_last(&head, data);
                display(head);
                break;
            case 4:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_position(&head, data, position);
                display(head);
                break;
            case 5:
                deletefirst(&head);
                display(head);
                break;
            case 6:
                deleteAtlast(&head);
                display(head);
                break;
            case 7:
                printf("\nEnter position to delete: ");
                scanf("%d", &position);
                deleteAtpos(&head, position);
                display(head);
                break;
            case 8:
                display(head);
                break;
            case 9:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
