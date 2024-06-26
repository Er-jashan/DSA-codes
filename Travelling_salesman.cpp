#include<iostream>
using namespace std;
int a[10][10],cost=0,visited[10],n;

void get()
{
    cout<<"Enter number of cities:";
    cin>>n;

    cout<<"Enter cost matrix:";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements in row"<<i+1<<":";
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            visited[i]=0;
        }

    }
    cout<<"Enter the cost list:";

    for(int i=0;i<n;i++)
    {
       cout<<endl;
       for(int j=0;j<n;j++)
       {
        cout<<"\t"<<a[i][j];
       }
    }
}
// int least(int c)

// {
//     int nc=999;
//     int min=999,kmin;
//     for(int i=0;i<n;i++)
//     {
//         if((a[c][i]!=0)&&(visited[i]==0))
//         {
//            if(a[c][i]<min)
//            {
//             min=a[i][0]+a[c][i];
//             kmin=a[c][i];
//             nc=1;

//            }
//         }
//     }
//     if(min!=999)
//       {
//         cost+=kmin;
//         return nc;
//       }


// }
int least(int city);
void mincost(int city)
{
   
    int ncity;
    visited[city]=1;
    cout<<"-->"<<city+1;
    ncity=least(city);//ncity=least(0)

    if(ncity==999)
    {
          ncity=0;
          cout<<ncity+1;
          cost+=a[city][ncity];
         return;
         
    }
    mincost(ncity);
};
int least(int c)
{
    int nc=999;
    int min=999,kmin;
    for(int i=0;i<n;i++)
    {
        if((a[c][i]!=0)&&(visited[i]==0))//if(a[0][0]!=0 &&)
        {
           if(a[c][i]<min)
           
            min=a[i][0]+a[c][i];
            kmin=a[c][i];
            nc=i;
         
           
        }
    }
    if(min!=999)
      
        cost+=kmin;
        return nc;
      
    

}


// int least(int c)

// {
//     int nc=999;
//     int min=999,kmin;
//     for(int i=0;i<n;i++)
//     {
//         if((a[c][i]!=0)&&(visited[i]==0))
//         {
//            if(a[c][i]<min)
//            {
//             min=a[i][0]+a[c][i];
//             kmin=a[c][i];
//             nc=1;

//            }
//         }
//     }
//     if(min!=999)
//       {
//         cost+=kmin;
//         return nc;
//       }

// }


void put()
{
    cout<<"Minimum cost is:"<<cost;
    
}

int  main()
{
    get();
    cout<<"The path is :";
    mincost(0);
    put();
    return 0 ;
}