// A logistics company stores numeric tracking IDs for parcels arriving at its distribution center. Before
// parcels are dispatched, the system must arrange the tracking IDs in ascending order using LSD Radix Sort.
// Write a complete C++ implementation of Radix Sort using a stable Counting Sort as the subroutine. Display
// the original array, the frequency count array, the cumulative count array, and the output array during every
// pass. After each pass, show how the output array is copied back to the original array. Your solution must
// handle duplicate tracking IDs correctly, determine the total number of digit passes dynamically using the
// maximum value.
// trackingIDs[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100}

#include <iostream>
using namespace std;

#define CAPACITY 50
static int pass = 0;

void countSort(int arr[], int n, int exp)
{
    int output[CAPACITY];
    int count[10] = {0};
    pass++;
    cout << "\n\n ------------ Pass " << pass << " -------------" << endl;
    // frequency for each count
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    cout << "Frequency count array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    // cumulative frequency count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    cout << "Cumulative count array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "Output array: ";
    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    cout << "Original array after copy back: ";
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

    cout << "\n\nFinal Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nTotal number of passes: " << pass << endl;
    return 0;
}
