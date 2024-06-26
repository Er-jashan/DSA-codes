#include<iostream>
using namespace std;

// Assuming 'm' is a global variable or passed as a parameter to the function
int m;
int W[10]; // Weight array should be globally defined or passed as a parameter

// Function to find the subsets that sum up to 'm'
void sumOfSubset(int s, int k, int r, int X[]) {
    // Check if the current subset's sum is equal to 'm'
    if(s + W[k] == m) {
        X[k] = 1; // Include the current element in the subset
        for(int i = 0; i <= k; i++) {
            if(X[i] == 1) cout << W[i] << " "; // Print the subset
            // cout<<X[k]<<" ";
        }
        cout << endl;
        X[k] = 0; // Backtrack and set the current element's inclusion to false
    } else if (s + W[k] + W[k+1] <= m) { // Check if the next element can be included
        X[k] = 1; // Include the current element and move to the next
        sumOfSubset(s + W[k], k + 1, r - W[k], X);
    }
    if((s + r - W[k] >= m) && (s + W[k+1] <= m)) {
        X[k] = 0; // Exclude the current element and move to the next
        sumOfSubset(s, k + 1, r - W[k], X);
    }
    //  for(int i = 0; i <= k; i++) {
    //         if(W[i] == 1) cout<< "1 "; // Print the subset
    //         // cout<<X[k]<<" ";
    //     }
    // // cout<<"Path:";
    // for(int i=0;i<k;i++)
    // {
    //     cout<<X[k]<<" ";
    // }
}

int main() {
    int X[6] = {0}; // Array to keep track of included elements
    // Initialize 'm', 'W', and other necessary variables here
    m=30;
    // int n=6;

      W[0] = 5; W[1] = 10; W[2] = 12; W[3] = 13; W[4] = 15; W[5] = 18;
    // Call the function with initial values
    sumOfSubset(0, 0,73, X);
    return 0;
}
