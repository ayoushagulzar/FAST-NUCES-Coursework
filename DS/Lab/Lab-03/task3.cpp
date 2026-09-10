// A warehouse has product quantities : 10 20 30 40 5 50 60 70 The value 5 is located
// far from its correct position. Write a program using Comb Sort to sort the quantities
// in ascending order. In addition to the sorted array, display the gap used in every
// major iteration .

//  Note(not replace Comb Sort with Bubble Sort).
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
        cout << "Gap after iteration " << count << ": " << gap << endl;

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
    }
}

int main()
{
    int n = 8;
    int array[] = {10, 20, 30, 40, 5, 50, 60, 70};

    cout << "Original Array: ";
    printArray(array, n);
    cout << endl;

    comb_sort(array, n);
    cout << "Sorted Array: ";
    printArray(array, n);
    cout << endl;

    return 0;
}