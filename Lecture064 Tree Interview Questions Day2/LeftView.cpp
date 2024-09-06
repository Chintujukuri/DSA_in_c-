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

queue<node *> q;
void leftView(node *root, vector<int> &ans, int level)
{
    if (root == nullptr)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    leftView(root->left, ans, level + 1);
    leftView(root->right, ans, level + 1);
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
        leftView(root, ans, level);
        for (int i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/* using leftView
queue<node*> q;
void leftView(node* root)
{
    if(root==nullptr) return;
    q.push(root);
    bool printNext=true;

    q.push(nullptr);
    while(!q.empty())
    {
        node* N=q.front();
        q.pop();
        if(N==nullptr)
        {
            if(!q.empty())
            {
                q.push(N);
                printNext=true;
            }
        }
        else
        {
            if(printNext)
            {
                cout<<(N->data)<<" ";
                printNext=false;
            }
            if(N->left)
                q.push(N->left);
            if(N->right)
                q.push(N->right);

        }

    }
}
*/