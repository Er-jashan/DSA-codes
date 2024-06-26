#include<iostream>
using namespace std;
struct node
{
int data;
node* link;
}*head;

void createList(int n);
void display();

int main()
{
int n,data;
cout<<"Enter the total no. of node:";
cin>>n;
createList(n);
cout<<"The list is :"<<endl;
display();
return 0;
}

void createList(int n)
{
struct node *newnode,*temp;
int i;
head=new node();

if(head==NULL)
{
cout<<"Unable to allocate memory..";
}
else{
cout<<"Required List :";
// cin>>data;
head->data=rand()%100;
head->link=NULL;
temp=head;
for(int i=2;i<=n;i++)
{
newnode=new node();
if(newnode==NULL)
{
cout<<"Unable to allocate memory..";
break;
}
else{
// cout<<"Other values are:";
newnode->data=rand()%100;
newnode->link=NULL;
temp->link=newnode;
temp=temp->link;
}
}
}
}
void display()
{
struct node *temp;
if(head==NULL)
{
cout<<"List is empty..";
}
else{
temp=head;
while(temp!=NULL)
{
cout<<temp->data<<"->";
temp=temp->link;
}
cout<<"NULL";
cout<<endl;
}
}