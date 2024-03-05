#include <stdlib.h>
#include <stdio.h>
int i=0;
struct node {
  int data;
  struct node *next;
};
void display(struct node *head){
     printf("\ncurrent elements:");
    struct node *temp=head;
while(temp!=0){
printf("%d",temp->data);
temp=temp->next;
}
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
  if(*headAddress == nn){
    return 1;
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
     if(temp->next == nn){
        i++;
    return 1;
  }
  return 0;
  }
}int append_position(struct node **headAddress, int data) {
  struct node *nn = create_node(data);
  struct node *temp = *headAddress;
  if (*headAddress == NULL) {
    *headAddress = nn;
  } else {
    
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nn;
  }
   if(temp->next == nn){
    i++;
    return 1;
  }
  return 0;
}

int main()
{ int data;
  struct node *head = NULL;
  int n;
  printf("Enter the number of nodes :");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
     
      printf("\nEnter the data for node %d :",i+1);
      scanf("%d",&data);
      printf("\n1.starting\n2.end\n\nwhere to insert(1/2/3):");
      int option,s;
      scanf("%d",&option);
    switch(option){
        case 1:
        s=append_start(&head,data);
        break;
        case 2:
        s=append_end(&head,data);
        break;
        case 3:
        s=append_position(&head,data);
      break;
    }  if(s=1){
        printf("inserted successfully");
        display(head);
    }
    }
    

    
   
}