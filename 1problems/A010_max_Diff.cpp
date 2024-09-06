//find the maximum difference between the two elements such that largerelement comes after the smaller element
#include <bits/stdc++.h>
using namespace std;
// int findMaxDiff(vector<int> &arr)
// {
//     int ans = INT_MIN;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             if (arr[i] < arr[j])
//             {
//                 ans = max(ans, (arr[j] - arr[i]));
//             }
//         }
//     }
//     return ans;
// }

//O(N);
int findMaxDiff(vector<int> &arr)
{
    int maxDiff=0;
    int n = arr.size();
    int minEle=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-minEle>maxDiff)
            maxDiff=arr[i]-minEle;
        if(minEle>arr[i])
            minEle=arr[i];
    }
    return maxDiff;
}

    int main()
{
    vector<int> arr = {9, 2, 1, 9, 4, 10};
    cout << findMaxDiff(arr);
    return 0;
}