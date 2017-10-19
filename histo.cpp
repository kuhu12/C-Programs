#include<iostream>
#include<stack>
using namespace std;
int getmaxarea(int hist[],int n)
{
    stack<int> s;
    int max_area=0;
    int tp=0;
    int area_with_top;
    int i=0;
    while(i<n)
    {
        if(s.empty()||hist[s.top()]<=hist[i])
            s.push(i++);
        else
        {
            tp=s.top();
            s.pop();
            area_with_top=hist[tp]*(s.empty()?i:(i-s.top()-1));
            if(max_area<area_with_top)
                max_area=area_with_top;
        }
    }
    while(s.empty()==false)
    {
        tp=s.top();
        s.pop();
        area_with_top=hist[tp]*(s.empty()?i:(i-s.top()-1));
            if(max_area<area_with_top)
                max_area=area_with_top;
    }
    return max_area;
}
int main()
{
    int hist[]={5,6,3,6,2,8,7};
    int size=sizeof(hist)/sizeof(hist[0]);
    cout<<"maximum area is"<< getmaxarea(hist,size);
    return 0;
}
