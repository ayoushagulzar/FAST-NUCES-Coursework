// A university stores students marks in an integer array. Sort the marks in ascending order
// using recursive Merge Sort.
// Input: {78, 45, 92, 63, 45, 88, 51, 70}
// Requirements:
//     1. Implement mergeSort() and merge() as separate functions.
//     2. Display the array after each merge operation.
//     3. Count and display the total number of merge operations.
//     4. Do not use a built-in sorting function.

#include <iostream>
using namespace std;

#define CAPACITY 10

static int mergeCount = 0;

void merge(int arr[], int start, int mid, int end, int n)
{
    int i = start, k = start, j = mid + 1;
    int temp[CAPACITY];

    // copy elements from both halves
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i++];
        }
        else
            temp[k] = arr[j++];
        k++;
    }

    // copy remaining elements of left half
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // copy remaining elements of right half
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // copy values to original array
    for (int i = start, k = start; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }
    mergeCount++;

    cout << "\nArray after merge " << mergeCount << ": ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int start, int end, int n)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        // left half call recursive call
        mergeSort(arr, start, mid, n);
        // right half call recursive call
        mergeSort(arr, mid + 1, end, n);
        // merge both halves
        merge(arr, start, mid, end, n);
    }
}

int main()
{
    int arr[CAPACITY];
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 1 || n > CAPACITY)
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

    cout << endl;
    mergeSort(arr, 0, n - 1, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal merge operations: " << mergeCount << endl;

    return 0;
}
