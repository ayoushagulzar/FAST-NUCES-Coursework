// A text editor stores the last 8 editing operations in a stack. Each operation is represented by an
// integer code. The editor receives the following operations:
//       12, 25, 17, 31, 44, 19
// The user then presses Undo three times, performs a new operation 52, and presses Undo twice again.
// Implement the system using an array-based stack. After every operation, display the current top
// operation. At the end, display the operations that remain in the stack from top to bottom.
// Your program should also handle an Undo request when the stack is empty.

#include <iostream>
using namespace std;

#define MAX 8

class Stack
{
public:
    int top;
    int array[MAX];

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top < 0;
    }

    bool isFull()
    {
        return top >= MAX - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow! Can not push " << x << endl;
            return;
        }

        array[++top] = x;
        cout << x << " pushed into stack." << endl;
        cout << "Now top element is " << array[top] << endl;
        cout << endl;
    }

    void undo()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return;
        }

        cout << array[top] << " is popped!" << endl;
        top--;

        if (!isEmpty())
            cout << "Now top element is " << array[top] << endl;
        else
            cout << "Stack is now empty." << endl;

        cout << endl;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack (top to bottom):" << endl;

        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << endl;
        }

        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(12);
    s.push(25);
    s.push(27);
    s.push(31);
    s.push(44);
    s.push(19);

    s.undo();
    s.undo();
    s.undo();

    s.push(52);
    s.undo();
    s.undo();

    s.print();

    return 0;
}