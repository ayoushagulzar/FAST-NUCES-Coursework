// A search application needs to display a sequence of search-range values from smallest to largest.
// Write a recursive C++ function that takes n, recursively calls itself with n-1, and then prints n.

#include <iostream>
using namespace std;

void searchRange(int n)
{
    if (n == 0)
    {
        return;
    }
    searchRange(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cout << "Enter the range limit: ";
    cin >> n;
    searchRange(n);

    return 0;
}