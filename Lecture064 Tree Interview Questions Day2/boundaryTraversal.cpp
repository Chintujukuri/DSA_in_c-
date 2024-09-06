#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to traverse the left boundary of the tree (excluding leaf nodes)
void traverseLeft(Node *root, vector<int> &ans)
{
    // Base case: if the current node is NULL or a leaf node, return
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    // Add the current node's data to the result
    ans.push_back(root->data);

    // Recursively traverse the left subtree if it exists, otherwise the right subtree
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

// Function to traverse all the leaf nodes of the tree
void traverseLeaf(Node *root, vector<int> &ans)
{
    // Base case: if the current node is NULL, return
    if (root == NULL)
        return;

    // If the current node is a leaf node, add its data to the result
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // Recursively traverse the left and right subtrees
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Function to traverse the right boundary of the tree (excluding leaf nodes)
void traverseRight(Node *root, vector<int> &ans)
{
    // Base case: if the current node is NULL or a leaf node, return
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    // Recursively traverse the right subtree if it exists, otherwise the left subtree
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // Add the current node's data to the result after returning from the recursion
    ans.push_back(root->data);
}

// Function to get the boundary traversal of the binary tree
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // Add the root node's data to the result
    ans.push_back(root->data);

    // Traverse the left boundary (excluding the root and leaf nodes)
    traverseLeft(root->left, ans);

    // Traverse all the leaf nodes
    // Left subtree
    traverseLeaf(root->left, ans);
    // Right subtree
    traverseLeaf(root->right, ans);

    // Traverse the right boundary (excluding the root and leaf nodes)
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    // Create a sample tree:
    //        20
    //       /  \
    //      8   22
    //     / \    \
    //    4  12   25
    //      /  \
    //     10  14
    // 20 8 4 10 14 25 22,.

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    // Get the boundary traversal
    vector<int> result = boundary(root);

    // Print the boundary traversal
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
