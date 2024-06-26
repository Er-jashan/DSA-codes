#include<iostream>
using namespace std;
int main()
{
    int stages=4,min;
    int n=8;
    int cost[9],d[9],path[9];
    int c[9][9]={
        {0,0,0,0,0,0,0,0,0},
        {0,0,2,1,3,0,0,0,0},
        {0,0,0,0,0,2,3,0,0},
        {0,0,0,0,0,6,7,0,0},
        {0,0,0,0,0,6,8,9,0},
        {0,0,0,0,0,0,0,0,6},
        {0,0,0,0,0,0,0,0,4},
        {0,0,0,0,0,0,0,0,5}
    };

    cost[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        min=INT8_MAX;
        for(int k=i+1;k<=n;k++)
        {
            if(c[i][k]!=0 && c[i][k]+cost[k]<min)
            {
                 min=c[i][k]+cost[k];
                 d[i]=k;
            }
        }
        cost[i]=min;
    }
    cout<<"Sequence of shortest path by forward approach:";
    path[1]=1,path[stages]=n;
    cout<<path[1]<<"-";
    for(int i=2;i<stages;i++)
    {
        path[i]=d[path[i-1]];
        cout<<path[i]<<"-";
    }
    cout<<path[stages];
}