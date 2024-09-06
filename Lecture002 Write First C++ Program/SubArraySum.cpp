#include <bits/stdc++.h>
using namespace std;

// bool subArray(vector<int> &arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == 0)
//                 return true;
//         }
//     }
//     return false;
// }

// in prefixsum if a number repeat that means sumof subset exist a zero o(n);
bool subArray(vector<int> &arr, int n)
{
    unordered_set<int> set;
    int preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == 0 || set.find(preSum) != set.end())
            return true;
        set.insert(preSum);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << (subArray(arr, n) ? "true" : "false") << endl;
}