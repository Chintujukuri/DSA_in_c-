#include <bits/stdc++.h>
using namespace std;

bool findEquilibriumIndex(vector<int> &arr, int n) {
    if (n == 1) return false; 
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    for (int i = 1; i < n - 1; i++) {
        if (prefixSum[i - 1] == (prefixSum[n - 1] - prefixSum[i]))
            return true;
    }
    return false;
}

int main() {
    int n;
    cout<<"enter no.of lelements: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (findEquilibriumIndex(arr, n))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
