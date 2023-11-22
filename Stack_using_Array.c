#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
// This library is used for boolean in c

struct Stack{
  int arr[2];
  int top;
};

// Initialization of The Stack Created
void initialize(struct Stack** stack){
    (*stack)->top=-1;
}
// We can use both double pointer and single pointer in this implementation

// Checks if the stack is empty
bool isempty(struct Stack* stack){
    return (stack->top==-1);
}

// Checks if the stack is full
bool isfull(struct Stack* stack){
    return (stack->top==1);
}

// Push Function
void push(struct Stack* stack,int data){
    if (!isfull(stack)){
        (stack)->arr[++(stack)->top]=data;
    }
    else {
        printf("Stack Overflow \n");
    }
}

// Pop Function
void pop(struct Stack* stack){
    if (!isempty(stack)){
      (stack)->arr[(stack)->top--];
    }
    else {
        printf("Stack Underflow \n");
    }
}

// Peek Function
void peek(struct Stack* stack){
    if (!isempty(stack)){
        printf("%d\n",stack->arr[stack->top]);
    }
    else {
        printf("Stack is empty \n");
    }
}

int main() {
    struct Stack* stack;
    initialize(&stack);
    push(stack,20);
    push(stack,30);
    push(stack,40);
    peek(stack);
    pop(stack);
    peek(stack);
}
