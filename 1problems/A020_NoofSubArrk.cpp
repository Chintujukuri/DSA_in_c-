#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), Space Complexity : O(n)
    int subarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp; // Map to store prefix sums
        int prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i]; // Calculate prefix sum

            // If the prefix sum equals k, it means we found a subarray
            if (prefixSum == k)
                ans++;

            // Check if (prefixSum - k) exists in the map
            if (mp.find(prefixSum - k) != mp.end())
                ans += mp[prefixSum - k];

            // Update the map with the current prefix sum
            mp[prefixSum]++;
        }

        return ans;
    }

    // Time Complexity: O(n), Space Complexity : O(1)
    int broteForce(vector<int> &arr, int k)
    {
        int n = arr.size();
        int cnt = 0;

        // Check all possible subarrays
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == k)
                    cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 2, 1, 1};
    int k = 6;

    // Using the efficient method
    int result = sol.subarraySum(arr, k);
    cout << "The number of subarrays with sum " << k << " using efficient method is: " << result << endl;

    // Using the brute force method
    int bruteForceResult = sol.broteForce(arr, k);
    cout << "The number of subarrays with sum " << k << " using brute force method is: " << bruteForceResult << endl;

    return 0;
}
