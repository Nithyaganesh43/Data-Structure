#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
void create(struct node **q,int d){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->next=NULL;
    nn->prev=NULL;
    nn->data=d;
    (*q)=nn;
}
void insert_beg(struct node **q,int d){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->next=NULL;
    nn->prev=NULL;
    nn->data=d;
    if(*q==NULL){
    (*q)=nn;
    }
    else{
        nn->next=*q;
        (*q)->prev=nn;
        *q=nn;
    }
}
void insert_last(struct node **q,int d){
   struct node *nn,*temp=*q;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->next=NULL;
    nn->prev=NULL;
    nn->data=d;
    if(*q==NULL){
    (*q)=nn;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    nn->prev=temp;
    temp->next=nn;
}
void insert_position(struct node **q,int d,int p){
   struct node *nn,*temp=*q;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->next=NULL;
    nn->prev=NULL;
    nn->data=d;
    if(*q==NULL){
    (*q)=nn;
    }
    for(int i=1;i<p-1;i++){
        temp=temp->next;
    }
    nn->next=temp->next;
    nn->prev=temp;
    temp->next=nn;
    temp->next->prev=nn;
}
void display(struct node *head){
     printf("\ncurrent elements:");
    struct node *temp=head;
while(temp!=NULL){
printf("%d",temp->data);
temp=temp->next;
}
}
int main(){
    struct node *head=NULL;
    int data,position;
    
    
    for(int i=0;i>-1;i++){int s=0;
        printf("\n1.create\n2.insert at beg\n3.insert at last\n4.insert at position\nenter your choise (1/2/3/4)");
    scanf("%d",&s);
    switch(s){
        
        case 1:
            printf("\nenter data to create:");
            scanf("%d",&data);
            create(&head,data);
            display(head);
    break;
        case 2:
             printf("\nenter data to insert at beg:");
              scanf("%d",&data);
              insert_beg(&head,data);
              display(head);
    break;
              case 3:
              printf("\nenter data to insert at last:");
    scanf("%d",&data);
    insert_last(&head,data);
    display(head);
    break; 
    case 4:
    printf("\nenter data to insert at position:");
    scanf("%d",&data);
    printf("\nenter  position:");
    scanf("%d",&position);
    insert_position(&head,data,position);
    display(head);
    break;

    }
    
}}