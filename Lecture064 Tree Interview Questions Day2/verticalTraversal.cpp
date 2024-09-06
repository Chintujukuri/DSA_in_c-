#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a node in the BST
Node *insertBt(Node *root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insertBt(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertBt(root->right, data);
    }
    return root;
}

class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<vector<int>> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();
            Node *frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto i : nodes)
        {
            vector<int> col;
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *root = nullptr;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            root = insertBt(root, data);
        }

        Solution obj;
        vector<vector<int>> res = obj.verticalOrder(root);
        for (auto v : res)
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
