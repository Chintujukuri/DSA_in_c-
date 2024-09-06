#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> prettyPrint(int A) {
    // Calculate the size of the matrix
    int size = 2 * A - 1;
    
    // Create an empty matrix filled with zeros
    vector<vector<int>> result(size, vector<int>(size, 0));
    
    // Fill the matrix layer by layer
    for (int i = 0; i < A; ++i) {
        for (int j = i; j < size - i; ++j) {
            result[i][j] = A - i;
            result[j][i] = A - i;
            result[size - i - 1][j] = A - i;
            result[j][size - i - 1] = A - i;
        }
    }
    
    return result;
}

int main() {
    int A = 4; 
    vector<vector<int>> result = prettyPrint(A);
    for(auto &row: result)
    {
        for(int val: row)
            cout<<val<<" ";
        cout<<"\n";
    }
    
    return 0;
}
