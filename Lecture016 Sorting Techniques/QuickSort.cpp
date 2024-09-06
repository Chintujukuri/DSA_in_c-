#include <bits/stdc++.h>
using namespace std;
// Best Case: O(n log n)
// Average Case: O(n log n)
// Worst Case : O(n^2)

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Pivot is the first element in the current subarray
    int i = low;
    int j = high;

    while (i < j)
    {
        // Move 'i' to the right while elements are less than or equal to the pivot
        while (arr[i] <= pivot && i <= high - 1)
            i++;

        // Move 'j' to the left while elements are greater than the pivot
        while (arr[j] > pivot && j >= low + 1)
            j--;

        // If 'i' is still to the left of 'j', swap them
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Swap the pivot element with the element at the 'j' position
    swap(arr[low], arr[j]);
    return j; // Return the partition index
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);  // Sort the left subarray
        quickSort(arr, pIndex + 1, high); // Sort the right subarray
    }
}

int main()
{
    vector<int> arr = {4, 2, 7, 6, 1, 8, 1, 3};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
