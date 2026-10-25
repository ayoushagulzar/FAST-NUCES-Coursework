// A university is conducting examinations for four courses: Programming, Database Systems, Operating
// Systems, and Computer Networks. The examination hall contains 6 x 8 seating grid, where each cell
// represents a seat.
// The university must assign one seat to each course while satisfying the following restrictions:
// - No two courses can be assigned seats in the same row or column.
// - No two courses can be assigned seats on the same diagonal.
// - The Programming examination must be assigned a seat in the first row.
// - The seat at position \((3,3)\) is unavailable due to a damaged desk.
// Write a recursive C++ program to generate and display all valid seating arrangements that satisfy
// these restrictions.
// Requirements:
//     - Use recursion to assign seats to the four courses.
//     - Check all restrictions before assigning a seat.
//     - Use backtracking to explore alternative arrangements.
//     - Display all valid arrangements and count the total number of valid arrangements.
//     - Do not use built-in library functions to generate arrangements or check constraints.

#include <iostream>
using namespace std;

#define ROWS 6
#define COLS 8
#define COURSES 4

string courseNames[COURSES] =
    {
        "Programming",
        "Database Systems",
        "Operating Systems",
        "Computer Networks"};

int seatRow[COURSES];
int seatCol[COURSES];

bool arrangementExists = false;
int arrangementCount = 0;

// Checking whether a seat is valid for the current course
bool isSafe(int course, int row, int col)
{
    // position 3,3 is damaged
    if (row == 3 && col == 3)
        return false;

    // programming must -> first row
    if (course == 0 && row != 0)
        return false;

    // checking for restrictions
    for (int i = 0; i < course; i++)
    {
        // if same row or column
        if (seatRow[i] == row || seatCol[i] == col)
            return false;

        // if same diagonal
        if (row - seatRow[i] == col - seatCol[i] ||
            row - seatRow[i] == seatCol[i] - col)
            return false;
    }

    return true;
}

void printArrangement()
{
    arrangementCount++;

    cout << "\nArrangement " << arrangementCount << ":\n";

    for (int i = 0; i < COURSES; i++)
    {
        cout << courseNames[i] << ": ("
             << seatRow[i] << ", "
             << seatCol[i] << ")\n";
    }
}

// generate all valid seating arrangements
void assignSeats(int course)
{
    // all cources are assigned-> base case
    if (course == COURSES)
    {
        arrangementExists = true;
        printArrangement();
        return;
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (isSafe(course, row, col))
            {
                // assigning seat to the current course
                seatRow[course] = row;
                seatCol[course] = col;

                // recursively assigning to the next course
                assignSeats(course + 1);

                // undo the current assignment(backtrack)
                seatRow[course] = -1;
                seatCol[course] = -1;
            }
        }
    }
}

int main()
{

    for (int i = 0; i < COURSES; i++)
    {
        seatRow[i] = -1;
        seatCol[i] = -1;
    }

    cout << "All Valid Examination Seating Arrangements\n";
    cout << "\n-------------------------------------------\n";

    assignSeats(0);

    if (!arrangementExists)
    {
        cout << "\nNo valid seating arrangement exists.\n";
    }

    cout << "\n-------------------------------------------\n";
    cout << "Total valid arrangements: "
         << arrangementCount << endl;

    return 0;
}
