#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

struct node *create_node(int data) {
  struct node *nn = (struct node *)malloc(sizeof(struct node));
  nn->data = data;
  nn->next = NULL;
  return nn;
}
void append(struct node **headAddress, int data) {
  struct node *nn = create_node(data);
  if (*headAddress == NULL) {
    *headAddress = nn;
  } else {
    struct node *temp = *headAddress;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nn;
  }
}
int main()
{
  struct node *head = NULL;
  int n;
  printf("Enter the number of nodes :");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      int data;
      printf("Enter the data for node %d :",i+1);
      scanf("%d",&data);
      append(&head,data);
    } 
}