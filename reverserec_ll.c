#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* head;
void reverse(struct node* p)
{
    if(p->next!= NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    struct node* q=p->next;
    q->next=p;
    p->next=NULL;

}
