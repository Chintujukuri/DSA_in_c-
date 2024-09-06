#include <iostream>
using namespace std;
int countTrailingZeros(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 5;
        count += n;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of trailing zeros in "
         << n << "! is " << countTrailingZeros(n) << "\n";
    return 0;
}
