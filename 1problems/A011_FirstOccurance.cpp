#include <bits/stdc++.h>
using namespace std;

// // O(n)
// int findFirst(vector<int> &arr, int ele)
// {
//     int size = arr.size();

//     for (int i = 0; i < size; i++)
//     {
//         if (ele == arr[i]) // Comparison using '=='
//             return i;
//     }
//     return -1;
// }

// When array is sorted O(log n)
int findFirstSorted(vector<int> &arr, int ele)
{
    int size = arr.size();
    int index = -1;

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (ele == arr[mid])
        {
            index = mid;
            right = mid - 1;
        }
        else if (ele < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return index;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 5, 6, 7};
    int ele;
    cout << "enter the ele: ";
    cin >> ele;

    int index = findFirstSorted(arr, ele);
    cout << "First occurrence of " << ele << " is at index " << index << endl;

    return 0;
}
