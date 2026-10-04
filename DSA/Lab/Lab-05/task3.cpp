// An office printer serves jobs strictly in the order they were submitted. One afternoon, IT support
// discovers that the first K jobs currently waiting were accidentally submitted in the wrong order by a
// faulty scanner app, and need to be reversed but every job after the first K was submitted correctly and
// must be left exactly where it is, in its original order.

// For example, if the print queue currently holds, from front to back, J1, J2, J3, J4, J5, J6, J7,
// and K = 3, the queue must become J3, J2, J1, J4, J5, J6, J7 only the first three jobs are reversed,
// and the remaining four are untouched, still in their original relative order at the back of the queue.
// Write a function void reverseFirstK(Queue &q, int k) that reverses just the first k elements of the queue
// in place, leaving the rest exactly as they were, using one stack as your only extra storage.
// Test your function on the example above with K = 3.

#include <iostream>
using namespace std;

#define MAX 7

class Stack
{
public:
    int top;
    string stack[MAX];

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

    void push(string word)
    {
        if (!isFull())
            stack[++top] = word;
    }

    string pop()
    {
        if (!isEmpty())
        {
            return stack[top--];
        }
        return " ";
    }
};

class Queue
{
public:
    string queue[MAX];
    int front;
    int rear;
    int number; // current no of elements in a queue

    Queue()
    {
        front = -1;
        rear = -1;
        number = 0;
    }

    bool isEmpty()
    {
        return number == 0;
    }

    bool isFull()
    {
        return number == MAX;
    }

    void enqueue(string word)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = word;
        number++;
    }

    string dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return " ";
        }

        front = (front + 1) % MAX;
        number--;

        return queue[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        int index = (front + 1) % MAX;

        cout << "Queue: ";
        for (int i = 0; i < number; i++)
        {
            cout << queue[index] << " ";
            index = (index + 1) % MAX;
        }
        cout << endl;
    }
};

void reverseFirstK(Queue &q, int k)
{
    Stack st;
    string word;

    for (int i = 0; i < k; i++)
    {
        word = q.dequeue();
        st.push(word);
    }

    while (st.isEmpty() == false)
    {
        word = st.pop();
        q.enqueue(word);
    }

    int size = q.number - k;
    for (int i = 0; i < size; i++)
    {
        word = q.dequeue();
        q.enqueue(word);
    }
}

int main()
{
    Queue queue;
    int k = 3;

    queue.enqueue("J1");
    queue.enqueue("J2");
    queue.enqueue("J3");
    queue.enqueue("J4");
    queue.enqueue("J5");
    queue.enqueue("J6");
    queue.enqueue("J7");

    reverseFirstK(queue, k);
    queue.display();

    return 0;
}