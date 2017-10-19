#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* top=NULL;
int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}
int peek() {
    return top->data;
}

void push(int x)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;

}
void pop()
{
    struct node *temp;
    if(top==NULL) return;
    temp=top;
    top=top->next;
    free(temp);
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void main() {
   push(1);
   push(2);
   push(3);
   push(4);
   printf("\nTop Element : %d\n", peek());

   printf("Stack as linked List\n");
   printList(top);
   pop();
   pop();
   pop();
   pop();
   pop();
   printList(top);

   return;
}
