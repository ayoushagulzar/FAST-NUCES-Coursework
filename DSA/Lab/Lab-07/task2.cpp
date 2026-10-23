// An online store stores product prices in an array.
// Sort the prices in ascending order using Merge Sort.
// Input: {1299, 499, 2499, 799, 499, 1599, 999, 299}
// Requirements:
//     1. Display the left and right subarrays before each merge.
//     2. Count comparisons between elements of the two subarrays during merging.
//     3. Display the final sorted prices and total comparisons.
//     4. Do not use a built-in sorting function.

#include <iostream>
using namespace std;

#define CAPACITY 10

static int mergeCount = 0;
static int comparisons = 0;

void merge(int arr[], int start, int mid, int end)
{
    int i = start, k = start, j = mid + 1;
    int temp[CAPACITY];
    int prevComparisons = comparisons;

    cout << "\n ------------ Merge " << mergeCount + 1 << " -------------" << endl;
    cout << "\nLeft subarray before merging: ";
    for (int i = start; i <= mid; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nRight subarray before merging: ";
    for (int i = mid + 1; i <= end; i++)
    {
        cout << arr[i] << " ";
    }

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

    cout << "\nComparisons = " << (comparisons - prevComparisons) << endl;
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        // left half call recursive call
        mergeSort(arr, start, mid);
        // right half call recursive call
        mergeSort(arr, mid + 1, end);
        // merge both halves
        merge(arr, start, mid, end);
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
    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nTotal comparisons: " << comparisons << endl;
    cout << "Total merge operations: " << mergeCount << endl;

    return 0;
}