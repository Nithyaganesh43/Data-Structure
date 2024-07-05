#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
};
typedef struct node node;
node* tail=NULL;

node* create(int d){
    node *nn=(node*)malloc(sizeof(node));
    nn->data=d;
    nn->next=nn->prev=nn;
    return nn;
}

void insert_beg(int d){
    if(tail==NULL){
        tail=create(d);
    }else{
        node *nn=create(d);
        nn->next=tail->next;
        nn->prev=tail;
        tail->next=nn;
        nn->next->prev=nn;
    }
}
void insert_last(int d){
     if(tail==NULL){
        tail=create(d);
    }else{
        node *nn=create(d);
        nn->next=tail->next;
        nn->prev=tail;
        tail->next=nn;
        nn->next->prev=nn;
        tail=nn;
    }
}
void deletefirst(){
    if(tail==NULL){
        printf("\n Nothing simply waste");
    }else{
        node* temp=tail->next;
        tail->next=temp->next;
        tail->next->prev=tail;
        free(temp);
    }
}
void deleteend(){
    if(tail==NULL){
        printf("\n Nothing simply waste");
    }else{
        node* temp=tail;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        tail=temp->prev;
        free(temp);

    }
}
void reverse(){
    if(tail==NULL || tail->next==tail){
        return;
    }else{
        node *curt=tail->next;
        while(curt!=tail){
            node *temp=curt->prev;
            curt->prev=curt->next;
            curt->next=temp;
            curt=curt->prev;
        }
        node *temp=curt->next;
        curt->next=curt->prev;
        curt->prev=temp;
        tail=temp;
    }
}
void display(){
    if(tail==NULL){
        printf("\nAthula onum ila");
    }else{
        node* temp=tail->next;
        printf("\nElements : ");
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
}
int main(){
    insert_beg(1);
    insert_beg(2);
    insert_beg(3);
    insert_beg(13);
    insert_beg(59);
    display();
    insert_last(4);
    display();
    deletefirst();
    display();
    deleteend();
    display();
    reverse();
    display();
}