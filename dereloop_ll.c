#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
void push(struct node **head_ref,int new_data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void printList(struct node* node)
{
    while(node!= NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
}
struct node* head;
void detectremove(struct node* head)
{
    node *slow= head;
    node *fast= head->next;

while(fast&&fast->next)
{
    if(slow==fast)
        break;
    slow=slow->next;
    fast=fast->next->next;
}
if(slow==fast)
{
    slow=head;
    while(slow!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}}
int main()
{
    struct node *start = NULL;


    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);

    start->next->next->next->next->next = start->next->next;

    detectremove(start);

    printf("\n Linked list after calling function ");
    printList(start);

    return 0;
}


}
