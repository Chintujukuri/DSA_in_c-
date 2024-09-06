#include <bits/stdc++.h>
using namespace std;
//only works when all are positives
//worst O(2n) O(1);

int main()
{
    vector<int> arr = {3, 1, 2, 1, 1, 1, 5}; // Example array
    int k = 5;                               // Target sum
    int n = arr.size();

    int sum = arr[0];
    int maxLen = 0;
    int left = 0, right = 0;

    while (right < n)
    {
        // Shrink the window from the left if the sum exceeds k
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // If the current sum equals k, update maxLen
        if (sum == k)
            maxLen = max(maxLen, right - left + 1);

        // Move the right pointer to the right to expand the window
        right++;
        if (right < n)
            sum += arr[right];
    }

    cout << "The length of the longest subarray with sum " << k << " is: " << maxLen << endl;
    return 0;
}
