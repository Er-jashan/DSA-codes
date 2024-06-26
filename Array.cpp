#include<iostream>
using namespace std;
#include<chrono>
typedef chrono::milliseconds MSEC;
typedef chrono::high_resolution_clock HRC;
int main()
{
    auto start=HRC::now();

    int size,i,*a,loc;
    cout<<"Enter the size of the array:";
    cin>>size;
    a=new int[size];
    cout<<"Elements in the array:";
    for(i=0;i<size;i++)
    {
        a[i]=rand()%10;
        cout<<a[i]<<" ";
    }
    // cout<<"Array:-";
    // for(i=0;i<size;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    cout<<endl;
 cout<<"Enter the index no., in which you want to delete element:";
    cin>>loc;
    i=loc;
    while(i<=size-1)
    {
        a[i]=a[i+1];
        i=i+1;
    }
    // size--;
    cout<<"Array,After deletion at the sepcified postion:";
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    delete[] a;
    cout<<"Last index shows the garbage value,because element is not longer exist.."<<endl;
    
    auto end=HRC::now();
    auto exec_time=chrono::duration_cast<MSEC>(end-start);

    cout<<"Execution time: "<<exec_time.count()<<" msec";
    return 0;
}