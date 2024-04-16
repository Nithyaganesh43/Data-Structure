#include <stdio.h>
#define size 5
int stack[size],top=-1;
void push(int val)
{
  if(top==size-1)
  {
    printf("\nOverflow");
  }
  else
  {
    stack[++top]=val;
  }
}
int pop(){
    if(top==-1){
    printf("\nunderflow");
    }
else{
    return stack[top--];
}
}
void display(){printf("\n");
    for(int i=top;i>=0;i--){
        printf("%d ->",stack[i]);
    }
}
int main(void)
{
            int val;
    while(1){
        printf("\nEnter your choise \n1.push\n2.pop\n");
        int choi;
        scanf("%d",&choi);
        switch(choi){
            case 1:
            printf("\nenter value to push:");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            pop();
            break;
        }
            display();
    }
return 0;
}
