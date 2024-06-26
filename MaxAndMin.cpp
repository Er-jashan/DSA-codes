#include<iostream>
using namespace std;
void MaxAndMin(int a[],int size)
{
   int max=a[0];
   int min=a[0];
   for(int i=0;i<size;i++)
   {
        if(a[i]>max)
        {
            max=a[i];
        }
        else if(a[i]<min)
        {
            min=a[i];
        }
   }
   cout<<"Maximum Element is :"<<max<<endl;
   cout<<"Minimum Element is :"<<min<<endl;
}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int a[size];
    cout<<"Elements in array are: ";
    for(int i=0;i<size;i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    MaxAndMin(a,size);
    return 0;
}