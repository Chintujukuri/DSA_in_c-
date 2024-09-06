#include <bits/stdc++.h>
using namespace std;

// Definition of a tree node
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

// Function to insert a node into the Binary Search Tree (BST)
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

// Function to perform the vertical order traversal of the BST
void verticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
    if (root == nullptr)
        return;

    // Traverse the left subtree
    verticalOrder(root->left, hd - 1, m);

    // Store the current node's data in the map
    m[hd].push_back(root->data);

    // Traverse the right subtree
    verticalOrder(root->right, hd + 1, m);
}

// Function to print the vertical order traversal
void printVertical(node *root)
{
    if (root == nullptr)
        return;

    // Map to store nodes at each horizontal distance
    map<int, vector<int>> m;

    // Perform the vertical order traversal
    verticalOrder(root, 0, m);

    // Print the nodes in vertical order
    for (auto i : m)
    {
        for (auto data : i.second)
        {
            cout << data << " ";
        }
        cout << "\n";
    }
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

        printVertical(root);
        cout << "\n";
    }
    return 0;
}


    //    3
    //   /   \
    //  1     5
    //   \    /
    //    2  4

    //     1

    //     2 3 4

    //     5
