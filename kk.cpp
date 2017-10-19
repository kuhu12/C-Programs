#include<stdio.h>
#include<stdbool.h>
#define V 4
void printSolution(int color[]);
bool isSafe(int v,bool graph[V][V],int c,int color[])
{int i;
    for(i=0;i<V;i++){
        if(graph[v][i]&&c==color[i]){
            return false;
    }}
return true;
}
bool graphcolorUtil(bool graph[V][V],int m,int color[],int v)
{
    if(v==V)
        return true;
    for(int c=1;c<=m;c++){
        if(isSafe(v,graph,c,color))
        {
           color[v]=c;
           if(graphcolorUtil(graph,m,color,v+1)==true)
             return true;
        color[v]=0;
    }}
return false;
}
bool graphColoring(bool graph[V][V], int m)
{
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;
    if (graphcolorUtil(graph, m, color, 0) == false)
    {
      printf("Solution does not exist");
      return false;
    }
    printSolution(color);
    return true;
}
void printSolution(int color[])
{
    printf("Solution Exists:"
            " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphColoring (graph, m);
    return 0;
}

