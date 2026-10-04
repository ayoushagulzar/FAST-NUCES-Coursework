// A shipping company's only available storage equipment is a set of stack-style bins, crates can
// only be added or removed from the top. Management now wants shipments processed strictly in the
// order they were received (first in, first out), but nobody is willing to buy new equipment. You are asked
// to prove this is possible by building a queue that is internally made of nothing but two stack bins
// working together, exposing only enqueue(item) and dequeue() to the rest of the system, which must
// never know that stacks are involved underneath. For example, if items A, B, and C are enqueued in that
// order, calling dequeue() three times in a row must return A, then B, then C true, FIFO behaviour even
// though every underlying operation is a stack push or pop.

// Logical Hint: Use one stack purely for incoming items and a second stack purely for outgoing items.
// Whenever the outgoing stack is empty and a dequeue() is requested, pour the entire incoming stack into
// the outgoing stack one item at a time (which reverses their order back to arrival order), then pop from
// the outgoing stack. If the outgoing stack already has items, just pop from it directly, don't touch the
// incoming stack at all in that case.

// Your Task (C++): Implement a class MyQueue with enqueue(int) and dequeue() methods, using two
// stacks. Test it with the sequence enqueue(A), enqueue(B), dequeue(), enqueue(C), dequeue(), dequeue()
// and confirm the dequeues return A, B, C in that order

#include <iostream>
using namespace std;

#define MAX 3

class Stack
{
public:
    int top;
    char stack[MAX];

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

    void push(char item)
    {
        if (!isFull())
            stack[++top] = item;
    }

    char pop()
    {
        if (!isEmpty())
        {
            return stack[top--];
        }
        return ' ';
    }
};

class MyQueue
{
    Stack ingoing;
    Stack outgoing;

public:
    void enqueue(char item)
    {
        if (ingoing.isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        ingoing.push(item);
    }

    char dequeue()
    {
        if (outgoing.isEmpty())
        {
            while (!ingoing.isEmpty())
            {
                outgoing.push(ingoing.pop());
            }
        }

        if (outgoing.isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return ' ';
        }

        return outgoing.pop();
    }
};

int main()
{
    MyQueue queue;
    queue.enqueue('A');
    queue.enqueue('B');

    cout << queue.dequeue() << " ";

    queue.enqueue('C');

    cout << queue.dequeue() << " ";
    cout << queue.dequeue() << " ";

    return 0;
}