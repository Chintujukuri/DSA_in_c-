#include <bits/stdc++.h>
using namespace std;
// // only for the positive numbers: O(n),O(1)
// int smallestMissingPositive(vector<int> &arr)
// {
//     int size = arr.size();

//     // Place each number in its right place if possible
//     for (int i = 0; i < size; i++)
//     {
//         while (arr[i] > 0 && arr[i] <= size && arr[i] != arr[arr[i] - 1])
//             swap(arr[i], arr[arr[i] - 1]);
//     }
//     // Find the first index which doesn't have the correct number
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] != i + 1)
//             return i + 1;
//     }
//     // If all numbers are in the correct place, return size + 1
//     return size + 1;
// }

// Time Complexity:
// Sorting the array: O(n log n).
// Binary search: O(log n).
// Overall Time Complexity: O(n log n). The sorting step is the dominant factor.
int smallestMissingPositive(vector<int> &arr)
{
    int size = arr.size();
    // Sort the array to prepare for binary search
    sort(arr.begin(), arr.end());
    // Initialize the binary search bounds
    int left = 0, right = size - 1;
    while (left <= right)
    {
        // Calculate mid to avoid overflow
        int mid = left + (right - left) / 2;
        // If the element at mid is in the correct position (1-based index)
        if (arr[mid] == mid + 1)
            // Move the search to the right half
            left = mid + 1;
        else
            // Otherwise, move the search to the left half
            right = mid - 1;
    }
    // The smallest missing positive integer is at position left + 1
    return left + 1;
}

int main()
{
    vector<int> arr = {-3, -2, 4, 5, 2, 3};
    int missing = smallestMissingPositive(arr);
    cout << "The smallest missing positive integer is: " << missing << endl;
    return 0;
}
