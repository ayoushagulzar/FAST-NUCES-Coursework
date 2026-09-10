// A cloud server receives the following load values from different servers:
// 90 20 80 30 70 40 60 50 10
// The values are stored in a random order. Before assigning these loads to servers, the
// system wants to arrange them in ascending order.
// Write a C++ program using Shell Sort with the following requirements:
//     1. Start the gap using n/2 and repeatedly reduce it by half until the gap becomes 1.
//     2. After processing each gap, display the complete array.
//     3. For every gap, count and display the number of comparisons performed.
//     4. Also count the number of shifts performed for that gap.
//     5. Finally, display the total comparisons and total shifts performed by Shell Sort.

#include <iostream>
#include <windows.h>
using namespace std;

static int no_of_shifts = 0;
static int no_of_comparisons = 0;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shell_sort(int arr[], int n)
{
    int count = 1;

    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        int gap_comparisons = 0;
        int gap_shifts = 0;

        // gapped insertion sort
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap)
            {
                gap_comparisons++;
                no_of_comparisons++;

                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;

                    gap_shifts++;
                    no_of_shifts++;
                }
                else
                    break;
            }

            arr[j] = temp;
        }

        cout << endl;
        cout << "Array after gap " << count << " (" << gap << "): ";
        printArray(arr, n);

        cout << "Comparisons for this gap: " << gap_comparisons << endl;

        cout << "Shifts for this gap: " << gap_shifts << endl;
        count++;

        Sleep(750); // 0.75 seconds
    }
}

int main()
{
    int n = 9;
    int array[] = {90, 20, 80, 30, 70, 40, 60, 50, 10};

    cout << "Original Array: ";
    printArray(array, n);
    Sleep(750);

    shell_sort(array, n);

    cout << endl;
    cout << "Total Comparisons: " << no_of_comparisons << endl;
    cout << "Total Shifts: " << no_of_shifts << endl;

    return 0;
}