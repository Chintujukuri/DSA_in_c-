#include <vector>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        // For round 1 to n-1
        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {
            // Process element till n-i th index
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            // Already sorted then it become o(n);
            break;
        }
    }
}

void bubbleSortFromEnd(vector<int> &arr, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        // For round n-1 to 1
        bool swapped = false;

        for (int j = n - 1; j > n - 1 - i; j--)
        {
            // Process element till n-i th index from the end
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            // Already sorted
            break;
        }
    }
}
