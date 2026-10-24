// A word-search game contains a character grid. Determine whether the word "CAT" exists by moving
// horizontally or vertically to adjacent cells. A cell cannot be used more than once in the same word path.

#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

bool searchWord(char grid[ROWS][COLS], string word, int row, int col, int index)
{
    // Base case(found all chars)
    if (index == word.length())
    {
        return true;
    }

    // Check boundaries and character match
    if (row < 0 || row >= ROWS ||
        col < 0 || col >= COLS ||
        grid[row][col] != word[index])
    {
        return false;
    }

    // Mark cell as visited
    char temp = grid[row][col];
    grid[row][col] = '#';

    // Search in all four directions
    if (searchWord(grid, word, row - 1, col, index + 1) ||
        searchWord(grid, word, row + 1, col, index + 1) ||
        searchWord(grid, word, row, col - 1, index + 1) ||
        searchWord(grid, word, row, col + 1, index + 1))
    {
        grid[row][col] = temp;
        return true;
    }

    // Backtrack
    grid[row][col] = temp;

    return false;
}

int main()
{
    char grid[ROWS][COLS] = {
        {'C', 'A', 'T'},
        {'O', 'R', 'D'},
        {'G', 'H', 'I'}};

    string word = "CAT";
    bool found = false;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (searchWord(grid, word, i, j, 0))
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            break;
        }
    }

    if (found)
    {
        cout << "Word found!";
    }
    else
    {
        cout << "Word not found.";
    }

    return 0;
}
