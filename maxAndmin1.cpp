#include<iostream>
using namespace std;

int max(int a[],int start,int end)// recursive call max1=(a,0,2)//max(a,0,1)
{
  
     if(end-start+1==1)//4-0+1==1  //(2-0+1==1) // max(1-0+1==1)
     {
        return a[start];//
     }
     if(end-start+1==2)//(2-0+1==2)//(1-0+1==2)
     {
        if(a[start]<a[end])//(a[0]<a[1])
        {
            return a[end];
        }
        else{
            return a[start];
        }
     }
     int m=start+(end-start)/2;//m=0+(4-0)/2=>m=2//m=0+(2-0)/2=>1
     int max1=max(a,start,m);//max1=max(a,0,2)//max1=max(a,0,1)
     int max2=max(a,m+1,end);//max2=max(a,3,4)//max2=max(a,2,2)
     if(max1<max2)
     {
        return max2;
     }
     else{
        return max1;
     }
}

int min(int a[],int start,int end)//1 2 3 
{
    int min1;
    if(end-1==0)
    {
       return a[start];
    }
    if(start>=end-2)
    {
        if(a[start]<a[start+1])
        {
            return a[start];
        }
        else{
            return a[start+1];
        }
    }
    min1=min(a,start+1,end);
    if(a[start]<min1)
    {
       return a[start];
    }
    else{
        return min1;
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
    cout<<"Maximum element in array:"<<max(a,0,size-1);
    cout<<endl;
    cout<<"Minimum element in array:"<<min(a,0,size-1);

    return 0;
}