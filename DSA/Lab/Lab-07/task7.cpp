// A hospital maintains numeric patient record IDs and needs to arrange them in ascending order to
// simplify record retrieval. Write a C++ program that implements Radix Sort for the given IDs. Your
// solution must handle numbers with different numbers of digits and display the array after every pass.
// arr[] = {91, 8, 1024, 56, 305, 7, 120}

#include <iostream>
using namespace std;

#define CAPACITY 10
static int pass = 0;

void countSort(int arr[], int n, int exp)
{
    int output[CAPACITY];
    int count[10] = {0};
    pass++;
    // frequency for each count
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // cumulative frequency count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "Output array after pass " << pass << ": ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        cout << arr[i] << " ";
    }
    cout << endl;
}
void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}
int main()
{
    int arr[CAPACITY];
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > CAPACITY)
    {
        cout << "Invalid number of elements.";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    radixSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
