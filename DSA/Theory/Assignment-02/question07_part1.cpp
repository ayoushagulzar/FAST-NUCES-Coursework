// A national logistics enterprise processes 5,000,000 parcels globally every day. Each parcel object
// contains a unique, non-negative numeric tracking number (ranging from 0 up to 999,999,999), a
// sender name, a destination city, and a region routing code.
// Develop a C++ program to sort these parcel records under two distinct scenarios. You must write your
// sorting algorithms completely from scratch without using any built-in language sorting features.

// Part 1: Tracking Number Sorting
// Your system must sort all 5 million parcels by their tracking numbers in ascending order.
// The Constraints: To prevent system timeouts during peak hours, your sorting routine must run in
// strictly linear time O(n) relative to the number of records. Furthermore, your algorithm must elegantly
// handle tracking numbers with radically different digit lengths (ranging from 1 digit up to 9 digits)
// without breaking down or allocating massive, unmanageable blocks of continuous memory.

#include <iostream>
#include <string>  // to use getline in code
#include <iomanip> //for manipulation (using setw function in this code)
using namespace std;

struct Parcel
{
    int trackingNum;
    string name;
    string city;
    int regionCode;
};

void countSort(Parcel arr[], int n, int exp)
{
    Parcel *output = new Parcel[n];
    int count[10] = {0};

    // frequency count
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i].trackingNum / exp) % 10;
        count[digit]++;
    }

    // cumulative count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i].trackingNum / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    delete[] output;
}

// radix Sort function for tracking numbers from 0 to 999999999
void radixSort(Parcel arr[], int n)
{
    if (n <= 1)
        return;

    int exp = 1;
    for (int i = 0; i < 9; i++)
    {
        countSort(arr, n, exp);
        exp *= 10;
    }
}

int main()
{
    Parcel parcels[5] = {
        {7314, "Ali Ahmed", "Karachi", 2},
        {314, "Sara Khan", "Lahore", 1},
        {47, "Ahmed Raza", "Islamabad", 3},
        {999999999, "Hira Shah", "Peshawar", 2},
        {4, "Hamza Ali", "Multan", 1}};

    int n = 5;

    radixSort(parcels, n);
    cout << "\n\n----------------------- Sorted parcels -----------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(18) << parcels[i].trackingNum
             << setw(20) << parcels[i].name
             << setw(20) << parcels[i].city
             << setw(20) << parcels[i].regionCode
             << endl;
    }

    return 0;
}
