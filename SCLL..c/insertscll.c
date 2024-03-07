#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node node;
node *tail=NULL;
void insertAtBeg(int data){
    node *nn;
    nn=(node*)malloc(sizeof(node));
    nn->data=data;
    if(tail==NULL){
        tail=nn;
        nn->next=nn;
    }else
    {
         nn->next=tail->next;
         tail->next=nn;
    }
}
void insertAtLast(int data){
    node *nn;
    nn=(node*)malloc(sizeof(node));
    nn->data=data;
    if(tail==NULL){
        tail=nn;
        nn->next=nn;
    }else
    {
         nn->next=tail->next;
         tail->next=nn;
    }tail=nn;
}
void deleteAtBeg(){
    if(tail->next==tail){
        printf("\nList empty");
        tail=NULL;
    }else{
        node *temp=tail->next;//head
        tail->next=tail->next->next;
        free(temp);
    }
}
void deleteAtLast(){
    if(tail->next==tail){
        printf("\nList empty");
        tail=NULL;
    }else{
    node *temp=tail;
    while(temp->next!=tail){
        temp=temp->next;
    }
    tail=temp;
    if(tail==NULL){
        printf("\nList empty");
    }else{
        node *temp=tail->next;//head
        tail->next=tail->next->next;
        free(temp);
    }
    }
}
void display(){
    if(tail==NULL){
        printf("\nathula onum illaah");
    }else{
        printf("\nelements:");
        node *temp=tail->next;
        while(temp!=tail){
            printf("%d",temp->data);//head
            temp=temp->next;
            
        }printf("%d",temp->data);
        
    }
}
int main(){
    int data,choise;
    while(1){
    printf("\n1.insertAtBeg\n2.insertAtLast\n3.deleteAtBeg\n4.deleteAtLast\n5.exit\nchoose (1/2/3/4/5):");
    scanf("%d",&choise);
    switch(choise){
        case 1 ...2:
        printf("\nenter data:");
        scanf("%d",&data);
    }
    switch(choise){
        case 1:
        insertAtBeg(data);
        break;
        case 2:
        insertAtLast(data);
        break;
        case 3:
        deleteAtBeg();
        break;
        case 4:
         deleteAtLast();
        break;
        case 5:
         exit(0);
        break;
        default: {
            printf("\ncorrect ah choose pannunga");
        }
    }
    display();
    }
}