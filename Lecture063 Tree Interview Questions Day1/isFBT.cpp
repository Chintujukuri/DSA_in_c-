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

bool isFBT(node *root)
{

    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    if (root->left != nullptr && root->right != nullptr)
        return isFBT(root->left) && isFBT(root->right);
    return false;
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

        if (isFBT(root))
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}