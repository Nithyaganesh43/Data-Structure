#include <stdio.h>
#include <stdlib.h>
struct stack{
int *arr;
int top;
int size;
};
struct stack* create(int size){
  struct stack* s = (struct stack*)malloc(sizeof(struct stack));
  s->arr = (int*)malloc(size * sizeof(int)); 
  s->top = -1;
  s->size = size;
  printf("\nStack created successfully");
  return s;
}
void push(struct stack* s,int data){
  if(s->top!=s->size-1){
    s->arr[++s->top]=data;
  }else{
    printf("Stack overflow");
  }
}
int pop(struct stack* s){
  if(s->top==-1){
    printf("stack underflow");
    return -4040404;
  }
  s->top--;
  return s->arr[s->top+1];
}
int peek(struct stack* s){
  if(s->top==-1){
    printf("stack underflow");
    return -4040404;
  }
  return s->arr[s->top];
}
void display(struct stack* s){
  if(s->top==-1){
    printf("\nstack is empty");
  }else{
    printf("\nElements in stack: ");
    for(int i=0;i<=s->top;i++){
      printf("%d ",s->arr[i]);
    }
  }
}
void increase(struct stack* s,int size){
  s->arr = (int*)realloc(s->arr ,size * sizeof(int)); 
  s->size=size;
  if(s->top>size-1){
    s->top=size-1;
  }
}
int main(void) {
      int val;
  printf("creating stack..... \n");
    printf("enter the size of stack:");
    int size;
    scanf("%d",&size);
    struct stack* s=create(size);
  while(1){
  printf("\n1.push\n2.pop\n3.peek\n4.modify size\n5.exit\n");
  printf("\nenter your choise:");
  int choise;
  scanf("%d",&choise);
  switch(choise){
    case 1:
    printf("enter the data to push:");
    int data;
    scanf("%d",&data);
    push(s,data);
    break;
    case 2:
      val=pop(s);
      if(val!=-4040404){
        printf("popped element is %d",val);
      }
    break;
    case 3:
      val=peek(s);
      if(val!=-4040404){

            printf("peeked :%d",val);
      }
    break;
    case 4:
    printf("enter the new size of stack:");
    int size;
      scanf("%d",&size);
    increase(s,size);
    break;
    case 5:
    exit(0);
    break;
  }display(s);
  }
  return 0;
}