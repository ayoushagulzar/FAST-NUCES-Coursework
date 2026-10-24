// A university wants to sort student marks in ascending order using Quick Sort.
// Always select the last element of the current subarray as the pivot.
// Input: {40, 20, 70, 10, 60, 30, 50}
// Requirements:
//     1. Implement recursive quickSort() and a separate partition().
//     2. Always choose the last element as pivot.
//     3. Display the pivot and subarray boundaries for every partition call.
//     4. Display the array after every partition completes.
//     5. Count partition operations.

#include <iostream>
using namespace std;

#define CAPACITY 10

static int partitionCount = 0;

// ================== Lomuto partition - last element as pivot =======================
int partition(int arr[], int start, int end, int n)
{
    int pivot = arr[end];
    int i = start - 1;
    cout << "\n\n ------------ Partition " << partitionCount + 1 << " -------------" << endl;
    cout << "Start: " << start << " , End: " << end << " , Pivot: " << pivot << endl;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    // swap
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    partitionCount++;
    cout << "Array after partition: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return i; // pivot's correct position
}

void quickSort(int arr[], int start, int end, int n)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end, n);
        // left half call
        quickSort(arr, start, partitionIndex - 1, n);
        // right half call
        quickSort(arr, partitionIndex + 1, end, n);
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
    quickSort(arr, 0, n - 1, n);

    cout << "\n\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nTotal partition operations: " << partitionCount;
    return 0;
}