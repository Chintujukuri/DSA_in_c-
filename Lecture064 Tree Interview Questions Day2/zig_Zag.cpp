#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the binary search tree
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

// Function to insert a node in the binary search tree
node *insertBt(node *root, int data)
{
    if (root == nullptr)
    {
        // If the tree is empty, create a new node
        root = new node(data);
        return root;
    }

    // Insert the data in the correct position in the BST
    if (data < root->data)
        root->left = insertBt(root->left, data);
    else if (data > root->data)
        root->right = insertBt(root->right, data);

    return root;
}

// Function to perform Zig-Zag Level Order traversal of the BST
void zigZag(node *root)
{
    vector<int> result;
    queue<node *> q;
    q.push(root);             // Start with the root node
    bool leftToRight = false; // Start traversal from right to left
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size); // Vector to store the current level's nodes
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            // Determine the position to insert the node's data based on the traversal direction
            int index = leftToRight ? i : size - i - 1;
            ans[index] = temp->data;
            // Push the children of the current node to the queue
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        leftToRight = !leftToRight; // Alternate the traversal direction
        // Append the current level's nodes to the result
        for (int i : ans)
            result.push_back(i);
    }

    // Print the result of the Zig-Zag Level Order traversal
    for (int i : result)
        cout << i << " ";
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        int n;
        cin >> n; 
        node *root = nullptr;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;                 // Read the data of each node
            root = insertBt(root, data); // Insert the data into the BST
        }
        zigZag(root); 
        cout << "\n"; 
    }
    return 0;
}
