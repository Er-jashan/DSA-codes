#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"ENter the elements in array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // Logic of selection sort:-
    for(int i=0;i<n-1;i++)
    {
        int min=i;// intialize The minimum element..
       for(int j=i+1;j<n;j++)
       {
        if(a[j]<a[min])// if jth element is smaller than minimum element..
        {
            int min=j;//Minimum element is now jth element
            //Swap the elements 
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
       }
    }
    cout<<"Array after selection sorting is :";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }
    return 0;
}