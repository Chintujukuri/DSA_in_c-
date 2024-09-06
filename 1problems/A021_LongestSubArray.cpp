#include <bits/stdc++.h>
using namespace std;
// optimal solution for +ve,-ve array
class Solution
{
public:
    // Efficient method to find the longest subarray with sum k
    //worst is n2 if collion occour
    int longestSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int prefixSum = 0;
        int maxLen = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            prefixSum = prefixSum + arr[i];
            if (prefixSum == k)
                maxLen = i + 1;

            if (umap.find(prefixSum - k) != umap.end())
            {
                maxLen = max(maxLen, i - umap[prefixSum - k]);
            }
            // Only store the first occurrence of prefixSum in the map
            // if we have zeros it changes the index
            if (umap.find(prefixSum) == umap.end())
            {
                umap[prefixSum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 2, 4, 3, 2, 4, 1, 2};
    int k = 6;

    // Using the efficient method to find the longest subarray with sum k
    int maxLength = sol.longestSubarraySum(arr, k);
    cout << "The length of the longest subarray with sum " << k << " is: " << maxLength << endl;

    return 0;
}
