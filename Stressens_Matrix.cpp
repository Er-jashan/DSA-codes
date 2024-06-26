#include<iostream>
using namespace std;

int Strassen(int size)
{
    if(size==2)
    {
        int C[2][2];
    int p,q,r,s,t,u,v;

    int A[2][2];
    cout<<"First Matrix:";
    for(int i=0;i<2;i++)
    {
          for(int j=0;j<2;j++)
          {
            cin>>A[i][j];
          }
    }
   cout<<"Second matrix:";
    int B[2][2];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cin>>B[i][j];
        }
    }

    cout<<"First MAtrix:";
    for(int i=0;i<2;i++)
    {
        cout<<endl;
        for(int j=0;j<2;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Second MAtrix:";
    for(int i=0;i<2;i++)
    {
        cout<<endl;
        for(int j=0;j<2;j++)
        {
            cout<<B[i][j]<<" ";

        }
        cout<<endl;
    }
    // int n;
    
    
    // Now according to Stressons Algorithm:-
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

    cout<<"Therfore,Matrix multiplication by using stressens Algorithm:-";
    for(int i=0;i<2;i++)
    {
        cout<<endl;
        for(int j=0;j<2;j++)
        {
            cout<<C[i][j]<<" ";
        }
    }
    }
    else{
        int mid=size/2;
        Strassen(mid)+Strassen(mid);
    }
 
}
void insert(double C[4][4],int size)
{
    
    double val;
    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            cin>>val;
            C[i][j]=val;
        }
    }
}
    double cal11(double C[4][4])
    {
        return ((C[1][1]*C[1][2])+(C[1][2]*C[2][1]));
    }
    double cal21(double C[4][4])
    {
      return (C[3][1]*C[4][2])+(C[3][2]*C[4][1]);
    }
    double cal12(double C[4][4])
    {
        return (C[1][3]*C[2][4])+(C[1][4]*C[2][3]);
    }
    double cal22(double C[4][4])
    {
        return (C[2][3]*C[1][4])+(C[2][4]*C[1][3]);
    }

int main()
{
    int size;
    cout<<"ENter the order of the matrix:";
    cin>>size;
    if(size==2)
    {
    Strassen(size);
    }
    else{
    double a11,a12,a22,a21,b11,b12,b21,b22,a[4][4],b[4][4];
	double p,q,r,s,t,u,v,c11,c12,c21,c22;
    cout<<"\n a: \n";
	insert(a,size);
	// insert values in the matrix a
	cout<<"\n b: \n";
	insert(b,size);

	//dividing single 4x4 matrix into four 2x2 matrices
	a11=cal11(a);
	a12=cal12(a);
	a21=cal21(a);
	a22=cal22(a);
	b11=cal11(b);
	b12=cal12(b);
	b21=cal21(b);
	b22=cal22(b);

	//assigning variables acc. to strassen's algo
	p=(a11+a22)*(b11+b22);
	q=(a21+a22)*b11;
	r=a11*(b12-b22);
	s=a22*(b21-b11);
	t=(a11+a12)*b22;
	u=(a11-a21)*(b11+b12);
	v=(a12-a22)*(b21+b22);

    //outputting the final matrix
    cout<<"\n final matrix";
 	cout<<"\n"<<p+s-t+v<<" "<<r+t;
	cout<<"\n"<<q+s<<" "<<p+r-q+u;
    }  
    return 0;
}