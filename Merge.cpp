#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int r,int size)
{
    int i=l;
    int j=m+1;
    int k=l;
    
    int temp[size];
    while(i<=m &&j<=r)
    {
                          if(a[i]<=a[j])
                                  {
                                     temp[k]=a[i];
                                        i++;
                                           k++;

                                         }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        j++;
        k++;
    }

    for(int p=l;p<=r;p++)
    {
       a[p]=temp[p];
    }
    
}

void MergeSort(int a[],int size,int l,int r)
{
    int m=(l+r)/2;
    if(l<r)
    {
        MergeSort(a,size,l,m);
        MergeSort(a,size,m+1,r);
        Merge(a,l,m,r,size);
    }

}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int a[size];
    cout<<"Enter the elements in array:";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted  array:";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Sorted array:-";
    MergeSort(a,size,0,size-1);
    
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;

}