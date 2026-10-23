// A data-processing system receives n integers, where n is not known at compile time.
// Sample input:
// n = 6
// Array = 35 12 90 12 48 7
// Requirements:
//     1. Read n and allocate the input array dynamically.
//     2. Implement recursive Merge Sort.
//     3. Allocate the temporary merge array dynamically rather than using a fixed-size array.
//     4. Count recursive calls, merge operations, and element comparisons.
//     5. Handle n &lt;= 0 with an error message.
//     6. Release all dynamically allocated memory.

#include <iostream>
using namespace std;

static int mergeCount = 0;
static int comparisons = 0;
static int recursiveCalls = 0;

void merge(int arr[], int start, int mid, int end, int n)
{
    int i = start, k = start, j = mid + 1;
    int *temp = new int[n];
    int prevComparisons = comparisons;

    // copy elements from both halves
    while (i <= mid && j <= end)
    {
        comparisons++;
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
    delete[] temp;

    cout << "\n Merge " << mergeCount << ": " << (comparisons - prevComparisons) << " comparison(s)" << endl;
}

void mergeSort(int arr[], int start, int end, int n)
{
    recursiveCalls++;
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
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of elements.";
        return 1;
    }

    int *arr = new int[n];

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

    cout << "\n\nTotal comparisons: " << comparisons << endl;
    cout << "Total merge operations: " << mergeCount << endl;
    cout << "Total recursive calls: " << recursiveCalls << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}