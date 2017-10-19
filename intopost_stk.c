#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct stack
{
    int top;
    unsigned capacity;
    int* array;
};
struct stack* createstack(unsigned capacity)
{
    struct stack* stack=(struct stack*)malloc(sizeof(struct stack));
    if(!stack)
        return NULL;
    stack->top=-1;
    stack->capacity=capacity;
     stack->array=(int*)malloc(stack->capacity * sizeof(int));
     if(!stack->array)
        return NULL;
     return stack;
}
int isEmpty(struct stack* stack)
{
return stack->top=-1;
}
char peek(struct stack* stack)
{
  return stack->array[stack->top];
}
char pop(struct stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->top--];
        return "$";
    }
}
void push(struct stack* stack,char op)
{
    stack->array[++stack->top]=op;
}
int isOperand(char ch)
{
    return(ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')
}
int prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
        return -1;
}
int infixtopostfix(char* exp)
{
    int i,k;
    struct stack* stack=

}
