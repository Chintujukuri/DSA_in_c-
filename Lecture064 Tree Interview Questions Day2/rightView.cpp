#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *insertBt(node *root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
        root->right = insertBt(root->right, data);
    else if (data < root->data)
        root->left = insertBt(root->left, data);
    return root;
}

queue<node *> q;
void rightView(node *root, vector<int> &ans, int level)
{
    if (root == nullptr)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    rightView(root->right, ans, level + 1);
    rightView(root->left, ans, level + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *root = nullptr;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            root = insertBt(root, data);
        }
        vector<int> ans;
        int level = 0;
        rightView(root, ans, level);
        for (int i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}