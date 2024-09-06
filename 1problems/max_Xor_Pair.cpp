#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *c[2];

    node()
    {
        this->c[0] = nullptr;
        this->c[1] = nullptr;
    }
};

void insert(node *root, int ele)
{
    for (int i = 30; i >= 0; i--)
    {
        int bit = ((ele >> i) & 1);
        if (root->c[bit] == nullptr)
            root->c[bit] = new node();
        root = root->c[bit];
    }
}
int search(node *root, int ele)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        int bit = ((ele >> i) & 1);
        if (root->c[!bit] != nullptr)
        {
            ans += (1 << i);
            root = root->c[!bit];
        }
        else
            root = root->c[bit];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        node *root = new node();
        for (int ele : arr)
            insert(root, ele);
            
        int ans = 0;
        for (auto ele : arr)
            ans = max(ans, search(root, ele));
        cout << ans << "\n";
    }
    return 0;
}

/*
Input
2
3
12 15 9
5
13 11 35 3 32

Output
6
46
*/