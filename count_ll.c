#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
void push(struct node** head_ref,int new_data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
int getCount(struct node* head)
{
    int count=0;
    struct node* current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}
void main()
{
    struct node* head=NULL;
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    printf("count of nodes is %d", getCount(head));

}

