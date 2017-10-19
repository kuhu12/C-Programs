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
    cout<<Distance(start1,end1);
    }
