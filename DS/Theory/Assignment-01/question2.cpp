/*
  Question 02: Shelf Capacity Insertion and Sorting

  Description:
  Develop a program to insert a new shelf capacity into a dynamically allocated
  array and arrange the resulting array in ascending order based on the following
  requirements:
  - Take the array size and shelf capacities as input from the user.
  - Create a larger dynamic array to accommodate the new shelf.
  - Copy the existing shelf capacities into the new array.
  - Insert the new shelf at the position specified by the user.
  - Display the array after insertion.
  - Identify and implement the sorting algorithm represented by the scenario.
  - Display the final sorted array.
  - Use dynamic memory (new/delete) and do not use sort() or STL containers.
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
    }
}
int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int *array1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Value " << i + 1 << ": ";
        cin >> array1[i];
    }

    cout << "Original Array: ";
    printArray(array1, n);
    cout << endl;

    // inserting one new shelf
    int m = n + 1;

    // create new array
    int *array2 = new int[m];

    for (int i = 0; i < n; i++)
    {
        // copying previous array values in new array
        array2[i] = array1[i];
    }

    delete[] array1;
    array1 = NULL;

    int position;
    int new_value;

    cout << "Enter the position where you want to insert the new shelf (1-based): "; // index+1
    cin >> position;

    cout << "Enter the new shelf capacity: "; // the exact value we want to add
    cin >> new_value;

    // Shift elements to make space
    for (int i = m - 1; i >= position; i--)
    {
        array2[i] = array2[i - 1];
    }

    // Insert new shelf
    array2[position - 1] = new_value;

    cout << "Array after insertion: ";
    printArray(array2, m);
    cout << endl;

    insertion_sort(array2, m);
    cout << endl;

    cout << "Sorted Array: ";
    printArray(array2, m);
    cout << endl;

    delete[] array2;
    array2 = NULL;

    return 0;
}