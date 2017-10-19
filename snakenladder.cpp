#include<iostream>
#include<queue>
using namespace std;
struct queueEntry
{
    int v;
    int dist;
};
int mindicethrow(int move[],n)
{
    bool *visited=new bool[N];
    for(i=0;i<=N;i++)
        visited[i]=false;

    queue<queueEntry> q;

    visited[0]=true;
    queueEntry s={0,0};
    q.push(s);

    queueEntry qe;
    while(!q.empty())
        {
            qe=q.front();
           int v=qe.v;
    if(v==N-1)
        break;
    q.pop();
    for(int j=v+1;j<=(v+6)&&j<N;++j)
    {
        if(!visited[j])
        {
            queueEntry a;
            a.dist=qe.dist+1;
            visited[j]=true;

        }

    }
    }



}
