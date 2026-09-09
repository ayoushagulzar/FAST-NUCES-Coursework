// A university wants to develop a Student Performance Analyzer. The program should
// allow the user to enter the marks of n students.

// Write a C++ program using Insertion Sort with the following requirements:
// The program should first ask the user to enter the number of students. The value of n
// must be between 5 and 15. If the user enters an invalid value, display an error message
// and ask again.

// After that, input the marks of all students. Each mark must be between 0 and 100. If
// an invalid mark is entered, ask the user to enter that mark again.
// Sort the marks in descending order using Insertion Sort.While sorting, your program
// must count and display:
// Total Comparisons and Total Shifts
// At the end, display:
//      Highest Marks
//      Lowest Marks
//      Average Marks
//      Sorted Marks

// If any student has scored 90 or above, display: High Achiever(s) Present Otherwise display:
// No High Achiever

#include <iostream>
using namespace std;

static int total_comparison = 0;
static int total_shifts = 0;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] < current)
        {
            total_comparison++; // this counts successful comparsions
            arr[previous + 1] = arr[previous];
            total_shifts++;
            previous--;
        }
        if (previous >= 0)
        {
            total_comparison++; // this counts unsuccessful comparisons (total = succ + unsucc)
        }
        arr[previous + 1] = current;
    }
}

int highest_marks(int arr[], int n)
{
    int highest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > highest)
        {
            highest = arr[i];
        }
    }
    return highest;
}

int lowest_marks(int arr[], int n)
{
    int lowest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < lowest)
        {
            lowest = arr[i];
        }
    }
    return lowest;
}

float average_marks(int arr[], int n)
{
    int sum = 0;
    float avg;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / n;

    return avg;
}

bool high_achievers(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 90)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    int *marks;

    do
    {
        cout << "Enter number of students between 5 and 15: ";
        cin >> n;

        if (n < 5 || n > 15)
        {
            cout << "Invalid input! The number of students must be between 5 and 15." << endl;
        }

    } while (n < 5 || n > 15);

    marks = new int[n];

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Enter marks (0-100) of student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid input! Marks must be between 0 and 100." << endl;
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    cout << endl;
    insertion_sort(marks, n);
    cout << "Sorted Array: ";
    printArray(marks, n);
    cout << endl;

    cout << "Total Shifts: " << total_shifts << endl;
    cout << "Total Comparisons: " << total_comparison << endl;
    cout << endl;

    int highest = highest_marks(marks, n);
    int lowest = lowest_marks(marks, n);
    float average = average_marks(marks, n);
    bool toppers = high_achievers(marks, n);

    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << average << endl;

    if (toppers)
        cout << "High achiever(s) present." << endl;
    else
        cout << "No High Achiever" << endl;

    delete[] marks;
    marks = NULL;

    return 0;
}