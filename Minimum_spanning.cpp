#include<bits/stdc++.h>
using namespace std;
// no. of vertices :
#define V 5

int  minimumNode(int node[],bool minSet[])
{
    int min=INT_MAX,minIndex;

    for(int v=0;v<V;v++)
    {
        if(minSet[v]==false && node[v]<min)
        {
            min=node[v],minIndex=v;
        }
    }
    return minIndex;

}

void printMST(int parent[],int graph[V][V])
{
     cout<<"Edge Weight\n";
     for(int i=1;i<V;i++)
     {
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
     }
}

void prims(int graph[V][V])
{
    int parent[V];
    int node[V];
    bool minSet[V];

    for(int i=0;i<V;i++)
    {
        node[i]=INT_MAX;
        minSet[i]=false;
    }

    node[0]=0;
    parent[0]=-1;

    for(int count=0;count=V-1;count++)
    {
        // pick the minimum key:-
        int m=minimumNode(node,minSet);
        minSet[m]=true;


        for(int v=0;v<V;v++)
        {
           if (graph[m][v] && minSet[v] == false
                && graph[m][v] < node[v])
                {
                parent[v] = m, node[v] = graph[m][v];
                }
        }
    }
    printMST(parent,graph);
}

int main()
{                      // A  B  C  D  E
    int graph[V][V] = { { 0, 2, 0, 6, 0 },//A
                        { 2, 0, 3, 8, 5 },//B
                        { 0, 3, 0, 0, 7 },//C
                        { 6, 8, 0, 0, 9 },//D
                        { 0, 5, 7, 9, 0 } };//E
 
    // Print the solution
    prims(graph);
 
    return 0;
}

// int main()
// {
//     cout<<"HEllo";
// }