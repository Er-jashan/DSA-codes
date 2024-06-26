#include<iostream>
#include<cstring>
using namespace std;

int m; // Number of colors
int n; // Number of nodes in the graph
int G[10][10]; // Graph represented as an adjacency matrix

// Function to check if it's safe to color the vertex 'k' with color 'c'
bool isSafe(int k, int c, int x[]) {
    for(int i = 0; i < n; i++) {
        if(G[k][i] && c == x[i]) { // If adjacent vertex 'i' is colored with color 'c'
            return false;
        }
    }
    return true;
}

// Recursive function to solve graph coloring problem
void GColor(int k, int x[]) {
    if(k == n) { // All vertices are colored
        for(int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int c = 1; c <= m; c++) { // Try different colors for vertex 'k'
        if(isSafe(k, c, x)) {
            x[k] = c; // Color vertex 'k' with color 'c'
            GColor(k + 1, x); // Recur for the next vertex
            x[k] = 0; // Backtrack
        }
    }
}

int main() {
    int x[10] = {0}; // Array to store colors assigned to vertices
    // Initialize 'm', 'n', and graph 'G' here
    m=3;
    n=4;//possible ways to color the n nodes: n^m
     memset(G, 0, sizeof(G));
    // Add edges to the graph G
    G[0][1] = G[1][0] = 1;
    G[0][3] = G[3][0] = 1;
    G[1][2] = G[2][1] = 1;
    G[1][3] = G[3][1] = 1;
    G[2][3] = G[3][2] = 1;
    // Call the function with initial values
    GColor(0, x);
    return 0;
}
