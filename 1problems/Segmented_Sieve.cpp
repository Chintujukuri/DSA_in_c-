#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void simpleSieve(int limit, vector<int> &primes)
{
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= limit; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }
    for (int p = 2; p <= limit; p++)
    {
        if (isPrime[p])
            primes.push_back(p);
    }
}

void segmentedSieve(int m, int n)
{
    // Limit for initial sieve
    int limit = floor(sqrt(n)) + 1;
    vector<int> primes;
    simpleSieve(limit, primes);

    // Initialize boolean array for the range [m, n]
    vector<bool> isPrime(n - m + 1, true);
    if (m == 1)
        isPrime[0] = false; // 1 is not prime

    // Mark non-prime numbers in the range [m, n] using primes found up to 'limit'
    for (int currentPrime : primes)
    {
        // Find the minimum number in the [m, n] range that is a multiple of currentPrime
        int base = (m / currentPrime) * currentPrime;
        if (base < m)
            base += currentPrime;
        // Ensure base is within the range [m, n] and mark multiples of currentPrime
        for (int j = base; j <= n; j += currentPrime)
        {
            if (j != currentPrime) // Ensure we do not mark the prime number itself
                isPrime[j - m] = false;
        }
    }

    // Output all prime numbers in the range [m, n]
    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
        {
            cout << (m + i) << "\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;

    // Read all test cases
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        segmentedSieve(m, n);
        if (t > 0)
            cout << "\n"; // Separate test cases with a blank line
    }

    return 0;
}
