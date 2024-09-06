#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
            {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (result.empty())
        cout << "No two elements sum up to the target." << endl;
    else
        cout << "The indices of the two elements that sum up to the target are: " << result[0] << " and " << result[1] << endl;

    return 0;
}