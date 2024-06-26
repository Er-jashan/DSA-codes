#include <iostream>
#include <climits> // Used for INT_MAX
using namespace std;

// It is the total no of verteices in the graph
#define vertex 7

// A method to find the vertex with minimum distance
// which is not yet included in Dset
int minimumDist(int dist[], bool Dset[])
{
    // initialize min with the maximum possible value
    // as infinity does not exist
    int min = INT_MAX, index;
    for (int v = 0; v < vertex; v++) {
        if (Dset[v] == false && dist[v] <= min) {
            min = dist[v];
            index = v;
        }
    }
    return index;
}

// Method to implement shortest path algorithm
void dijkstra(int graph[vertex][vertex], int src)
{
    int dist[vertex];
    bool Dset[vertex];
    // Initialize distance of all the vertex
    // to INFINITY and Dset as false
    for (int i = 0; i < vertex; i++) {
        dist[i] = INT_MAX;
        Dset[i] = false;
    }
    // Initialize the distance of the source vertec to zero
    dist[src] = 0;
    for (int c = 0; c < vertex; c++) {

        // u is any vertex that is not yet included in
        // Dset and has minimum distance
        int u = minimumDist(dist, Dset);
        // If the vertex with minimum distance found
        // include it to Dset

        Dset[u] = true;
        // Update dist[v] if not in Dset and their is a path from src to v
        // through u that has distance minimum than current value of dist[v]
        for (int v = 0; v < vertex; v++) {
            if (!Dset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    cout << "Vertex\t\tDistance from source" << endl;
    // will print the vertex with their distance
    // from the source to the console
    for (int i = 0; i < vertex; i++) {
        char c = 65 + i;
        cout << c << "\t\t" << dist[i] << endl;
    }
}

// Main program
int main()
{
    int graph[vertex][vertex] = { 
        { 0, 5, 3, 0, 0, 0, 0 }, 
        { 0, 0, 2, 0, 3, 0, 1 }, 
        { 0, 0, 0, 7, 7, 0, 0 }, 
        { 2, 0, 0, 0, 0, 6, 0 }, 
        { 0, 0, 0, 2, 0, 1, 0 }, 
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 10, 0, 0 } 
    };
    
    dijkstra(graph, 0);
    
    return 0;
}