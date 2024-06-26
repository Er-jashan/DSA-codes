#include<iostream>
using namespace std;
int f=-1,r=-1;
// int a,f=-1,r=-1;
void rear(int size,int Queue[]);
void front(int Queue[]);
void show(int Queue[]);
int  main()
{
    int ch,a;
    cout<<"Enter the size of the queue:";
    cin>>a;
    int Queue[a];
    cout<<"1.REAR:-"<<endl;
    cout<<"2.FRONT:-"<<endl;
    cout<<"3.SHOW:-"<<endl;
    cout<<"4.EXIT:-"<<endl;
    while(1)
    {
        cout<<"Enter choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:rear(a,Queue);
            break;
            case 2:front(Queue);
            break;
            case 3:show(Queue);
            break;
            case 4:exit(0);
            break;
            default:cout<<"Invalid option..";

        }
    }    
}
void rear(int size,int Queue[])
    {
        int item;
        //  cout<<"Enter the size of the queue:";
        // cin>>a;
        // int Queue[a];
        if(r==size-1)
        {
            cout<<"Queue is full";

        }
        else{
            if(f==-1)
            {
                f=0;
            }
            cout<<"Insert Element in queue:";
            cin>>item;
            
            r=r+1;
            Queue[r]=item;
        }
    }
    
    void front(int Queue[])
    {
        if(f==-1)
        {
            cout<<"Queue is empty.";
        }
        else{
        cout<<"Deleted "<<Queue[f]<<endl;
        f=f+1;

        }
    }
     void show(int Queue[])
    {
        int i;
        if(f==-1)
        {
            cout<<"Queue is empty.";
        }
        else{
            cout<<"Queue elements:";
            for(i=f;i<=r;i++)
            {
                cout<<Queue[i]<<" ";
            }
            cout<<endl;
        }
    }
    