
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;
void push(int x)
{
    if (top==MAX_SIZE-1)
    {
      printf("ERROR:  STACK OVERFLOW");
      return;
    }
    a[++top]=x;
}
void pop()
{
    if (top==-1)
    {
        printf("ERROR:  STACK UNDERFLOW");
        return;
    }
    top--;
}
int Top()
{
    return a[top];
}
void print()
{
    int i;
    printf("STACK:");
    for(i=0;i<=top;i++)
     printf("%d",a[i]);
    printf("\n");
}
int main()
{
    push(2);print();
    push(5);print();
    push(10);print();
    pop();print();
    push(15);print();
}
