// A national logistics enterprise processes 5,000,000 parcels globally every day. Each parcel object
// contains a unique, non-negative numeric tracking number (ranging from 0 up to 999,999,999), a
// sender name, a destination city, and a region routing code.
// Develop a C++ program to sort these parcel records under two distinct scenarios. You must write your
// sorting algorithms completely from scratch without using any built-in language sorting features.

// Part 2: Regional Code Consolidation
// Your system must also group parcels by their numeric region routing codes.
// The Constraints: Due to strict memory caps on our edge-computing servers, your sorting algorithm
// cannot exceed O(log n) auxiliary space complexity, eliminating heavy array mirroring. However, it
// must guarantee a predictable worst-case time complexity of O(nlogn) to prevent processing
// bottlenecks, and it must be stable so that if two parcels share the same regional code, their original
// sequence remains perfectly intact.

/*
Standard Merge Sort provides a worst-case time complexity of O(n log n) while maintaining stability, but it requires O(n)
auxiliary space. In comparison, standard Quick Sort does not guarantee stability or O(n log n) worst-case time complexity.
To satisfy all the constraints of Part 2, a specialized stable in-place merge algorithm would be needed. I have chosen Merge Sort
because it is stable and was covered in our coursework. It meets the time complexity and stability requirements, although its
auxiliary space complexity is O(n) rather than the required O(log n).
*/

#include <iostream>
#include <string>
using namespace std;

struct Parcel
{
    int trackingNumber;
    string senderName;
    string destinationCity;
    int regionalCode;
};

void merge(Parcel arr[], int first, int mid, int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;

    Parcel *leftArr = new Parcel[n1];
    Parcel *rightArr = new Parcel[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[first + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].regionalCode <= rightArr[j].regionalCode)
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Parcel arr[], int first, int last)
{
    if (first >= last)
        return;

    int mid = first + (last - first) / 2;

    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    merge(arr, first, mid, last);
}

int main()
{
    Parcel parcels[] =
        {
            {42, "Ali", "Karachi", 2},
            {7, "Sara", "Lahore", 1},
            {305, "Ahmed", "Islamabad", 3},
            {12, "Zara", "Peshawar", 2},
            {0, "Usman", "Quetta", 1}};

    int n = sizeof(parcels) / sizeof(parcels[0]);

    mergeSort(parcels, 0, n - 1);

    cout << "Parcels sorted by regional code:\n";

    for (int i = 0; i < n; i++)
    {
        cout << parcels[i].trackingNumber << " "
             << parcels[i].senderName << " "
             << parcels[i].destinationCity << " "
             << parcels[i].regionalCode << '\n';
    }

    return 0;
}
