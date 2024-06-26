#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r, int size) // 2 3 4 5 6
{
    int i = l;     // i=l=0
    int j = m + 1; // m=0+5/2=2:: j=2+1=3
    int k = l;     // k=0

    int temp[size];
    while (i <= m && j <= r) // 0<=2 && 3<=4//1<=2 && 4<=4
    {
        if (a[i] <= a[j]) // 2<=5//3<=6
        {
            temp[k] = a[i]; // temp[0]=a[0]==temp[0]=2
            i++;            // temp[1]=3
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    // store the elements in original array:-
    for (int p = l; p <= r; p++)
    {
        a[p] = temp[p];
    }
}

void mergeSort(int a[], int l, int r, int size)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        //  recursive call
        mergeSort(a, l, m, size);
        mergeSort(a, m + 1, r, size);
        merge(a, l, m, r, size);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array:";
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Sorted list :";
    mergeSort(a, 0, size - 1, size);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}