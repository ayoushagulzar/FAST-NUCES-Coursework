/*
Question 03: Package Weight Sorting

Description:
Develop a program to arrange package weights in ascending order using the
gap-based sorting algorithm described in the scenario. The program should:

* Take the array size and values as input from the user.
* Display the original array.
* Display the gap used in each iteration.
* Display the array after each pass.
* Display the final sorted array.
* Use a shrink factor of 1.3 to reduce the gap.
* Use gap-based comparisons and swapping.
* Do not use sort(), another array, or any other sorting algorithm.
  */

#include <iostream>
#include <windows.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    Sleep(750);
}

void comb_sort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;
    int count = 0;

    while (gap != 1 || swapped)
    {
        gap /= 1.3;

        // min gap should be 1
        if (gap < 1)
        {
            gap = 1;
        }

        count++;
        cout << endl;
        cout << "Gap for iteration " << count << ": " << gap;

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            if (arr[i] > arr[gap + i])
            {
                int temp = arr[i];
                arr[i] = arr[gap + i];
                arr[gap + i] = temp;

                swapped = true;
            }
        }
        cout << "\nArray after pass " << count << ":" << endl;
        printArray(arr, n);
        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;

    comb_sort(array, n);
    cout << endl;

    cout << "Sorted Array: ";
    printArray(array, n);
    cout << endl;

    delete[] array;
    array = NULL;

    return 0;
}