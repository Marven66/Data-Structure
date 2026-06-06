#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// recursive one
void shellSortRecursive(int arr[], int n, int gap)
{
    if (gap == 0)
        return;

    for (int i = gap; i < n; i++)
    {
        int temp = arr[i];
        int j;

        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            arr[j] = arr[j - gap];

        arr[j] = temp;
    }

    shellSortRecursive(arr, n, gap / 2);
}

void shellSortrec(int arr[], int n)
{
    shellSortRecursive(arr, n, n / 2);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    print(arr, n);

    int arr2[] = {12, 324, 54, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    shellSort(arr2, n2);
    for (int x : arr2)
        cout << x << " ";

    return 0;
}
