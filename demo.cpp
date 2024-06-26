// #include <iostream>
// using namespace std;
// int top=-1;

// void push(int arr[], int size)//a,2 ,-1
// {
//   if(top==size-1)
//   {
//     cout<<"overflow"<<endl;
//   }
//   else{
//     int item;
//     cout<<"enter element";
//     cin>>item;
//     top=top+1;
//     arr[top]=item;
//     // top=top+1;
//   }
// }

// void pop(int arr[], int size)
// {
//   if(top==-1)
//   {
//     cout<<"stack underflow"<<endl;
//   }
//   else
//   {
//     cout<< arr[top--];
//   }
// }

// void viewStack(int arr[])
// {
//   for(int i=top; i>=0; i--)
//   {
//     cout << arr[i]<<" ";
//   }
//   cout<<endl;
// }

// void isEmpty( )
// {
//   if(top==-1)
//     cout<<"yes"<< endl;
//   else    
//     cout<<"no"<< endl;
// }

// void isfull( int size)
// {
//   if(top==size-1)
//     cout<<"yes"<< endl;
//   else    
//     cout<<"no"<< endl;
// }

// int peek(int arr[])
// {
//   cout<<"top element is:"<< arr[top];
// }


// int main() 
// {
//   int size;
//   cout << "Enter the size of the stack: ";
//   cin >> size;

//   int arr[size];
// //   int top = -1;

//   int choice;
//   cout<<"1. push"<<endl<<"2. pop"<<endl<<"3. show"<<endl<<"4. isempty"<<endl<<"5. peek"<<endl<<"6. isfull"<<endl<<"7. exit"<<endl;

//   while(1)
//   {
//     cout<<" enter choice";
//     cin>>choice;
//     switch(choice)
//     {
//       case 1: push(arr, size);
//       break;
//       case 2: pop(arr, size);
//       break;
//       case 3: viewStack(arr);
//       break;
//       case 4: isEmpty();
//       break;
//       case 5: peek(arr);
//       break;
//       case 6: isfull(size);
//       break; 
//       case 7: exit(0);
//       default : cout << "invald choice";
//     }
//   }
// }

#include<iostream>
using namespace std;

void sort(float x[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(x[j]>x[j+1])
            {
                int temp=x[j];
                x[j]=x[i];
                x[i]=temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"enter no of items in sack";
    cin>>n;

    int w[n], p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter profit of item"<< i+1;
        cin>>p[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<"enter weight of item"<<i+1;
        cin>>w[i];
    }

    int wt;
    cout<<"specify weight of knapsack";
    cin>>wt;

    float x[n];
    for(int i=0; i<n; i++)
    {
        x[i]= p[i]/w[i];
    }

    sort(x,n);

    float result;
    for(int i=0;i<n && wt>0;i++)
    {
        while(wt>0)
        {
            if(w[i]<=wt)
            {
                result+=p[i];
                wt-=w[i];
            }
            else{

                result=wt*x[i];
                wt=0;
            }
        }
    }   
    cout<<"max profit is: "<< result;
}
