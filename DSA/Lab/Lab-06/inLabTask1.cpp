// A savings application starts with Rs. 10 on Day 1. The amount doubles every day,
// so Day 2 has Rs. 20, Day 3 has Rs. 40, and so on. Write a recursive C++ function that
// takes the number of days n as input and calculates the amount available on Day n.
// For example, if n = 5, the amount on Day 5 should be Rs. 160.

#include <iostream>
using namespace std;

int savings(int n)
{
    int amount = 10;
    if (n == 1)
    {
        return amount;
    }
    return 2 * savings(n - 1);
}

int main()
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    int saving = savings(n);
    cout << "Your saving : Rs. " << saving;
    return 0;
}