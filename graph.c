#include<stdio.h>
#include<stdlib.h>
struct AdjListNode
{int dest;
struct AdjListNode* head;
};
struct AdjList
{
struct AdjListNode *head;
};
struct Graph{
int V;
struct Adjlist* array;
}
