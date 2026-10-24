// FAST NUCES offers two academic awards: Dean’s List and Rector’s List, where the Rector’s List is
// the higher award. The university wants to develop a system to rank students according to
// their academic performance and determine award eligibility.
// Develop a C++ program that stores student ID, name, department, and CGPA. Your program must
// rank students by CGPA in descending order, assign awards according to university policy, and
// display the final merit list. Students with equal CGPAs should be handled appropriately.

// Algorithmic Constraints:
// To ensure the system scales efficiently to large university databases, you are strictly forbidden from
// using O(N^2) sorting techniques (such as Bubble, Selection, or Insertion Sort), as well as built-in
// library sorting functions.
//     1. You must manually implement a divide-and-conquer sorting algorithm to achieve an
//     average time complexity of O(nlogn)
//     2. Explain your chosen algorithm briefly and explain how it handles the stability of
//     records when CGPAs are equal.
//     3. Test your program using at least 30 students, including students with equal CGPAs
//     and students eligible for different awards.

#include <iostream>
#include <string>  // to use getline in code
#include <iomanip> //for manipulation (using setw function in this code)
using namespace std;

struct Student
{
    int id;
    string name;
    string department;
    float cgpa;
    string award;
};

void merge(Student arr[], int n, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    Student *temp = new Student[n];

    while (i <= mid && j <= end)
    {
        // descending order by CGPA
        if (arr[i].cgpa >= arr[j].cgpa)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    for (int i = start, k = start; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }

    delete[] temp;
}

void mergeSort(Student arr[], int n, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        // left half call
        mergeSort(arr, n, start, mid);
        // right half call
        mergeSort(arr, n, mid + 1, end);
        // merge both
        merge(arr, n, start, mid, end);
    }
}

int main()
{
    int n;
    do
    {
        cout << "Enter number of students: ";
        cin >> n;

        if (n <= 0)
            cout << "Number of students must be positive." << endl;

    } while (n <= 0);

    Student *students = new Student[n];

    // input and awards assigning
    for (int i = 0; i < n; i++)
    {
        cout << "-------- Student " << i + 1 << " --------" << endl;
        cout << "Enter student id: ";
        cin >> students[i].id;
        cout << "Enter student name: ";
        cin.ignore();                   // ignores left-over newline
        getline(cin, students[i].name); // to get full name
        cout << "Enter student department: ";
        getline(cin, students[i].department);
        do
        {
            cout << "Enter student's CGPA (0.00 - 4.00): ";
            cin >> students[i].cgpa;

            if (students[i].cgpa < 0.00 || students[i].cgpa > 4.00)
            {
                cout << "Invalid! CGPA must be between 0.00 and 4.00." << endl;
            }

        } while (students[i].cgpa < 0.00 || students[i].cgpa > 4.00);

        if (students[i].cgpa == 4.00)
        {
            students[i].award = "Rector's List";
        }
        else if (students[i].cgpa >= 3.50)
        {
            students[i].award = "Dean's List";
        }
        else
        {
            students[i].award = "No Award";
        }
    }

    mergeSort(students, n, 0, n - 1);

    cout << "\n\n------------------ MERIT LIST ------------------\n";
    // left ---> for left align
    cout << left
         << setw(12) << "Student ID"
         << setw(25) << "Student Name"
         << setw(20) << "Department"
         << setw(10) << "CGPA"
         << "Award" << endl;

    for (int i = 0; i < n; i++)
    {
        // left ---> for left align
        cout << left
             << setw(12) << students[i].id
             << setw(25) << students[i].name
             << setw(20) << students[i].department
             << setw(10) << students[i].cgpa
             << students[i].award << endl;
    }

    delete[] students;
    return 0;
}

// Algorithm: Merge Sort works on divide-and-conquer technique, it divides the array into smaller halves,
// sorts them recursively, and merges them in descending order of CGPA.

// Stability: Merge Sort is stable because when two students have equal CGPAs, the student
// from the left half is placed first, which preserves their original order.

/*
Sample Input:
no of students: 30
1001, Ali Ahmed, CS, 3.80
1002, Sara Khan, SE, 4.00
1003, Ahmed Raza, AI, 3.20
1004, Ayesha Malik, SE, 3.50
1005, Hamza Ali, CS, 3.80
1006, Fatima Noor, AI, 3.90
1007, Usman Tariq, CS, 2.90
1008, Hira Shah, SE, 4.00
1009, Bilal Hassan, CS, 3.40
1010, Zoya Ahmed, AI, 3.50
1011, Daniyal Khan, SE, 3.70
1012, Maham Iqbal, CS, 3.90
1013, Saad Ali, AI, 3.00
1014, Noor Fatima, SE, 3.60
1015, Hassan Raza, CS, 3.80
1016, Eman Tariq, AI, 4.00
1017, Hamza Ahmed, CS, 3.30
1018, Laiba Noor, SE, 3.70
1019, Ahmed Hassan, AI, 3.50
1020, Minal Shah, CS, 3.95
1021, Abdullah Khan, AI, 2.70
1022, Areeba Ali, SE, 3.60
1023, Usama Raza, CS, 3.80
1024, Iqra Ahmed, AI, 3.20
1025, Taha Malik, SE, 3.90
1026, Noor Fatima, CS, 3.50
1027, Danish Ali, AI, 3.10
1028, Anaya Hassan, SE, 3.70
1029, Rayyan Shah, CS, 4.00
1030, Maryam Tariq, AI, 3.40
*/