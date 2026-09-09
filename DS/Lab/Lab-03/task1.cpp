// An online store receives the following product prices: 45 12 78 34 23 90 The prices
// are currently in a completely random order. using the standard Using the standard
// Bubble Sort algorithm, determine the following.
// 1. Number of passes required to completely sort the array.
// 2. Total number of comparisons.
// 3. Total number of swaps.
// 4. Array after each pass.

#include <iostream>
#include <windows.h>
using namespace std;

static int no_of_passes = 0;
static int no_of_comparisons = 0;
static int no_of_swaps = 0;

void printArray(int arr[], int n);

void bubble_sort(int arr[], int n)
{
    // no: of passes
    for (int i = 0; i < n - 1; i++)
    {
        no_of_passes++;

        // no: of comparisons
        for (int j = 0; j < n - 1 - i; j++)
        {
            no_of_comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                no_of_swaps++;
            }
        }

        cout << "\nArray after pass " << i + 1 << ":" << endl;
        printArray(arr, n);
        Sleep(1000); // argument is in milliseconds.Therefore , 1000 ms = 1 sec
    }
    cout << endl;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 6;
    int array[] = {45, 12, 78, 34, 23, 90};

    cout << "Original Array: ";
    printArray(array, n);

    bubble_sort(array, n);
    cout << endl;

    cout << "Number of passes: " << no_of_passes << endl;
    cout << "Number of Comparisons: " << no_of_comparisons << endl;
    cout << "Number of Swaps: " << no_of_swaps << endl;
    return 0;
}