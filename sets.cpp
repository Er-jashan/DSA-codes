#include<iostream>
using namespace std;
void find(int a[],int size)
{
    int value;
    cout<<"Enter the value ,which you want to be search: ";
    cin>>value;
    int flag=0;
    cout<<"Press any no. except 1 for searching:";
    int ch;
    cin>>ch;
    do{
    for(int i=0;i<size;i++)
    {
         if(a[i]==value)
         {
            flag=1;
            cout<<"Element is found at "<<i<<" index";
            break;
         }
    }
    if(flag==0)
    {
        cout<<"Element not found.."<<endl;
        break;
    }
    cout<<"Press any no. for exit:";
    break;
    }while(ch==1);
}

void set_union(int a[],int size1,int size2)
{

    int c[size1+size2];
   for(int i=0;i<size1;i++)
   {
    for(int j=0;j<i+size2;j++)
    {
      c[i]=a[i+j];
      cout<<c[i];
    }
   }
}
void intersection(int a[],int b[],int size1,int size2)
{
    cout<<"Intersection of the sets are:";
   for(int i=0;i<size1;i++)
   {
     for(int j=0;j<size2;j++)
     {
           if(a[i]==b[j])
           {
            cout<<a[i]<<" ";
           }
     }
   }
   cout<<endl;
}
int main()
{
    cout<<"ENter the size 1st sets:";
    int size1;
    cin>>size1;
    char ch;
    int a[size1];
    // cout<<"Enter the size of the "<<i<<" set:";
    // cin>>size1;
    // int a[size1];
    cout<<"Enter the elements in set:";
    for(int i=0;i<size1;i++)
    {
        cin>>a[i];
    }

    cout<<"ENter the size 2nd sets:";
    int size2;
    cin>>size2;
    int b[size2];
       cout<<"Enter the elements in set:";
    for(int i=0;i<size2;i++)
    {
        cin>>b[i];
    }
   set_union(a,size1,size2);
    // cout<<"If you want to search in "<<i<<" set then Press Y for searching, else Press any key to return:";
    // cout<<endl;
    // // cout<<"Press N for exit..";
    // // cout<<endl;
    // cin>>ch;
    // if(ch=='Y')
    // {
    //     find(a,size1);
    // }
    
    //  in
    // cout<<"Enter the size of the array:";
    // cin>>size2;
    // int b[size2];
    // cout<<"Enter the elements in array:";
    // for(int j=0;j<size2;j++)
    // {
    //     cin>>b[j];
    // }
    
    // intersection(a,b,size1,size2);
    
    // intersection(a,size1);
//    set_union(a,size1);
    return 0;

}