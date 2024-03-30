#include <stdlib.h>
#include <stdio.h>
int i=0;
struct node {
  int data;
  struct node *next;
};
void display(struct node *head) {
    printf("\nCurrent elements: ");
    struct node *temp = head;
    if(head=NULL){
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *create_node(int data) {
  struct node *nn = (struct node *)malloc(sizeof(struct node));
  nn->data = data;
  nn->next = NULL;
  return nn;
}
int append_start(struct node **headAddress, int data) {
  struct node *nn = create_node(data);
  if (*headAddress == NULL) {
    *headAddress = nn;
  } else {
    nn->next=*headAddress;

    *headAddress = nn;
  }
  return 0;

}
int append_end(struct node **headAddress, int data) {
  struct node *nn = create_node(data);
    struct node *temp = *headAddress;
  if (*headAddress == NULL) {
    *headAddress = nn;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nn;
     
  return 0;
  }
}int append_position(struct node **headAddress, int data,int pos) {
  struct node *nn = create_node(data);
  struct node *temp = *headAddress;
  if (*headAddress == NULL) {
    *headAddress = nn;
  } else {
    for(int i=1;i<pos-1;i++) {
      temp = temp->next;
    }
    nn->next=temp->next;
    temp->next = nn;
  }
  return 0;
}void delete_beg(struct node **head) {
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);

}
void delete_last(struct node **head){
     struct node *temp = *head;
     if(temp->next==NULL){
      
        *head=NULL;
     }
     else{
      while(temp->next->next!=NULL){
        temp=temp->next;
      }
      temp->next=NULL;}
      free(temp->next);
    
}
void delete_pos(struct node **head,int pos){
    struct node *temp=*head,*temp2;
    if(pos==1){
        delete_beg(head);
        return 0;
    }
     else{
     for(int i=1;i<pos-1;i++) {
      temp = temp->next;
    }
    temp2=temp->next;
    temp->next=temp->next->next;
    
    free(temp2);

}}

int main()
{ int data,pos;
  struct node *head = NULL;
  int n;
  while(1){
     
      printf("1.starting\n2.end\n3.insert at position\n4.deleting at beg\n5.delete at last\ndelete at position\nwhat you want(1/2/3/4/5/6):");
      int option;
      scanf("%d",&option);
    switch(option){
        case 1:
      printf("\nEnter the data for node :");
      scanf("%d",&data);
        append_start(&head,data);
        break;
        case 2:
      printf("\nEnter the data for node :");
      scanf("%d",&data);
        append_end(&head,data);
        break;
        case 3:
      printf("\nEnter the data for node and position:");
      scanf("%d\n%d",&data,&pos);
        append_position(&head,data,pos);
      break;
      case 4:
      delete_beg(&head);
      break;
      case 5:
      delete_last(&head);
      break;
      case 6:
    printf("\nEnter the  position:");
      scanf("%d",&pos);
      delete_pos(&head,pos);
    }display(head);
    pos=0;
    }
}