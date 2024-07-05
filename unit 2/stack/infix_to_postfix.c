#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int top = -1;
char stack[max], infix[max], postfix[max];
int precedence(char symbol) {
  switch (symbol) {
  case '^':
    return 3;
    break;
  case '*':
  case '/':
    return 2;
    break;
  case '+':
  case '-':
    return 1;
    break;
  default:
    return 0;
  }
}
int isEmpty() {
  if (top == -1)
    return 1;
  else
    return 0;
}
void push(char item) {
  if (top == max - 1) {
    printf("stack overflow");
    exit(0);
  } else {
    top++;
    stack[top] = item;
  }
}
char pop() {
  if (top == -1) {
    printf("stack underflow\n");
    exit(EXIT_FAILURE);
  } else {
    return stack[top--];
  }
}
void infixtopostfix(char infix[]) {
  int i, j = 0;
  char symbol, next;
  int len=strlen(infix);
  for (i = 0; i < len ; i++) {
    symbol = infix[i];
    switch (symbol) {
    case '(':
      push(symbol);
      break;
    case ')':
      while ((next = pop()) != '(') {
        postfix[j++] = next;
      }
      break;
    case '^':
      push(symbol);
      break;
    case '+':
    case '-':
    case '*':
    case '/':
    // https://youtube.com/clip/Ugkxd1qC6ntxn6G7RJpcoGKockDH5rKSZ5DQ?feature=shared
      while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
        postfix[j++] = pop();
      }
      push(symbol);
      break;
    default:
      postfix[j++] = symbol;
    }
  }
  while (!isEmpty()) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
}
int main() {
  printf("Enter the infix expression: ");
 scanf("%s", infix);
  infixtopostfix(infix);
  printf("The postfix expression is: %s", postfix);
  while (top != -1) {
    pop();
  }
}