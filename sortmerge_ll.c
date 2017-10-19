#include<stdlib.h>
#include<stdio.h>
struct node{
int data;
struct node* next;
};

struct node* sortedmerge(struct node* a,struct node* b)
{
    struct node* result;
   if(a==NULL)return b;
    else if(b==NULL) return a;

    if(a->data <= b->data)
    {
         result=a;
        result->next=sortedmerge(a->next,b);
    }
    else{
        result=b;
        result->next=sortedmerge(a,b->next);
    }
    return result;
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
    struct node* L1 = NULL;
    struct node* L2 = NULL;



    push(&L1, 9);
    push(&L1, 6);
    push(&L1, 4);
    push(&L2, 3);
    push(&L2, 2);
    push(&L2, 1);


    printList(sortedmerge(L1,L2));

    return 0;
}
