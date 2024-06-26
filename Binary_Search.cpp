#include<iostream>
using namespace std;
void binary(int val,int a[],int beg,int end)
{
    int mid;
    if(end>=beg)
    {
        mid=(end+beg)/2;

        if(a[mid]==val)
        {
            cout<<"Element is present at "<<mid<<" index";
        }
        else if(a[mid]<val)
        {
            binary(val,a,beg+1,end);//recursive call
        }
        else{
            binary(val,a,beg,end-1);//recursive call
        }
    }
}
// sort function to firstly sort the given array
void Sort(int a[],int size)
{
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size-1;j++)
    {
        if(a[i]<a[j])
        {
            swap(a[i],a[j]);
        }
    }
  }
}
int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int a[size];
    cout<<"Elements in array:";
    for(int i=0;i<size;i++)
    {
        a[i]=rand()%10;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    Sort(a,size);
    cout<<"Resultant array:-";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int val;
    cout<<"Enter the element , which you want to be search:";
    cin>>val;
    binary(val,a,0,size-1);
    return 0;
}