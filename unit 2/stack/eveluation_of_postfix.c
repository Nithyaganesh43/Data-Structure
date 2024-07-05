#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max 1000
int top = -1;
int stack[max];
char postfix[max];
void push(char s){
stack[++top]=s;
}
int pop(){
    return stack[top--];
}
bool isNum(char ch) {
    return ch >= '0' && ch <= '9';
}
void eveluate(char exp[]){
    int len=strlen(exp);
    int i;
    char elem;
    for(i=0;i<len;i++){
        elem=exp[i];
        if(isNum(elem)){
            push(elem-'0');//char to int 
        }
        else{
            int a,b;
            b=pop();
            a=pop();

            switch(elem){
                case '+':
                    push(a+b);
                    break;
                case '-':
                    push(a-b);
                    break;
                case '/':
                    push(a/b);
                    break;
                case '*':
                    push(a*b);
                    break;
            }
            
        }
    }
    
printf("\n Result :%d",pop());
}
int main() {
printf("Enter the postfix expression: ");
scanf("%s", postfix);
eveluate(postfix);  
}