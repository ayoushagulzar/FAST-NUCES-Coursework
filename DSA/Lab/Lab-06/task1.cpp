// A messaging application needs to display a given string in reverse order using recursion.
// Write a recursive C++ function that prints the characters of a string in reverse without
// creating another reversed string.

#include <iostream>
using namespace std;

void stringReverse(string str, int start)
{
    if (start == str.length())
    {
        return;
    }

    stringReverse(str, start + 1);
    cout << str[start];
}
int main()
{
    string str;
    cout << "Enter the string you want to reverse: ";
    cin >> str;
    stringReverse(str, 0);

    return 0;
}