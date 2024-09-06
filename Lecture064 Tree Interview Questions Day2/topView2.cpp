#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the binary tree
class node
{
public:
    int data;    // Value stored in the node
    node *left;  // Pointer to the left child
    node *right; // Pointer to the right child

    // Constructor to initialize a new node
    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to insert a new node into the binary tree
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

// Helper function to compute the top view of the binary tree
void topView(node *root, int hd, int lvl, map<int, pair<int, int>> &m)
{
    if (root == nullptr)
        return;

    // If the horizontal distance is not in the map, or if the current level is less than the stored level
    if (m.find(hd) == m.end() || m[hd].first > lvl)
    {
        m[hd] = {lvl, root->data};
    }

    // Recur for the left subtree with horizontal distance decreased by 1 and level increased by 1
    topView(root->left, hd - 1, lvl + 1, m);

    // Recur for the right subtree with horizontal distance increased by 1 and level increased by 1
    topView(root->right, hd + 1, lvl + 1, m);
}

// Function to print the top view of the binary tree
void printTopView(node *root)
{
    if (root == nullptr)
        return;

    // Map to store the nodes at each horizontal distance
    map<int, pair<int, int>> m;
    topView(root, 0, 0, m);

    // Print the top view nodes
    for (auto i : m)
    {
        cout << i.second.second << " ";
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

        printTopView(root); 
        cout << "\n";       
    }
    return 0;
}
