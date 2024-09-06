// find a pair of integers in an array arr that sum up to a given value sum

//  #include<bits/stdc++.h>
//  using namespace std;

// int main()
// {
//     int n,sum;
//     cin>>n>>sum;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]+arr[j]==sum)
//                 cout<<arr[i]<<" "<<arr[j];
//         }
//     }
//     return 0;
// } n2 complexity.

// 5 14
// 3 6 1 2 8
// 6 8

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, sum;
//     cin >> n >> sum;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     sort(arr.begin(),arr.end());
//     int p1=0;
//     int p2=n-1;
//     while(p1<p2)
//     {
//         if(arr[p1]+arr[p2]==sum)
//         {
//             cout<<arr[p1]<<" "<<arr[p2];
//             break;
//         }
//         else if (arr[p1] + arr[p2]>sum)
//             p2--;
//         else
//             p1++;
//     }
//     return 0;
// }
// complexity: nlogn it uses intrasor(combination of quicksort,heapsort,insertionsort)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
        set.insert(arr[i]);
        int complement=sum-arr[i];
        if(set.find(complement)!=set.end())
        {
            cout<<complement<<" "<<arr[i];
            break;
        }
    }
    return 0;
}
//o(n);