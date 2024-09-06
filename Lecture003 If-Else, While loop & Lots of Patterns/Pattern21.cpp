#include <iostream>
using namespace std;

int main() {
    /*
    Pattern 2
        *
        **
        ***
        ****
     */
    // Creating Scanner Object For taking inputs from the USER
    cout << "Enter Number of ROWS for the Pattern: ";
    int noOfRows;
    cin >> noOfRows;

    // Procedure to Print the Required Pattern
    for (int row = 1; row <= noOfRows; row++) {
        for (int column = 1; column <= row; column++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
