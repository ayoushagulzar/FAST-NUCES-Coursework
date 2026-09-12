/*
  Question 01: Cable Length Sorting

  Description:
  Develop a program to arrange the given cable lengths in ascending order
  by identifying and implementing the sorting algorithm described in the
  scenario. The program should:
  - Take the array size and values as input from the user.
  - Display the original array.
  - Display the array after each iteration.
  - Display the final sorted array.
  - Use a temporary variable and shifting instead of repeated swapping.
  - Do not use sort() or another array.
*/

#include <iostream>
#include <Windows.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    Sleep(1000);
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && current < arr[previous])
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;

        cout << "\nArray after pass " << i << ":" << endl;
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
        cout << "Value at index " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;

    insertion_sort(array, n);
    cout << endl;

    cout << "Sorted Array: ";
    printArray(array, n);
    cout << endl;

    delete[] array;
    array = NULL;

    return 0;
}