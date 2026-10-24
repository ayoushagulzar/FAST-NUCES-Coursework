// A digital library stores books using numeric accession numbers. During a database migration,
// the accession numbers must be sorted in ascending order, and repeated numbers must remain in their
// original relative order. The input sequence is {7314, 314, 731, 34, 3147, 147, 47, 7314, 4,
// 314}.Design a Radix Sort solution that sorts these accession numbers without using comparison-
// based sorting algorithms. Determine the maximum number of digit passes required, show the array
// after every pass.

#include<iostream>
using namespace std;

#define CAPACITY 50
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

    cout << endl;
    cout << "\nOutput array after pass " << pass << ": ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        cout << arr[i] << " ";
    }
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

    cout << "\n\nFinal Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal number of passes: " << pass << endl;
    return 0;
}
