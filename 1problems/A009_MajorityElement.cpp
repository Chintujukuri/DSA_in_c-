#include <bits/stdc++.h>
using namespace std;
// //Time Complexity: 𝑂(𝑛)::Space Complexity: 𝑂(𝑛)
// int majorityElement(vector<int> &nums)
// {
//     int n = nums.size();
//     unordered_map<int, int> map;
//     for (int i = 0; i < n; i++)
//         map[nums[i]]++;
//     for (pair<int, int> pair : map)
//     {
//         if (pair.second > n / 2)
//             return pair.first;
//     }
//     return -1;
// }

// //O(nlogn)
// int majorityElement(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     return nums[n / 2];
// }

// Time Complexity: 𝑂(𝑛)::Space Complexity: 𝑂(1)
// implementing moores voting alogorithm:
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int candidate = 0;

    // Finding the candidate for majority element
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
            count++;
        else
            count--;
    }

    // Verifying the candidate
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate)
            count++;
    }
    if (count > n / 2)
        return candidate;
    else
        return -1;
}

int main()
{
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4, 4};
    int result = majorityElement(nums);
    if (result != -1)
        cout << "Majority element is: " << result << endl;
    else
        cout << "No majority element found." << endl;
    return 0;
}
