#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int data[MAX_SIZE];

int front = -1, rear = -1;

void enqueue(int item) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    data[rear] = item;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = data[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    return item;
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i != (rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE) {
        printf("%d ", data[i]);
    }
    printf("\n");
}


int main() {
    int choice, item;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Dequeued element: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
