
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i, bool isMaxHeap)
{
    int extreme = i; // largest or smallest
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap)
    {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    else
    {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i)
    {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}

void heapSort(vector<int> &arr, bool increasing)
{
    int n = arr.size();

    bool isMaxHeap = increasing; // ascending → max heap, descending → min heap

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // Extract elements
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "1. Increasing order\n2. Decreasing order\nChoose: ";
    int choice;
    cin >> choice;

    heapSort(arr, choice == 1);

    cout << "Sorted output: ";
    for (int x : arr)
        cout << x << " ";
}
