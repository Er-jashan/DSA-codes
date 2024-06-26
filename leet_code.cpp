#include <iostream>
using namespace std;

void sum(int nums[], int target, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                cout << " indeces whose sum is equal to target integer is:" << i
                     << " " << j;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int nums[size];
    cout << "Enter the elements:";
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target element:";
    cin >> target;
    sum(nums, target, size);
    return 0;
}