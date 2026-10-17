// A banking application receives a positive integer from the user and needs to calculate
// the sum of its digits using recursion. For example, if the input is 345, the output
// should be 12 because 3+4+5=12.
// Write a recursive C++ function to calculate the sum of digits without using loops.

#include <iostream>
using namespace std;

int sumDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int remainder = n % 10;
    return remainder + sumDigits(n / 10);
}

int main()
{
    int n;
    cout << "Enter positive number: ";
    cin >> n;
    if (n < 0)
    {
        do
        {
            cout << "Please enter positive number!" << endl;
            cin >> n;
        } while (n < 0);
    }

    int sum = sumDigits(n);
    cout << "Sum = " << sum << endl;
    return 0;
}