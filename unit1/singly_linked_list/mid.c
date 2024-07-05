#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node;
node* create(int d){
    node* nn=(node*)malloc(sizeof(node));
    nn->data=d;
    nn->next=NULL;
    return nn;
}
void mid(node *head){
    node* temp=head;
    int count=0;
    while(temp){
        temp=temp->next;
        count++;
    }
    if(count%2==0){
        count=count/2-1;
    }else{
        count=count/2;
    }temp=head;
    while(count--){
temp=temp->next;
    }
    printf("\n Middle element is : %d",temp->data);
}
void display(node* head){
    printf("\nelements: ");
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int cho,data;
    while(1){
        printf("1.insert\n2.mid call\n:");
        
    }
node* head=create(1);
head->next=create(2);
head->next->next=create(3);

mid(head);
head->next->next->next=create(4);

mid(head);
head->next->next->next->next=create(5);

mid(head);
display(head);
}