#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void swapnodes(struct node **head_ref,int x,int y)
{
if(x==y)
return;
struct node *prevx=NULL, *currx= *head_ref;
while(currx && currx->data!=x)
{ prevx=currx;
  currx=currx->next;
}
struct node *prevy=NULL, *curry= *head_ref;
while(curry && curry->data!=y)
{ prevy=curry;
  curry=curry->next;
}
if(currx == NULL||curry == NULL)
return;
if(prevx!=NULL)
  prevx->next=curry;
else
  *head_ref=curry;
if(prevy!=NULL)
  prevy->next=currx;
else
  *head_ref=currx;
struct node *temp = curry->next;
curry->next = currx->next;
currx->next  = temp;
}
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Druver program to test above function */
int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling swapNodes() ");
    printList(start);

    swapnodes(&start, 4, 3);

    printf("\n Linked list after calling swapNodes() ");
    printList(start);

    return 0;
}
