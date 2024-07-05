#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} node;

node *tail = NULL; // Global declaration of tail pointer

void create(int d) {
    node *nn;
    nn = (node*)malloc(sizeof(node));
    nn->data = d;
    nn->next = nn; // Pointing to itself
    nn->prev = nn; // Pointing to itself
    tail = nn;
}

void insert_beg(int d) {
    if (tail == NULL) {
        create(d);
        return;
    }
    node *nn = (node*)malloc(sizeof(node));
    nn->data = d;
    nn->next = tail->next;
    tail->next = nn;
    nn->prev = tail;
    nn->next->prev = nn;
}

void insert_last(int d) {
    if (tail == NULL) {
        create(d);
        return;
    }
    node *nn;
    nn = (node*)malloc(sizeof(node));
    nn->data = d;
    nn->next=tail->next;
    nn->prev=tail;
    tail->next->prev=nn;
    tail->next=nn;
    tail=nn;
}

void insert_position(int d, int p) {
    if (tail == NULL || p <= 1) {
        insert_beg(d);
        return;
    }
    node *nn, *temp = tail->next;
    nn = (node*)malloc(sizeof(node));
    nn->data = d;
    for (int i = 0; i < p - 2 && temp != tail; i++) {
        temp = temp->next;
    }
    nn->next = temp->next;
    nn->prev = temp;
    temp->next->prev = nn;
    temp->next = nn;
    if (temp == tail) // Update tail if inserted at the last position
        tail = nn;
}

void deletefirst() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    if (tail == tail->next) {
          tail = NULL;
          return;
    }
    // If only one node in the list
      
    node *temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = tail;
    
    printf("%d data is deleted\n", temp->data);
    free(temp);
}

void deleteAtlast() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    if (tail == tail->next) {
          tail = NULL;
          return;
    }
    node *temp=tail;
    tail->next->prev=tail->prev;
    tail->prev->next=tail->next;
    tail=tail->prev;
    free(temp);
}

void deleteAtpos(int pos) {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    if (tail == tail->next ) {
          tail = NULL;
          return;
    }
    if(pos==1){
        deletefirst();
        return;
    }
    node *temp=tail->next;
    pos-=2;
    while(temp!=tail && pos>0){
        temp=temp->next;
    }
    if(temp==tail){
        deleteAtlast();
        return;
    }
    temp=temp->next;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
}

void reverse() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    node *current = tail->next;
    node *temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != tail->next);
    tail = temp->prev;
}

void display() {
    int count=0;
    printf("\nCurrent elements: ");

    if(tail == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != tail->next);
    printf("\nCount is: %d\n", count);
}

int main() {
    int data, position, choice;

    while (1) {
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at last\n4. Insert at position\n5. Delete at beginning\n6. Delete at end\n7. Delete at position\n8. Reverse\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to create: ");
                scanf("%d", &data);
                create(data);
                display();
                break;
            case 2:
                printf("\nEnter data to insert at beginning: ");
                scanf("%d", &data);
                insert_beg(data);
                display();
                break;
            case 3:
                printf("\nEnter data to insert at last: ");
                scanf("%d", &data);
                insert_last(data);
                display();
                break;
            case 4:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_position(data, position);
                display();
                break;
            case 5:
                deletefirst();
                display();
                break;
            case 6:
                deleteAtlast();
                display();
                break;
            case 7:
                printf("\nEnter position to delete: ");
                scanf("%d", &position);
                deleteAtpos(position);
                display();
                break;
            case 8:
                reverse();
                printf("List reversed\n");
                display();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
