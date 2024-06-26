#include<iostream>
using namespace std;
int main()
{
    int x,y;
    // int C[x][y];
    int p,q,r,s,t,u,v;
    int n;
    cout<<"Enter the order of the matrix 2*2 only:-";
    cin>>n;
    cout<<"Enter the matrix of "<<n<<"*"<<n<<endl;
    //{{12,34},
    //             {22,10}};
    
    cout<<"ENter  the row1 of first matrix:";
    cin>>x;
    cout<<"Enter the column1 of the first matrix:";
    cin>>y;
    int A[x][y];
    cout<<"Enter the elements in first matrix:";
    for(int i=0;i<x;i++)
    {
        cout<<endl;
        for (int j=0;j<y;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<endl;
    int a,b;
     cout<<"ENter  the row2 of first matrix:";
    cin>>a;
    cout<<"Enter the column2 of the first matrix:";
    cin>>b;
    int B[a][b];
    cout<<"Enter the elements in second matrix:";
    for(int i=0;i<a;i++)
    {
        cout<<endl;
        for(int j=0;j<b;j++)
        {
            cin>>B[i][j];
        }
    }

    cout<<"First MAtrix:";
    for(int i=0;i<x;i++)
    {
        cout<<endl;
        for(int j=0;j<y;j++)
        {
            cout<<A[i][j]<<" ";
        }
    }

    cout<<"Second MAtrix:";
    for(int i=0;i<a;i++)
    {
        cout<<endl;
        for(int j=0;j<b;j++)
        {
            cout<<B[i][j]<<" ";

        }
    }

    // Now according to Stressons Algorithm:-
    
    int C[x][y];
    for(int i=0;i<x;i++)
    {
        cout<<endl;
        for(int j=0;j<b;j++)
        {
    p=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]); //p=(A11+A22)*(B11+B22)
    q=B[0][0]*(A[1][0]+A[1][1]); //B11(A21+A22)
    r=A[0][0]*(B[0][1]-B[1][1]);//A11(B12+B22)
    s=A[1][1]*(B[1][0]-B[0][0]);//A22(B21-B11)
    t=B[1][1]*(A[0][0]+A[0][1]);//B22(A11+A12)
    u=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);//(A21-A11)(B11+B12)
    v=(B[1][0]+B[1][1])*(A[0][1]-A[1][1]);//(B21+B22)(A12-A22)

    // Now the resultant matrix elements by stressens fromula :-
    C[0][0]=p+s-t+v;
    C[0][1]=r+t;
    C[1][0]=q+s;
    C[1][1]=p+r-q+u;


        }
    }
    
    // p=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]); //p=(A11+A22)*(B11+B22)
    // q=B[0][0]*(A[1][0]+A[1][1]); //B11(A21+A22)
    // r=A[0][0]*(B[0][1]-B[1][1]);//A11(B12+B22)
    // s=A[1][1]*(B[1][0]-B[0][0]);//A22(B21-B11)
    // t=B[1][1]*(A[0][0]+A[0][1]);//B22(A11+A12)
    // u=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);//(A21-A11)(B11+B12)
    // v=(B[1][0]+B[1][1])*(A[0][1]-A[1][1]);//(B21+B22)(A12-A22)

    // // Now the resultant matrix elements by stressens fromula :-
    // C[0][0]=p+s-t+v;
    // C[0][1]=r+t;
    // C[1][0]=q+s;
    // C[1][1]=p+r-q+u;

    cout<<"Therfore,Matrix multiplication by using stressens Algorithm:-";
    for(int i=0;i<2;i++)
    {
        cout<<endl;
        for(int j=0;j<2;j++)
        {
            cout<<C[i][j]<<" ";
        }
    }
    
    return 0;
}