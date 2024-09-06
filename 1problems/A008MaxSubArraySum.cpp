#include <bits/stdc++.h>
using namespace std;

// int findMaxSum(vector<int> &arr, int n)
// {
//     int ans = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             ans = max(ans, sum);
//         }
//     }
//     return ans;
// }
// O(n2);

//kadanes algorothim O(n);
int findMaxSum(vector<int> &arr, int n)
{
    int max_sum = arr[0];
    int glo_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_sum = max(arr[i], max_sum + arr[i]);
        glo_sum = max(glo_sum, max_sum);
    }
    return glo_sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << findMaxSum(arr, n);
    return 0;
}