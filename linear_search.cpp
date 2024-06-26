#include<iostream>
using namespace std;
void search(int a[],int val,int size)
{
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]==val)
        {
            flag=1;
            cout<<"Element is present at "<<i<<" index"<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"Element is not present in list.";
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
        a[i]=rand()%100;//rand()=random function to generate random numbers
        cout<<a[i]<<" ";

    }
    cout<<endl;
    int val;
    cout<<"Enter the value which ,you want to be search:";
    cin>>val;
    search(a,val,size);
    return 0;
}