#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 0, 0, 1, 0};

    unordered_map<int, int> map;
    int size = arr.size();
    int prefix = 0, maxLen = 0;

    for (int i = 0; i < size; i++)
    {
        // Convert 0 to -1
        if (arr[i] == 0)
            arr[i] = -1;

        // Calculate prefix sum
        prefix += arr[i];

        // Check if prefix sum is 0
        if (prefix == 0)
            maxLen = i + 1;

        // Check if the prefix sum has been seen before
        if (map.find(prefix) != map.end())
            maxLen = max(maxLen, i - map[prefix]);
        else
            map[prefix] = i;
    }

    cout << "Maximum length of subarray with equal number of 0s and 1s: " << maxLen << endl;

    return 0;
}
