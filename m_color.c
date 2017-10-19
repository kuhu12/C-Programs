#include<stdio.h>
#include<stdbool.h>
#define V 4
void print_color(int color[]);
bool is_safe(int v,bool graph[V][V],int c,int color[])
{
    int i=0;
for( i=0;i<=V;i++){
    if(graph[v][i] && c==color[i]){
        return false;
}}
return true;
}
bool graph_color(int v,bool graph[V][V],int m,int color[])
{
    int c;
if(v==V)
 return true;
for(c=1;c<=m;c++)
{
    if(is_safe(v,graph,c,color))
    {
        color[v]=c;
        if(graph_color(v+1,graph,c,color)==true)
            return true;
        color[v]=0;
}}
return false;
}
bool graph_coloring(bool graph[V][V],int m)
{
int *color=new int[V];
for (int i=0;i<=V;i++)
    color[i]=0;
if(graph_color(0,graph,m,color)==false)
{ printf("Solution does not exist");
return false;
}
printSolution(color)
return true;
}
void printSolution(int color[])
{
printf("solution exits");
for(i=0,i<=V,i++)
   printf("%d",color[i]);
   printf("\n");
}
void main()
{
bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors
    graph_coloring (graph, m);
    return 0;
}
}
