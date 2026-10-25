
#include <iostream>
using namespace std;

const int N = 4;
int pathCount = 1;

// 1 = open cell, 0 = obstacle
//assuming the grid since it is not given in question
int buildingGrid[N][N] =
{
    {1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
    {0, 1, 1, 1}
};

int path[N][N] = {0};
int visited[N][N] = {0};
bool pathExists = false;

// Check whether the cell is valid
bool isSafe(int row, int col)
{
    // Outside the building
    if (row < 0 || row >= N || col < 0 || col >= N)
        return false;

    // Obstacle
    if (buildingGrid[row][col] == 0)
        return false;

    // Already visited in the current path
    if (visited[row][col] == 1)
        return false;

    return true;
}

void printPath()
{
    cout << "---------- Path " << pathCount << " ----------\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    pathCount++;
}

void findAllPaths(int row, int col)
{
    // Check whether the current cell is valid
    if (!isSafe(row, col))
        return;

    path[row][col] = 1; // marking current cell as part of the path 
    visited[row][col] = 1; // marking the cell as visited

    // Destination reached
    if (row == N - 1 && col == N - 1)
    {
        pathExists = true;
        printPath();
    }
    else
    {
        // Move RIGHT
        findAllPaths(row, col + 1);

        // Move DOWN
        findAllPaths(row + 1, col);

        // Move LEFT
        findAllPaths(row, col - 1);

        // Move UP
        findAllPaths(row - 1, col);
    }

    //undo current cell markings(backtrack)
    path[row][col] = 0;
    visited[row][col] = 0;
}

int main()
{
    cout << "Building Grid:\n\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << buildingGrid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAll possible paths:\n";

    findAllPaths(0, 0);

    if (!pathExists)
    {
        cout << "No valid path exists.\n";
    }

    return 0;
}
