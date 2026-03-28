#include <iostream>
#include <algorithm>
using namespace std;
template <class t>

void insertion_sort(t data[], int n)
{
    for (size_t i = 1; i < n; i++)
    {
        t tmp = data[i];
        size_t j = i;
        for (; j > 0 && tmp < data[j - 1]; j--)
        {
            data[j] = data[j - 1];
        }
        data[j] = tmp;
    }
}
template <class t>
void selection_sort(t data[], int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        size_t least = i;

        for (size_t j = i + 1; j < n; j++)
        {
            if (data[j] < data[least])
            {
                least = j;
            }
        }

        if (least != i)
        {
            swap(data[i], data[least]);
        }
    }
}
template <class t>
void bubble_sort(t data[], int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

template <class T>
void shellsort(T data[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            T tmp = data[i];
            int j = i;

            for (; j >= gap && tmp < data[j - gap]; j -= gap)
            {
                data[j] = data[j - gap];
            }

            data[j] = tmp;
        }
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // اختيار أول عنصر كمحور
    int i = left;

    for (int j = left + 1; j <= right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[left]); // وضع المحور في مكانه الصحيح
    return i;                // إرجاع موقع المحور
}

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main()
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(arr, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubble_sort(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    shellsort(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, 6);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}