#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head;
struct node* reverse(struct node* head)
{
    struct node *current,*prev,*next;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
void push(struct node **head_ref,int new_data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node* start = NULL;


    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling ");
    printList(start);

    start=reverse(start);

    printf("\n Linked list after calling  ");
    printList(start);

    return 0;
}
