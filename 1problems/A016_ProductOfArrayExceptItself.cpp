#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    int max_sum = arr[0];
    int global_sum = arr[0];

    for (int i = 0; i < n; i++)
    {
        max_sum = max(arr[i], max_sum + arr[i]);
        global_sum = max(global_sum, max_sum);
    }
    cout << global_sum;

    return 0;
}