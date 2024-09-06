#include <bits/stdc++.h>
using namespace std;
// o(n3);
//  int main()
//  {
//      int n, sum;
//      cin >> n >> sum;
//      vector<int> arr(n);
//      for (int i = 0; i < n; i++)
//          cin >> arr[i];
//      for (int i = 0; i < n-2; i++)
//      {
//          for (int j = i + 1; j < n-1; j++)
//          {
//              for(int k=j+1;k<n;k++)
//              {
//                  if(arr[i]+arr[j]+arr[k]==sum)
//                  {
//                      cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
//                      break;
//                  }

//             }
//         }
//     }
//     return 0;
// }

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int p1 = i + 1;
        int p2 = n - 1;

        while (p1 < p2)
        {
            int c_sum = arr[i] + arr[p1] + arr[p2];
            if (c_sum == sum)
            {
                cout<<arr[i]<<" "<<arr[p1]<<" "<<arr[p2];
                break;
            }
            else if(c_sum<sum)
                p1++;
            else p2++;
        }
    }
    return 0;
}

// O(nlogn)+O(n)×O(n)=O(nlogn)+O(n2)=O(n2)
