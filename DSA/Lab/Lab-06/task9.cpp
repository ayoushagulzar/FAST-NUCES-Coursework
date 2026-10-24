// A puzzle game must fill empty cells of a 4 x 4 Sudoku grid. Each row, each column, and each 2 x 2 box
// must contain numbers 1 to 4 without repetition. Use backtracking to solve the puzzle.
// Initial grid (0 represents an empty cell):
//     1 0 0 4
//     0 4 1 0
//     0 1 4 0
//     4 0 0 1


#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int grid[N][N], int row, int col, int num)
{
    // Check row nd col
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    // Find the starting position of the 2 x 2 box
    int boxRow = (row / 2) * 2;
    int boxCol = (col / 2) * 2;

    // Check the box
    for (int i = boxRow; i < boxRow + 2; i++)
    {
        for (int j = boxCol; j < boxCol + 2; j++)
        {
            if (grid[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N])
{
    // Find an empty cell
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                // Try numbers from 1 to 4
                for (int num = 1; num <= 4; num++)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        // Recursively solve the remaining grid
                        if (solveSudoku(grid))
                        {
                            return true;
                        }

                        // Backtrack
                        grid[row][col] = 0;
                    }
                }

                // No number works in this cell
                return false;
            }
        }
    }

    // No empty cells remain
    return true;
}

int main()
{
    int grid[N][N] = {
        {1, 0, 0, 4},
        {0, 4, 1, 0},
        {0, 1, 4, 0},
        {4, 0, 0, 1}
    };

    if (solveSudoku(grid))
    {
        cout << "Solved Sudoku:\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}
