#include <iostream>
using namespace std;

int main() {
    /*
    Pattern 1
        *******
        *******
        *******
     */
    // Creating input stream for taking inputs from the user
    cout << "Enter Number of ROWS and COLUMNS for the Pattern: ";
    int noOfRows, noOfColumns;
    cin >> noOfRows >> noOfColumns;

    // Procedure to Print the Required Pattern
    for (int row = 1; row <= noOfRows; row++) {
        for (int column = 1; column <= noOfColumns; column++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
