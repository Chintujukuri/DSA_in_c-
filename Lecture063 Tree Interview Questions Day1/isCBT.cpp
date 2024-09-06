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
    if (data < root->data)
        root->left = insertBt(root->left, data);
    else if (data > root->data)
        root->right = insertBt(root->right, data);

    return root;
}
bool isCBT(node *root)
{
    if (root == nullptr)
        return true;
    queue<node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (flag)
                return false;
            q.push(temp->left);
        }
        else
            flag = true;
        if (temp->right)
        {
            if (flag)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;
    }
    return true;
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
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

        if (isCBT(root))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}