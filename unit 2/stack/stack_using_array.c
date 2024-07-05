#include<stdio.h>
#include<stdlib.h>
#define max 100
int arr[max];
int top=-1;
void push(){
    int d;
        printf("\nEnter data : ");
        scanf("%d",&d);
    if(top==max-1){
        printf("\nOverFlow.");
        return;
    }
    arr[++top]=d;
}

void pop(){
    if(top==-1){
        printf("\nUnderFlow");
        return;
    }
    printf("\nPoped %d",arr[top--]);
}

void peek(){
    if(top==-1){
        printf("\nUnderFlow");
        return;
    }
    printf("\nPeeked %d",arr[top]);
}

int main(){
    int cho;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\nEnter your choise:");
        scanf("%d",&cho);
        switch(cho){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            exit(0);
        }
    }
}