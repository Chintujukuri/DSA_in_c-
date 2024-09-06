#include <bits/stdc++.h>
using namespace std;

void mergeF(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);
    int idx = 0, p1 = low, p2 = mid + 1;
    while (p1 <= mid && p2 <= high)
    {
        if (arr[p1] <= arr[p2])
        {
            temp[idx] = arr[p1];
            idx++;
            p1++;
        }
        else
        {
            temp[idx++] = arr[p2++];
        }
    }
    while (p1 <= mid)
        temp[idx++] = arr[p1++];
    while (p2 <= high)
        temp[idx++] = arr[p2++];

    // Copy sorted elements back to original array
    for (int i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeF(arr, low, mid, high);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
Important Points about Merge Sort:

1. **Divide and Conquer Algorithm**: Merge sort is a classic example of the divide and conquer strategy. It divides the array into two halves, recursively sorts them, and then merges the sorted halves.

2. **Stable Sort**: Merge sort is a stable sort, meaning that it preserves the relative order of equal elements.

3. **Time Complexity**: Merge sort has a consistent time complexity of O(n log n) for all cases (worst, average, and best). This is due to the divide and conquer method which divides the array and merges them in logarithmic steps.

4. **Space Complexity**: Merge sort requires O(n) extra space for the temporary arrays used during the merge process. This makes it less memory efficient compared to in-place sorting algorithms like quicksort.

5. **Non-Adaptive**: Merge sort does not adapt to the input data. It always performs O(n log n) operations even if the array is already sorted or has few elements out of order.

6. **Sequential Access**: It accesses data in a sequential manner, making it suitable for linked lists and external sorting (sorting large data sets that do not fit into memory).

7. **Not In-Place**: Merge sort is not an in-place sorting algorithm since it requires additional space proportional to the size of the array being sorted.

8. **Applications**: Merge sort is used in various applications such as sorting linked lists, large datasets, and in algorithms that require stable sorting as a subroutine.

9. **Comparison-Based**: Merge sort is a comparison-based sorting algorithm, meaning it sorts elements by comparing them with each other.
*/