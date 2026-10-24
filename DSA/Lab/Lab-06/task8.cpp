// A security application has four distinct characters: A, B, C, and D. It needs to generate
// every possible arrangement of these characters.
// Write a backtracking program that prints all permutations without missing any arrangement.

#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permute(char arr[], int start, int n)
{
    // Base case: all charaxter arranged
    if (start == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++)
    {
        // Place a character at the current position
        swap(arr[start], arr[i]);

        // Arrange the remaining characters(recursive func)
        permute(arr, start + 1, n);

        // Backtrack
        swap(arr[start], arr[i]);
    }
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    int n = 4;

    permute(arr, 0, n);

    return 0;
}
