#include <stdio.h>
#include <stdlib.h>
struct queue{
    int arr[5];
    int front,rear;
};
struct queue* create(){
struct queue* q=(struct queue*)malloc(sizeof(struct queue));
q->front=q->rear=-1;
return q;
}
void enqueue(struct queue* q,int data){
    if(q->rear==4){
        printf("overflow");
        return;
        }
        if(q->front==-1){
            q->front++;
        }
        q->arr[++(q->rear)]=data;
}
int dequeue(struct queue* q){
        if(q->front==-1 || q->rear<q->front){
            printf("\n underflow");
            return -404;
        }
        int temp=q->arr[0];
        for(int i=1;i<q->rear+1;i++){
            q->arr[i-1]=q->arr[i];
        }
        q->rear--;
        return temp;
}
void display(struct queue* q){
    printf("\n Elements in queue :");
    for(int i=0;i<q->rear+1;i++){
        printf("%d ",q->arr[i]);
    }
}
int main(){
    
        struct queue *q=NULL;
   
            q=create();
            printf("\n New queue created successfully");
            enqueue(q,1);
    display(q);
             enqueue(q,12);
    display(q);
              enqueue(q,13);
    display(q);
               enqueue(q,14);
    display(q);
             enqueue(q,14);
    display(q);
             enqueue(q,14);
    display(q);
            
            printf("\n dequeued %d",dequeue(q));
    display(q);
            printf("\n dequeued %d",dequeue(q));
    display(q);
        
            printf("\n dequeued %d",dequeue(q));
           
        
    display(q);            printf("\n dequeued %d",dequeue(q));
           
        
    display(q);            printf("\n dequeued %d",dequeue(q));
           
        
    display(q);            printf("\n dequeued %d",dequeue(q));
           
        
    display(q);
    
}