#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Important Points about Selection Sort:

1. **Algorithm Explanation**:
   - Selection sort is an in-place comparison-based sorting algorithm.
   - It divides the input array into two parts: the subarray of items already sorted, which is built up from left to right at the front (left) of the array, and the subarray of items remaining to be sorted that occupy the rest of the array.
   - Initially, the sorted subarray is empty, and the unsorted subarray is the entire input array.

2. **Time Complexity**:
   - The time complexity of selection sort is O(n^2) in all cases (worst, average, and best) because it involves two nested loops.

3. **Space Complexity**:
   - The space complexity of selection sort is O(1) because it is an in-place sorting algorithm that requires no additional storage space.


*/
