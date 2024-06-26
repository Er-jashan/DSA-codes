#include <iostream>
#include <vector>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Structure to store the solution path
struct Item {
    int value;
    int weight;
    bool chosen;
};

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<Item>& items, int n, vector<int>& path, vector<int>& tempPath) {
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if (items[n - 1].weight > W)
        return knapsack(W, items, n - 1, path, tempPath);

    // Calculate value when nth item is included or not included
    int included = items[n - 1].value + knapsack(W - items[n - 1].weight, items, n - 1, tempPath, tempPath);
    int notIncluded = knapsack(W, items, n - 1, path, tempPath);

    // Choose the maximum of including or not including the nth item
    if (included > notIncluded) {
        tempPath[n - 1] = 1; // Mark as chosen
        if (n == items.size()) { // Only update the path at the top level call
            path = tempPath;
        }
        return included;
    } else {
        tempPath[n - 1] = 0; // Mark as not chosen
        return notIncluded;
    }
}

int main() {
    vector<Item> items = {
        {10, 2, false},
        {10, 4, false},
        {12, 6, false},
        {18, 9, false}
    };
    int W = 15;
    int n = items.size();
    vector<int> path(n, 0); // Initialize path with 0s
    vector<int> tempPath(n, 0); // Temporary path for tracking

    cout << "Maximum value in a knapsack of capacity " << W << " is "
         << knapsack(W, items, n, path, tempPath) << endl;

    // Print the path
    cout << "Items included (0/1 form): ";
    for (int i = 0; i < n; ++i) {
        cout << tempPath[i] << " ";
    }
    cout << endl;

    return 0;
}
