// A warehouse stores product IDs and chooses the first element of each subarray as pivot.
// Input: {55, 25, 75, 15, 65, 35, 45}
// Requirements:
//     1. Implement Quick Sort using the first element as pivot.
//     2. Write a partition function that correctly supports this pivot strategy.
//     3. Display the pivot and array after each partition.
//     4. Count element comparisons.

#include<iostream>
using namespace std;

#define CAPACITY 10

static int partitionCount = 0;
static int comparisons = 0;

// ================== Two-pointer partition - first element as pivot =======================
int partition(int arr[], int start, int end, int n)
{
    int pivot = arr[start];
    int i = start;
    int j = end;

    cout << "\n\n ------------ Partition " << partitionCount + 1 << " -------------" << endl;
    cout << "Pivot: " << pivot << endl;

    while (i < j)
    {

        // This logic misses the final element-to-pivot comparison when a loop condition becomes false.
        //  while (i < end && arr[i] <= pivot)
        //  { i++; comparisons++; }

        // while (arr[j] > pivot)
        // { j--; comparisons++; }

        // checking for elements less than or equal to pivot
        while (i < end)
        {
            comparisons++;
            if (arr[i] > pivot)
                break;
            i++;
        }

        // checking for elements greater than pivot
        while (j > start)
        {
            comparisons++;
            if (arr[j] <= pivot)
                break;
            j--;
        }

        if (i < j)
        {
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position
    int temp = arr[j];
    arr[j] = arr[start];
    arr[start] = temp;

    partitionCount++;
    cout << "Array after partition: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return j; // pivot's correct position
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

    cout << "\nTotal comparisons: " << comparisons << endl;
    cout << "Total partition operations: " << partitionCount << endl;
    return 0;
}