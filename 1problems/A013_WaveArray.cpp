/*
A wave array is a specific arrangement of elements in an array where the elements appear in a wave-like pattern. For an array to be considered a "wave array," the elements must satisfy the following condition:

For even indices (i.e., arr[0], arr[2], arr[4], ...), the element should be greater than or equal to its neighboring elements.
For odd indices (i.e., arr[1], arr[3], arr[5], ...), the element should be less than or equal to its neighboring elements.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {20, 10, 8, 6, 4, 2};

    int size = arr.size();

    // Sorting the array
    sort(arr.begin(), arr.end()); // Time Complexity: O(n log n)

    // Swapping adjacent elements
    for (int i = 0; i < size; i += 2) // Time Complexity: O(n/2)
        swap(arr[i], arr[i + 1]);

    // Outputting the array
    for (int i = 0; i < size; i++) // Time Complexity: O(n)
        cout << arr[i] << " ";

    return 0;
}
