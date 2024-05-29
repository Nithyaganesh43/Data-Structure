#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node *front=NULL,*rear=NULL;
void enqueue(int data){
    node *nn=(node*)malloc(sizeof(node));
    nn->data=data;
    nn->next=NULL;
    if(front==NULL){
        front=rear=nn;
        return;
    }
    rear->next=nn;
    rear=nn;
}
int dequeue(){
    if(front==NULL){
        return -1000;
    }
    int temp=front->data;
    front=front->next;
    return temp;
}
void display(){
    if(front==NULL){
        printf("The contents of the queue are  {}\n");
        return;
    }
    printf("The contents of the queue are ");
    node *temp=front;
    while(temp!=rear){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
}
int main(){    
     printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\nEnter your choice\n");

    static char t;
    scanf("%c",&t);
    if(t=='1'){
   goto c1;
    }
    else if(t=='2'){
        goto c2;
    }
    else if(t=='3'){
        goto c3;
    }
    else if(t=='T'){
        goto c;
    }

    int cho,data;
    while(1){
       
        printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\nEnter your choice\n");
         c:
         scanf("%d",&cho);
        switch(cho){
            case 1:
            c1:
            printf("Enter the element to be inserted/entered\n");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            c2:
            data=dequeue();
            if(data==-1000){
                printf("Queue is empty\n");
                break;
            }
            printf("\nThe deleted element is %d\n",data);
            break;
            case 3:
            c3:
            display();
            break;
            default: {
                exit(0);
            }
        }
    }
}