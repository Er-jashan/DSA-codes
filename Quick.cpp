#include<iostream>
using namespace std;
#include<chrono>
typedef chrono::seconds sec;
typedef chrono::high_resolution_clock HRC;
//that function consider last element as pivot , place the pivot at its exact position and place smaller elements to left of pivot and larger to right of pivot

int partition(int a[],int start,int end)
{
    int pivot=a[end];//pivot element
    int i=start-1;//i=0-1;
    //start=0 ; j=0;j<=size-1;j++
    for(int j=start;j<=end-1;j++)
    {
        //if current element is smaller than the pivot

        //for fisrt iteration:-
        //if(3<9)==>true                             //3,6,8,1,9        
        if(a[j]<pivot)
        {
            i++;//increment index of smaller elements::i=-1+1=0
            int t=a[i];//t=3
            a[i]=a[j];//3=3
            a[j]=t;//3=temp
        }
    }
     int t = a[i+1];  //t=a[0]=3
    a[i+1] = a[end];  //3=9
    a[end] = t;  //9=t
    return (i + 1); 
}
//function to implement sort
void quick(int a[],int start,int end)
{
    if(start<end)
    {
        int p=partition(a,start,end);
        quick(a,start,p-1);//recursive calls
        quick(a,p+1,end);//recursive calls
    }

}
//Function to print an array
void print(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    auto start=HRC::now();
    // cout<<"Before sorting array is:-";
    // int a[]={34,9,12,76,55};
    // int n=sizeof(a)/sizeof(a[0]);
    int size;
    cout<<"ENter the size of the array:";
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++)
    {
       a[i]=rand()%100;
       cout<<a[i]<<" ";
    }
    cout<<endl;
    // print(a,n);
    quick(a,0,size-1);
    cout<<endl;
    cout<<"After sorting array is : ";
    // print(a,size);
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    auto end=HRC::now();
    auto exec_time=chrono::duration_cast<sec>(end-start);

    cout<<"Execution time :"<<exec_time.count()<<" sec";
    return 0;
}