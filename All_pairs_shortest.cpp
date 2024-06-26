#include<iostream>
#include<iomanip>//manipulate function -manipulate the format of input /output
using namespace std;
#define node 7
int main()
{
    int n;
    cout<<"Enter the order of the  matrix :";
    cin>>n;
    int A[n][n];
    cout<<"Ente the elements in matrix:";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           cin>>A[i][j];
        }
    
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=n;j++)
            {
                if((A[i][k]+A[k][j])<A[i][j])
                {
                A[i][j]=A[i][k]+A[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<endl;
       for(int j=1;j<=n;j++)
        {
           cout<<setw(3)<<A[i][j];
        }
    }
    return 0;
    }