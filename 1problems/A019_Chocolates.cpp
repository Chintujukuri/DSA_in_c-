// Given an array A[] of size N representing the number of chocolates in each packet and M students, distribute the packets such that each student gets exactly one packet, and the difference between the maximum and minimum chocolates distributed is minimized.

#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int A[], int N, int M)
{
    // Base cases
    if (M == 0 || N == 0)
        return 0;
    if (N < M)
        return -1; // More students than packets

    // Sort the array (Time Complexity: O(N*log(N)))
    sort(A, A + N);

    // Initialize the minimum difference as a large value
    int min_diff = INT_MAX;

    // Traverse the array to find the minimum difference
    // (Time Complexity: O(N))
    for (int i = 0; i + M - 1 < N; i++)
    {
        int diff = A[i + M - 1] - A[i];
        min_diff = min(min_diff, diff);
    }

    return min_diff;
}

int main()
{
    // Example 1
    int A1[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int N1 = sizeof(A1) / sizeof(A1[0]);
    int M1 = 5;
    cout << "Minimum difference is " << findMinDiff(A1, N1, M1) << endl;

    return 0;
}
