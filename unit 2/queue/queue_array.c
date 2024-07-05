#include <stdio.h>
#include <stdlib.h>
#define max 10
int arr[max];
int front=-1,rear=-1;
void enqueue(){
    int d;
    printf("\nEnter data : ");
    scanf("%d",&d);
    if(rear==10-1){
        printf("\nOverFlow");
        return;
    }
    arr[++rear]=d;
    if(front==-1)front++;
}
void dequeue(){
    if(rear==-1){
        printf("\nUnderFlow");
        front=-1;
        return;
    }
    printf("\nDequeued %d ",arr[front]);
    
    for(int i=0;i<rear;i++){
arr[i]=arr[i+1];
    }
    rear--;
}
void frontElem(){
    if(front==-1){
        printf("\nEmpty");
        return;
    }
    printf("\nFront : %d",arr[front]);
}
void display(){
    printf("\nELEMENTES IN QUQUE : ");
    for(int i=0;i<rear+1;i++){
        printf(" %d ",arr[i]);
    }
}
int main(){
    int cho;
    while(1){
     printf("\n1.Enquqe\n2.Dequeue\n3.Front\nEnter your choise:");
        scanf("%d",&cho);
        switch(cho){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            frontElem();
            break;
           
} display();printf("\n Front %d rear %d",front,rear);
    }
}