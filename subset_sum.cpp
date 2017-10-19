#include<stdio.h>
#include<stdlib.h>

#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))

static int total_nodes;

void printSubset(int A[],int size)
{
    for(i=0;i<size;i++)
    {
        printf("%*d",5,A[i]);
    }
   printf("\n");
}
int comparator(const void *pLhs,const void *pRhs)
{
    int *lhs=(int *)pLhs;
    int *rhs=(int *)PRhs;
    return *lhs>*rhs
}
