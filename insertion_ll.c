#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void push(struct node** head_ref,int new_data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data= new_data;
    new_node->next= *head_ref;
    *head_ref= new_node;

}
void insertAfter(struct node* prev_node,int new_data)
{
     if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
    struct node* new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data= new_data;
    new_node-> next= prev_node->next;
    prev_node->next=new_node;

}
void append (struct node** head_ref,int new_data)
{ struct node* new_node= (struct node*)malloc(sizeof(struct node));
struct node *last= *head_ref;
new_node->data= new_data;
new_node->next= NULL;
if(*head_ref==NULL)
    { *head_ref=new_node;
       return;
}
while(last->next!=NULL)
   last=last->next;
last->next=new_node;
return;
}
void printlist(struct node *n)
{
    while(n!= NULL)
    {
        printf("%d",n->data);
        n=n->next;
    }
}
int main()
{
    struct node* head=NULL;
    append(&head,8);
    push(&head,9);
    push(&head,1);
    append(&head,10);
    insertAfter(head->next,5);


    printlist(head);
    return 0;
}
