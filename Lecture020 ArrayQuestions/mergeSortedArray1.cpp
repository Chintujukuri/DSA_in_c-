#include <iostream>
#include <vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{

    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // copy first array k element ko
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    // copy kardo second array k remaining element ko
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{

    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[7] = {2, 4, 6, 10, 11, 14, 15};

    int arr3[12] = {0};

    merge(arr1, 5, arr2, 7, arr3);

    print(arr3, 12);

    return 0;
}