#include<iostream>
using namespace std;
// total no. of objects =n
void knapsack(int n, float weight[],float profit[],float capacity)
{
   float x[20],total_profit=0;
   int i,j,u;
   u=capacity;// u=20

   for( i=0;i<n;i++)
   {
    x[i]=0.0;// 
   }
   
   for( i=0;i<n;i++)
   {                 //
    if(weight[i]>u)//(weight[0]>20)
    {
        break;
    }
   
    else{
        x[i]=1.0;
        total_profit=total_profit+profit[i];
        u=u-weight[i];
    }
   }
   
    if(i<n)
    {
        x[i]=u/weight[i];
        // total_profit=total_profit+(x[i]*profit[i]);
    }
   total_profit=total_profit+(x[i]*profit[i]);
   
   
   
   cout<<"The resultant vector is : ";
   for (i=0;i<n;i++)
   {
    cout<<x[i]<<" ";
   }
   cout<<endl;

   cout<<"MAximum profit is :"<<total_profit;
   

}

int main()
{
    float weight[20],profit[20],capacity;
    int num;
    float ratio[20],temp;

    cout<<"Enter the no. of objects :";
    cin>>num;

    cout<<"Enter the weights nd profits of the each object :";
    for(int i=0;i<num;i++)
    {
        cin>>weight[i]>>profit[i];
    }

    cout<<"ENter the capacity of the knapsack :-";
    cin>>capacity;

    for( int i=0;i<num;i++)
    {
        ratio[i]=profit[i]/weight[i];
    }

    for( int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
          if(ratio[i]<ratio[j])
          {
            temp=ratio[j];
            ratio[j]=ratio[i];
            ratio[i]=temp;

            temp=weight[j];
            weight[j]=weight[i];
            weight[i]=temp;

            temp =profit[j];
            profit[j]=profit[i];
            profit[i]=temp;
            
          }
        }
    }
    cout<<"Sorted ratio: "<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<ratio[i]<<" ";
    }
    knapsack(num,weight,profit,capacity);
    return 0;

}