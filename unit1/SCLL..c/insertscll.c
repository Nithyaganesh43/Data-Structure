#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node node;
node *tail=NULL;
node* create(int data){
    node *nn=(node*)malloc(sizeof(node));
    nn->data=data;
    nn->next=nn;//initialy it points to itself
    return nn;
}

void deleteAtBeg(){
    if(tail==NULL){
        printf("\nEmpty");
        return;
    }
    if(tail==tail->next){
        free(tail);
        tail=NULL;
        return;
        }
    node* temp = tail->next;
    tail->next = tail->next->next;
    free(temp);
}
void deleteAtLast(){
    if(tail==NULL){
        printf("\nEmpty");
        return;
    }
    if(tail==tail->next){
        free(tail);
        tail=NULL;
        return;
        }
    node* temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
   free(tail);
    tail=temp;
}

node* reverse( ) {
    if (tail == NULL || tail->next == tail) return tail;

    node *prev, *curt = (tail)->next, *next = curt->next;
  
    while(curt!=tail){
        prev=curt;
        curt=next;
        next=curt->next;
        curt->next=prev;
    }next->next=tail;//elame same as singly but last step la next null agathu head ku poirum atha
    return next;//use panni head tail ah point panra maari panita matter over
}
void insertAtBeg(int data){
   if(tail==NULL){
    tail=create(data);
    return;
   }
   node *nn=create(data);
   nn->next=tail->next;
   tail->next=nn;
}
void insertAtLast(int data){
     if(tail==NULL){
    tail=create(data);
    return;
   }
   node *nn=create(data);
   nn->next=tail->next;
   tail->next=nn;
   tail=nn;
}
void display(){
    if(tail==NULL){
        printf("\nEmpty");
        return;
    }
    printf("\nElements :");
     node* temp=tail->next;
    while(temp!=tail){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }printf("%d -> ",tail->data);
}
int main(){
    int data,choise;
    while(1){
    printf("\n1.insertAtBeg\n2.insertAtLast\n3.deleteAtBeg\n4.deleteAtLast\n5.reverse\n6.exit\nchoose (1/2/3/4/5/6):");
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
        tail=reverse();
        break;
        case 6:
         exit(0);
        break;
        default: {
            printf("\ncorrect ah choose pannunga");
        }
    }
    display();
    }
}