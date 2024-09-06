#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // Place the temp value at its correct position
        arr[j + 1] = temp;
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

    insertionSort(n, arr);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Important Points about Insertion Sort:

1. **Algorithm Explanation**:
   - Insertion sort is a simple and intuitive comparison-based sorting algorithm.
   - It builds the sorted array one element at a time by repeatedly picking the next element and inserting it into its correct position in the already sorted part of the array.

3. **Time Complexity**:
   - The time complexity of insertion sort is O(n^2) in the worst and average cases due to the nested loops. However, it performs well for small or nearly sorted datasets with a time complexity of O(n) in the best case (when the array is already sorted).

4. **Space Complexity**:
   - The space complexity of insertion sort is O(1) as it is an in-place sorting algorithm that requires no additional storage space.



7. **Adaptive**:
   - Insertion sort is adaptive, meaning it takes advantage of existing order in the input array. The more sorted the array is initially, the fewer operations it performs.

8. **Simple Implementation**:
   - Insertion sort is simple to implement and understand, making it a good choice for educational purposes and for sorting small datasets.

9. **Applications**:
   - Insertion sort is used in practice for small arrays (usually fewer than 10-20 elements), as the overhead of more complex algorithms does not pay off for small sorting tasks.
   - It is also used as a subroutine in more advanced sorting algorithms like quicksort and shellsort.
*/
