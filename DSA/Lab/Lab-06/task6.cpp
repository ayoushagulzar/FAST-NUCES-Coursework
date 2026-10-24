// A robot must travel from the top-left cell to the bottom-right cell of a 4 x 4 maze.
// A value of 1 represents an open cell, while 0 represents a blocked cell.
// The robot can move only right or down. Use backtracking to find a valid path.

#include <iostream>
using namespace std;

const int N = 4;

bool solveMaze(int maze[N][N], int path[N][N], int row, int col)
{
    // Base case (reached dest)
    if (row == N - 1 && col == N - 1 && maze[row][col] == 1)
    {
        path[row][col] = 1;
        return true;
    }

    // Check if the current cell is valid and open
    if (row >= N || col >= N || maze[row][col] == 0)
    {
        return false;
    }

    // Mark the current cell as part of the path
    path[row][col] = 1;

    //move right
    if (solveMaze(maze, path, row, col + 1))
    {
        return true;
    }

    // mov down
    if (solveMaze(maze, path, row + 1, col))
    {
        return true;
    }

    // Backtracking (remove this cell from the path)
    path[row][col] = 0;

    return false;
}

int main()
{
    int maze[N][N] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}};

    int path[N][N] = {0};

    if (solveMaze(maze, path, 0, 0))
    {
        cout << "Path found:\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Path not found.";
    }

    return 0;
}
