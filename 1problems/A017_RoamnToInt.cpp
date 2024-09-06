#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
// O(n)
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> map;

        // Map Roman numerals to their integer values
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // Check if the current value is less than the next value
            if (i < n - 1 && map[s[i]] < map[s[i + 1]])
            {
                ans -= map[s[i]]; // Subtract if the current value is less
            }
            else
            {
                ans += map[s[i]]; // Add otherwise
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string roman;

    cout << "Enter a Roman numeral: ";
    cin >> roman;

    int integerValue = solution.romanToInt(roman);
    cout << "The integer value is: " << integerValue << endl;

    return 0;
}