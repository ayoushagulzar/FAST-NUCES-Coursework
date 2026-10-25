// A university's security system requires a special access code containing N digits. Each digit
// must be selected from a given set of allowed digits. However, the system imposes the following
// restrictions:
//     - No digit can appear more than once.
//     - The sum of all digits must equal a given target value S.
//     - The digits must appear in strictly increasing order.

// Write a recursive C++ program that generates all valid access codes satisfying these conditions.
// For example, if the allowed digits are {1, 2, 3, 4, 5}, N=3, and S=9,
// the program should display: 1 3 5
//                             2 3 4
// Requirements:
//     - Use recursion to select digits and construct combinations.
//     - Use backtracking to remove a selected digit when exploring another possibility.
//     - Display all valid combinations and count them.
//     - If no valid combination exists, display an appropriate message.
//     - Do not use built-in library functions for generating combinations or checking the conditions.

#include <iostream>
using namespace std;

#define MAX 100

int allowedDigits[MAX];
int combination[MAX];

int N, S, M;
int combinationCount = 0;

void findCombinations(int index, int start, int sum)
{
    // All digits selected->base case
    if (index == N)
    {
        if (sum == S)
        {
            combinationCount++;

            for (int i = 0; i < N; i++)
            {
                cout << combination[i] << " ";
            }

            cout << endl;
        }

        return;
    }

    // selecting each remaining digit
    for (int i = start; i < M; i++)
    {
        combination[index] = allowedDigits[i]; // selectt the current digit

        // select the next digit -> do this recursively
        findCombinations(index + 1, i + 1, sum + allowedDigits[i]);
    }
}

int main()
{
    cout << "Enter the number of allowed digits: ";
    cin >> M;

    if (M <= 0 || M > MAX)
    {
        cout << "Invalid number!.\n";
        return 0;
    }

    cout << "Enter the allowed digits in increasing order:\n";

    for (int i = 0; i < M; i++)
    {
        cin >> allowedDigits[i];

        if (i > 0 && allowedDigits[i] <= allowedDigits[i - 1])
        {
            cout << "Digits must be distinct and in increasing order.\n";
            return 0;
        }
    }

    cout << "Enter the number of digits in the access code (N): ";
    cin >> N;

    cout << "Enter the target sum (S): ";
    cin >> S;

    if (N <= 0 || N > M)
    {
        cout << "Invalid value of N.\n";
        return 0;
    }

    findCombinations(0, 0, 0);

    if (combinationCount == 0)
    {
        cout << "No valid combination exists.\n";
    }
    else
    {
        cout << "\nTotal valid combinations: " << combinationCount << endl;
    }

    return 0;
}
