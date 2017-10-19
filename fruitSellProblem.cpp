#include<bits/stdc++.h>
using namespace std;
double Distance (pair<int,int> p1,pair<int,int> p2)
{
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
int main()
{
    int N,i,j;
    pair<int,int> start1,end1,current;
    cin>>start1.first>>start1.second;
    cin>>end1.first>>end1.second;
    cin>>N;
    pair<int,int> Arr[N];

    for(i=0;i<N;++i)
        cin>>Arr[i].first>>Arr[i].second;
    bool visited[N];
    for(i=0;i<N;++i)
        visited[i]=false;
    current=start1;
    int d,min1,minInd;
    double ans=0;
    for(i=0;i<N;++i)
    {
        min1=1000;
        minInd=-1;
        for(j=0;j<N;++j)
        {
           if(visited[j]==false&&min1>Distance(current,Arr[j]))
           {
               minInd=j;
               min1=Distance(current,Arr[j]);
           }
        }
       // cout<<Distance(current,Arr[minInd])<<endl;
        ans+=Distance(current,Arr[minInd]);
        current=Arr[minInd];
        visited[minInd]=true;
    }
    ans+=Distance(end1,Arr[minInd]);
    cout<<ans<<endl;
    return 0;

}
