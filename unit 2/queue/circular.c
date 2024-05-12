#include<stdio.h>
#define size 6
int queue[size],front=-1,rear=-1;
void enqueue(int num){
    //overflow
    if((rear+1)%size==front){
        printf("\nOver flow");
        return;
    }
    if(front==-1){
        front++;
        rear++;
        queue[rear]=num;
        return;
    }
    rear=(rear+1)%size;
    queue[rear]=num;
}
int dequeue(){
    if(front==-1){
        printf("\nUnder flow");
        return -10000000;
    }
    int num=queue[front];
    if(front ==  rear){
        front = rear = -1;
        return num;
    }
    front=(front+1)%size;
    return num;
}
void print(){
    if(front==-1){
        printf("\nempty:");
        return;
    }
    printf("\nElements :");
int i;
    for(i=front;i!=rear;i=(i+1)%size){
        printf("%d ",queue[i]);
    }
    printf("%d ",queue[i]);
}

int main(){
    while(1){
     printf("\nChoose :\n1.enqueue\n2.dequeue\n");
    int num;
        int val;
    scanf("%d",&num);   
    switch(num){
        case 1:
        printf("\nenter val:");
        scanf("%d",&val);
        enqueue(val);
        break;
        case 2:
        printf("\nDequeued element: %d",dequeue());
        break;
   }print();
    }
    

}