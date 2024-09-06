#include <bits/stdc++.h>
using namespace std;

// Definition of a trie node
class node
{
public:
    node *c[2]; // Two children nodes for 0 and 1
    node()
    {
        this->c[1] = nullptr; // Initialize child node for bit 1 to null
        this->c[0] = nullptr; // Initialize child node for bit 0 to null
    }
};

// Function to insert a number into the trie
void insert(node *root, int n)
{
    for (int i = 30; i >= 0; i--)
    {                             // Iterate through each bit from the 30th to 0th
        int bit = ((n >> i) & 1); // Extract the i-th bit of n
        if (root->c[bit] == nullptr)
            root->c[bit] = new node; // Create a new node if it doesn't exist
        root = root->c[bit];         // Move to the child node corresponding to the current bit
    }
}

// Function to perform XOR search in the trie
int search(node *root, int n)
{
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {                             // Iterate through each bit from the 30th to 0th
        int bit = ((n >> i) & 1); // Extract the i-th bit of n
        if (root->c[!bit] != nullptr)
        {                         // Check if the opposite bit exists in the trie
            ans = ans | (1 << i); // Set the corresponding bit in the answer
            root = root->c[!bit]; // Move to the child node of the opposite bit
        }
        else
        {
            root = root->c[bit]; // Move to the child node of the current bit
        }
    }
    return ans; // Return the maximum XOR value found
}

int main()
{
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int n;
        cin >> n; // Number of elements in the array
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i]; // Input array elements

        node *root = new node; // Create a new trie node as root
        insert(root, 0);       // Insert 0 into the trie initially
        int ans = 0;
        int xorSum = 0;
        for (int i = 0; i < n; i++)
        {
            xorSum = xorSum ^ arr[i];             // Update the XOR sum with the current element
            insert(root, xorSum);                 // Insert the updated XOR sum into the trie
            ans = max(ans, search(root, xorSum)); // Update the maximum XOR value found
        }

        cout << ans << "\n"; // Output the maximum XOR value for the current test case
    }
    return 0;
}
