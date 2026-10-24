// A student has five numbers: {2, 3, 5, 6, 8}. The student must select a subset whose sum is exactly 9.
// Each number can be selected at most once. Use backtracking to find and display one valid subset.
// If no subset exists, display an appropriate message.


#include<iostream>
using namespace std;

const int N = 5;

bool findSubset(int arr[], int subset[], int index, int sum, int target)
{
    // Base case
    if (sum == target)
    {
        return true;
    }

    // Base case: All elements checked
    if (index == N || sum > target)
    {
        return false;
    }

    // store current element
    subset[index] = 1;

    if (findSubset(arr, subset, index + 1, sum + arr[index], target))
    {
        return true;
    }

    // remove current element (backtracking)
    subset[index] = 0;

    if (findSubset(arr, subset, index + 1, sum, target))
    {
        return true;
    }

    return false;
}

int main()
{
    int arr[N] = {2, 3, 5, 6, 8};
    int subset[N] = {0};
    int target = 9;

    if (findSubset(arr, subset, 0, 0, target))
    {
        cout << "Subset found: ";

        for (int i = 0; i < N; i++)
        {
            if (subset[i] == 1)
            {
                cout << arr[i] << " ";
            }
        }
    }
    else
    {
        cout << "subset not found!";
    }

    return 0;
}
